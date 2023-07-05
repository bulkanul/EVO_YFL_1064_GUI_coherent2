#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    conn = new tcp_usb_connector();
    connect(this,SIGNAL(set_conn_params(QString,int)),conn,SLOT(init_connection(QString,int)));
    connect(conn,SIGNAL(version_error()),this,SLOT(version_conflict()));
    connect(this, SIGNAL(send_command(QString,int,QString)),conn, SLOT(data_write(QString,int,QString)));
    connect(conn,SIGNAL(connection_state(int)),this,SLOT(connection_state(int)));


    dc = new dc_panel(this);
    ui->groupBox->layout()->addWidget(dc);
    dc1 = new dc_panel(this);
    ui->groupBox->layout()->addWidget(dc1);
    dc2 = new dc_panel(this);
    ui->groupBox->layout()->addWidget(dc2);

    cb = new cb_panel(this);
    cb->ID=0;
//    cb->enable_widget(false);
    ui->groupBox->layout()->addWidget(cb);
    connect(cb, SIGNAL(send_command(QString,int,QString)),conn, SLOT(data_write(QString,int,QString)));
    connect(cb, SIGNAL(sig_usr_changes(QString,int)),this, SLOT(change_interface(QString,int)));
    connect(conn, SIGNAL(send_to_dev(QStringList)),cb, SLOT(data_received(QStringList)));
//    dc1 = new dc_panel(this);
//    dc1->ID=1;
//    dc1->enable_widget(false);
//    ui->groupBox->layout()->addWidget(dc1);
//    connect(dc1, SIGNAL(send_command(QString,int,QString)),conn, SLOT(data_write(QString,int,QString)));
//    connect(dc1, SIGNAL(sig_usr_changes(QString,int)),this, SLOT(change_interface(QString,int)));
//    connect(conn, SIGNAL(send_to_dev(QStringList)),dc1, SLOT(data_received(QStringList)));

//    dc2 = new dc_panel(this);
//    dc2->ID=2;
//    dc2->enable_widget(false);
//    ui->groupBox->layout()->addWidget(dc2);
//    connect(dc2, SIGNAL(send_command(QString,int,QString)),conn, SLOT(data_write(QString,int,QString)));
//    connect(dc2, SIGNAL(sig_usr_changes(QString,int)),this, SLOT(change_interface(QString,int)));
//    connect(conn, SIGNAL(send_to_dev(QStringList)),dc2, SLOT(data_received(QStringList)));
//    user = new user_panel(this);
//    user->ID=0;
//    user->enable_widget(false);
//    ui->groupBox->layout()->addWidget(user);
//    connect(user, SIGNAL(send_command(QString,int,QString)),conn, SLOT(data_write(QString,int,QString)));
//    connect(user, SIGNAL(sig_usr_changes(QString,int)),this, SLOT(change_interface(QString,int)));
//    connect(conn, SIGNAL(send_to_dev(QStringList)),user, SLOT(data_received(QStringList)));


//    QSettings settings(QString("configs/config.ini"), QSettings::IniFormat);
//    if(settings.value("prev_connection").toString()!=""){
//        qDebug() <<"saved writed"
//                 <<settings.value("prev_connection").toString()
//                 <<settings.value("prev_ip").toString()
//                 <<settings.value("prev_port").toString();
//        conn->connection_is_tcp=settings.value("prev_connection").toString()=="TCP";

//        if(settings.value("prev_ip").toString()!=""){
//            ui->ip_adress->setText(settings.value("prev_ip").toString());
//            conn->ip=settings.value("prev_ip").toString();
//        }

//        conn->serial=settings.value("prev_port").toString();
//        if(settings.value("prev_connection").toString()=="true"){
//            ui->rb_tcp->setChecked(true);
//        }else{
//            ui->rb_serial->setChecked(true);
//            on_refresh_ports_clicked();
//        }
//        QThread::msleep(100);
//        on_pushButton_clicked();
//    }
//    installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

