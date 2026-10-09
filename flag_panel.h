#ifndef FLAG_PANEL_H
#define FLAG_PANEL_H

#include <QWidget>
#include <QSet>
#include "device_panel.h"

namespace Ui {
class flag_panel;
}

class flag_panel : public device_panel
{
    Q_OBJECT
    QStringList errors_list={
                            "ALARM_INTERLOCK_1",
                            "ALARM_INTERLOCK_2",
                            "ALARM_EMERGENCY",
                            "ALARM_KEYLOCK",
                            "ALARM_PHASE_NOT_OK",
                            "ALARM_STOP"
    };

public:
    explicit flag_panel(QWidget *parent = nullptr);

    ~flag_panel();
    void setCommunicationError(const QString &unit, bool active);

private slots:
    void data_received_and_profed();
    void on_pushButton_clicked();
    void on_pushButton_init_clicked();
    void on_pb_stop_onoff_clicked(bool checked);

private:
    void refreshErrorState();
    Ui::flag_panel *ui;
    int alarm_count = 0;
    QStringList device_alarms;
    QStringList active_alarms;
    QSet<QString> communication_errors;
};

#endif // FLAG_PANEL_H
