#include "preamplifier_all_panel.h"
#include "ui_preamplifier_all_panel.h"

#include <QMessageBox>

preamplifier_all_panel::preamplifier_all_panel(QWidget *parent) :
    device_panel(parent),
    ui(new Ui::preamplifier_all_panel)
{
    ui->setupUi(this);
    connect(this,SIGNAL(enter_event(QObject*)),this,SLOT(key_catcher(QObject*)));
    connect(this,SIGNAL(command_proofed()),this,SLOT(data_received_and_profed()));
    family="allpreamp";

    ui->dsb_power->installEventFilter(this);
}

preamplifier_all_panel::~preamplifier_all_panel()
{
    delete ui;
}

void preamplifier_all_panel::on_pb_onoff_clicked(bool checked)
{
    // ui->pb_onoff->setChecked(!checked);
    send_command("lsonoff " + family, ID, QString::number(checked));
}

void preamplifier_all_panel::data_received_and_profed()
{
    if (param_check(raw_params,0) == "lrstatus") {
        ui->l_power->setText(QString::number(param_check(raw_params, 3).toDouble()) + " Вт");
    }
    else if (param_check(raw_params,0) == "lronoff"){

    }
}

void preamplifier_all_panel::key_catcher(QObject* key)
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
