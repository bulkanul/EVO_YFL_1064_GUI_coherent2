#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QThread>
#include <QKeyEvent>
#include <QButtonGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Main control board");
    connect(this,SIGNAL(pass_event(QKeyEvent *)),this,SLOT(pass_controller(QKeyEvent *)));

    conn = new tcp_usb_connector();
    connect(this,SIGNAL(set_conn_params(QString,int)),conn,SLOT(init_connection(QString,int)));
    connect(conn,SIGNAL(version_error()),this,SLOT(version_conflict()));
    connect(this, SIGNAL(send_command(QString,int,QString)),conn, SLOT(data_write(QString,int,QString)));
    connect(conn,SIGNAL(connection_state(int)),this,SLOT(connection_state(int)));

    QGridLayout* layout = new QGridLayout(ui->groupBox);

    gen = new generator_panel(this);
    gen->ID = 0;
    // gen->enable_widget(false);
    layout->addWidget(gen, 0, 0, 3, 1);
    connect(gen, SIGNAL(sig_usr_changes(QString, int)), this, SLOT(change_interface(QString,int)));
    connect(gen, SIGNAL(send_command(QString,int,QString)),conn, SLOT(data_write(QString,int,QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)), gen, SLOT(data_received(QStringList)));

    chan1 = new channel_panel(1, this);
    connect(chan1->preamp, SIGNAL(send_command(QString,int,QString)),conn, SLOT(data_write(QString,int,QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)), chan1->preamp, SLOT(data_received(QStringList)));
    connect(chan1->amp, SIGNAL(send_command(QString,int,QString)),conn, SLOT(data_write(QString,int,QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)), chan1->amp, SLOT(data_received(QStringList)));
    layout->addWidget(chan1, 0, 1);

    chan2 = new channel_panel(2, this);
    connect(chan2->preamp, SIGNAL(send_command(QString,int,QString)),conn, SLOT(data_write(QString,int,QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)), chan2->preamp, SLOT(data_received(QStringList)));
    connect(chan2->amp, SIGNAL(send_command(QString,int,QString)),conn, SLOT(data_write(QString,int,QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)), chan2->amp, SLOT(data_received(QStringList)));
    layout->addWidget(chan2, 1, 1);

    chan3 = new channel_panel(3, this);
    connect(chan3->preamp, SIGNAL(send_command(QString,int,QString)),conn, SLOT(data_write(QString,int,QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)), chan3->preamp, SLOT(data_received(QStringList)));
    connect(chan3->amp, SIGNAL(send_command(QString,int,QString)),conn, SLOT(data_write(QString,int,QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)), chan3->amp, SLOT(data_received(QStringList)));
    layout->addWidget(chan3, 2, 1);
    chan3->setDisabled(true);

    chan4 = new channel_panel(4, this);
    connect(chan4->preamp, SIGNAL(send_command(QString,int,QString)),conn, SLOT(data_write(QString,int,QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)), chan4->preamp, SLOT(data_received(QStringList)));
    connect(chan4->amp, SIGNAL(send_command(QString,int,QString)),conn, SLOT(data_write(QString,int,QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)), chan4->amp, SLOT(data_received(QStringList)));
    layout->addWidget(chan4, 3, 1);
    chan4->setDisabled(true);

    chan5 = new channel_panel(5, this);
    connect(chan5->preamp, SIGNAL(send_command(QString,int,QString)),conn, SLOT(data_write(QString,int,QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)), chan5->preamp, SLOT(data_received(QStringList)));
    connect(chan5->amp, SIGNAL(send_command(QString,int,QString)),conn, SLOT(data_write(QString,int,QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)), chan5->amp, SLOT(data_received(QStringList)));
    layout->addWidget(chan5, 4, 1);
    chan5->setDisabled(true);

    chan_all = new channel_all_panel(0, this);
    connect(chan_all->preamp, SIGNAL(send_command(QString,int,QString)),conn, SLOT(data_write(QString,int,QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)), chan_all->preamp, SLOT(data_received(QStringList)));
    connect(chan_all->amp, SIGNAL(send_command(QString,int,QString)),conn, SLOT(data_write(QString,int,QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)), chan_all->amp, SLOT(data_received(QStringList)));
    layout->addWidget(chan_all, 5, 1);

    flags = new flag_panel(this);
    connect(flags, SIGNAL(send_command(QString,int,QString)), conn, SLOT(data_write(QString,int,QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)), flags, SLOT(data_received(QStringList)));
    layout->addWidget(flags, 3, 0, 2, 1);

    div = new divider_panel(this);
    connect(div, SIGNAL(send_command(QString,int,QString)), conn, SLOT(data_write(QString,int,QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)), div, SLOT(data_received(QStringList)));
    layout->addWidget(div, 5, 0);

    ui->groupBox->setLayout(layout);

    QSettings settings(QString("configs/config.ini"), QSettings::IniFormat);
    if(settings.value("prev_connection").toString()!=""){
        qDebug() <<"saved writed"
                 <<settings.value("prev_connection").toString()
                 <<settings.value("prev_ip").toString()
                 <<settings.value("prev_port").toString();
        conn->connection_is_tcp=settings.value("prev_connection").toString()=="TCP";

        if(settings.value("prev_ip").toString()!=""){
            ui->ip_adress->setText(settings.value("prev_ip").toString());
            conn->ip=settings.value("prev_ip").toString();
        }

        conn->serial=settings.value("prev_port").toString();
        if(settings.value("prev_connection").toString()=="true"){
            ui->rb_tcp->setChecked(true);
        }else{
            ui->rb_serial->setChecked(true);
            on_refresh_ports_clicked();
        }
        QThread::msleep(100);
        on_pushButton_clicked();
    }
    installEventFilter(this);
    ui->pb_error_cleaner->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::change_interface(QString name, int state)
{
//    if(name=="pb_error_cleaner"){
//        ui->pb_error_cleaner->setVisible(state);
//    }else if(name.contains("l_footer_emission")==true){
//        if(name.split(" ")[1]=="cw")light_state[name.split(" ")[2].toUInt()]=state;
//        else if(name.split(" ")[1]=="dc")light_state[5]=state;
//        else if(name.split(" ")[1]=="ns")light_state[6]=state;
//        bool max=0;
//        for(int i=0;i<7;i++){
//           max|=light_state[i];
//        }
//        ui->l_footer_emission->setEnabled(!max);
//    }else if(name.contains("l_footer_key")==true){
//        ui->l_footer_key->setEnabled(state);
////    if(name=="l_footer_connection_status"){
////        ui->l_footer_connection_status->setText(state?"Состояние : ПОДКЛЮЧЕНО":"Состояние : ОТКЛЮЧЕНО");
////    }
//    }else if(name=="l_footer_interlock"){
//        ui->l_footer_interlock->setEnabled(state);
//    }else if(name=="l_footer_acdc_ok"){
//        ui->l_footer_acdc_ok->setEnabled(state);
//    }else if(name=="l_footer_acdc_t_alarm"){
//        ui->l_footer_acdc_t_alarm->setEnabled(state);
//    }
}

