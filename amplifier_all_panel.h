#ifndef AMPLIFIER_ALL_PANEL_H
#define AMPLIFIER_ALL_PANEL_H

#include <QWidget>
#include "device_panel.h"

namespace Ui {
class amplifier_all_panel;
}

class amplifier_all_panel : public device_panel
{
    Q_OBJECT

public:
    explicit amplifier_all_panel(QWidget *parent = nullptr);
    ~amplifier_all_panel();
    friend class channel_all_panel;
private slots:
    void auto_telemetry_call(QString family);
    void data_received_and_profed();
    // void key_catcher(QObject *key);
    void on_pb_laser_onoff_clicked(bool checked);

private:
    Ui::amplifier_all_panel *ui;
};

#endif // AMPLIFIER_ALL_PANEL_H
