#include "generator_panel.h"
#include "ui_generator_panel.h"

#include <QMessageBox>

generator_panel::generator_panel(QWidget *parent) :
    device_panel(parent),
    ui(new Ui::generator_panel)
{
    ui->setupUi(this);
    connect(this,SIGNAL(enter_event(QObject*)),this,SLOT(key_catcher(QObject*)));
    connect(this,SIGNAL(command_proofed()),this,SLOT(data_received_and_profed()));
    family="gen";

    ui->dsb_temp_1->installEventFilter(this);
    ui->dsb_temp_2->installEventFilter(this);
}

generator_panel::~generator_panel()
{
    delete ui;
}

void generator_panel::on_pb_tec_1_onoff_clicked(bool checked)
{
    send_command("lsteconoff gen", ID, "0 " + QString::number(checked));
}


void generator_panel::on_pb_tec_2_onoff_clicked(bool checked)
{
    send_command("lsteconoff " + family, ID, "1 " + QString::number(checked));
}

void generator_panel::data_received_and_profed()
{
    if (param_check(raw_params,0) == "lrstatus") {
        ui->l_laser_state->setText(param_check(raw_params,3).toInt()?"ВКЛ.":"ВЫКЛ.");
        ui->l_laser_temp_0->setText(QString::number(param_check(raw_params,6).toDouble()) + " °C");
        ui->l_laser_temp_1->setText(QString::number(param_check(raw_params,7).toDouble()) + " °C");
        ui->l_laser_temp_2->setText(QString::number(param_check(raw_params,8).toDouble()) + " °C");
        ui->l_tec_state_1->setText(param_check(raw_params,9).toInt()?"ВКЛ.":"ВЫКЛ.");
        ui->l_tec_state_2->setText(param_check(raw_params,10).toInt()?"ВКЛ.":"ВЫКЛ.");
        ui->l_tec_temp_1->setText(QString::number(param_check(raw_params,11).toDouble()) + " °C");
        ui->l_tec_temp_2->setText(QString::number(param_check(raw_params,12).toDouble()) + " °C");
        ui->l_tec_temp_1->setText(QString::number(param_check(raw_params,13).toDouble()) + " °C");
        ui->l_pd_back->setText(QString::number(param_check(raw_params,14).toDouble()) + " В");
        ui->l_pd_forw->setText(QString::number(param_check(raw_params,15).toDouble()) + " В");
    }
    else if (param_check(raw_params,0) == "lronoff"){
        ui->pb_laser_onoff->setChecked(param_check(raw_params,3).toInt());
    }
    else if (param_check(raw_params,0) == "lrteconoff"){
        if (param_check(raw_params,3).toInt() == 0)
            ui->pb_tec_1_onoff->setChecked(param_check(raw_params,4).toInt());
        else if (param_check(raw_params,3).toInt() == 1)
            ui->pb_tec_2_onoff->setChecked(param_check(raw_params,4).toInt());
    }
}

void generator_panel::key_catcher(QObject* key)
{
    QMessageBox *mesg = new QMessageBox(QMessageBox::Information,
                                        "Подтверждение",
                                        "Отправить команду усилителю "+QString::number(ID)+"?",
                                        QMessageBox::Yes | QMessageBox::No);
    if(mesg->exec()==QMessageBox::Yes){
        if(key->objectName() == "dsb_temp_1"){
            emit sl_data_set("lstemptec", ID,  "0 " + QString::number(ui->dsb_temp_1->value()).replace(",","."));
        }
        else if(key->objectName() == "dsb_temp_2"){
            emit sl_data_set("lstemptec", ID, "1 " + QString::number(ui->dsb_temp_2->value()).replace(",","."));
        }
    }
}

void generator_panel::on_pb_laser_onoff_clicked(bool checked)
{
    send_command("lsonoff " + family, ID, QString::number(checked));
}