void MainWindow::on_pushButton_clicked()
{
//    if(ui->pushButton->text()=="Connect"){
//        laser->first_set_write=true;
        if(ui->rb_tcp->isChecked()){
            conn->connection_is_tcp=true;
            emit set_conn_params(ui->ip_adress->text()/*"127.0.0.1"*/,7878);
        }else if(ui->rb_serial->isChecked()){
            conn->connection_is_tcp=false;
            emit set_conn_params(ui->serial_combo_box->currentText().split(" ").last(),404);
        }
        on_menu_main_clicked();
//    }else{
//        if(conn->connection_is_tcp){
//            conn->tcp_disconnect();
//        }else{
//            conn->serial_disconnect();
//        }
//    }
}

void MainWindow::version_conflict()
{
    QMessageBox *mesg = new QMessageBox(QMessageBox::Information,
                                        "Failed",
                                        "Version Conflict",
                                        QMessageBox::Ok);
    if(mesg->exec()==QMessageBox::Ok){
    }
}

void MainWindow::on_menu_button_clicked()
{
//    if(ui->stackedWidget->currentIndex()==0){
        ui->stackedWidget->setCurrentIndex(1);
//    }else if(ui->stackedWidget->currentIndex()==1){
//        ui->stackedWidget->setCurrentIndex(0);
//    }
}

