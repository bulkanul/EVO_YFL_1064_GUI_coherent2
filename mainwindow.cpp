#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user_panel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    conn=new tcp_usb_connector;
    conn->crypto_version_controller=false;
    connect(this,SIGNAL(send_connection_type(QString,int)),conn, SLOT(init_connection(QString,int)));
//    connect(conn,SIGNAL(connection_state(int)),this,SLOT(display_connection(int)));
//    connect(conn,SIGNAL(version_failed()),this,SLOT(display_version_error()));
//    connect(this, SIGNAL(send_ver_command(QString)),conn, SLOT(data_ver_write(QString)));
//    connect(this, SIGNAL(search_script(int)),conn, SLOT(start_search(int)));
//    connect(conn, SIGNAL(send_device_list(QList<int>)),this, SLOT(show_dev_list(QList<int>)));
    connect(this, SIGNAL(send_command(QByteArray)),conn, SLOT(raw_command_write(QByteArray)));

    dc = new dc_panel(this);
    connect(dc, SIGNAL(send_command(QByteArray)),conn, SLOT(raw_command_write(QByteArray)));
    connect(this, SIGNAL(update_internal_address(QString)),dc, SLOT(internal_address_write(QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)),dc, SLOT(data_received(QStringList)));
    connect(dc, SIGNAL(call_ui_buttons(QString,bool)),this, SLOT(update_ui(QString,bool)));
    ui->groupBox->layout()->addWidget(dc);
    dc->ID=0;

    dc1 = new dc_panel(this);
    connect(dc1, SIGNAL(send_command(QByteArray)),conn, SLOT(raw_command_write(QByteArray)));
    connect(this, SIGNAL(update_internal_address(QString)),dc1, SLOT(internal_address_write(QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)),dc1, SLOT(data_received(QStringList)));
    connect(dc1, SIGNAL(call_ui_buttons(QString,bool)),this, SLOT(update_ui(QString,bool)));
    ui->groupBox->layout()->addWidget(dc1);
    dc1->ID=1;

    dc2 = new dc_panel(this);
    connect(dc2, SIGNAL(send_command(QByteArray)),conn, SLOT(raw_command_write(QByteArray)));
    connect(this, SIGNAL(update_internal_address(QString)),dc2, SLOT(internal_address_write(QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)),dc2, SLOT(data_received(QStringList)));
    connect(dc2, SIGNAL(call_ui_buttons(QString,bool)),this, SLOT(update_ui(QString,bool)));
    ui->groupBox->layout()->addWidget(dc2);
    dc2->ID=2;

    cb = new cb_panel(this);
    cb->ID=0;
    connect(cb, SIGNAL(send_command(QByteArray)),conn, SLOT(raw_command_write(QByteArray)));
    connect(this, SIGNAL(update_internal_address(QString)),cb, SLOT(internal_address_write(QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)),cb, SLOT(data_received(QStringList)));
    connect(cb, SIGNAL(call_ui_buttons(QString,bool)),this, SLOT(update_ui(QString,bool)));
    ui->groupBox->layout()->addWidget(cb);

    user = new user_panel(this);
    connect(user, SIGNAL(send_command(QByteArray)),conn, SLOT(raw_command_write(QByteArray)));
    connect(this, SIGNAL(update_internal_address(QString)),user, SLOT(internal_address_write(QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)),user, SLOT(data_received(QStringList)));
    ui->groupBox->layout()->addWidget(user);
    user->ID=0;

    connect(this, SIGNAL(send_command(QByteArray)),conn, SLOT(raw_command_write(QByteArray)));
//    dc2 = new dc_panel(this);
//    dc2->ID=2;
//    dc2->enable_widget(false);
//    ui->groupBox->layout()->addWidget(dc2);
//    connect(dc2, SIGNAL(send_command(QString,int,QString)),conn, SLOT(data_write(QString,int,QString)));
//    connect(dc2, SIGNAL(sig_usr_changes(QString,int)),this, SLOT(change_interface(QString,int)));
//    connect(conn, SIGNAL(send_to_dev(QStringList)),dc2, SLOT(data_received(QStringList)));



    QSettings settings(QString("configs/config.ini"), QSettings::IniFormat);
    if(settings.value("prev_connection").toString()!=""){
        qDebug() <<"saved writed"<<settings.value("prev_port").toString();
        conn->serial=settings.value("prev_connection").toString();
        if(settings.value("local_addr").toString()!=""){
            ui->ip_adress_2->setText(settings.value("local_addr").toString());
        }else{
            ui->ip_adress_2->setText("00A");
        }
        on_refresh_ports_clicked();
        on_connect_btn_clicked();
    }
    emit update_internal_address(ui->ip_adress_2->text());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_ui(QString name,bool state)
{
    if(name=="dc0")dc_err=state;
    else if(name=="dc1")dc1_err=state;
    else if(name=="dc2")dc2_err=state;
    else if(name=="cb")cb_err=state;
    ui->pb_error_cleaner->setVisible(dc_err || dc1_err || dc2_err || cb_err);
}


void MainWindow::on_connect_btn_clicked()
{
    emit send_connection_type(ui->serial_combo_box->currentData().toString(),404);
    ui->menu_button->setText("Настройки подключения");
    ui->stackedWidget->setCurrentIndex(0);
    conn->tmr->start();
    emit send_command(QString("O").toUtf8()+'\r');
    emit send_command(QString("S6").toUtf8()+'\r');
}


void MainWindow::on_menu_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(!ui->stackedWidget->currentIndex());
    ui->menu_button->setText(ui->stackedWidget->currentIndex()?"Главная":"Настройки подключения");
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
    ui->serial_combo_box->setCurrentText(ui->serial_combo_box->itemText(current_port_index));
}


void MainWindow::on_ip_adress_2_editingFinished()
{
    QSettings settings(QString("configs/config.ini"), QSettings::IniFormat);
    settings.setValue("local_addr",ui->ip_adress_2->text());
    emit update_internal_address(ui->ip_adress_2->text());
}

void MainWindow::on_pb_error_cleaner_clicked()
{
    ui->pb_error_cleaner->setVisible(false);
    QString message ="t"+ui->ip_adress_2->text()+"81c00000000000000";
    emit send_command(message.toUtf8()+'\r');
    dc->error_displayer=true;
    dc1->error_displayer=true;
    dc2->error_displayer=true;
    cb->error_displayer=true;
}


void MainWindow::on_all_save_in_memory_clicked()
{
    ui->pb_error_cleaner->setVisible(false);
    QString message ="t"+ui->ip_adress_2->text()+"85200000000000000";
    emit send_command(message.toUtf8()+'\r');
}

