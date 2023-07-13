#include "cb_panel.h"
#include "ui_cb_panel.h"
#include "device_panel.h"

#include <QTimer>
#include <QDebug>
#include <QMessageBox>

cb_panel::cb_panel(QWidget *parent):
    device_panel(parent),
    ui(new Ui::cb_panel)
{
    ui->setupUi(this);
    connect(this,SIGNAL(enter_event(QObject*)),this,SLOT(key_catcher(QObject*)));
    connect(this,SIGNAL(command_proofed()),this,SLOT(data_received_and_profed()));
    label_list.append(ui->forward_label_0);
    label_list.append(ui->forward_label_1);
    label_list.append(ui->forward_label_2);
    label_list.append(ui->backward_label_0);
    label_list.append(ui->backward_label_1);
    label_list.append(ui->backward_label_2);
    label_list.append(ui->forward_level_label_0);
    label_list.append(ui->forward_level_label_1);
    label_list.append(ui->forward_level_label_2);
    label_list.append(ui->backward_level_label_0);
    label_list.append(ui->backward_level_label_1);
    label_list.append(ui->backward_level_label_2);
    tmr=new QTimer();
    tmr->setInterval(1300);
    connect(tmr,SIGNAL(timeout()),this,SLOT(auto_telemetry_call()));
    tmr->start();
}

cb_panel::~cb_panel()
{
    delete ui;
}

void cb_panel::auto_telemetry_call()
{
    count++;
    if(count>30){
        enable_widget(false);
        connection_lost=true;
    }
    emit send_command(QString("t"+internal_address+"89600"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
    emit send_command(QString("t"+internal_address+"89700"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
    emit send_command(QString("t"+internal_address+"89A00"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
    emit send_command(QString("t"+internal_address+"89B00"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
    emit send_command(QString("t"+internal_address+"89200"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');

    emit send_command(QString("t"+internal_address+"89600"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0100000000").toUtf8()+'\r');
    emit send_command(QString("t"+internal_address+"89700"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0100000000").toUtf8()+'\r');
    emit send_command(QString("t"+internal_address+"89A00"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0100000000").toUtf8()+'\r');
    emit send_command(QString("t"+internal_address+"89B00"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0100000000").toUtf8()+'\r');
    emit send_command(QString("t"+internal_address+"89200"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0100000000").toUtf8()+'\r');

    emit send_command(QString("t"+internal_address+"89600"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0200000000").toUtf8()+'\r');
    emit send_command(QString("t"+internal_address+"89700"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0200000000").toUtf8()+'\r');
    emit send_command(QString("t"+internal_address+"89A00"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0200000000").toUtf8()+'\r');
    emit send_command(QString("t"+internal_address+"89B00"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0200000000").toUtf8()+'\r');
    emit send_command(QString("t"+internal_address+"89200"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0200000000").toUtf8()+'\r');
}

void cb_panel::key_catcher(QObject* key)
{
    QMessageBox *mesg = new QMessageBox(QMessageBox::Information,
                                        "Conformation",
                                        "Send command on dc "+QString::number(ID)+"?",
                                        QMessageBox::Yes | QMessageBox::No);
    if(mesg->exec()==QMessageBox::Yes){
        QDoubleSpinBox *target = static_cast<QDoubleSpinBox*>(key);
        QString command;
        command=key->objectName().contains("treashold")?(key->objectName().contains("forward")?"1A":"17"):
                                                        (key->objectName().contains("forward")?"1B":"16");
        QString message ="t";
        message.append(internal_address);
        message.append("8");
        message.append(command);
        message.append("00");
        message.append(QString("%1").arg(ID, 2, 16, QLatin1Char( '0' )));
        message.append("00");
        int value=target->value()*100;
        unsigned char *bytes = (unsigned char *)&value;
        unsigned char letters[] = {bytes[3],bytes[2],bytes[1],bytes[0]};
        QByteArray data=QByteArray(reinterpret_cast<char*>(letters),4);
        message.append(QString("%1").arg(value, 8, 16, QLatin1Char( '0' )));
        emit send_command(message.toUtf8()+'\r');
    }

}
void cb_panel::internal_address_write(QString data)
{
    internal_address =data;
}

void cb_panel::data_received_and_profed()
{
    bool bStatus = false;
    uint nHex = raw_params[0].mid(13,8).toUInt(&bStatus,16);
    if(raw_params[0].mid(1,3).toUInt(&bStatus,16)==0x055 && raw_params[0].mid(9,2).toUInt(&bStatus,16)==ID){
        qDebug()<<raw_params[0].mid(5,2);
        count=0;
        enable_widget(true);
        if(raw_params[0].mid(5,2)=="95"){
            if(error_displayer){
                call_msg_box(pars_bits(nHex,errors_cb_list));
                error_displayer=false;
            }
            emit call_ui_buttons(nHex!=0);
//            ui->button_error->setVisible(nHex!=0);
//            ui->label_error->setVisible(nHex!=0);
            enable_widget(nHex==0);
        }else if(raw_params[0].mid(5,2)=="9B"){
            label_list[raw_params[0].mid(11,2).toInt()]->setText(QString::number(nHex)+"");
        }else if(raw_params[0].mid(5,2)=="97"){
            label_list[3+raw_params[0].mid(11,2).toInt()]->setText(QString::number(nHex)+"");
        }else if(raw_params[0].mid(5,2)=="9A"){
            label_list[6+raw_params[0].mid(11,2).toInt()]->setText(QString::number(nHex)+"");
        }else if(raw_params[0].mid(5,2)=="96"){
            label_list[9+raw_params[0].mid(11,2).toInt()]->setText(QString::number(nHex)+"");
        }
    }
}
