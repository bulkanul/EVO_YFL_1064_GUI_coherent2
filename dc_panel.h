#ifndef DC_PANEL_H
#define DC_PANEL_H

#include <QWidget>
#include <device_panel.h>


namespace Ui {
class dc_panel;
}

class dc_panel : public device_panel
{
    Q_OBJECT
public:
    explicit dc_panel(QWidget *parent = nullptr);
    ~dc_panel();

    QTimer* tmr;
    int auto_call=6;
    bool connection_lost=true;
    QString internal_address;
    bool first_call=true;
    QString family="dc";
    QStringList errors_dc_list={"flag_REBOOTED",
                                "flag_ALARM_INTERLOCK",
                                "flag_Overtemp",
                                "flag_OverCurrent",
                                "flag_UnderVoltage_IN",
                                "flag_OverVoltage_IN",
                                "flag_UnderVoltage_OUT",
                                "flag_OverCurrent_IND" };

public slots:
    void data_received(QString);
    void key_catcher(QObject*);
    void internal_address_write(QString);
    void data_received_and_profed();
    void send_pref();

private slots:
    void on_on_off_button_clicked(bool checked);
    void indicate(double);
    void telemetry_call(QString);
    void on_button_error_clicked();
    void update_pref();
    void on_mode_activated(int index);

signals:
    void sig_dis_enabled(QWidget*,bool);
    void send_message_window(QString,QString);
    void send_command(QByteArray);
    void call_ui_buttons(QString,bool);

private:
    Ui::dc_panel *ui;
};

#endif // DC_PANEL_H
