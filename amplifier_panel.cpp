#include "amplifier_panel.h"
#include "ui_amplifier_panel.h"

#include <QMessageBox>

amplifier_panel::amplifier_panel(QWidget *parent) :
    device_panel(parent),
    ui(new Ui::amplifier)
{
    ui->setupUi(this);
    connect(this,SIGNAL(enter_event(QObject*)),this,SLOT(key_catcher(QObject*)));
    connect(this,SIGNAL(command_proofed()),this,SLOT(data_received_and_profed()));
    family="amp";

    ui->w_error_box->hide();

    ui->dsb_power->installEventFilter(this);
}

amplifier_panel::~amplifier_panel()
{
    delete ui;
}

void amplifier_panel::data_received_and_profed()
{
    if (param_check(raw_params,0) == "lrstatus") {
        ui->pb_laser_onoff->setChecked(param_check(raw_params,3).toInt());
        ui->pb_pilot_onoff->setChecked(param_check(raw_params,4).toInt());

        if(param_check(raw_params, 5).toInt()){
            error_code = param_check(raw_params, 5).toInt();
            ui->w_error_box->show();
            error_displayer = false;
        } else {
            ui->w_error_box->hide();
        }

        ui->l_power->setText(QString::number(param_check(raw_params,6).toDouble()) + " %");
        ui->l_temp_0->setText(QString::number(param_check(raw_params,8).toDouble()) + " °C");
        ui->l_temp_1->setText(QString::number(param_check(raw_params,9).toDouble()) + " °C");
        ui->l_temp_2->setText(QString::number(param_check(raw_params,10).toDouble()) + " °C");
        ui->l_pd_back->setText(QString::number(param_check(raw_params,11).toDouble()) + " В");
        ui->l_pd_forw->setText(QString::number(param_check(raw_params,12).toDouble()) + " В");
        ui->l_diff_pd->setText(QString::number(param_check(raw_params,13).toDouble()) + " В");
        ui->l_pd_power->setText(QString::number(param_check(raw_params,14).toDouble()) + " кВт");
    }
//    else if (param_check(raw_params,0) == "lronoff"){
//        ui->pb_laser_onoff->setChecked(param_check(raw_params,3).toInt());
//    }
//    else if (param_check(raw_params,0) == "lrpilotonoff"){
//        ui->pb_pilot_onoff->setChecked(param_check(raw_params,3).toInt());
//    }
}

void amplifier_panel::key_catcher(QObject* key)
{
    QMessageBox *mesg = new QMessageBox(QMessageBox::Information,
                                        "Подтверждение",
                                        "Отправить команду усилителю "+QString::number(ID)+"?",
                                        QMessageBox::Yes | QMessageBox::No);
    if(mesg->exec()==QMessageBox::Yes){
        if(key->objectName() == "dsb_power"){
            emit sl_data_set("lspower", ID, QString::number(ui->dsb_power->value()).replace(",","."));
        }
    }
}

void amplifier_panel::on_pb_laser_onoff_clicked(bool checked)
{
    ui->pb_laser_onoff->setChecked(!checked);
    send_command("lsonoff " + family, ID, QString::number(checked));
}


void amplifier_panel::on_pb_pilot_onoff_clicked(bool checked)
{
    ui->pb_pilot_onoff->setChecked(!checked);
    send_command("lspilotonoff " + family, ID, QString::number(checked));
}


void amplifier_panel::on_pushButton_clicked()
{
    call_msg_box(parse_bits(error_code, errors_list));
}

