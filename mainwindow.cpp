#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QThread>
#include <QKeyEvent>
#include <QButtonGroup>
#include <QInputDialog>
#include <QDialog>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Main control board");
    connect(this,&MainWindow::pass_event,this,&MainWindow::pass_controller);

    conn = new tcp_usb_connector();
    connect(this,&MainWindow::set_conn_params,conn,&tcp_usb_connector::init_connection);
    connect(conn,&tcp_usb_connector::version_error,this,&MainWindow::version_conflict);
    connect(conn,&tcp_usb_connector::connection_timeout,this,&MainWindow::connection_timeout);
    connect(conn,&tcp_usb_connector::network_info_received,this,&MainWindow::on_network_info);
    connect(this,&MainWindow::send_command,conn,&tcp_usb_connector::data_write);
    connect(conn,&tcp_usb_connector::connection_state,this,&MainWindow::connection_state);

    QGridLayout* layout = new QGridLayout(ui->groupBox);

    gen = new generator_panel(this);
    gen->ID = 0;
    // gen->enable_widget(false);
    layout->addWidget(gen, 0, 0, 3, 1);
    connect(gen,&generator_panel::sig_usr_changes,this,&MainWindow::change_interface);
    connect(gen,&device_panel::send_command,conn,&tcp_usb_connector::data_write);
    connect(conn,&tcp_usb_connector::send_to_dev,gen,&device_panel::data_received);
    connect(conn,&tcp_usb_connector::get_command,gen,&device_panel::auto_telemetry_call);
    connect(gen,&generator_panel::emission_changed,this,&MainWindow::on_emission_changed);

    chan1 = new channel_panel(1, this);
    connect(chan1->preamp,&device_panel::send_command,conn,&tcp_usb_connector::data_write);
    connect(conn,&tcp_usb_connector::send_to_dev,chan1->preamp,&device_panel::data_received);
    connect(chan1->amp,&device_panel::send_command,conn,&tcp_usb_connector::data_write);
    connect(conn,&tcp_usb_connector::send_to_dev,chan1->amp,&device_panel::data_received);
    connect(conn,&tcp_usb_connector::get_command,chan1->amp,&device_panel::auto_telemetry_call);
    connect(conn,&tcp_usb_connector::get_command,chan1->preamp,&device_panel::auto_telemetry_call);
    layout->addWidget(chan1, 0, 1);


    chan2 = new channel_panel(2, this);
    connect(chan2->preamp,&device_panel::send_command,conn,&tcp_usb_connector::data_write);
    connect(conn,&tcp_usb_connector::send_to_dev,chan2->preamp,&device_panel::data_received);
    connect(chan2->amp,&device_panel::send_command,conn,&tcp_usb_connector::data_write);
    connect(conn,&tcp_usb_connector::send_to_dev,chan2->amp,&device_panel::data_received);
    connect(conn,&tcp_usb_connector::get_command,chan2->amp,&device_panel::auto_telemetry_call);
    connect(conn,&tcp_usb_connector::get_command,chan2->preamp,&device_panel::auto_telemetry_call);

    layout->addWidget(chan2, 1, 1);

    chan3 = new channel_panel(3, this);
    connect(chan3->preamp,&device_panel::send_command,conn,&tcp_usb_connector::data_write);
    connect(conn,&tcp_usb_connector::send_to_dev,chan3->preamp,&device_panel::data_received);
    connect(chan3->amp,&device_panel::send_command,conn,&tcp_usb_connector::data_write);
    connect(conn,&tcp_usb_connector::send_to_dev,chan3->amp,&device_panel::data_received);
    connect(conn,&tcp_usb_connector::get_command,chan3->amp,&device_panel::auto_telemetry_call);
    connect(conn,&tcp_usb_connector::get_command,chan3->preamp,&device_panel::auto_telemetry_call);
    layout->addWidget(chan3, 2, 1);
    // chan3->setDisabled(true);

    chan4 = new channel_panel(4, this);
    connect(chan4->preamp,&device_panel::send_command,conn,&tcp_usb_connector::data_write);
    connect(conn,&tcp_usb_connector::send_to_dev,chan4->preamp,&device_panel::data_received);
    connect(chan4->amp,&device_panel::send_command,conn,&tcp_usb_connector::data_write);
    connect(conn,&tcp_usb_connector::send_to_dev,chan4->amp,&device_panel::data_received);
    connect(conn,&tcp_usb_connector::get_command,chan4->amp,&device_panel::auto_telemetry_call);
    connect(conn,&tcp_usb_connector::get_command,chan4->preamp,&device_panel::auto_telemetry_call);
    layout->addWidget(chan4, 3, 1);
    // chan4->setDisabled(true);

    chan_all = new channel_all_panel(0, this);
    connect(chan_all->preamp,&device_panel::send_command,conn,&tcp_usb_connector::data_write);
    connect(conn,&tcp_usb_connector::send_to_dev,chan_all->preamp,&device_panel::data_received);
    connect(chan_all->amp,&device_panel::send_command,conn,&tcp_usb_connector::data_write);
    connect(conn,&tcp_usb_connector::send_to_dev,chan_all->amp,&device_panel::data_received);
    connect(conn,&tcp_usb_connector::get_command,chan_all->amp,&device_panel::auto_telemetry_call);
    connect(conn,&tcp_usb_connector::get_command,chan_all->preamp,&device_panel::auto_telemetry_call);
    layout->addWidget(chan_all, 5, 1);
    // chan_all->setDisabled(true);

    flags = new flag_panel(this);
    connect(flags,&flag_panel::sig_usr_critical_error,this,&MainWindow::on_usr_critical_error);
    connect(flags,&device_panel::send_command,conn,&tcp_usb_connector::data_write);
    connect(conn,&tcp_usb_connector::send_to_dev,flags,&device_panel::data_received);
    connect(conn,&tcp_usb_connector::get_command,flags,&device_panel::auto_telemetry_call);
    layout->addWidget(flags, 3, 0, 2, 1);

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

    connect(ui->pb_network_info, &QPushButton::clicked,
            this, &MainWindow::show_network_info_dialog);
    connect(ui->pb_bootloader, &QPushButton::clicked,
            this, &MainWindow::enter_bootloader);
    connect(ui->pb_request_status, &QPushButton::clicked,
            conn, &tcp_usb_connector::request_status_manual);
    connect(ui->pb_request_version, &QPushButton::clicked,
            conn, &tcp_usb_connector::request_version_manual);
