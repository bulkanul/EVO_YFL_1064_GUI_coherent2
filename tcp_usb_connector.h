#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QNetworkProxy>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QSettings>
#include <QFile>
#include <QTimer>

class tcp_usb_connector: public QObject
{
    Q_OBJECT

public:
    tcp_usb_connector();
    void update_tcp_socket();
    void update_serial_socket();
    QTcpSocket* _pSocket=nullptr;
    QSerialPort* _sSocket=nullptr;

    QString sketched_message;
    QByteArray sketch;
    QString pref_identificator="";
    QString board_identificator="";

    QString ip="";
    int port=0;
    int finded=0;
    int standart_delay=50;

    QString serial="";
    bool first_set_write=true;
    bool logg=false;
    bool stop_search=false;

    bool start_finding=false;

    int count=60;
    int pool_count=0;
    bool connection_is_tcp=true;
    bool reconnect=true;
    bool no_reconnect_by_dev=false;
    bool connected=false;
    QStringList raw_params;
    bool double_caller=false;
//    QStringList fifo_command;
    QByteArrayList crupto_fifo_command;
    QStringList fifo_searcher;
    QList<int> fifo_finder;
    bool version_protection =true;
    QTimer* tmr;
    QTimer* tmr1;
//    bool crypto=true;
    bool crypto_version_controller=true;

    QStringList dev_list={"dc0","tec0","tec1","cb","usr"};

signals:
    void send_to_dev(QStringList);
    void send_to_dev(QByteArray);
    void err_changes(QString,int,int);
    void send_to_amplifaer(QStringList);
    void send_to_resonator(QStringList);
    void send_to_user(QStringList);
    void connection_state(bool);
    void version_failed();
    void send_device_list(QList<int>);
    void version_error(QString);
    void sig_usr_changes(QString,int);
    void start_timer(QString);
    void get_command(QString);

public slots:
    void data_received();
    void data_write(QString,int,QString);
    void data_write(int,int,QString);
    void raw_command_write(QByteArray);
    void data_ver_write(QString);
    void sender();
    void init_connection(QString,int);
    QStringList double_localizator(QByteArray);
    QString params(int);
    void display_reconnect();
    void display_connected();
    void display_disconnected();

    void tcp_connect(QString,int);
    void tcp_reconnect();
    void tcp_disconnect();

    void serial_connect(QString);
    void serial_set_prefs(QString);
    void serial_reconnect();
    void serial_handle_error(QSerialPort::SerialPortError error);
    void serial_disconnect();
    void change_timer_delay(int);
    void get_command_pool();
};

#endif // CONNECTOR_H
