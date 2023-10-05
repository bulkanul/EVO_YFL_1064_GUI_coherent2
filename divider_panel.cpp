#include "divider_panel.h"
#include "ui_divider_panel.h"

#include <QMessageBox>

divider_panel::divider_panel(QWidget *parent) :
    device_panel(parent),
    ui(new Ui::divider_panel)
{
    ui->setupUi(this);

    connect(this,SIGNAL(enter_event(QObject*)),this,SLOT(key_catcher(QObject*)));
    connect(this,SIGNAL(command_proofed()),this,SLOT(data_received_and_profed()));
    family="div";
    ID = 0;

    ui->dsb_pd_forw->installEventFilter(this);
}

divider_panel::~divider_panel()
{
    delete ui;
}

void divider_panel::data_received_and_profed()
{
    if (param_check(raw_params,0) == "lrstatus") {
        // flag
        ui->l_pd_forw->setText(QString::number(param_check(raw_params, 4).toDouble()) + " В");
    }
}

void divider_panel::key_catcher(QObject* key)
{
    QMessageBox *mesg = new QMessageBox(QMessageBox::Information,
                                        "Подтверждение",
                                        "Отправить команду делителю "+QString::number(ID)+"?",
                                        QMessageBox::Yes | QMessageBox::No);
    if(mesg->exec()==QMessageBox::Yes){
        if(key->objectName() == "dsb_pd_forw"){
            emit sl_data_set("lslvlpd", ID, QString::number(ui->dsb_pd_forw->value()).replace(",","."));
        }
    }
}
