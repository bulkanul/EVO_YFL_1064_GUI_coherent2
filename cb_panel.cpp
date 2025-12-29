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
    label_list.append(ui->backward_label_0);
    label_list.append(ui->backward_label_1);

    label_list.append(ui->forward_level_label_0);
    label_list.append(ui->forward_level_label_1);
    label_list.append(ui->backward_level_label_0);
    label_list.append(ui->backward_level_label_1);

    label_list.append(ui->temp_label_0);
    label_list.append(ui->temp_label_1);

    label_list.append(ui->temp_level_label_0);
    label_list.append(ui->temp_level_label_1);

    label_list.append(ui->curr_level_label_0);
    label_list.append(ui->curr_level_label_1);
    label_list.append(ui->curr_level_label_1);

    ui->forward_treashold_0->installEventFilter(this);
    ui->forward_treashold_1->installEventFilter(this);

    ui->backward_treashold_0->installEventFilter(this);
    ui->backward_treashold_1->installEventFilter(this);

    ui->temp_level_0->installEventFilter(this);

    ui->curr_lvl_0->installEventFilter(this);
    ui->curr_lvl_1->installEventFilter(this);
    family="cd";
}

cb_panel::~cb_panel()
{
    delete ui;
}


void cb_panel::telemetry_call(QString family)
{
if(family==this->family){
      count_no_responce++;
      count++;
      }
    if(count_no_responce>8){
        enable_widget(false);
        connection_lost=true;
        return;
    }
    if(family==this->family){
          if(count%label_list.length()==0)      emit send_command(QString("t"+internal_address+"89600"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
          else if(count%label_list.length()==1) emit send_command(QString("t"+internal_address+"89700"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
          else if(count%label_list.length()==2) emit send_command(QString("t"+internal_address+"89A00"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
          else if(count%label_list.length()==3) emit send_command(QString("t"+internal_address+"89B00"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
          else if(count%label_list.length()==4) emit send_command(QString("t"+internal_address+"89200"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
          else if(count%label_list.length()==5) emit send_command(QString("t"+internal_address+"89600"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0100000000").toUtf8()+'\r');
          else if(count%label_list.length()==6) emit send_command(QString("t"+internal_address+"89700"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0100000000").toUtf8()+'\r');
          else if(count%label_list.length()==7) emit send_command(QString("t"+internal_address+"89A00"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0100000000").toUtf8()+'\r');
          else if(count%label_list.length()==8) emit send_command(QString("t"+internal_address+"89B00"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0100000000").toUtf8()+'\r');
          else if(count%label_list.length()==9) emit send_command(QString("t"+internal_address+"89200"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0100000000").toUtf8()+'\r');
          else if(count%label_list.length()==10) emit send_command(QString("t"+internal_address+"89500"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
          else if(count%label_list.length()==11) emit send_command(QString("t"+internal_address+"89F00"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
          else if(count%label_list.length()==12) emit send_command(QString("t"+internal_address+"89F00"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0100000000").toUtf8()+'\r');

          else if(count%label_list.length()==13) emit send_command(QString("t"+internal_address+"8A500"+QString("%1").arg(0, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
          else if(count%label_list.length()==14) emit send_command(QString("t"+internal_address+"8A500"+QString("%1").arg(1, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
          qDebug()<<"call"<<family<<ID << count;
        }

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
        QString addres="00";
        QString local_addres="00";
        int value;
        if(key->objectName().contains("temp_level")){
            command="1F";
            value=target->value()*10;
            local_addres=QString("%1").arg(key->objectName().right(1).toInt(), 2, 16, QLatin1Char( '0' ));
        }else if(key->objectName().contains("curr_lvl")){
           command="25";
           addres=QString("%1").arg(key->objectName().right(1).toInt(), 2, 16, QLatin1Char( '0' ));
           value=target->value()*100;
        }else{
            command=key->objectName().contains("forward")?"1A":"16";
            value=target->value()*100;
            local_addres=QString("%1").arg(key->objectName().right(1).toInt(), 2, 16, QLatin1Char( '0' ));
        }
        QString message ="t";
        message.append(internal_address);
        message.append("8");
        message.append(command);
        message.append("22");
        message.append(addres);
        message.append(local_addres);
        unsigned char *bytes = (unsigned char *)&value;
        unsigned char letters[] = {bytes[3],bytes[2],bytes[1],bytes[0]};
        QByteArray data=QByteArray(reinterpret_cast<char*>(letters),4);
        message.append(QString("%1").arg(value, 8, 16, QLatin1Char( '0' )));
        qDebug()<<"sl_data_readed send"<<message;
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
    if(raw_params[0].mid(1,3)==internal_address ||raw_params[0].mid(1,3)=="055"){
      if(raw_params[0].mid(5,2)=="A5"){
      if(raw_params[0].mid(10,1).toInt()==max_curr_call)max_curr_call++;
        QDoubleSpinBox* lineEdit = this->findChild<QDoubleSpinBox*>("curr_lvl_"+raw_params[0].mid(10,1));
        if (lineEdit) {
          if(!lineEdit->isEnabled())lineEdit->setValue(nHex/100.0);
          lineEdit->setEnabled(true);
          label_list[12+raw_params[0].mid(10,1).toInt()]->setText(QString::number(nHex/100.0)+"");
        }
      }
    }
    if(raw_params[0].mid(1,3).toUInt(&bStatus,16)==0x055 && raw_params[0].mid(9,2).toUInt(&bStatus,16)==ID){
        qDebug()<<raw_params[0].mid(5,2);
        count_no_responce=0;
        enable_widget(true);
        if(raw_params[0].mid(5,2)=="95"){
            if(error_displayer){
                call_msg_box(pars_bits(nHex,errors_cb_list));
                error_displayer=false;
            }
            emit call_ui_buttons("cb",nHex!=0);
            ui->button_error->setVisible(nHex!=0);
            ui->label_error->setVisible(nHex!=0);
        }else if(raw_params[0].mid(5,2)=="9B"){
            label_list[raw_params[0].mid(11,2).toInt()]->setText(QString::number(nHex/100.0)+"");
        }else if(raw_params[0].mid(5,2)=="97"){
            label_list[2+raw_params[0].mid(11,2).toInt()]->setText(QString::number(nHex/100.0)+"");
        }else if(raw_params[0].mid(5,2)=="9A"){
            label_list[4+raw_params[0].mid(11,2).toInt()]->setText(QString::number(nHex/100.0)+"");
        }else if(raw_params[0].mid(5,2)=="96"){
            label_list[6+raw_params[0].mid(11,2).toInt()]->setText(QString::number(nHex/100.0)+"");
        }else if(raw_params[0].mid(5,2)=="92"){
            label_list[8+raw_params[0].mid(11,2).toInt()]->setText(QString::number(nHex/10.0)+"");
        }else if(raw_params[0].mid(5,2)=="9F"){
            label_list[10+raw_params[0].mid(11,2).toInt()]->setText(QString::number(nHex/10.0)+"");  
        }

    }
}

void cb_panel::on_button_error_clicked()
{
  error_displayer=true;
}

