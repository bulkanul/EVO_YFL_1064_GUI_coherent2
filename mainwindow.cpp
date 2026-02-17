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

    connect(this, SIGNAL(send_command(QByteArray)),conn, SLOT(raw_command_write(QByteArray)));

    dc = new dc_panel(this);
    connect(dc, SIGNAL(send_command(QByteArray)),conn, SLOT(raw_command_write(QByteArray)));
    connect(this, SIGNAL(update_internal_address(QString)),dc, SLOT(internal_address_write(QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)),dc, SLOT(data_received(QStringList)));
    connect(dc, SIGNAL(call_ui_buttons(QString,bool)),this, SLOT(update_ui(QString,bool)));
    connect(conn, SIGNAL(get_command(QString)),dc, SLOT(telemetry_call(QString)));
    ui->groupBox->layout()->addWidget(dc);
    dc->ID=0;
    dc->name_section()->setText("HPLD 1000 0");

    dc1 = new dc_panel(this);
    connect(dc1, SIGNAL(send_command(QByteArray)),conn, SLOT(raw_command_write(QByteArray)));
    connect(this, SIGNAL(update_internal_address(QString)),dc1, SLOT(internal_address_write(QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)),dc1, SLOT(data_received(QStringList)));
    connect(dc1, SIGNAL(call_ui_buttons(QString,bool)),this, SLOT(update_ui(QString,bool)));
    connect(conn, SIGNAL(get_command(QString)),dc1, SLOT(telemetry_call(QString)));
    ui->groupBox->layout()->addWidget(dc1);
    dc1->ID=1;
    dc1->name_section()->setText("HPLD 1000 1");


    dc2 = new dc_panel(this);
    connect(dc2, SIGNAL(send_command(QByteArray)),conn, SLOT(raw_command_write(QByteArray)));
    connect(this, SIGNAL(update_internal_address(QString)),dc2, SLOT(internal_address_write(QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)),dc2, SLOT(data_received(QStringList)));
    connect(dc2, SIGNAL(call_ui_buttons(QString,bool)),this, SLOT(update_ui(QString,bool)));
    connect(conn, SIGNAL(get_command(QString)),dc2, SLOT(telemetry_call(QString)));
    ui->groupBox->layout()->addWidget(dc2);
    dc2->ID=2;
    dc2->name_section()->setText("HPLD 1000 2");

    dc3 = new dc_panel(this);
    connect(dc3, SIGNAL(send_command(QByteArray)),conn, SLOT(raw_command_write(QByteArray)));
    connect(this, SIGNAL(update_internal_address(QString)),dc3, SLOT(internal_address_write(QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)),dc3, SLOT(data_received(QStringList)));
    connect(dc3, SIGNAL(call_ui_buttons(QString,bool)),this, SLOT(update_ui(QString,bool)));
    connect(conn, SIGNAL(get_command(QString)),dc3, SLOT(telemetry_call(QString)));
    ui->groupBox->layout()->addWidget(dc3);
    dc3->ID=3;
    dc3->name_section()->setText("HPLD 1000 3");

    dc4 = new dc_panel(this);
    connect(dc4, SIGNAL(send_command(QByteArray)),conn, SLOT(raw_command_write(QByteArray)));
    connect(this, SIGNAL(update_internal_address(QString)),dc4, SLOT(internal_address_write(QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)),dc4, SLOT(data_received(QStringList)));
    connect(dc4, SIGNAL(call_ui_buttons(QString,bool)),this, SLOT(update_ui(QString,bool)));
    connect(conn, SIGNAL(get_command(QString)),dc4, SLOT(telemetry_call(QString)));
    ui->groupBox->layout()->addWidget(dc4);
    dc4->ID=4;
    dc4->name_section()->setText("HPLD 1000 4");

    dc5 = new dc_panel(this);
    connect(dc5, SIGNAL(send_command(QByteArray)),conn, SLOT(raw_command_write(QByteArray)));
    connect(this, SIGNAL(update_internal_address(QString)),dc5, SLOT(internal_address_write(QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)),dc5, SLOT(data_received(QStringList)));
    connect(dc5, SIGNAL(call_ui_buttons(QString,bool)),this, SLOT(update_ui(QString,bool)));
    connect(conn, SIGNAL(get_command(QString)),dc5, SLOT(telemetry_call(QString)));
    ui->groupBox->layout()->addWidget(dc5);
    dc5->ID=5;
    dc5->name_section()->setText("HPLD 1000 5");

    dc6 = new dc_panel(this);
    connect(dc6, SIGNAL(send_command(QByteArray)),conn, SLOT(raw_command_write(QByteArray)));
    connect(this, SIGNAL(update_internal_address(QString)),dc6, SLOT(internal_address_write(QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)),dc6, SLOT(data_received(QStringList)));
    connect(dc6, SIGNAL(call_ui_buttons(QString,bool)),this, SLOT(update_ui(QString,bool)));
    connect(conn, SIGNAL(get_command(QString)),dc6, SLOT(telemetry_call(QString)));
    ui->groupBox->layout()->addWidget(dc6);
    dc6->ID=6;
    dc6->name_section()->setText("HPLD 1000 6");

    dc7 = new dc_panel(this);
    connect(dc7, SIGNAL(send_command(QByteArray)),conn, SLOT(raw_command_write(QByteArray)));
    connect(this, SIGNAL(update_internal_address(QString)),dc7, SLOT(internal_address_write(QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)),dc7, SLOT(data_received(QStringList)));
    connect(dc7, SIGNAL(call_ui_buttons(QString,bool)),this, SLOT(update_ui(QString,bool)));
    connect(conn, SIGNAL(get_command(QString)),dc7, SLOT(telemetry_call(QString)));
    ui->groupBox->layout()->addWidget(dc7);
    dc7->ID=7;
    dc7->name_section()->setText("HPLD 1000 7");


    cb = new cb_panel(this);
    cb->ID=0;
    connect(cb, SIGNAL(send_command(QByteArray)),conn, SLOT(raw_command_write(QByteArray)));
    connect(this, SIGNAL(update_internal_address(QString)),cb, SLOT(internal_address_write(QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)),cb, SLOT(data_received(QStringList)));
    connect(cb, SIGNAL(call_ui_buttons(QString,bool)),this, SLOT(update_ui(QString,bool)));
    connect(conn, SIGNAL(get_command(QString)),cb, SLOT(telemetry_call(QString)));
    ui->groupBox->layout()->addWidget(cb);

    user = new user_panel(this);
    connect(user, SIGNAL(send_command(QByteArray)),conn, SLOT(raw_command_write(QByteArray)));
    connect(this, SIGNAL(update_internal_address(QString)),user, SLOT(internal_address_write(QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)),user, SLOT(data_received(QStringList)));
    connect(conn, SIGNAL(get_command(QString)),user, SLOT(telemetry_call(QString)));
    ui->groupBox->layout()->addWidget(user);
    user->ID=0;


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
    else if(name=="dc3")dc3_err=state;
    else if(name=="dc4")dc4_err=state;
    else if(name=="dc5")dc5_err=state;
    else if(name=="dc6")dc6_err=state;
    else if(name=="dc7")dc7_err=state;
    else if(name=="cb")cb_err=state;
    ui->pb_error_cleaner->setVisible(dc_err || dc1_err ||dc2_err ||dc3_err ||dc4_err ||dc5_err ||dc6_err ||dc7_err ||cb_err);
}


void MainWindow::on_connect_btn_clicked()
{
    emit send_connection_type(ui->serial_combo_box->currentData().toString(),404);
    ui->menu_button->setText("Настройки подключения");
    ui->stackedWidget->setCurrentIndex(0);
    if(conn->connected){
        conn->tmr->start();
        conn->tmr1->start();
    }
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
    cb->error_displayer=true;
}


void MainWindow::on_all_save_in_memory_clicked()
{
    ui->pb_error_cleaner->setVisible(false);
    QString message ="t"+ui->ip_adress_2->text()+"85200000000000000";
    emit send_command(message.toUtf8()+'\r');
}

