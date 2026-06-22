#include "user_panel.h"
#include "ui_user_panel.h"

#include <QMessageBox>
#include <QTimer>
#include <QDebug>

user_panel::user_panel(QWidget *parent) :
    device_panel(parent),
    ui(new Ui::user_panel)
{
    ui->setupUi(this);
    connect(ui->spin,SIGNAL(valueChanged(double)),this,SLOT(indicate(double)));
    connect(this,SIGNAL(enter_event(QObject*)),this,SLOT(key_catcher(QObject*)));
    connect(this,SIGNAL(command_profed()),this,SLOT(data_received_and_profed()));
    ui->spin->installEventFilter(this);
    ui->calib->installEventFilter(this);
}
user_panel::~user_panel()
{
    delete ui;
}
void user_panel::key_catcher(QObject* key)
{
    QMessageBox *mesg = new QMessageBox(QMessageBox::Information,
                                        "Conformation",
                                        "Send command on dc "+QString::number(ID)+"?",
                                        QMessageBox::Yes | QMessageBox::No);
    if(mesg->exec()==QMessageBox::Yes){
        if(key->objectName() == "spin"){
            QString message ="t";
            message.append(internal_address);
            message.append("811");
            message.append("00");
            message.append(QString("%1").arg(ID, 2, 16, QLatin1Char( '0' )));
            message.append("00");
            int value=ui->spin->value()*100;
            unsigned char *bytes = (unsigned char *)&value;
            unsigned char letters[] = {bytes[3],bytes[2],bytes[1],bytes[0]};
            QByteArray data=QByteArray(reinterpret_cast<char*>(letters),4);
            message.append(QString("%1").arg(value, 8, 16, QLatin1Char( '0' )));
            emit send_command(message.toUtf8()+'\r');
        }else if(key->objectName() == "calib"){
            QString message ="t";
            message.append(internal_address);
            message.append("823");
            message.append("00");
            message.append(QString("%1").arg(ID, 2, 16, QLatin1Char( '0' )));
            message.append("00");
            int value=ui->calib->value()*1000;
            unsigned char *bytes = (unsigned char *)&value;
            unsigned char letters[] = {bytes[3],bytes[2],bytes[1],bytes[0]};
            QByteArray data=QByteArray(reinterpret_cast<char*>(letters),4);
            message.append(QString("%1").arg(value, 8, 16, QLatin1Char( '0' )));
            emit send_command(message.toUtf8()+'\r');
        }
    }
}

void user_panel::internal_address_write(QString data)
{
    internal_address =data;
}

void user_panel::data_received_and_profed()
{
    bool bStatus = false;
    uint nHex = raw_params[0].mid(13,8).toUInt(&bStatus,16);
    if(raw_params[0].mid(1,3).toUInt(&bStatus,16)==0x055 && raw_params[0].mid(9,2).toUInt(&bStatus,16)==ID){
        count_no_responce=0;
        enable_widget(true);
        if(raw_params[0].mid(5,2)=="91"){
            if(raw_params[0].mid(11,2)=="00"){
                ui->power_label->setText(QString::number(nHex/100.0,'d',2)+" %");
            }else if(raw_params[0].mid(11,2)=="01"){
                ui->target_power_label->setText(QString::number(nHex/100.0,'d',2)+" %");
            }
        }else if(raw_params[0].mid(5,2)=="90"){
            ui->power_state_label->setText(nHex?"ON":"OFF");
            ui->on_off_button->setChecked(nHex);
        }else if(raw_params[0].mid(5,2)=="9D"){
            ui->pilot_state_label->setText(nHex?"ON":"OFF");
            ui->on_off_pilot_button->setChecked(nHex);
        }else if(raw_params[0].mid(5,2)=="A3"){
            ui->koeffi_label->setText(QString::number(nHex/1000.0,'d',3));
        }else if(raw_params[0].mid(5,2)=="A4"){
            ui->ret_pow_label->setText(QString::number(nHex/100.0,'d',2)+"кВт");
        }else if(raw_params[0].mid(5,2)=="9E"){
            ui->diff_pd_label->setText(QString::number(nHex/100.0,'d',2)+" V");
        }
    }
}

void user_panel::indicate(double count)
{
    ui->indicator->setValue(int(count*10)-100);
}

void user_panel::on_on_off_button_clicked(bool checked)
{
    QString message ="t";
    message.append(internal_address);
    message.append("810");
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

void user_panel::on_on_off_pilot_button_clicked(bool checked)
{
    QString message ="t";
    message.append(internal_address);
    message.append("81d");
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


void user_panel::telemetry_call(QString family)
{
    if(count_no_responce>6){
        enable_widget(false);
        connection_lost=true;
//        first_call=true;
    }
    if(family==this->family){
        count_no_responce++;
        count++;
        if(count%7==0)      emit send_command(QString("t"+internal_address+"89000"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
        else if(count%7==1) emit send_command(QString("t"+internal_address+"89100"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
        else if(count%7==2) emit send_command(QString("t"+internal_address+"89100"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0100000000").toUtf8()+'\r');
        else if(count%7==3) emit send_command(QString("t"+internal_address+"89d00"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
        else if(count%7==4) emit send_command(QString("t"+internal_address+"8A300"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
        else if(count%7==5) emit send_command(QString("t"+internal_address+"8A400"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
        else if(count%7==6) emit send_command(QString("t"+internal_address+"89E00"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');

    }
}
