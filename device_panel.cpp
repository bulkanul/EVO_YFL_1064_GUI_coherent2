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
//    tmr=new QTimer();
//    tmr->setInterval(800);
//    connect(tmr,SIGNAL(timeout()),this,SLOT(auto_telemetry_call()));
//    tmr->start();
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
    count++;
    count_no_responce++;
    if(count_no_responce>6){
         enable_widget(true);
         first_pref_cmd=false;
         first_status_cmd=true;
         first_calib=true;
    }
//    qDebug()<<"auto_telemetry_call"<<family<<ID<<count_no_responce;
    if(count%2==0 || first_pref_cmd){
        sl_data_get("lgstatus",ID,"");
    }else{
        sl_data_get("lgconf",ID,"");
    }
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

    if((param_check(message,2).toInt()==ID && param_check(message,1)==family) || (param_check(message,0).contains("conf") && param_check(message,1)=="usr")){
        raw_params=message;
        count_no_responce=0;
        enable_widget(key);
        if(silence_count<=0){
            emit command_proofed();
        }else{
            silence_count--;
        }
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

void device_panel::data_received(QByteArray data)
{
    if(data.mid(9,2)== QString("%1").arg(ID, 2, 16, QLatin1Char( '0' )) ){
        very_raw_params=data;
        emit command_proofed();
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
//    if(first_pref){
//        dialog.setGeometry(400, 600, 300, 100);
//        QVBoxLayout* dialogLay = new QVBoxLayout(&dialog);
//        int i=0;
//        foreach(QString name ,pref_names){
//            QSplitter* splitter = new QSplitter(Qt::Horizontal,&dialog);
//            QLabel* name_label=new QLabel(name,&dialog);
//            name_label->setGeometry(0, 0, 100, 30);
//            splitter->addWidget(name_label);
//            container_values.append(new QLabel(writed_values[i]));
//            splitter->addWidget(container_values.last());
//            container_values.last()->setGeometry(0, 0, 100, 30);
//            spiners.append(new QDoubleSpinBox(&dialog));
//            spiners.last()->setMaximum(50000);
//            splitter->addWidget(spiners.last());
//            dialogLay->addWidget(splitter);
//            i++;
//        }

//        QSplitter* buttonsplitter = new QSplitter(Qt::Horizontal,&dialog);
//        QDialogButtonBox* diagButton =new QDialogButtonBox(QDialogButtonBox::Save,&dialog);
//        connect(diagButton,SIGNAL(accepted()),this,SLOT(send_pref()));
////        connect(diagButton,SIGNAL(accepted()),&dialog,SLOT(accept()));
//        pref_status=new QLabel("",&dialog);
//        dialogLay->addWidget(pref_status);
//        buttonsplitter->addWidget(diagButton);
//        dialogLay->addWidget(buttonsplitter);
//        first_pref=false;
//    }
//    dialog.exec();
    dialog = new QDialog();
    dialog->setWindowTitle(family + " configuration");
    dialog->setModal(true);
    dialog->setMinimumWidth(500);
    dialog->setMaximumWidth(500);
//        dialog->setWindowIcon(QIcon(":/interface/conf_icon.ico"));
    QVBoxLayout* dialogLay = new QVBoxLayout(dialog);
    QLabel* title_label=new QLabel("Laser (" + family +") configuration",dialog);
//        QLabel* note_label = new QLabel("prefs_note",dialog);
//        QGroupBox* can_gb = new QGroupBox(dialog);
//        QVBoxLayout* can_v_layout= new QVBoxLayout(dialog);
    QFont title_font = title_label->font();
//        note_label->setWordWrap(true);
    title_font.setPointSize(14);
    title_font.setBold(true);
    title_label->setFont(title_font);
//        can_gb->setStyleSheet(  "QGroupBox {"
//                                "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #ffffff, stop: 1 #FFFFFF);"
//                                "border: 1px solid gray;"
//                                "margin-top: 1ex;"
//                                "}");
//        can_gb->setLayout(can_v_layout);
//        can_gb->layout()->addWidget(new QLabel("Device reset is nessesary after CAN ID change",dialog));
    dialogLay->addWidget(title_label);
//        dialogLay->addWidget(note_label);
//        dialogLay->addWidget(can_gb);
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
//            if(i == 0)
//                can_v_layout->addLayout(splitter);
//            else
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
