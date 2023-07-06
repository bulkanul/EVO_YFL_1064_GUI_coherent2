#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cb_panel.h>
#include <dc_panel.h>
#include "device_panel.h"
#include <tcp_usb_connector.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    dc_panel *dc;
    dc_panel *dc1;
    dc_panel *dc2;
    cb_panel *cb;
    tcp_usb_connector *conn;
    static QString internal_address;
signals:
    void send_connection_type(QString,int);
    void update_internal_address(QString);
private slots:
    void on_connect_btn_clicked();
    void on_menu_button_clicked();

    void on_refresh_ports_clicked();

    void on_ip_adress_2_editingFinished();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
