#include "tcp_usb_connector.h"

#include <QTime>
#include <qtimer.h>

tcp_usb_connector::tcp_usb_connector()
{
    tmr=new QTimer();
    tmr->setInterval(standart_delay);
    connect(tmr,SIGNAL(timeout()),this,SLOT(sender()));

    tmr1=new QTimer();
    tmr1->setInterval(standart_delay+standart_delay/2);
    connect(tmr1,SIGNAL(timeout()),this,SLOT(get_command_pool()));
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
    emit start_timer(pref_identificator);
//    tmr->stop();
//    tmr->start();
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
        display_connected();
            emit raw_command_write(QString("O").toUtf8()+'\r');
            emit raw_command_write(QString("S6").toUtf8()+'\r');
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
    //    ui->l_footer_connection_status->setText("Состояние: ОТКЛЮЧЕНО");
}

void tcp_usb_connector::change_timer_delay(int delay)
{
    if(tmr->interval()!=delay){
//        tmr->setInterval(delay);
        if(logg)qDebug()<<"now delay is "<< delay;
    }
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
    if(logg)qDebug() << "connecting to " +ip+":"+ QString::number(port);
    update_tcp_socket();
    _pSocket->setProxy(QNetworkProxy::NoProxy);
    _pSocket->connectToHost(ip, quint16(port));
}

void tcp_usb_connector::tcp_reconnect(void)
{
    if(reconnect){
        if(logg)qDebug() << "tcp reconnecting ";
        emit connection_state(1);
        update_tcp_socket();
        _pSocket->abort();//something
        _pSocket->setProxy(QNetworkProxy::NoProxy);
        _pSocket->connectToHost(ip, quint16(port));
    }
}

void tcp_usb_connector::tcp_disconnect(void)
{
    _pSocket->abort();
}
void tcp_usb_connector::data_write(int command,int number,QString data){
    QString message;
    if(data=="404"){
        message=QString("%1").arg(command, 2, 16, QLatin1Char( '0' ));
        crupto_fifo_command.append(message.toUtf8());
    }else{
        message="t"+QString("%1").arg(number, 3, 16, QLatin1Char( '0' ))+"8"+QString("%1").arg(command, 2, 16, QLatin1Char( '0' ))+QString("%1").arg(data.toInt(), 14, 16, QLatin1Char('0'));
        crupto_fifo_command.append(message.toUtf8());
    }
    if(logg)qDebug()<<"fifo add data_write"+message;
}

void tcp_usb_connector::data_write(QString command,int number,QString data){
    QString message;
    message= command+" "+QString::number(number)+" "+data;
    if(crypto_version_controller){
        QByteArray temp;
        foreach(QChar c,message){
            temp.append(c.unicode()+100);
        }
        crupto_fifo_command.append(temp);
        if(logg)qDebug()<<"fifo add "+pref_identificator+" "+temp;
    }else{
        crupto_fifo_command.append(message.toUtf8());
        if(logg)qDebug()<<"fifo add "+pref_identificator+" "+message;

    }
}

void tcp_usb_connector::raw_command_write(QByteArray cmd)
{
    qDebug()<<"fifo add raw "<<pref_identificator<<cmd;
    crupto_fifo_command.append(cmd);
}

void tcp_usb_connector::data_ver_write(QString command)
{
//     fifo_command.append("l"+command.toUtf8());
    QString message ="l"+command;
    QByteArray temp;
    foreach(QChar c,message){
        temp.append(c.unicode()+100);
    }
    crupto_fifo_command.append(temp);
    if(logg)qDebug()<<"fifo add "<<pref_identificator<<message;
}

