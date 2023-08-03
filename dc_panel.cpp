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
    tmr->setInterval(1300);
    connect(tmr,SIGNAL(timeout()),this,SLOT(auto_telemetry_call()));
    tmr->start();
    connect(this,SIGNAL(command_proofed()),this,SLOT(data_received_and_profed()));
    connect(this,SIGNAL(tool_clicked()),this,SLOT(update_pref()));

    ui->spin->installEventFilter(this);
    prefs.append(prefs_struct{-1,"Max current, A",4,-1});
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
//    if(ID==404||this->accessibleName()!=""){
//        qDebug()<<"dc ID"<<this<<this->objectName().split("_");
//        ID=this->objectName().split("_")[1].toInt();
//    }
//    count=0;
//    connection_lost=false;
//    bool bStatus = false;
//    uint nHex = message.right(8).toUInt(&bStatus,16);
//    if(bStatus){
//        if(message.indexOf(QString::number(ON_OFF_LASER+CALL_SUFFIX,16))==5 ){
//            ui->power_state_label->setText(nHex?"ON":"OFF");
//            ui->on_off_button->setChecked(nHex);
//        }else if(message.indexOf(QString::number(CURRENT_LASER+CALL_SUFFIX,16))==5){
//            ui->current_ld_label->setText(QString::number(nHex/10.0)+" A");
//        }else if(message.indexOf(QString::number(TEMP_LASER+CALL_SUFFIX,16))==5){
//            ui->temp_label->setText(QString::number(nHex/10.0)+" C");
//        }else if(message.indexOf(QString::number(MODE_LASER+CALL_SUFFIX,16).toUpper())==5){
//            ui->mode_label->setText(ui->mode->itemText(nHex));
//        }else if(message.indexOf(QString::number(VOLT_IN_LASER+CALL_SUFFIX,16).toUpper())==5){
//            ui->input_voltage_label->setText(QString::number(nHex/10.0)+" V");
//        }else if(message.indexOf(QString::number(VOLT_OUT_LASER+CALL_SUFFIX,16).toUpper())==5){
//            ui->output_voltage_label->setText(QString::number(nHex/10.0)+" V");
//        }
//    }
}
void dc_panel::data_received_and_profed()
{
    bool bStatus = false;
    uint nHex = raw_params[0].mid(13,8).toUInt(&bStatus,16);
    if(raw_params[0].mid(1,3).toUInt(&bStatus,16)==0x055 && raw_params[0].mid(9,2).toUInt(&bStatus,16)==ID){
        count=0;
        enable_widget(true /*&& raw_params[0].mid(5,2)!="A2"*/);
        qDebug()<<raw_params[0].mid(5,2);
        if(raw_params[0].mid(5,2)=="A0"){
            ui->temp_label->setText(QString::number(nHex/10.0,'d',1)+" C");
            indicate(nHex/10.0);
        }else if(raw_params[0].mid(5,2)=="99"){
            ui->current_ld_label->setText(QString::number(nHex/100.0,'d',2)+" A");
        }else if(raw_params[0].mid(5,2)=="94"){
            ui->spin->setMaximum(nHex/100.0);
            ui->curr_max_label->setText(QString::number(nHex/100.0,'d',2));
            ui->indicator->setMaximum(nHex/10.0);
            container_values[0]->setText(QString::number(nHex/100.0,'d',2));
        }else if(raw_params[0].mid(5,2)=="98"){
            ui->power_state_label->setText(nHex?"ON":"OFF");
            ui->on_off_button->setChecked(nHex);
        }else if(raw_params[0].mid(5,2)=="A1"){
            ui->mode_label->setText(ui->mode->itemText(nHex));
        }else if(raw_params[0].mid(5,2)=="A2"){
            if(error_displayer){
                call_msg_box(pars_bits(nHex,errors_dc_list));
                error_displayer=false;
            }
            emit call_ui_buttons("dc"+QString::number(ID),nHex!=0);
            ui->button_error->setVisible(nHex!=0);
            ui->label_error->setVisible(nHex!=0);
//            enable_widget(nHex==0);
        }
    }
}

void dc_panel::send_pref()
{
    qDebug()<<"value len"<<spiners.length();
    if(spiners.length()>0){
//        qDebug()<<"value"<<spiners[0]->value();
//        ui->spin->setMaximum(spiners[0]->value());
//        ui->curr_max_label->setText(QString::number(spiners[0]->value(),'d',1));
//        ui->indicator->setMaximum(spiners[0]->value()*10);

        QString message ="t";
        message.append(internal_address);
        message.append("814");
        message.append("00");
        message.append(QString("%1").arg(ID, 2, 16, QLatin1Char( '0' )));
        message.append("00");
        int value=spiners[0]->value()*100;
        unsigned char *bytes = (unsigned char *)&value;
        unsigned char letters[] = {bytes[3],bytes[2],bytes[1],bytes[0]};
        QByteArray data=QByteArray(reinterpret_cast<char*>(letters),4);
        message.append(QString("%1").arg(value, 8, 16, QLatin1Char( '0' )));
        emit send_command(message.toUtf8()+'\r');
        emit send_command(QString("t"+internal_address+"89400"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
    }
}

void dc_panel::indicate(double count)
{
    ui->indicator->setValue(int(count*10));
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
    if(count>6){
        enable_widget(false);
        connection_lost=true;
    }
    emit send_command(QString("t"+internal_address+"8A000"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
    emit send_command(QString("t"+internal_address+"89800"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
    emit send_command(QString("t"+internal_address+"8A200"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
}

//void dc_panel::enable_widget(bool state)
//{
//    ui->cw_widget->setEnabled(state);
//}

void dc_panel::on_mode_currentIndexChanged(int index)
{
    QString message ="t";
    message.append(internal_address);
    message.append("821");
    message.append("00");
    message.append(QString("%1").arg(ID, 2, 16, QLatin1Char( '0' )));
    message.append("00");
    int value=index;
    unsigned char *bytes = (unsigned char *)&value;
    unsigned char letters[] = {bytes[3],bytes[2],bytes[1],bytes[0]};
    QByteArray data=QByteArray(reinterpret_cast<char*>(letters),4);
    message.append(QString("%1").arg(value, 8, 16, QLatin1Char( '0' )));
    emit send_command(message.toUtf8()+'\r');
//    emit send_command(MODE_LASER,ID,QString::number(index));
}

void dc_panel::on_button_error_clicked()
{
    error_displayer=true;
}

void dc_panel::update_pref()
{
    emit send_command(QString("t"+internal_address+"89400"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
}


