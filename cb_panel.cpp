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
    connect(this,SIGNAL(command_profed()),this,SLOT(data_received_and_profed()));
    connect(this,SIGNAL(tool_clicked()),this,SLOT(get_pref()));

    ui->hpld_curr_0->installEventFilter(this);
    ui->hpld_curr_1->installEventFilter(this);
    ui->forward_treashold->installEventFilter(this);
    ui->backward_treashold->installEventFilter(this);
    ui->forward_treashold_2->installEventFilter(this);
    ui->backward_treashold_2->installEventFilter(this);
    ui->therm_resis->installEventFilter(this);
    ui->therm_beta->installEventFilter(this);
    ui->therm_vref->installEventFilter(this);
    ui->over_temp->installEventFilter(this);


    labels.append(ui->cur_temp_0);
    labels.append(ui->cur_temp_1);
    labels.append(ui->hpld_curr_label_0);
    labels.append(ui->hpld_curr_label_1);
    labels.append(ui->pd_forward);
    labels.append(ui->pd_forward_2);
    labels.append(ui->pd_backward);
    labels.append(ui->pd_backward_2);
    labels.append(ui->forward_treashold_label);
    labels.append(ui->forward_treashold_label_2);
    labels.append(ui->backward_treashold_label);
    labels.append(ui->backward_treashold_label_2);
    labels.append(ui->therm_resis_label);
    labels.append(ui->therm_vref_label);
    labels.append(ui->therm_beta_label);
    labels.append(ui->over_temp_label);
    family="cb";
    this->setEnabled(false);
}

cb_panel::~cb_panel()
{
    delete ui;
}

