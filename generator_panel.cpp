#include "generator_panel.h"
#include "ui_generator_panel.h"

#include <QMessageBox>

generator_panel::generator_panel(QWidget *parent) :
    device_panel(parent),
    ui(new Ui::generator_panel)
{
    ui->setupUi(this);
    
    connect(this,&device_panel::enter_event,this,&device_panel::key_catcher);
    connect(this,&device_panel::command_proofed,this,&generator_panel::data_received_and_profed);
    connect(ui->pb_laser_onoff, &QPushButton::clicked, this, &device_panel::on_on_off_button_clicked);

    family = "gen";

    ui->w_error_box->hide();
    ui->pushButton->setVisible(false);
}

generator_panel::~generator_panel()
{
    delete ui;
}

void generator_panel::data_received_and_profed()
{
    // lrstatus gen <id> <started> <flags> <t1> <t2> <tec1_on> <tec2_on> <tec1_t> <tec2_t> <pd1> <pd2> <pd3> <hpld1_on> <hpld2_on> <curr1> <curr2>
    // [0]      [1]  [2]  [3]       [4]     [5]  [6]  [7]       [8]       [9]      [10]     [11]  [12]  [13]  [14]       [15]       [16]    [17]

    if (param_check(raw_params, 0) == "lrstatus") {

        // 1 Laser State
        bool isStarted = param_check(raw_params, 3).toInt();
        ui->pb_laser_onoff->setChecked(isStarted);

        emit sig_usr_changes("l_footer_connection_status", true);
        emit emission_changed(isStarted);

        // 2 Flags (Errors)
        int flags = param_check(raw_params, 4).toInt();
        check_error_state(flags, error_code, ui->w_error_box, ui->pushButton);

        double coreT1 = param_check(raw_params, 5).toDouble();
        double coreT2 = param_check(raw_params, 6).toDouble();
        ui->l_core_temp_1->setText(QString::number(coreT1, 'f', 1) + " °C");
        ui->l_core_temp_2->setText(QString::number(coreT2, 'f', 1) + " °C");

        // 3 TEC State & Temps
        bool tec1 = param_check(raw_params, 7).toInt();
        bool tec2 = param_check(raw_params, 8).toInt();

        ui->l_tec_1_indicator->setEnabled(tec1);
        ui->l_tec_2_indicator->setEnabled(tec2);

        double tecTemp1 = param_check(raw_params, 9).toDouble();
        double tecTemp2 = param_check(raw_params, 10).toDouble();
        ui->dsb_temp_1->setValue(tecTemp1);
        ui->dsb_temp_2->setValue(tecTemp2);

        double pd1 = param_check(raw_params, 11).toDouble();
        double pd2 = param_check(raw_params, 12).toDouble();
        double pd3 = param_check(raw_params, 13).toDouble();
        ui->l_pd1_fw->setText(QString::number(pd1, 'f', 2) + " V");
        ui->l_pd2_bw->setText(QString::number(pd2, 'f', 2) + " V");
        ui->l_pd3->setText(QString::number(pd3, 'f', 2) + " V");

        // 4 HPLD Status
        bool hpld1_on = param_check(raw_params, 14).toInt();
        bool hpld2_on = param_check(raw_params, 15).toInt();
        double hpld1_cur = param_check(raw_params, 16).toDouble();
        double hpld2_cur = param_check(raw_params, 17).toDouble();

        ui->l_hpld_1_status->setText(hpld1_on ? "ON" : "OFF");
        ui->l_hpld_1_status->setStyleSheet(hpld1_on ? "font-weight: bold; color: green;" : "font-weight: bold; color: gray;");
        ui->l_hpld_1_current->setText(QString::number(hpld1_cur, 'f', 2) + " A");

        ui->l_hpld_2_status->setText(hpld2_on ? "ON" : "OFF");
        ui->l_hpld_2_status->setStyleSheet(hpld2_on ? "font-weight: bold; color: green;" : "font-weight: bold; color: gray;");
        ui->l_hpld_2_current->setText(QString::number(hpld2_cur, 'f', 2) + " A");
    }
    else if (param_check(raw_params, 0) == "lronoff") {
        ui->pb_laser_onoff->setChecked(param_check(raw_params, 3).toInt());
    }
}

void generator_panel::on_pushButton_clicked()
{
    call_msg_box(parse_bits(error_code, errors_list));
}