void MainWindow::on_menu_main_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_refresh_ports_clicked()
{
    int current_port_index = 0;
    const auto infos = QSerialPortInfo::availablePorts();
    ui->serial_combo_box->clear();
    for (const QSerialPortInfo &info : infos)
    {
        ui->serial_combo_box->addItem("\"" + info.description() + "\" " + info.portName(),info.portName());
    }
    current_port_index = ui->serial_combo_box->findData(conn->serial);
    ui->serial_combo_box->setCurrentIndex(current_port_index);
//    ui->serial_combo_box->setCurrentText(ui->serial_combo_box->itemText(current_port_index));
}

void MainWindow::on_pb_error_cleaner_clicked()
{
    emit send_command("lserrclr usr",0,"");
    ui->pb_error_cleaner->setVisible(false);
}

void MainWindow::on_all_reset_1_clicked()
{
    QMessageBox *mesg;
    mesg = new QMessageBox(QMessageBox::Information,"Conformation", "factory reset?");
    mesg->addButton(QMessageBox::Yes);
    mesg->addButton(QMessageBox::No);
    mesg->show();
    if(mesg->exec()==QMessageBox::Yes){
        emit send_command("lsfactrst",0,"");
    }
}

void MainWindow::on_all_save_seed_clicked()
{

}

void MainWindow::on_all_restore_seed_clicked()
{

}

void MainWindow::on_all_save_in_memory_clicked()
{

}

void MainWindow::connection_state(int state)
{
    switch (state){
    case 0:
        ui->l_footer_connection_status->setText("Состояние : ОТКЛЮЧЕНО");
        break;
    case 1:
        ui->l_footer_connection_status->setText("Состояние : ПОДКЛЮЧЕНО");
        break;
    case 2:
        ui->l_footer_connection_status->setText("Состояние : ПЕРЕПОДКЛЮЧЕНИЕ...");
    }

}

bool MainWindow::eventFilter(QObject *target, QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        emit pass_event(keyEvent);
    }
    return false;
}

void MainWindow::pass_controller(QKeyEvent *keyEvent)
{
    if(keyEvent->key() == Qt::Key_A){
        admin_pass++;
    }else if(keyEvent->key() == Qt::Key_D && admin_pass==1){
        admin_pass++;
    }else if(keyEvent->key() == Qt::Key_M && admin_pass==2){
        admin_pass++;
    }else if(keyEvent->key() == Qt::Key_I && admin_pass==3){
        admin_pass++;
    }else if(keyEvent->key() == Qt::Key_N && admin_pass==4){
        admin_pass++;
    }else{
        admin_pass=0;
    }
    if(admin_pass==5){
        //ui->groupBox_2->setVisible(true);
        user_ui=false;
    }

    if(keyEvent->key() == Qt::Key_U ){
        user_pass++;
    }else if(keyEvent->key() == Qt::Key_S && user_pass==1){
        user_pass++;
    }else if(keyEvent->key() == Qt::Key_E && user_pass==2){
        user_pass++;
    }else if(keyEvent->key() == Qt::Key_R && user_pass==3){
        user_pass++;
    }else{
        user_pass=0;
        pass="";
    }
    if(user_pass==4){
        //ui->groupBox_2->setVisible(false);
        user_ui=true;
    }

}

void MainWindow::on_disconnect_clicked()
{
    if(conn->connection_is_tcp){
        conn->tcp_disconnect();
    }else{
        conn->serial_disconnect();
    }
    ui->l_footer_connection_status->setText("Состояние: ОТКЛЮЧЕНО");
}
