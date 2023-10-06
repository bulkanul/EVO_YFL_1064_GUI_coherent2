#include "tcp_usb_connector.h"
#include <QThread>
#include <qtimer.h>

//tcp_usb_connector::~tcp_usb_connector()
//{
//    tcp_disconnect();
//}

tcp_usb_connector::tcp_usb_connector()
{
    tmr=new QTimer();
    tmr->setInterval(50);
    connect(tmr,SIGNAL(timeout()),this,SLOT(sender()));
}
void tcp_usb_connector::serial_set_prefs(QString serial_port)
{
    _sSocket->setPortName(serial_port);
    _sSocket->setBaudRate(115200);
    _sSocket->setDataBits( QSerialPort::Data8);
    _sSocket->setFlowControl(QSerialPort::NoFlowControl);
    _sSocket->setStopBits(QSerialPort::OneStop);
    _sSocket->setParity(QSerialPort::NoParity);
}

void tcp_usb_connector::serial_connect(QString serial_port)
{
    if(_sSocket)delete(_sSocket);
    this->serial=serial_port;
    _sSocket = new QSerialPort;
    serial_set_prefs(serial_port);
    connect(_sSocket,SIGNAL(readyRead()),this,SLOT(data_received()));
    connect(_sSocket,SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(serial_handle_error(QSerialPort::SerialPortError)));

    _sSocket->flush();
    if (_sSocket->open(QIODevice::ReadWrite))
    {
        _sSocket->flush();
        _sSocket->clear(QSerialPort::AllDirections);
        qDebug("serial port is opened SUCCESSFULLY");
    }
}

void tcp_usb_connector::serial_reconnect(void)
{
    _sSocket->close();
    qDebug("serial port DISONNECTED by soft");
    serial_connect(serial);
}

void tcp_usb_connector::serial_disconnect(void)
{
    _sSocket->close();
    // ui->l_footer_connection_status->setText("Состояние: ОТКЛЮЧЕНО");
}

void tcp_usb_connector::serial_handle_error(QSerialPort::SerialPortError error)
{
    if ( (_sSocket->isOpen()) && (error == QSerialPort::ResourceError))
    {
        _sSocket->close();
//        interface_enabled(false);
//        ui->l_footer_connection_status->setText("Состояние: ОТКЛЮЧЕНО ИЗ-ЗА ОШИБКИ");
        qDebug("serial port DISONNECTED by error"+ error);
    }
}

void tcp_usb_connector::update_serial_socket(){
    _sSocket = new QSerialPort();
    connect(_sSocket,SIGNAL(readyRead()),this,SLOT(data_received()));
    connect(_sSocket, SIGNAL(connected()),this, SLOT(display_connected()));
    connect(_sSocket,SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(serial_handle_error(QSerialPort::SerialPortError))); // подключаем проверку ошибок порта
}


void tcp_usb_connector::update_tcp_socket(){
    _pSocket = new QTcpSocket();
    connect(_pSocket, SIGNAL(connected()),this, SLOT(display_connected()));
    connect(_pSocket, SIGNAL(disconnected()),this, SLOT(display_disconnected()));
    connect(_pSocket, SIGNAL(readyRead()),this, SLOT(data_received()));
}

void tcp_usb_connector::tcp_connect(QString ip,int port)
{
    this->ip=ip;
    this->port=port;
    qDebug() << "connecting to " +ip+":"+ QString::number(port);
    update_tcp_socket();
    _pSocket->setProxy(QNetworkProxy::NoProxy);
    _pSocket->connectToHost(ip, quint16(port));
}

void tcp_usb_connector::tcp_reconnect(void)
{
    if(reconnect){
        qDebug() << "tcp reconnecting ";
        emit connection_state(2);
        _pSocket->abort();//something
        _pSocket->setProxy(QNetworkProxy::NoProxy);
        _pSocket->connectToHost(ip, quint16(port));
    }
}

void tcp_usb_connector::tcp_disconnect(void)
{
    reconnect=true;
    // _pSocket->abort();
    _pSocket->close();
}


void tcp_usb_connector::data_write(QString command,int number,QString data){
    QString message;
    if (command.contains("lg_") || command.contains("ls_")) // debug only
        fifo_command.append(command); //debug only
    else{
        message= command+" "+QString::number(number)+" "+data;
        fifo_command.append(message);
    }
    //qDebug()<<"fifo add "+command;
}

void tcp_usb_connector::data_ver_write(QString command)
{
     fifo_command.append("l"+command.toUtf8());
     //qDebug()<<"fifo add "+command;
}

