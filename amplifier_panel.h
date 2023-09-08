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

public:
    explicit amplifier_panel(QWidget *parent = nullptr);
    ~amplifier_panel();

private slots:
    void data_received_and_profed();
    void key_catcher(QObject *key);
    void on_pb_laser_onoff_clicked(bool checked);

    void on_pb_pilot_onoff_clicked(bool checked);

private:
    Ui::amplifier *ui;
};

#endif // AMPLIFIER_PANEL_H
