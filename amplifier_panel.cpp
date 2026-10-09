#include "amplifier_panel.h"
#include "ui_amplifier_panel.h"
#include "level_placeholders.h"

#include <QMessageBox>

amplifier_panel::amplifier_panel(QWidget *parent) :
    device_panel(parent),
    ui(new Ui::amplifier)
{
    ui->setupUi(this);
    connect(this,&device_panel::enter_event,this,&device_panel::key_catcher);
    connect(this,&device_panel::command_proofed,this,&amplifier_panel::data_received_and_profed);
    connect(ui->pb_laser_onoff, &QPushButton::clicked, this, &device_panel::on_on_off_button_clicked);

    family="amp";

    ui->w_error_box->hide();
    ui->pushButton->setVisible(false);

    ui->power->installEventFilter(this);

    for(int i = 0; i < 6; ++i) {
        ui->gridLayout->setColumnStretch(i, 1);
    }
    ui->horizontalLayout_4->setStretch(0, 0);
    ui->horizontalLayout_4->setStretch(1, 1);

    ui->verticalSpacer_4->changeSize(20, 0, QSizePolicy::Minimum, QSizePolicy::Fixed);
    level_placeholders::addHeading(ui->gridLayout, this, 5, 6);
    level_labels = {
        level_placeholders::add(ui->gridLayout, this, 6, 0, "l_level_amp_temp_0"),
        level_placeholders::add(ui->gridLayout, this, 6, 1, "l_level_amp_temp_1"),
        level_placeholders::add(ui->gridLayout, this, 6, 2, "l_level_amp_pd_1_fwd"),
        level_placeholders::add(ui->gridLayout, this, 6, 3, "l_level_amp_pd_2_back")
    };
    ui->gridLayout->invalidate();
}

amplifier_panel::~amplifier_panel()
{
    delete ui;
}

void amplifier_panel::data_received_and_profed()
{
    // lrstatus amp <id> <started> <pilot> <power%> <flags> <temp1> <temp2> <pd1_bw> <pd2_fw> <diff_pd> <p_calib>
    // [0]      [1]  [2] [3]       [4]     [5]       [6]     [7]     [8]     [9]      [10]      [11]      [12]
    
    if (param_check(raw_params,0) == "lrstatus") {
        // [3] = started_state
        ui->pb_laser_onoff->setChecked(param_check(raw_params, 3).toInt());
        
        // [4] = start_pilot
        ui->pb_pilot_onoff->setChecked(param_check(raw_params, 4).toInt());
        
        // [5] = power_percent
        ui->l_power->setText(QString::number(param_check(raw_params, 5).toDouble(), 'f', 2) + " %");
        ui->progressBar_power->setValue(static_cast<int>(param_check(raw_params, 5).toDouble()));

        // [6] = flags
        int flags = param_check(raw_params, 6).toInt();
        check_error_state(flags, error_code, ui->w_error_box, ui->pushButton);
        const bool qbhFault = (flags & (1 << 3)) != 0;
        if (qbh_fault != qbhFault) {
            qbh_fault = qbhFault;
            emit qbhFaultChanged(qbh_fault);
        }

        // [7] = temp1, [8] = temp2
        readings[0] = param_check(raw_params, 7).toDouble();
        readings[1] = param_check(raw_params, 8).toDouble();
        ui->l_temp_0->setText(QString::number(readings[0], 'f', 1) + " °C");
        ui->l_temp_1->setText(QString::number(readings[1], 'f', 1) + " °C");
        
        // Protocol order: Back1, Fwd1. Display order: Fwd1, Back1.
        readings[2] = param_check(raw_params, 10).toDouble();
        readings[3] = param_check(raw_params, 9).toDouble();
        ui->l_pd_1_fwd->setText(QString::number(readings[2], 'f', 2) + " V");
        ui->l_pd_2_back->setText(QString::number(readings[3], 'f', 2) + " V");
        readings_valid = true;
        refreshReadingColors();
        
        // [11] = diff_pd
        ui->l_diff_pd->setText(QString::number(param_check(raw_params, 11).toDouble(), 'f', 2) + " V");
        
        // [12] = power_pd_calib
        ui->l_pd_power->setText(QString::number(param_check(raw_params, 12).toDouble(), 'f', 2) + " kW");
    }
    else if (param_check(raw_params,0) == "lronoff"){
        // lronoff amp <id> <value>
        ui->pb_laser_onoff->setChecked(param_check(raw_params, 3).toInt());
    }
    else if (param_check(raw_params,0) == "lrpilotonoff"){
        // lrpilotonoff amp <id> <value>
        ui->pb_pilot_onoff->setChecked(param_check(raw_params, 3).toInt());
    }
    else if (param_check(raw_params,0) == "lrpower"){
        // lrpower amp <id> <value>
        ui->progressBar_power->setValue(static_cast<int>(param_check(raw_params, 3).toDouble()));
    }
}

void amplifier_panel::setLevels(const std::array<double, 4> &values)
{
    levels = values;
    levels_valid = true;
    for (size_t i = 0; i < level_labels.size(); ++i) {
        const QString comparison = i == 2 ? "> " : "< ";
        level_labels[i]->setText(comparison + QString::number(levels[i], 'f', 2) +
                                 (i < 2 ? " °C" : " V"));
        level_labels[i]->setToolTip(i == 2 ? "Allowed above this level"
                                                : "Allowed below this level");
    }
    refreshReadingColors();
}

void amplifier_panel::clearLevels()
{
    levels_valid = false;
    readings_valid = false;
    for (QLabel *label : level_labels) {
        label->setText(QString::fromUtf8("—"));
        label->setToolTip("Threshold unavailable");
    }
    refreshReadingColors();
}

void amplifier_panel::refreshReadingColors()
{
    const std::array<QLabel *, 4> sensor_labels = {
        ui->l_temp_0, ui->l_temp_1, ui->l_pd_1_fwd, ui->l_pd_2_back
    };
    for (size_t i = 0; i < sensor_labels.size(); ++i) {
        if (!levels_valid || !readings_valid) {
            sensor_labels[i]->setStyleSheet("");
            continue;
        }
        const auto kind = i == 2 ? level_placeholders::LimitKind::Minimum
                                 : level_placeholders::LimitKind::Maximum;
        level_placeholders::colorReading(sensor_labels[i], readings[i], levels[i], kind);
    }
}

void amplifier_panel::on_pb_pilot_onoff_clicked(bool checked)
{
    ui->pb_pilot_onoff->setChecked(!checked);
    // lspilotonoff amp <id> <value>
    emit sl_data_set("lspilotonoff", ID, QString::number(checked ? 1 : 0));
}


void amplifier_panel::on_pushButton_clicked()
{
    QStringList details;
    for (int bit : {1, 0, 2, 3, 4, 5, 6, 7, 8}) {
        if (error_code & (1 << bit)) details.append(errors_list.at(bit));
    }
    call_msg_box(details.join('\n'));
}
