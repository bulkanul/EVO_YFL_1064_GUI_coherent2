#ifndef USER_PANEL_H
#define USER_PANEL_H

#include <QWidget>
#include <device_panel.h>

namespace Ui {
class user_panel;
}

class user_panel : public device_panel
{
    Q_OBJECT
public:
    explicit user_panel(QWidget *parent = nullptr);
    ~user_panel();

    QTimer* tmr;
    int auto_call=6;
    bool connection_lost=true;
    QString internal_address;

public slots:
    void key_catcher(QObject*);
    void internal_address_write(QString);
    void data_received_and_profed();

private slots:
    void on_on_off_button_clicked(bool checked);
    void indicate(double);
    void auto_telemetry_call();

signals:
    void sig_dis_enabled(QWidget*,bool);
    void send_message_window(QString,QString);
    void send_command(QByteArray);

private:
    Ui::user_panel *ui;
};

#endif // DC_PANEL_H
