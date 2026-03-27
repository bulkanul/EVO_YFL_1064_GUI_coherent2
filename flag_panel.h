#ifndef FLAG_PANEL_H
#define FLAG_PANEL_H

#include <QWidget>
#include "device_panel.h"

namespace Ui {
class flag_panel;
}

class flag_panel : public device_panel
{
    Q_OBJECT
    QStringList errors_list={
                            "ALARM_PHASE_NOT_OK",
                            "ALARM_EMERGENCY",
                            "ALARM_KEYLOCK",
                            "ALARM_INTERLOCK_1",
                            "ALARM_INTERLOCK_2",
                            "ALARM_STOP"
    };

public:
    explicit flag_panel(QWidget *parent = nullptr);

    ~flag_panel();

private slots:
    void data_received_and_profed();
    void on_pushButton_clicked();
    void on_pushButton_init_clicked();
    void on_pb_stop_onoff_clicked(bool checked);

signals:
    void sig_usr_critical_error(bool show_clear_btn);

private:
    Ui::flag_panel *ui;
    int error_code;
};

#endif // FLAG_PANEL_H
