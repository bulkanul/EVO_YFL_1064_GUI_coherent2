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

#define PROTOCOL_VERSION_NAME "1_5kW_coherent_system_main_control_board06092023"

class tcp_usb_connector: public QObject
{
    Q_OBJECT

public:
    // ~tcp_usb_connector();
    tcp_usb_connector();
    void update_tcp_socket();
    void update_serial_socket();
    QTcpSocket* _pSocket=nullptr;
    QSerialPort* _sSocket=nullptr;

    QString sketched_message;
    QByteArray sketch;

    QString ip="";
    int port=0;
    int finded=0;

    QString serial="";
    bool first_set_write=true;
    bool logg=false;
    bool stop_search=false;

    bool start_finding=false;

    int count=60;
    bool connection_is_tcp=true;
    bool reconnect=true;
    bool connected=false;
    QStringList raw_params;
    bool double_caller=false;
    QStringList fifo_command;
    QStringList fifo_searcher;
//    QStringList fifo_finder;
    QList<int> fifo_finder;
    bool version_protection =true;
    int standart_delay=12;
    int pool_count=0;
    QTimer* tmr;
    // QStringList dev_list={"sns0","snscw0","tec0","dc0","usr0"};
    QStringList dev_list={"gen0",
                          "preamp0","preamp1","preamp2","preamp3","preamp4",
                          "allpreamp0",
                          "amp0","amp1","amp2","amp3","amp4",
                          "allamp0",
                          "usr0",
                          "div0"};
    QTimer* tmr1;
signals:
    void send_to_dev(QStringList);
    void send_to_amplifaer(QStringList);
    void send_to_resonator(QStringList);
    void send_to_user(QStringList);
    void connection_state(int);
    void version_failed();
    void send_device_list(QList<int>);
    void version_error();
    void get_command(QString);

public slots:
    void data_received();
    void data_write(QString,int,QString);
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
    void get_command_pool();
};

#endif // CONNECTOR_H
