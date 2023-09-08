#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dc_panel.h"
#include "generator_panel.h"
#include "general_panel.h"
#include "channel_panel.h"
#include "tcp_usb_connector.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    channel_panel* chan1;
    channel_panel* chan2;
    channel_panel* chan3;
    channel_panel* chan4;
    channel_panel* chan5;

    generator_panel* gen;

    general_panel* general;

    tcp_usb_connector *conn;
    QString serial_port;
    bool light_state[7]={0,0,0,0,0,0,0};

    int user_pass=0;
    int admin_pass=0;
    QString pass;
    bool user_ui=false;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void change_interface(QString,int);

    void pass_controller(QKeyEvent *keyEvent);

signals:
    void set_conn_params(QString,int);

    void send_command(QString,int,QString);

    void pass_event(QKeyEvent *keyEvent);

private slots:
    void on_menu_button_clicked();

    void on_refresh_ports_clicked();

    void on_pushButton_clicked();

    void version_conflict();

    void on_pb_error_cleaner_clicked();

    void on_all_reset_1_clicked();

    void on_all_save_seed_clicked();

    void on_all_restore_seed_clicked();

    void on_all_save_in_memory_clicked();

    void connection_state(int);

    void on_menu_main_clicked();

    void on_disconnect_clicked();

private:
    Ui::MainWindow *ui;

protected:
    bool eventFilter(QObject *target, QEvent *event) override;
};
#endif // MAINWINDOW_H
