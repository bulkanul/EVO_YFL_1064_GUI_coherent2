#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <cb_panel.h>
#include <dc_panel.h>
#include "device_panel.h"
#include <tcp_usb_connector.h>
#include <user_panel.h>
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
    cb_panel *cb;
    user_panel *user;
    tcp_usb_connector *conn;
    bool dc_err=false;
    bool dc1_err=false;
    bool cb_err=false;
signals:
    void send_connection_type(QString,int);
    void update_internal_address(QString);
    void send_command(QByteArray);
public slots:
    void update_ui(QString,bool);
private slots:
    void on_connect_btn_clicked();
    void on_menu_button_clicked();
    void on_refresh_ports_clicked();
    void on_ip_adress_2_editingFinished();
    void on_pb_error_cleaner_clicked();

    void on_all_save_in_memory_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
