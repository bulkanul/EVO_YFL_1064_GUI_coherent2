#include "dc_panel.h"
#include "ui_cb_panel.h"
#include "ui_dc_panel.h"
#include "device_panel.h"
#include "mainwindow.h"

#include <QTimer>
#include <QDebug>
#include <QMessageBox>

dc_panel::dc_panel(QWidget *parent):
    device_panel(parent),
    ui(new Ui::dc_panel)
{
    ui->setupUi(this);
    connect(ui->spin,SIGNAL(valueChanged(double)),this,SLOT(indicate(double)));
    connect(this,SIGNAL(enter_event(QObject*)),this,SLOT(key_catcher(QObject*)));
    tmr=new QTimer();
    tmr->setInterval(2000);
    connect(tmr,SIGNAL(timeout()),this,SLOT(auto_telemetry_call()));
    tmr->start();
    connect(this,SIGNAL(command_proofed()),this,SLOT(data_received_and_profed()));
//    installEventFilter(this);
//    ID=7;
}

dc_panel::~dc_panel()
{
    delete ui;
}

void dc_panel::key_catcher(QObject* key)
{
    QMessageBox *mesg = new QMessageBox(QMessageBox::Information,
                                        "Conformation",
                                        "Send command on dc "+QString::number(ID)+"?",
                                        QMessageBox::Yes | QMessageBox::No);
    if(mesg->exec()==QMessageBox::Yes){
        if(key->objectName() == "spin"){
            QString message ="t";
            message.append(internal_address);
            message.append("819");
            message.append("00");
            message.append(QString("%1").arg(ID, 2, 16, QLatin1Char( '0' )));
            message.append("00");
            int value=ui->spin->value()*100;
            unsigned char *bytes = (unsigned char *)&value;
            unsigned char letters[] = {bytes[3],bytes[2],bytes[1],bytes[0]};
            QByteArray data=QByteArray(reinterpret_cast<char*>(letters),4);
            message.append(QString("%1").arg(value, 8, 16, QLatin1Char( '0' )));
            emit send_command(message.toUtf8()+'\r');
//            emit send_command(CURRENT_LASER,ID,QString::number(ui->spin->value()*10).replace(",","."));
        }
    }
}

void dc_panel::internal_address_write(QString data)
{
    internal_address =data;
}

void dc_panel::data_received(QString message)
{
    if(ID==404||this->accessibleName()!=""){
        qDebug()<<"dc ID"<<this<<this->objectName().split("_");
        ID=this->objectName().split("_")[1].toInt();
    }
    count=0;
    connection_lost=false;
    bool bStatus = false;
    uint nHex = message.right(8).toUInt(&bStatus,16);
    if(bStatus){
        if(message.indexOf(QString::number(ON_OFF_LASER+CALL_SUFFIX,16))==5 ){
            ui->power_state_label->setText(nHex?"ON":"OFF");
            ui->on_off_button->setChecked(nHex);
        }else if(message.indexOf(QString::number(CURRENT_LASER+CALL_SUFFIX,16))==5){
            ui->current_ld_label->setText(QString::number(nHex/10.0)+" A");
        }else if(message.indexOf(QString::number(TEMP_LASER+CALL_SUFFIX,16))==5){
            ui->temp_label->setText(QString::number(nHex/10.0)+" C");
        }else if(message.indexOf(QString::number(MODE_LASER+CALL_SUFFIX,16).toUpper())==5){
            ui->mode_label->setText(ui->mode->itemText(nHex));
        }else if(message.indexOf(QString::number(VOLT_IN_LASER+CALL_SUFFIX,16).toUpper())==5){
            ui->input_voltage_label->setText(QString::number(nHex/10.0)+" V");
        }else if(message.indexOf(QString::number(VOLT_OUT_LASER+CALL_SUFFIX,16).toUpper())==5){
            ui->output_voltage_label->setText(QString::number(nHex/10.0)+" V");
        }
    }
}
void dc_panel::data_received_and_profed()
{
    bool bStatus = false;
    uint nHex = raw_params[0].mid(13,8).toUInt(&bStatus,16);
    if(raw_params[0].mid(1,3).toUInt()==internal_address.toUInt() && raw_params[0].mid(9,2).toUInt()==ID){
        qDebug()<<raw_params[0].mid(5,2);
        if(raw_params[0].mid(5,2)=="A0"){
            ui->temp_label->setText(QString::number(nHex/10.0)+" C");
            indicate(nHex/10.0);
        }else if(raw_params[0].mid(5,2)=="99"){
            ui->current_ld_label->setText(QString::number(nHex/100.0)+" C");
        }
    }
}

void dc_panel::indicate(double count)
{
    ui->indicator->setValue(int(count*10)-100);
}

void dc_panel::on_on_off_button_clicked(bool checked)
{
    QString message ="t";
    message.append(internal_address);
    message.append("818");
    message.append("00");
    message.append(QString("%1").arg(ID, 2, 16, QLatin1Char( '0' )));
    message.append("00");
    int value=checked;
    unsigned char *bytes = (unsigned char *)&value;
    unsigned char letters[] = {bytes[3],bytes[2],bytes[1],bytes[0]};
    QByteArray data=QByteArray(reinterpret_cast<char*>(letters),4);
    message.append(QString("%1").arg(value, 8, 16, QLatin1Char( '0' )));
    emit send_command(message.toUtf8()+'\r');
}

void dc_panel::auto_telemetry_call()
{
    count++;
    if(count>30){
        enable_widget(false);
        connection_lost=true;
    }
    emit send_command(QString("t"+internal_address+"8a000"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
//    emit send_command(VOLT_OUT_LASER+CALL_SUFFIX,ID,"");
//    emit send_command(CURRENT_LASER+CALL_SUFFIX,ID,"");
//    emit send_command(MODE_LASER+CALL_SUFFIX,ID,"");
//    emit send_command(TEMP_LASER+CALL_SUFFIX,ID,"");
//    emit send_command(ON_OFF_LASER+CALL_SUFFIX,ID,"");
}

void dc_panel::enable_widget(bool state)
{
    ui->cw_widget->setEnabled(state);
}

void dc_panel::on_mode_currentIndexChanged(int index)
{
//    emit send_command(MODE_LASER,ID,QString::number(index));
}