void tcp_usb_connector::sender()
{
    count++;
    // qDebug() << "fifo length: " << fifo_command.length();
    if(logg)qDebug()<<"count "<<count;
    if(count>60){
        if(fifo_command.length()>0)fifo_command.removeFirst();
        data_ver_write("gvers");
        display_reconnect();
    }
    if(fifo_command.length()>100){
        qDebug() << "danger overfull";
        fifo_command.clear();
    }
    if(fifo_command.length()>0){
        if(connection_is_tcp){
            if(_pSocket->isOpen()&&_pSocket->isWritable()){
            if(connected){
                if(!version_protection || fifo_command[0].contains("gvers"))_pSocket->write(fifo_command[0].toUtf8()+'\r'+'\n');
                if(logg)qDebug()<<"socket send "<<fifo_command[0].toUtf8();
            }else{
                if(logg)qDebug()<<"socket not";
            }
//            if(fifo_command.length()>=1)fifo_command.removeFirst();
            }
        }else{
            if(_sSocket->isOpen()&&_sSocket->isWritable()){
                if(logg)qDebug()<<"socket s is work";
                if(!version_protection || fifo_command[0].contains("gvers"))_sSocket->write(fifo_command[0].toUtf8()+'\r'+'\n');
                if(logg)qDebug()<<"socket send "<<fifo_command[0].toUtf8();
            }
        }
        if(fifo_command.length()>0){
            //qDebug()<<"fifo removed"<<fifo_command.length();
            fifo_command.removeFirst();
        }
        //qDebug()<<"fifo length "<<fifo_command.length();
    }
}

void tcp_usb_connector::init_connection(QString adress, int port)
{
    first_set_write=true;
//    qDebug()<<_sSocket->objectName()<<_pSocket->objectName();
    if(_sSocket!=nullptr)_sSocket->close();
    if(_pSocket!=nullptr)_pSocket->abort();
    if(port==404){
        serial_connect(adress);
        connection_is_tcp=false;
    }else{
        tcp_connect(adress,port);
        connection_is_tcp=true;
    }
    tmr->stop();
    tmr->start();
}

void tcp_usb_connector::data_received(){
    QByteArray data;
    if(double_caller){
        raw_params=double_localizator(sketched_message.toUtf8());
    }else{
        if(connection_is_tcp){
            do{
                int bytes = _pSocket->bytesAvailable();
                data = _pSocket->readLine();
                // qDebug() << data.count() << "vs" << bytes;
                raw_params=double_localizator(data);
            }while(_pSocket->bytesAvailable() != 0);
        }
        else{
            do{
                int bytes = _sSocket->bytesAvailable();
                data = _sSocket->readLine();
                qDebug() << data.count() << "vs" << bytes;
                raw_params=double_localizator(data);
            }while(_sSocket->bytesAvailable() != 0);
        }
    }
    if(raw_params.size()>=1){
        if(first_set_write){
         qDebug() << "saved"<<connection_is_tcp<<ip<<serial;
         QSettings settings(QString("configs/config.ini"), QSettings::IniFormat);
         settings.setValue("prev_connection",connection_is_tcp);
         settings.setValue("prev_ip",ip);
         settings.setValue("prev_port",serial);
         first_set_write=false;
        }
        count=0;
        if(params(0)=="lrvers"){
            if(params(1)!=(PROTOCOL_VERSION_NAME)){
                emit version_error();
            }else{
                version_protection=false;
                fifo_command.clear();
            }
        }
        if(logg)qDebug()<<"sl_data_readed "<<raw_params;

        if(params(3).indexOf("ERR")!=0 && !version_protection){
                emit send_to_dev(raw_params);
        }
        emit connection_state(1);
    }
}

QStringList tcp_usb_connector::double_localizator(QByteArray data){
    if(QString::fromStdString(data.toStdString()).indexOf("\r")<0){
        sketch.append(data);
        return QStringList("\r error");
    }else{
        sketch.append(data);
        QString raw_command = QString::fromStdString(sketch.toStdString());
        sketch.clear();
        if(raw_command.count("\r")>1){
            QString temp_string=raw_command;
            for(int i =0;i<raw_command.count("\r");i++){
                double_caller=true;
                sketched_message=temp_string.left(temp_string.indexOf("\r")+1);
                temp_string=temp_string.right(temp_string.length()-temp_string.indexOf("\r")-1);
                data_received();
            }
            return QStringList("error unknown");
        }else{
            double_caller=false;
//            if(raw_command.lastIndexOf("lr")>=0){
                QStringList list;
                if(raw_command.lastIndexOf("lrerrclr")==0){
                    list =  raw_command.right(raw_command.length()
                                      - raw_command.indexOf("lr")).left(raw_command.indexOf("\r")).split(" ");
                }else{
                    list = raw_command.right(raw_command.length() - raw_command.lastIndexOf("lr")).left(raw_command.indexOf("\r")).split(" ");
                }
                for(int i=0; i<list.length();i++){
                   list[i].replace(",",".");
                }
                list.last().remove("\r");
                qDebug()<<"filtred "<<list;
                return list ;
        }
    }
}

QString tcp_usb_connector::params(int number){
    if(raw_params.length()>number){
        return raw_params[number];
    }else{
        return "N/A";
    }
}

void tcp_usb_connector::display_reconnect()
{
    version_protection=true;
    if(count%100==0){
        emit connection_state(2);
        if(connection_is_tcp){
            tcp_reconnect();
        }else{
            serial_reconnect();
        }
    }
}

void tcp_usb_connector::display_connected()
{
    connected=true;
    emit connection_state(1);
    count=0;
}

void tcp_usb_connector::display_disconnected()
{
    connected=false;
    emit connection_state(0);
    if(count>30){
         display_reconnect();
    }
}
