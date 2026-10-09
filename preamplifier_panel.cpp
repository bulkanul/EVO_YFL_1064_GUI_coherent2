#include "preamplifier_panel.h"
#include "ui_preamplifier_panel.h"
#include "level_placeholders.h"
#include <QDebug>
#include <QMessageBox>

preamplifier_panel::preamplifier_panel(QWidget *parent) :
    device_panel(parent),
    ui(new Ui::preamplifier_panel)
{
    ui->setupUi(this);
    connect(this,&device_panel::enter_event,this,&device_panel::key_catcher);
    connect(this,&device_panel::command_proofed,this,&preamplifier_panel::data_received_and_profed);
    connect(ui->pb_onoff, &QPushButton::clicked, this, &device_panel::on_on_off_button_clicked);

    family="preamp";

    ui->w_error_box->hide();
    ui->pushButton->setVisible(false);
    ui->pb_reset->setVisible(false);

    ui->l_temp_0->setMaximumWidth(QWIDGETSIZE_MAX);
    ui->l_temp_1->setMaximumWidth(QWIDGETSIZE_MAX);
    ui->label_8->setMaximumWidth(QWIDGETSIZE_MAX);
    ui->label_9->setMaximumWidth(QWIDGETSIZE_MAX);
    ui->l_pd_1_fwd->setMaximumWidth(QWIDGETSIZE_MAX);
    ui->l_pd_2_back->setMaximumWidth(QWIDGETSIZE_MAX);
    ui->l_pd_3_fwd->setMaximumWidth(QWIDGETSIZE_MAX);
    ui->l_pd_4_back->setMaximumWidth(QWIDGETSIZE_MAX);

    ui->horizontalLayout_3->setStretch(0, 0);
    ui->horizontalLayout_3->setStretch(1, 1);

    this->setMinimumWidth(0);
    for (int i =0; i<6; ++i){
        ui->gridLayout_2->setColumnStretch(i, 1);
    }

    ui->verticalSpacer_4->changeSize(20, 0, QSizePolicy::Minimum, QSizePolicy::Fixed);
    level_placeholders::addHeading(ui->gridLayout_2, this, 4, 6);
    level_labels = {
        level_placeholders::add(ui->gridLayout_2, this, 5, 0, "l_level_preamp_temp_0"),
        level_placeholders::add(ui->gridLayout_2, this, 5, 1, "l_level_preamp_temp_1"),
        level_placeholders::add(ui->gridLayout_2, this, 5, 2, "l_level_preamp_pd_1_fwd"),
        level_placeholders::add(ui->gridLayout_2, this, 5, 3, "l_level_preamp_pd_2_back"),
        level_placeholders::add(ui->gridLayout_2, this, 5, 4, "l_level_preamp_pd_3_fwd"),
        level_placeholders::add(ui->gridLayout_2, this, 5, 5, "l_level_preamp_pd_4_back")
    };
    ui->gridLayout_2->invalidate();
}

preamplifier_panel::~preamplifier_panel()
{
    delete ui;
}

