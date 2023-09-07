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
    QStringList errors_dc_list={"flag_REBOOTED",
                                "flag_ALARM_INTERLOCK",
                                "flag_Overtemp",
                                "flag_OverCurrent",
                                "flag_UnderVoltage_IN",
                                "flag_OverVoltage_IN",
                                "flag_UnderVoltage_OUT",
                                "flag_OverCurrent_IND" };
    QStringList panel_state;

    double get_current();
    void set_current(double value);

    void setTitle(QString postfix);

    bool get_check_state();

public slots:
    void data_received_and_profed();
    void key_catcher(QObject*);
    void enable_selected(bool);

private slots:
    void on_on_off_button_clicked(bool checked);
    void on_mode_currentIndexChanged(int index);
    void indicate(double);
    void indicate_temp(double);
    void on_button_error_clicked();

signals:
    void send_message_window(QString,QString);
    void sig_usr_changes(QString,int);
private:
    Ui::dc_panel *ui;
};

#endif // DC_PANEL_H
