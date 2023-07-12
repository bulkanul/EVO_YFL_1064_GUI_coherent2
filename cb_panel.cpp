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
}

cb_panel::~cb_panel()
{
    delete ui;
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
        command=key->objectName().contains("treashold")?(key->objectName().contains("forward")?"1A":"16"):
                                                        (key->objectName().contains("forward")?"9B":"96");
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

void cb_panel::data_received_and_profed()
{
    bool bStatus = false;
    uint nHex = raw_params[0].mid(13,8).toUInt(&bStatus,16);
    if(raw_params[0].mid(1,3).toUInt(&bStatus,16)==0x055 && raw_params[0].mid(9,2).toUInt(&bStatus,16)==ID){
        qDebug()<<raw_params[0].mid(5,2);
        if(raw_params[0].mid(5,2)=="A2"){
//            ui->temp_label->setText(QString::number(nHex/10.0)+" C");
//            indicate(nHex/10.0);
        }else if(raw_params[0].mid(5,2)=="95"){
            if(error_displayer){
                call_msg_box(pars_bits(nHex,errors_cb_list));
                error_displayer=false;
            }
            emit call_ui_buttons(nHex!=0);
//            ui->button_error->setVisible(nHex!=0);
//            ui->label_error->setVisible(nHex!=0);
            enable_widget(nHex==0);
        }
    }
}
