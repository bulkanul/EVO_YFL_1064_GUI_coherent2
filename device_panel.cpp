#include "device_panel.h"
#include "tcp_usb_connector.h"

#include <QDialog>
#include <QDialogButtonBox>
#include <QGroupBox>
#include <QKeyEvent>
#include <QMessageBox>
#include <QPushButton>
#include <QSplitter>
#include <QTimer>
#include <QVBoxLayout>

device_panel::device_panel(QWidget *parent) : QWidget(parent)
{
    tmr=new QTimer();
    tmr->setInterval(800);
    connect(tmr,SIGNAL(timeout()),this,SLOT(auto_telemetry_call()));
    tmr->start();
}

bool device_panel::eventFilter(QObject *target, QEvent *event)
{
    if(event->type() == QEvent::Wheel)
    {
         if(target->inherits("QDoubleSpinBox")){
            return true;
         }
         else if(target->inherits("QSlider"))
         {
            return true;
         }
         else if(target->inherits("QComboBox"))
         {
            return true;
         }
    }
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if(keyEvent->key()==Qt::Key_Return ||keyEvent->key()== Qt::Key_Enter){
            emit enter_event(target);
        }
    }
    return false;
}

void device_panel::auto_telemetry_call()
{
    if (family == "" && ID == -1)
        return;
    count++;
    count_no_responce++;
    if(count_no_responce>6){
        if (family != "debug")
            enable_widget(false);
        first_pref_cmd=false;
        first_status_cmd=true;
        first_calib=true;
    }
//    qDebug()<<"auto_telemetry_call"<<family<<ID<<count_no_responce;
    if (family != "debug")
        sl_data_get("lgstatus",ID,"");

}

QString device_panel::param_check(QStringList list,int number){
    if(list.length()>number){
        return list[number];
    }else{
        return "N/A";
    }
}

QStringList device_panel::double_localizator(QByteArray data){
    QStringList list_splitter =QString::fromStdString(data.toStdString()).split("\r");
    QStringList list =  list_splitter[0].split(" ");
    for(int i=0; i<list.length();i++){
       list[i].replace(",",".");
    }
    return list;
}

void device_panel::data_received(QStringList message)
{

//    qDebug()<<"data_received call"<<message<<ID<<family<<key;
    if((param_check(message,2).toInt()==ID && param_check(message,1)==family)){// || (param_check(message,0).contains("conf") && param_check(message,1)=="usr")){
        raw_params=message;
        count_no_responce=0;
        enable_widget(key);
        if(silence_count<=0){
            emit command_proofed();
        }else{
            silence_count--;
        }
    }
//    if(message.size() == 2 && param_check(message, 1) != "NL_SSL_eth_board_29032023" && family == "debug"){ //debug only
//        raw_params=message;
//        emit command_proofed();
//    }
    if(param_check(message,0)=="lrstatus"){
       // qDebug();
    }
    if(param_check(message,3)=="ERR"){
        enable_widget(false);
    }
    if(param_check(raw_params,0)=="lrconf" && family!="usr"){
        writed_values.clear();
        for (int i=3;i<prefs.length()+3;i++ ) {
             prefs[i-3].value=param_check(raw_params,i).toDouble();
            if(dialog!=nullptr){
//                if(container_values.length()>(i-3) && prefs.length()>(i-3)){
                    container_values[i-3]->setText(QString::number(param_check(raw_params,i).toDouble(),'d',prefs[i-3].precision));
//                }
            }
        }
        first_pref_cmd=true;
//        if(dialog.isVisible())pref_status->setText("Сохранено");
    }
}

void device_panel::sl_data_set(QString comm,int number,QString data)
{
    emit send_command(comm+" "+family,number,data);
}

void device_panel::sl_data_get(QString comm,int number,QString data)
{
    emit send_command(comm+" "+family,number,data);
}

void device_panel::send_laser(QString type, QString mess){
    sl_data_set(type,ID,mess);
}

void device_panel::on_toolButton_clicked()
{
    dialog = new QDialog();
    dialog->setWindowTitle(family + " configuration");
    dialog->setModal(true);
    dialog->setMinimumWidth(500);
    dialog->setMaximumWidth(500);
    QVBoxLayout* dialogLay = new QVBoxLayout(dialog);
    QLabel* title_label=new QLabel("Laser (" + family +") configuration",dialog);
    QFont title_font = title_label->font();
    title_font.setPointSize(14);
    title_font.setBold(true);
    title_label->setFont(title_font);
    dialogLay->addWidget(title_label);
    spiners.clear();
    container_values.clear();
    for(int i = 0; i < prefs.length(); i ++)
    {
        QHBoxLayout* splitter = new QHBoxLayout(dialog);
        QLabel* name_label=new QLabel(prefs[i].title,dialog);
        container_values.append(new QLabel((prefs[i].value==-1)?"N/A":(QString::number(prefs[i].value,'f',prefs[i].precision)),dialog));
        splitter->setSpacing(9);
        container_values[i]->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
        splitter->addWidget(name_label);
        QDoubleSpinBox* spinbox = new QDoubleSpinBox(dialog);
        spiners.append(spinbox);
        spinbox->setMaximum(0xffffffff);
        spinbox->setDecimals(prefs[i].precision);
        spinbox->setValue(prefs[i].value);
        splitter->addWidget(container_values[i]);
        splitter->addWidget(spinbox);
        dialogLay->addLayout(splitter);
    }
    QHBoxLayout* splitter = new QHBoxLayout(dialog);
    QPushButton* cancel_button = new QPushButton("Close",dialog);
    QPushButton* write_button = new QPushButton("Write",dialog);
    connect(cancel_button,SIGNAL(clicked()),dialog,SLOT(close()));
    connect(write_button,SIGNAL(clicked()),this,SLOT(send_pref()));
    splitter->addWidget(cancel_button);
    splitter->addWidget(write_button);
    dialogLay->addItem(splitter);
    dialog->exec();
}

void device_panel::enable_widget(bool state)
{
    this->setEnabled(state);
}

void device_panel::send_pref()
{
    QString message;
    bool first=false;
    foreach(QDoubleSpinBox* spiner ,spiners){
       if(first){
           message+=" ";
       }
       first=true;
       message+=QString::number(spiner->value(),'d',4);
    }
    emit sl_data_set("lsconf",ID,message);
}

QString device_panel::pars_bits(unsigned char mess,QStringList list){
    QString answer;
    for (int i=0;i<8;i++){
         if(((mess & (1<<(i)))!=0 )){
            answer+= list[i]+'\n';
        }
    }
    return answer;
}

void device_panel::call_msg_box(QString msg){
    if(error_displayer && msg!=""){
        error_displayer=false;

        QMessageBox *mesg;
        mesg = new QMessageBox(QMessageBox::Information,family+" Ошибка", msg);
        mesg->addButton(QMessageBox::Ok);
        mesg->show();
    }
}

void device_panel::silence_counter(int count)
{
    silence_count=count;
}