void preamplifier_panel::data_received_and_profed()
{
    // lrstatus preamp <id> <started> <power> <flags> <t1> <t2> <pd1_bw> <pd2_bw> <pd3_fw> <pd4_fw>
    //  [0]    [1]     [2]     [3]      [4]     [5]    [6]  [7]   [8]       [9]     [10]     [11]
    
    if (param_check(raw_params,0) == "lrstatus") {
        
        // [3] = started_state
        bool isStarted = param_check(raw_params, 3).toInt();
        ui->pb_onoff->setChecked(isStarted);
        
        // [4] = power value (0-100)
        // ui->progressBar_power->setValue(static_cast<int>(param_check(raw_params, 4).toDouble()));

        // [5] = flags
        preamp_error_flags = param_check(raw_params, 5).toInt();
        refreshErrorState();

        // [6] = temp1, [7] = temp2
        readings[0] = param_check(raw_params, 6).toDouble();
        readings[1] = param_check(raw_params, 7).toDouble();
        ui->l_temp_0->setText(QString::number(readings[0], 'f', 1) + " °C");
        ui->l_temp_1->setText(QString::number(readings[1], 'f', 1) + " °C");
        
        // Protocol order: Back1, Back2, Fwd1, Fwd2. Display order: Fwd1, Back1, Fwd2, Back2.
        readings[2] = param_check(raw_params, 10).toDouble();
        readings[3] = param_check(raw_params, 8).toDouble();
        readings[4] = param_check(raw_params, 11).toDouble();
        readings[5] = param_check(raw_params, 9).toDouble();
        ui->l_pd_1_fwd->setText(QString::number(readings[2], 'f', 2) + " V");
        ui->l_pd_2_back->setText(QString::number(readings[3], 'f', 2) + " V");
        ui->l_pd_3_fwd->setText(QString::number(readings[4], 'f', 2) + " V");
        ui->l_pd_4_back->setText(QString::number(readings[5], 'f', 2) + " V");
        readings_valid = true;
        refreshReadingColors();
    }
    else if (param_check(raw_params,0) == "lronoff"){
        // lronoff preamp <id> <value>
        ui->pb_onoff->setChecked(param_check(raw_params, 3).toInt());
    }
    else if (param_check(raw_params,0) == "lrpower"){
        // lrpower preamp <id> <value>
        // ui->progressBar_power->setValue(static_cast<int>(param_check(raw_params, 3).toDouble()));
    }
    else if (param_check(raw_params,0) == "lrreset"){
        // lrreset preamp <id>
        preamp_error_flags = 0;
        refreshErrorState();
    }
}

void preamplifier_panel::setLevels(const std::array<double, 6> &values)
{
    levels = values;
    levels_valid = true;
    for (size_t i = 0; i < level_labels.size(); ++i) {
        const QString comparison = i == 2 || i == 4 ? "> " : "< ";
        level_labels[i]->setText(comparison + QString::number(levels[i], 'f', 2) +
                                 (i < 2 ? " °C" : " V"));
        level_labels[i]->setToolTip(i == 2 || i == 4 ? "Allowed above this level"
                                                       : "Allowed below this level");
    }
    refreshReadingColors();
}

void preamplifier_panel::clearLevels()
{
    levels_valid = false;
    readings_valid = false;
    for (QLabel *label : level_labels) {
        label->setText(QString::fromUtf8("—"));
        label->setToolTip("Threshold unavailable");
    }
    refreshReadingColors();
}

void preamplifier_panel::refreshReadingColors()
{
    const std::array<QLabel *, 6> sensor_labels = {
        ui->l_temp_0, ui->l_temp_1, ui->l_pd_1_fwd,
        ui->l_pd_2_back, ui->l_pd_3_fwd, ui->l_pd_4_back
    };
    for (size_t i = 0; i < sensor_labels.size(); ++i) {
        if (!levels_valid || !readings_valid) {
            sensor_labels[i]->setStyleSheet("");
            continue;
        }
        const auto kind = (i == 2 || i == 4) ? level_placeholders::LimitKind::Minimum
                                              : level_placeholders::LimitKind::Maximum;
        level_placeholders::colorReading(sensor_labels[i], readings[i], levels[i], kind);
    }
}

void preamplifier_panel::setAmpQbhFault(bool active)
{
    if (amp_qbh_fault == active) return;
    amp_qbh_fault = active;
    refreshErrorState();
}

void preamplifier_panel::refreshErrorState()
{
    const int hasError = preamp_error_flags != 0 || amp_qbh_fault;
    check_error_state(hasError, displayed_error_state, ui->w_error_box, ui->pushButton);
}

void preamplifier_panel::on_pushButton_clicked()
{
    QStringList details;
    for (int bit : {1, 0, 3, 2, 4, 5, 6, 7}) {
        if (preamp_error_flags & (1 << bit)) details.append(errors_list.at(bit));
    }
    if (amp_qbh_fault) details.append("QBH fault");
    call_msg_box(details.join('\n'));
}

void preamplifier_panel::on_pb_reset_clicked()
{
    // emit sl_data_set("lsreset", ID, "");
}
