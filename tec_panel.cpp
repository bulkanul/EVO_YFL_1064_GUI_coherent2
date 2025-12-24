#include "tec_panel.h"
#include "ui_tec_panel.h"

#include "ui_cb_panel.h"
#include "device_panel.h"
#include "mainwindow.h"

#include <QTimer>
#include <QDebug>
#include <QMessageBox>

tec_panel::tec_panel(QWidget *parent) :
    device_panel(parent),
    ui(new Ui::tec_panel)
{
    ui->setupUi(this);
    connect(ui->spin,SIGNAL(valueChanged(double)),this,SLOT(indicate(double)));
    connect(this,SIGNAL(enter_event(QObject*)),this,SLOT(key_catcher(QObject*)));
    connect(this,SIGNAL(command_profed()),this,SLOT(data_received_and_profed()));

    ui->spin->installEventFilter(this);
    prefs.append(prefs_struct{-1,"Сoefficient KP",0,-1});
    prefs.append(prefs_struct{-1,"Сoefficient KI",0,-1});
    prefs.append(prefs_struct{-1,"Сoefficient KD",0,-1});
}

tec_panel::~tec_panel()
{
    delete ui;
}


void tec_panel::key_catcher(QObject* key)
{
    QMessageBox *mesg = new QMessageBox(QMessageBox::Information,
                                        "Conformation",
                                        "Send command on dc "+QString::number(ID)+"?",
                                        QMessageBox::Yes | QMessageBox::No);
    if(mesg->exec()==QMessageBox::Yes){
        if(key->objectName() == "spin"){
            QString message ="t";
            message.append(internal_address);
            message.append("824");
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

void tec_panel::internal_address_write(QString data)
{
    internal_address =data;
}

void tec_panel::data_received_and_profed()
{
    bool bStatus = false;
    uint nHex = raw_params[0].mid(13,8).toUInt(&bStatus,16);
    if(raw_params[0].mid(1,3).toUInt(&bStatus,16)==0x055 && raw_params[0].mid(9,2).toUInt(&bStatus,16)==ID){
        count_no_responce=0;
        enable_widget(true /*&& raw_params[0].mid(5,2)!="A2"*/);
        qDebug()<<raw_params[0].mid(5,2);
        if(raw_params[0].mid(5,2)=="A4"){
            ui->temp_label->setText(QString::number(nHex/100.0,'d',2)+" C");
            indicate(nHex/10.0);
        }else if(raw_params[0].mid(5,2)=="A3"){
            ui->power_state_label->setText(nHex?"ON":"OFF");
            ui->on_off_button->setChecked(nHex);
        }
    }
}

void tec_panel::send_pref()
{
    qDebug()<<"value len"<<spiners.length();
    int count_spins=0;
    if(spiners.length()>2){
        foreach (QDoubleSpinBox *spin, spiners) {
            QString message ="t";
            message.append(internal_address);
            message.append("8"+QString::number(25+count_spins));
            message.append("00");
            message.append(QString("%1").arg(ID, 2, 16, QLatin1Char( '0' )));
            message.append("00");
            int value=spin->value()*(count_spins==0?(100):(10000));
            unsigned char *bytes = (unsigned char *)&value;
            unsigned char letters[] = {bytes[3],bytes[2],bytes[1],bytes[0]};
            QByteArray data=QByteArray(reinterpret_cast<char*>(letters),4);
            message.append(QString("%1").arg(value, 8, 16, QLatin1Char( '0' )));
            emit send_command(message.toUtf8()+'\r');
            emit send_command(QString("t"+internal_address+"89400"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
            count_spins++;
        }
    }
}

void tec_panel::indicate(double count)
{
    ui->indicator->setValue(int(count*10));
}

void tec_panel::on_on_off_button_clicked(bool checked)
{
    QString message ="t";
    message.append(internal_address);
    message.append("823");
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

void tec_panel::telemetry_call(QString family)
{
    if(count_no_responce>6){
        enable_widget(false);
        connection_lost=true;
        first_call=true;
    }
    if(family==this->family+QString::number(ID)){
        count_no_responce++;
        count++;
        if(first_call){
            if(count%3==0)      emit send_command(QString("t"+internal_address+"8A500"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
            else if(count%3==1) emit send_command(QString("t"+internal_address+"8A600"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
            else {
                                emit send_command(QString("t"+internal_address+"8A700"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
                first_call=false;
            }
        }else{
            if(count%2==0)      emit send_command(QString("t"+internal_address+"8A400"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
            else if(count%2==1) emit send_command(QString("t"+internal_address+"8A300"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
        }
        qDebug()<<"call"<<family<<ID << count;
    }

}
