#ifndef TEC_PANEL_H
#define TEC_PANEL_H

#include <QDialog>
#include <device_panel.h>

namespace Ui {
class tec_panel;
}

class tec_panel : public device_panel
{
    Q_OBJECT

public:
    explicit tec_panel(QWidget *parent = nullptr);
    ~tec_panel();

    QTimer* tmr;
    int auto_call=6;
    bool connection_lost=true;
    QString internal_address;
    bool first_call=true;
    QString family="tec";

public slots:
    void key_catcher(QObject*);
    void internal_address_write(QString);
    void data_received_and_profed();
    void send_pref();

private slots:
    void on_on_off_button_clicked(bool checked);
    void indicate(double);
    void telemetry_call(QString);

signals:
    void sig_dis_enabled(QWidget*,bool);
    void send_message_window(QString,QString);
    void send_command(QByteArray);
    void call_ui_buttons(QString,bool);
private:
    Ui::tec_panel *ui;
};

#endif // TEC_PANEL_H
