#include "user_panel.h"
#include "ui_user_panel.h"

#include <QMessageBox>
#include <QTimer>

user_panel::user_panel(QWidget *parent) :
    device_panel(parent),
    ui(new Ui::user_panel)
{
    ui->setupUi(this);
    connect(ui->spin,SIGNAL(valueChanged(double)),this,SLOT(indicate(double)));
    connect(this,SIGNAL(enter_event(QObject*)),this,SLOT(key_catcher(QObject*)));
    tmr=new QTimer();
    tmr->setInterval(1300);
    connect(tmr,SIGNAL(timeout()),this,SLOT(auto_telemetry_call()));
    tmr->start();
    connect(this,SIGNAL(command_proofed()),this,SLOT(data_received_and_profed()));
    ui->spin->installEventFilter(this);
//    ID=7;
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
//            emit send_command(CURRENT_LASER,ID,QString::number(ui->spin->value()*10).replace(",","."));
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
        count=0;
        enable_widget(true);
        if(raw_params[0].mid(5,2)=="91"){
            ui->current_ld_label->setText(QString::number(nHex/100.0,'d',2)+" %");
        }else if(raw_params[0].mid(5,2)=="90"){
            ui->power_state_label->setText(nHex?"ON":"OFF");
            ui->on_off_button->setChecked(nHex);
//        }else if(raw_params[0].mid(5,2)=="A2"){
//            if(error_displayer){
//                call_msg_box(pars_bits(nHex,errors_dc_list));
//                error_displayer=false;
//            }
//            ui->button_error->setVisible(nHex!=0);
//            ui->label_error->setVisible(nHex!=0);
//            enable_widget(nHex==0);
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

void user_panel::auto_telemetry_call()
{
    count++;
    if(count>30){
        enable_widget(false);
        connection_lost=true;
    }
    emit send_command(QString("t"+internal_address+"89000"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
    emit send_command(QString("t"+internal_address+"89100"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
}
