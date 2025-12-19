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

    tec1 = new tec_panel(this);
    connect(tec1, SIGNAL(send_command(QByteArray)),conn, SLOT(raw_command_write(QByteArray)));
    connect(this, SIGNAL(update_internal_address(QString)),tec1, SLOT(internal_address_write(QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)),tec1, SLOT(data_received(QStringList)));
    connect(tec1, SIGNAL(call_ui_buttons(QString,bool)),this, SLOT(update_ui(QString,bool)));
    connect(conn, SIGNAL(get_command(QString)),tec1, SLOT(telemetry_call(QString)));
    ui->groupBox->layout()->addWidget(tec1);
    tec1->ID=0;

    tec2 = new tec_panel(this);
    connect(tec2, SIGNAL(send_command(QByteArray)),conn, SLOT(raw_command_write(QByteArray)));
    connect(this, SIGNAL(update_internal_address(QString)),tec2, SLOT(internal_address_write(QString)));
    connect(conn, SIGNAL(send_to_dev(QStringList)),tec2, SLOT(data_received(QStringList)));
    connect(tec2, SIGNAL(call_ui_buttons(QString,bool)),this, SLOT(update_ui(QString,bool)));
    connect(conn, SIGNAL(get_command(QString)),tec2, SLOT(telemetry_call(QString)));
    ui->groupBox->layout()->addWidget(tec2);
    tec2->ID=1;

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
    else if(name=="cb")cb_err=state;
    ui->pb_error_cleaner->setVisible(dc_err || cb_err);
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

