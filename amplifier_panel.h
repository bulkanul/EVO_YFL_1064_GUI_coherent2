#ifndef AMPLIFIER_PANEL_H
#define AMPLIFIER_PANEL_H

#include <QWidget>
#include "device_panel.h"

namespace Ui {
class amplifier;
}

class amplifier_panel : public device_panel
{
    Q_OBJECT

QStringList errors_list={"Backward PD 0",
                         "Forward PD 0",
                         "N\\A",
                         "QBH fault",
                         "N\\A",
                         "N\\A",
                         "INTERLOCK",
                         "Internal ERROR"
                        };

public:
    explicit amplifier_panel(QWidget *parent = nullptr);
    ~amplifier_panel();

    friend class channel_panel;
private slots:
    void data_received_and_profed();
    void key_catcher(QObject *key);
    void on_pb_laser_onoff_clicked(bool checked);

    void on_pb_pilot_onoff_clicked(bool checked);

    void on_pushButton_clicked();

private:
    Ui::amplifier *ui;
    int error_code;
};

#endif // AMPLIFIER_PANEL_H
