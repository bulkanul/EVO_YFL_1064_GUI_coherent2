#ifndef CB_PANEL_H
#define CB_PANEL_H
#include <QWidget>
#include <device_panel.h>

namespace Ui {
class cb_panel;
}
class cb_panel : public device_panel
{
    Q_OBJECT
public:
    explicit cb_panel(QWidget *parent = nullptr);
    ~cb_panel();
    QStringList panel_state;
    QTimer* tmr;
    int auto_call=6;
    bool connection_lost=true;
    QList <QLabel*> labels;
    QStringList commands;
    QStringList commands_send;
    QStringList command_setter;
    QStringList errors_cb_list={"Backward_fault_0",
                                "Forward_fault_0",
                                "Backward_fault_1",
                                "Forward_fault_1",
                                "Interlock_L_ok_H_bad",
                                "Sys_overheat",
                                "Internal ERROR",
                                "Internal ERROR" };
    QStringList errors_dc_list={"flag_REBOOTED",
                                "flag_ALARM_INTERLOCK",
                                "flag_Overtemp",
                                "flag_OverCurrent",
                                "flag_UnderVoltage_IN",
                                "flag_OverVoltage_IN",
                                "flag_UnderVoltage_OUT",
                                "flag_OverCurrent_IND" };
    uint cbErrorHex=0;
    uint dc1ErrorHex=0;
    uint dc2ErrorHex=0;
public slots:
    void data_received_and_profed();
    void key_catcher(QObject*);
    void internal_address_write(QString);
    void telemetry_call(QString);
    void get_pref();
private slots:
     void on_button_error_clicked();
signals:
    void send_message_window(QString,QString);
    void call_ui_buttons(QString,bool);
private:
    QString prepare_str(int value);
    Ui::cb_panel *ui;
};
#endif // DC_PANEL_H
