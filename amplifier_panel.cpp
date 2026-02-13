#include "amplifier_panel.h"
#include "ui_amplifier_panel.h"

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

        // [6] = flags
        int flags = param_check(raw_params, 6).toInt();
        check_error_state(flags, error_code, ui->w_error_box, ui->pushButton);

        // [7] = temp1, [8] = temp2
        ui->l_temp_0->setText(QString::number(param_check(raw_params, 7).toDouble(), 'f', 1) + " °C");
        ui->l_temp_1->setText(QString::number(param_check(raw_params, 8).toDouble(), 'f', 1) + " °C");
        
        // [9] = pd1_bw, [10] = pd2_fw
        ui->l_pd_back->setText(QString::number(param_check(raw_params, 9).toDouble(), 'f', 2) + " V");
        ui->l_pd_forw->setText(QString::number(param_check(raw_params, 10).toDouble(), 'f', 2) + " V");
        
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
    call_msg_box(parse_bits(error_code, errors_list));
}