void cb_panel::telemetry_call(QString family)
{
    if(count_no_responce>6){
        enable_widget(false);
        connection_lost=true;
       first_pref=true;
    }
    if(family==this->family){
        count_no_responce++;
        count++;
        // int counter=1;
        // int temp=0;
       if(first_pref){
          first_pref=false;
          get_pref();
//            emit send_command(QString("t"+internal_address+"89400"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000").toUtf8()+'\r');
       }else{
          bool flag=true;
        int counter=0;
        foreach (QLabel* var, labels) {
          if(var->text()=="N/A"){
            flag=false;
            break;
          }
          counter++;
        }
        if(flag){
          this->setEnabled(true);
          QString temp;
          if(count%7==0)
            temp=QString("t"+internal_address+"89500"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000");
          else if(count%7==1)
            temp =QString("t"+internal_address+"89B00"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000");
          else if(count%7==2)
            temp =QString("t"+internal_address+"89700"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000");
          else if(count%7==3)
              temp =QString("t"+internal_address+"89B00"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0100000000");
          else if(count%7==4)
              temp =QString("t"+internal_address+"89700"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0100000000");
          else if(count%7==5)
              temp =QString("t"+internal_address+"89200"+QString("%1").arg(0, 2, 16, QLatin1Char( '0' ))+"0000000000");
          else if(count%7==6)
              temp =QString("t"+internal_address+"89200"+QString("%1").arg(1, 2, 16, QLatin1Char( '0' ))+"0000000000");
          emit send_command(temp.toUtf8()+'\r');
        }else
          emit send_command(commands[counter].toUtf8()+'\r');

        qDebug()<<"else"<<family<<ID << count;
       }
    }
}

void cb_panel::get_pref()
{
    foreach (QString var, commands) {
      emit send_command(var.toUtf8()+'\r');
    }
}


QString cb_panel::prepare_str(int value)
{
    QString respond;
    unsigned char *bytes = (unsigned char *)&value;
    unsigned char letters[] = {bytes[3],bytes[2],bytes[1],bytes[0]};
    QByteArray data=QByteArray(reinterpret_cast<char*>(letters),4);
    respond.append(QString("%1").arg(value, 8, 16, QLatin1Char( '0' )));
    return respond;
}
void cb_panel::on_button_error_clicked()
{
    error_displayer=true;
}

void cb_panel::key_catcher(QObject* key)
{
    QMessageBox *mesg = new QMessageBox(QMessageBox::Information,
                                        "Conformation",
                                        "Send command on cb "+QString::number(ID)+"?",
                                        QMessageBox::Yes | QMessageBox::No);
    if(mesg->exec()==QMessageBox::Yes){
        QDoubleSpinBox *target = static_cast<QDoubleSpinBox*>(key);
        QString command;
        QString address="00";
        QString inner_address="00";
        int multiplier=1;
        if(target->objectName().contains("hpld_curr")){
          command="25";
          multiplier=100;
          if(target->objectName().contains("_1"))address="01";
        }else if(target->objectName().contains("_treashold")){
          if(target->objectName().contains("forward_")){
              if(target->objectName().contains("_2"))inner_address="01";
              command="1A";
          }else if(target->objectName().contains("backward_")){
              if(target->objectName().contains("_2"))inner_address="01";
              command="16";
          }
          multiplier=100;
        }else if(target->objectName().contains("therm_")){
          if(target->objectName().contains("_resis"))  command="31";
          else if(target->objectName().contains("_vref")){command="38"; multiplier=1000;}
          else if(target->objectName().contains("_beta"))command="32";
        }else if(target->objectName().contains("volt_amp_ext")){
          command="30";
          multiplier=100;
        }else if(target->objectName().contains("tec_temp")){
          command="28";
          multiplier=100;
          if(target->objectName().contains("_1"))address="01";
        }else if(target->objectName().contains("over_temp")){
          command="33";
          multiplier=10;
        }

        QString message ="t";
        message.append(internal_address);
        message.append("8");
        message.append(command);
        message.append("00");
        message.append(address);
        message.append(inner_address);
        double value_target=target->value();
        int value=round(value_target*multiplier);
        unsigned char *bytes = (unsigned char *)&value;
        unsigned char letters[] = {bytes[3],bytes[2],bytes[1],bytes[0]};
        QByteArray data=QByteArray(reinterpret_cast<char*>(letters),4);
        message.append(QString("%1").arg(value, 8, 16, QLatin1Char( '0' )));
        // emit send_command(message.toUtf8()+'\r');
        // emit send_command(message.toUtf8()+'\r');
        emit send_command(message.toUtf8()+'\r');
    }

}
void cb_panel::internal_address_write(QString data)
{
    bool ok=false;
    internal_address =QString("%1").arg(data.toInt(&ok,16), 3, 16, QLatin1Char( '0' )).toUpper();
    commands.clear();
    commands.append(QString("t"+internal_address+"89200"+QString("%1").arg(0 , 2, 16, QLatin1Char( '0' ))+"0000000000"));
    commands.append(QString("t"+internal_address+"89200"+QString("%1").arg(1 , 2, 16, QLatin1Char( '0' ))+"0000000000"));
    commands.append(QString("t"+internal_address+"8A500"+QString("%1").arg(0 , 2, 16, QLatin1Char( '0' ))+"0000000000"));
    commands.append(QString("t"+internal_address+"8A500"+QString("%1").arg(1 , 2, 16, QLatin1Char( '0' ))+"0000000000"));
    commands.append(QString("t"+internal_address+"89B00"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000"));
    commands.append(QString("t"+internal_address+"89B00"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0100000000"));
    commands.append(QString("t"+internal_address+"89700"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000"));
    commands.append(QString("t"+internal_address+"89700"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0100000000"));
    commands.append(QString("t"+internal_address+"89A00"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000"));
    commands.append(QString("t"+internal_address+"89A00"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0100000000"));
    commands.append(QString("t"+internal_address+"89600"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000"));
    commands.append(QString("t"+internal_address+"89600"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0100000000"));
    commands.append(QString("t"+internal_address+"8B100"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000"));
    commands.append(QString("t"+internal_address+"8B800"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000"));
    commands.append(QString("t"+internal_address+"8B200"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000"));
    commands.append(QString("t"+internal_address+"8B300"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000"));
    commands.append(QString("t"+internal_address+"89500"+QString("%1").arg(ID, 2, 16, QLatin1Char( '0' ))+"0000000000"));
}

void cb_panel::data_received_and_profed()
{
    bool bStatus = false;
    uint nHex = raw_params[0].mid(13,8).toUInt(&bStatus,16);
    QString command=raw_params[0].mid(5,2);
    if(raw_params[0].mid(1,3).toUInt(&bStatus,16)==0x055){
        count_no_responce=0;
        enable_widget(true);
        if(raw_params[0].mid(5,2)=="95"){
          cbErrorHex=nHex;
            if(error_displayer){
                call_msg_box(pars_bits(dc1ErrorHex,errors_dc_list),pars_bits(dc2ErrorHex,errors_dc_list),pars_bits(cbErrorHex,errors_cb_list));
            }
            emit call_ui_buttons("cb",cbErrorHex!=0||dc1ErrorHex!=0);
            ui->button_error->setVisible(cbErrorHex!=0||dc1ErrorHex!=0);
            ui->label_error->setVisible(cbErrorHex!=0||dc1ErrorHex!=0);
        }else if(raw_params[0].mid(5,2)=="A2"){
          if(raw_params[0].mid(9,2)=="01"){
            dc2ErrorHex=nHex;
          }else{
            dc1ErrorHex=nHex;
          }
            if(error_displayer){
                call_msg_box(pars_bits(dc1ErrorHex,errors_dc_list),pars_bits(dc2ErrorHex,errors_dc_list),pars_bits(cbErrorHex,errors_cb_list));
            }
            emit call_ui_buttons("dc"+QString::number(ID),cbErrorHex!=0||dc1ErrorHex!=0);
            ui->button_error->setVisible(cbErrorHex!=0||dc1ErrorHex!=0);
            ui->label_error->setVisible(cbErrorHex!=0||dc1ErrorHex!=0);
        }else if(raw_params[0].mid(5,2)=="92"){
          if(raw_params[0].mid(9,2)=="00"){
            ui->cur_temp_0->setText(QString::number(nHex/100.0)+" C");
          }else if(raw_params[0].mid(9,2)=="01"){
            ui->cur_temp_1->setText(QString::number(nHex/100.0)+" C");
          }
        }else if(raw_params[0].mid(5,2)=="A5"){
          if(raw_params[0].mid(9,2)=="00"){
            if(ui->hpld_curr_label_0->text()=="N/A")ui->hpld_curr_0->setValue(nHex/100.0);
            ui->hpld_curr_label_0->setText(QString::number(nHex/100.0)+" A");
          }else if(raw_params[0].mid(9,2)=="01"){
            if(ui->hpld_curr_label_1->text()=="N/A")ui->hpld_curr_1->setValue(nHex/100.0);
            ui->hpld_curr_label_1->setText(QString::number(nHex/100.0)+" A");
          }
        }else if(raw_params[0].mid(5,2)=="9A"){
            if(raw_params[0].mid(11,2)=="00"){
                if(ui->forward_treashold_label->text()=="N/A")ui->forward_treashold->setValue(nHex/100.0);
                ui->forward_treashold_label->setText(QString::number(nHex/100.0)+"");
            }else if(raw_params[0].mid(11,2)=="01"){
                if(ui->forward_treashold_label_2->text()=="N/A")ui->forward_treashold_2->setValue(nHex/100.0);
                ui->forward_treashold_label_2->setText(QString::number(nHex/100.0)+"");
            }
        }else if(raw_params[0].mid(5,2)=="9B"){
            if(raw_params[0].mid(11,2)=="00"){
                ui->pd_forward->setText(QString::number(nHex/100.0)+"");
            }else if(raw_params[0].mid(11,2)=="01"){
                ui->pd_forward_2->setText(QString::number(nHex/100.0)+"");
            }
        }else if(raw_params[0].mid(5,2)=="97"){
            if(raw_params[0].mid(11,2)=="00"){
                ui->pd_backward->setText(QString::number(nHex/100.0)+"");
            }else if(raw_params[0].mid(11,2)=="01"){
                ui->pd_backward_2->setText(QString::number(nHex/100.0)+"");
            }
        }else if(raw_params[0].mid(5,2)=="96"){
            if(raw_params[0].mid(11,2)=="00"){
                if(ui->backward_treashold_label->text()=="N/A")ui->backward_treashold->setValue(nHex/100.0);
                ui->backward_treashold_label->setText(QString::number(nHex/100.0)+"");
            }else if(raw_params[0].mid(11,2)=="01"){
                if(ui->backward_treashold_label_2->text()=="N/A")ui->backward_treashold_2->setValue(nHex/100.0);
                ui->backward_treashold_label_2->setText(QString::number(nHex/100.0)+"");
            }
        }else if(raw_params[0].mid(5,2)=="B1"){
          if(ui->therm_resis_label->text()=="N/A")ui->therm_resis->setValue(nHex);
          ui->therm_resis_label->setText(QString::number(nHex)+" Ohm");
        }else if(raw_params[0].mid(5,2)=="B8"){
          if(ui->therm_vref_label->text()=="N/A")ui->therm_vref->setValue(nHex/1000.0);
          ui->therm_vref_label->setText(QString::number(nHex/1000.0)+" V");
        }else if(raw_params[0].mid(5,2)=="B2"){
          if(ui->therm_beta_label->text()=="N/A")ui->therm_beta->setValue(nHex);
          ui->therm_beta_label->setText(QString::number(nHex)+"");
        }else if(raw_params[0].mid(5,2)=="B3"){
          if(ui->over_temp_label->text()=="N/A")ui->over_temp->setValue(nHex/10.0);
          ui->over_temp_label->setText(QString::number(nHex/10.0)+" C");
        }else{
          bool ok=true;

          if(raw_params[0].mid(5,2).toInt(&ok,16)<0x80){
            quint32 value = raw_params[0].mid(5,2).toInt(&ok,16)+0x80;
            QString command=raw_params[0];
            command.replace(5,2,QString::number(value, 16).toUpper());
            value = raw_params[0].mid(2,2).toInt(&ok,16);

            QString temp=QString("%1").arg(raw_params[0].mid(7,2).toInt(&ok,16), 2, 16, QLatin1Char( '0' )).toUpper();
            command.replace(2,2,temp);
            command.replace(7,2,QString::number(value, 16).toUpper());
            emit send_command(command.toUtf8()+'\r');
            qDebug()<<"mess cb echo else"<<raw_params[0]<<raw_params[0].mid(5,2);
          }else{
            qDebug()<<"unreaded"<<raw_params[0].mid(5,2).toInt(&ok,16)<<raw_params[0];
          }
        }

    }
}
