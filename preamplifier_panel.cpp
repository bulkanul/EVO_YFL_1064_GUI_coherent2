#include "preamplifier_panel.h"
#include "ui_preamplifier_panel.h"
#include <QDebug>
#include <QMessageBox>

preamplifier_panel::preamplifier_panel(QWidget *parent) :
    device_panel(parent),
    ui(new Ui::preamplifier_panel)
{
    ui->setupUi(this);
    connect(this,&device_panel::enter_event,this,&device_panel::key_catcher);
    connect(this,&device_panel::command_proofed,this,&preamplifier_panel::data_received_and_profed);
    family="preamp";

    ui->w_error_box->hide();
    ui->pushButton->setVisible(false);
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
        ui->progressBar_power->setValue(static_cast<int>(param_check(raw_params, 4).toDouble()));

        // [5] = flags
        int flags = param_check(raw_params, 5).toInt();
        check_error_state(flags, error_code, ui->w_error_box, ui->pushButton);
        // if (flags) {
        //     error_code = flags;
        //     ui->w_error_box->show();
        //     ui->pushButton->setVisible(true);
        //     error_displayer = false;
        // } else {
        //     ui->w_error_box->hide();
        //     ui->pushButton->setVisible(false);
        // }

        // [6] = temp1, [7] = temp2
        ui->l_temp_0->setText(QString::number(param_check(raw_params, 6).toDouble(), 'f', 1) + " °C");
        ui->l_temp_1->setText(QString::number(param_check(raw_params, 7).toDouble(), 'f', 1) + " °C");
        
        // [8] = pd1_bw, [9] = pd2_bw, [10] = pd3_fw, [11] = pd4_fw
        ui->l_pd_1_back->setText(QString::number(param_check(raw_params, 8).toDouble(), 'f', 2) + " V");
        ui->l_pd_2_back->setText(QString::number(param_check(raw_params, 9).toDouble(), 'f', 2) + " V");
        ui->l_pd_3_fwd->setText(QString::number(param_check(raw_params, 10).toDouble(), 'f', 2) + " V");
        ui->l_pd_4_fwd->setText(QString::number(param_check(raw_params, 11).toDouble(), 'f', 2) + " V");
    }
    else if (param_check(raw_params,0) == "lronoff"){
        // lronoff preamp <id> <value>
        ui->pb_onoff->setChecked(param_check(raw_params, 3).toInt());
    }
    else if (param_check(raw_params,0) == "lrpower"){
        // lrpower preamp <id> <value>
        ui->progressBar_power->setValue(static_cast<int>(param_check(raw_params, 3).toDouble()));
    }
    else if (param_check(raw_params,0) == "lrreset"){
        // lrreset preamp <id>
        ui->w_error_box->hide();
    }
}

// void preamplifier_panel::key_catcher(QObject* key)
// {
//     Q_UNUSED(key);
// }


void preamplifier_panel::on_pb_onoff_clicked(bool checked)
{
    ui->pb_onoff->setChecked(!checked);
    
    // lsonoff preamp <id> <value>
    emit send_command("lsonoff " + family, ID, QString::number(checked ? 1 : 0));
    
    silence_counter(2);
}


void preamplifier_panel::on_pushButton_clicked()
{
    call_msg_box(parse_bits(error_code, errors_list));
}

void preamplifier_panel::on_pb_reset_clicked()
{
    emit sl_data_set("lsreset", ID, "");
}
