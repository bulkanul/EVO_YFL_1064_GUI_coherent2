#include "preamplifier_panel.h"
#include "ui_preamplifier_panel.h"
#include <QDebug>
#include <QMessageBox>

preamplifier_panel::preamplifier_panel(QWidget *parent) :
    device_panel(parent),
    ui(new Ui::preamplifier_panel)
{
    ui->setupUi(this);
    connect(this,SIGNAL(enter_event(QObject*)),this,SLOT(key_catcher(QObject*)));
    connect(this,SIGNAL(command_proofed()),this,SLOT(data_received_and_profed()));
    family="preamp";

    ui->dsb_power->installEventFilter(this);
}

preamplifier_panel::~preamplifier_panel()
{
    delete ui;
}

void preamplifier_panel::data_received_and_profed()
{
    if (param_check(raw_params,0) == "lrstatus") {
        ui->pb_onoff->setChecked(param_check(raw_params,3).toInt());
        ui->l_power->setText(QString::number(param_check(raw_params,4).toDouble()) + " Вт");
        ui->l_temp_0->setText(QString::number(param_check(raw_params,6).toDouble()) + " °C");
        ui->l_temp_1->setText(QString::number(param_check(raw_params,7).toDouble()) + " °C");
        ui->l_temp_2->setText(QString::number(param_check(raw_params,8).toDouble()) + " °C");
        ui->l_pd_back_0->setText(QString::number(param_check(raw_params,9).toDouble()) + " В");
        ui->l_pd_back_2->setText(QString::number(param_check(raw_params,10).toDouble()) + " В");
        ui->l_pd_forw_0->setText(QString::number(param_check(raw_params,11).toDouble()) + " В");
        ui->l_pd_forw_2->setText(QString::number(param_check(raw_params,12).toDouble()) + " В");
    }
    else if (param_check(raw_params,0) == "lronoff"){
        // ui->pb_onoff->setChecked(param_check(raw_params,3).toInt());
    }
}

void preamplifier_panel::key_catcher(QObject* key)
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


void preamplifier_panel::on_pb_onoff_clicked(bool checked)
{
    ui->pb_onoff->setChecked(!checked);
    send_command("lsonoff " + family, ID, QString::number(checked));
}