void tcp_usb_connector::sender()
{
    count++;

    QByteArray temp;
    if(crypto_version_controller){
        if(count>20){
            if(crupto_fifo_command.length()>0)crupto_fifo_command.removeFirst();
            data_ver_write("gvers");
            display_reconnect();
        }
        if(logg)qDebug()<<"version_protection "<<version_protection;
        if(crupto_fifo_command.length()!=0)change_timer_delay(crupto_fifo_command.length()>10?standart_delay*10/crupto_fifo_command.length():standart_delay);
        QString findmessage="gvers";
        foreach(QChar c,findmessage){
            temp.append(c.unicode()+100);
        }
    }else{
        if(!no_reconnect_by_dev && count>20)display_reconnect();
    }
//    if(logg)qDebug()<<"fifo add "<<pref_identificator<<crupto_fifo_command;
    if(crupto_fifo_command.length()>0){
        if(connection_is_tcp){
            if(_pSocket->isOpen()&&_pSocket->isWritable()){
                if(connected){
                    if(crypto_version_controller){
                        if(!version_protection || crupto_fifo_command[0].contains(temp)){
                            _pSocket->write(crupto_fifo_command[0]+'q'+'n');
                            if(logg)qDebug()<<"socket send "<<crupto_fifo_command[0]+'q'+'n';
                        }else{
                           if(logg)qDebug()<<"socket send "<<"gvers";
                        }
                    }else{
                        _pSocket->write(crupto_fifo_command[0]+'\r'+'\n');
                        if(logg)qDebug()<<"socket send "<<crupto_fifo_command[0]+'\r'+'\n';
                    }
                }else{
                    if(logg)qDebug()<<"socket not";
                }
                if(crupto_fifo_command.length()>0){
                    if(logg)qDebug()<<"fifo removed"<<crupto_fifo_command.length();
                    crupto_fifo_command.removeFirst();
                }
            }
        }else{
            if(_sSocket->isOpen()&&_sSocket->isWritable()){
                if(connected){
                    if(crypto_version_controller){
                        if(!version_protection || crupto_fifo_command[0].contains(temp)){
                            _sSocket->write(crupto_fifo_command[0]+'q'+'n');
                            if(logg)qDebug()<<"socket s send "<<crupto_fifo_command[0];
                        }else{
                            if(logg)qDebug()<<"socket s send "<<"gvers";
                        }
                    }else{
                        _sSocket->write(crupto_fifo_command[0]);
                        if(logg)qDebug()<<"socket s send "<<crupto_fifo_command[0];
                    }
                }else{
                    if(logg)qDebug()<<"socket not";
                }
                if(crupto_fifo_command.length()>0){
                    if(logg)qDebug()<<"fifo removed"<<crupto_fifo_command.length();
                    crupto_fifo_command.removeFirst();
                }
                if(logg)qDebug()<<"fifo length "<<crupto_fifo_command.length();
            }
        }
    }
}


void tcp_usb_connector::get_command_pool()
{
   pool_count++;
   if(logg)qDebug()<<"sender count "<<count<<pool_count<<crupto_fifo_command.length();
   emit get_command(dev_list[pool_count%5]);

}

void tcp_usb_connector::data_received(){
    if(logg)qDebug()<<"data_received";
    QByteArray data;
    if(double_caller){
        raw_params=double_localizator(sketched_message.toUtf8());
    }else{
        if(connection_is_tcp){
            while(_pSocket->bytesAvailable()){
                if(crypto_version_controller){
                    QByteArray temp;
                    foreach(QChar c,_pSocket->readLine()){
                        temp.append(c.unicode()-100);
                    }
                    data += temp;
                }else{
                   data =_pSocket->readLine();
                }
            }
        }else{
            while(_sSocket->bytesAvailable()){
                if(crypto_version_controller){
                    QByteArray temp;
                    foreach(QChar c,_sSocket->readLine()){
                        temp.append(c.unicode()-100);
                    }
                    data += temp;
                }else{
                    data =_sSocket->readLine();
                 }
            }
        }
        raw_params=double_localizator(data);
    }
    if(raw_params.size()>=1){
        if(first_set_write){
            qDebug() << "saved"<<connection_is_tcp<<ip<<serial;
            QSettings settings(QString("configs/config.ini"), QSettings::IniFormat);
            settings.setValue("prev_connection",serial);
            first_set_write=false;
        }
        count=0;
        if(logg)qDebug()<<"sl_data_readed "<<pref_identificator<<raw_params;
        if(crypto_version_controller){
            if(!version_protection){
                if(params(3).indexOf("ERR")!=0){
                    emit send_to_dev(raw_params);
                    emit sig_usr_changes("l_footer_connection_status",1);
                }else{
                    err_changes(params(1),params(2).toInt(),params(3)=="ERR");
                }
            }
        }else{
            emit send_to_dev(raw_params);
        }

        emit connection_state(false);
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
                                      - raw_command.indexOf("t")).left(raw_command.indexOf("\r")).split(" ");
                }else{
                    list = raw_command.right(raw_command.length() - raw_command.lastIndexOf("t")).left(raw_command.indexOf("\r")).split(" ");
                }
                for(int i=0; i<list.length();i++){
                   list[i].replace(",",".");
                }
                list.last().remove("\r");
//                qDebug()<<"filtred "<<list;
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
    if(count%50==0){
        emit connection_state(true);
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
//    emit connection_state(0);
    count=0;
}

void tcp_usb_connector::display_disconnected()
{
    connected=false;
//    emit connection_state(1);
    if(count>30){
         display_reconnect();
    }
}
