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


#define PROTOCOL_VERSION_NAME "EVO_YFL_1064_FW Main_board_03022026"

// 0 = auto telemetry OFF (commands only when you send manually)
// 1 = auto telemetry ON (lgstatus, lgonoff etc. by timer)
#define AUTO_TELEMETRY_ENABLED 1

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
    QList<int> fifo_finder;
    bool version_protection =true;
    int standart_delay=30;
    int pool_count=0;
    QTimer* tmr;
    QStringList dev_list={"gen0",
                          "preamp0","preamp1","preamp2","preamp3",
                          "allpreamp0",
                          "amp0","amp1","amp2","amp3",
                          "allamp0",
                          "usr0"};
    QTimer* tmr1;
signals:
    void send_to_dev(QStringList);
    void send_to_amplifaer(QStringList);
    void send_to_resonator(QStringList);
    void send_to_user(QStringList);
    void connection_state(int);
    void connection_timeout();
    void version_failed();
    void send_device_list(QList<int>);
    void version_error();
    void get_command(QString);
    void ip_received(QString ip);
    void mac_received(QString mac);
    void hash_received(QString hash);
    void network_info_received(QString type, QString value);

public slots:
    void data_received();
    void data_write(QString,int,QString);
    void data_common_write(QString command, QString args = "");
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
    void request_status_manual();  // manual status request (when AUTO_TELEMETRY_ENABLED=0)
    void request_version_manual();  // manual lgvers (when AUTO_TELEMETRY_ENABLED=0)
};

#endif // CONNECTOR_H