#if AUTO_TELEMETRY_ENABLED
    ui->pb_request_status->setVisible(false);
    ui->pb_request_version->setVisible(false);
#else
    ui->pb_request_status->setVisible(true);
    ui->pb_request_version->setVisible(true);
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::change_interface(QString name, int state)
{
    Q_UNUSED(name);
    Q_UNUSED(state);
}

void MainWindow::on_pushButton_clicked()
{
        if(ui->rb_tcp->isChecked()){
            conn->connection_is_tcp=true;
            emit set_conn_params(ui->ip_adress->text()/*"127.0.0.1"*/,7878);
        }else if(ui->rb_serial->isChecked()){
            conn->connection_is_tcp=false;
            emit set_conn_params(ui->serial_combo_box->currentText().split(" ").last(),404);
        }
        on_menu_main_clicked();
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
        ui->stackedWidget->setCurrentIndex(1);
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
}

void MainWindow::on_pb_error_cleaner_clicked()
{
    emit send_command("lserrclr usr",0,"");
    ui->pb_error_cleaner->setVisible(false);
}

void MainWindow::on_usr_critical_error(bool show_clear_btn)
{
    ui->pb_error_cleaner->setVisible(show_clear_btn);
}

void MainWindow::on_all_reset_1_clicked()
{
    QMessageBox *mesg = new QMessageBox(QMessageBox::Warning, "Factory Reset",
                           "Are you sure you want to reset to factory settings?\n"
                           "The device will be rebooted.",
                           QMessageBox::Yes | QMessageBox::No, this);
    if(mesg->exec() == QMessageBox::Yes){
        conn->data_common_write("lsfactrst");
    }
    delete mesg;
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
    QString connectionInfo;
    if(conn->connection_is_tcp){
        connectionInfo = QString("TCP: %1:%2").arg(conn->ip).arg(7878);
    } else {
        connectionInfo = QString("Serial: %1").arg(conn->serial);
    }
    
    switch (state){
    case 0:
        ui->l_footer_connection_status->setText("Disconnected");
        break;
    case 1:
        ui->l_footer_connection_status->setText(QString("Connected | %1").arg(connectionInfo));
        break;
    case 2:
        ui->l_footer_connection_status->setText(QString("Reconnecting... | %1").arg(connectionInfo));
        break;
    }
}

bool MainWindow::eventFilter(QObject *target, QEvent *event)
{
    Q_UNUSED(target);
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
    connection_state(0);
}

void MainWindow::connection_timeout()
{
    QMessageBox *mesg = new QMessageBox(QMessageBox::Critical,
                                        "Connection Error",
                                        "Failed to connect to device.\n\n"
                                        "Maximum retry count exceeded.\n"
                                        "Check connection and try again.",
                                        QMessageBox::Ok);
    mesg->exec();
    delete mesg;    
    connection_state(0);
}

