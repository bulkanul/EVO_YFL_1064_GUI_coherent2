#include "divider_panel.h"
#include "ui_divider_panel.h"

#include <QMessageBox>
#include <QTimer>

divider_panel::divider_panel(QWidget *parent) :
    device_panel(parent),
    ui(new Ui::divider_panel)
{
    ui->setupUi(this);

//    delete tmr;
//    tmr = new QTimer();
//    tmr->setInterval(1400);
//    connect(tmr,SIGNAL(timeout()),this,SLOT(auto_telemetry_call()));
//    tmr->start();

    connect(this,SIGNAL(enter_event(QObject*)),this,SLOT(key_catcher(QObject*)));
    connect(this,SIGNAL(command_proofed()),this,SLOT(data_received_and_profed()));
    family="div";
    ID = 0;

    ui->w_error_box->hide();

    ui->dsb_pd_forw->installEventFilter(this);
}

divider_panel::~divider_panel()
{
    delete ui;
}

void divider_panel::data_received_and_profed()
{
    if (param_check(raw_params,0) == "lrstatus") {

        if(param_check(raw_params, 3).toInt()){
            error_code = param_check(raw_params, 3).toInt();
            ui->w_error_box->show();
            error_displayer = false;
        } else {
            ui->w_error_box->hide();
        }

        auto pd_value = QString::number(param_check(raw_params, 4).toDouble(), 'f', 2);
        ui->l_pd_forw->setText(QString::number(pd_value.toDouble()) + " В");
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

void divider_panel::on_pushButton_clicked()
{
    call_msg_box(parse_bits(error_code, errors_list));
}

