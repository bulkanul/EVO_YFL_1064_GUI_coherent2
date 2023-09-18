#include "amplifier_all_panel.h"
#include "ui_amplifier_all_panel.h"

#include <QMessageBox>

amplifier_all_panel::amplifier_all_panel(QWidget *parent) :
    device_panel(parent),
    ui(new Ui::amplifier_all_panel)
{
    ui->setupUi(this);
    connect(this,SIGNAL(enter_event(QObject*)),this,SLOT(key_catcher(QObject*)));
    connect(this,SIGNAL(command_proofed()),this,SLOT(data_received_and_profed()));
    family="allamp";

    ui->dsb_power->installEventFilter(this);
}

amplifier_all_panel::~amplifier_all_panel()
{
    delete ui;
}

void amplifier_all_panel::data_received_and_profed()
{
    if (param_check(raw_params,0) == "lrstatus") {

    }
    else if (param_check(raw_params,0) == "lronoff"){

    }
    else if (param_check(raw_params,0) == "lrpilotonoff"){

    }
}

void amplifier_all_panel::key_catcher(QObject* key)
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

void amplifier_all_panel::on_pb_laser_onoff_clicked(bool checked)
{
    send_command("lsonoff " + family, ID, QString::number(checked));
}