void MainWindow::on_emission_changed(bool isActive)
{
    this->isEmissionActive = isActive;
    Q_UNUSED(isActive);
}

void MainWindow::set_device_ip()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Set Device IP"),
                                         tr("New IP Address:"), QLineEdit::Normal,
                                         "192.168.26.220", &ok);
    if (ok && !text.isEmpty()) {
        conn->data_common_write("lsip", text);
    }
}

void MainWindow::enter_bootloader()
{
    QMessageBox *mesg = new QMessageBox(QMessageBox::Critical, "Bootloader",
                           "Entering bootloader mode.\nConnection will be lost.",
                           QMessageBox::Yes | QMessageBox::No, this);
    if(mesg->exec() == QMessageBox::Yes){
        conn->data_common_write("lsbootloader");
    }
    delete mesg;
}

void MainWindow::show_network_info_dialog()
{
    if (!networkDialog) {
        networkDialog = new QDialog(this);
        networkDialog->setWindowTitle(tr("Network Info"));
        auto *layout = new QGridLayout(networkDialog);

        layout->addWidget(new QLabel(tr("IP address:"), networkDialog), 0, 0);
        networkIpEdit = new QLineEdit(networkDialog);
        networkIpEdit->setInputMask("000.000.000.000; ");
        networkIpEdit->setPlaceholderText("192.168.26.220");
        networkIpEdit->setText(currentIp.isEmpty() ? ui->ip_adress->text() : currentIp);
        layout->addWidget(networkIpEdit, 0, 1);

        auto *btnReadIp = new QPushButton(tr("Read"), networkDialog);
        auto *btnSetIp  = new QPushButton(tr("Set"),  networkDialog);
        layout->addWidget(btnReadIp, 0, 2);
        layout->addWidget(btnSetIp,  0, 3);

        layout->addWidget(new QLabel(tr("MAC address:"), networkDialog), 1, 0);
        networkMacEdit = new QLineEdit(networkDialog);
        networkMacEdit->setInputMask("HH:HH:HH:HH:HH:HH; ");
        networkMacEdit->setPlaceholderText("11:22:33:44:55:66");
        networkMacEdit->setText(currentMac);
        layout->addWidget(networkMacEdit, 1, 1);

        auto *btnReadMac = new QPushButton(tr("Read"), networkDialog);
        auto *btnSetMac  = new QPushButton(tr("Set"),  networkDialog);
        layout->addWidget(btnReadMac, 1, 2);
        layout->addWidget(btnSetMac,  1, 3);

        auto *btnClose = new QPushButton(tr("Close"), networkDialog);
        layout->addWidget(btnClose, 2, 0, 1, 4);

        connect(btnClose, &QPushButton::clicked, networkDialog, &QDialog::close);

        // lgip / lsip <ip>
        connect(btnReadIp, &QPushButton::clicked, this, [this]() {
            conn->data_common_write("lgip");
        });
        connect(btnSetIp, &QPushButton::clicked, this, [this]() {
            if (networkIpEdit)
                conn->data_common_write("lsip", networkIpEdit->text());
        });

        // lgmac / lsmac <xx xx xx xx xx xx>
        connect(btnReadMac, &QPushButton::clicked, this, [this]() {
            conn->data_common_write("lgmac");
        });
        connect(btnSetMac, &QPushButton::clicked, this, [this]() {
            if (networkMacEdit) {
                // Convert HH:HH:HH:HH:HH:HH -> xx xx xx xx xx xx
                QString mac = networkMacEdit->text().replace(':', ' ');
                conn->data_common_write("lsmac", mac);
            }
        });
    }

    if (networkIpEdit) {
        networkIpEdit->setText(currentIp.isEmpty() ? ui->ip_adress->text() : currentIp);
    }
    if (networkMacEdit) {
        // Display MAC in HH:HH:HH:HH:HH:HH format
        networkMacEdit->setText(currentMac.replace(' ', ':'));
    }

    networkDialog->show();
    networkDialog->raise();
    networkDialog->activateWindow();
}

void MainWindow::on_network_info(QString type, QString value)
{
    if (type == "IP") {
        currentIp = value;
        ui->ip_adress->setText(value);
        if (networkIpEdit) {
            networkIpEdit->setText(value);
        }
    } else if (type == "MAC") {
        currentMac = value;
        if (networkMacEdit) {
            networkMacEdit->setText(value);
        }
    }
}
