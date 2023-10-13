#ifndef PREAMPLIFIER_PANEL_H
#define PREAMPLIFIER_PANEL_H

#include <QWidget>
#include "device_panel.h"

namespace Ui {
class preamplifier_panel;
}

class preamplifier_panel : public device_panel
{
    Q_OBJECT

QStringList errors_list={"Backward PD 0",
                         "Forward PD 0",
                         "Backward PD 1",
                         "Forward PD 1",
                         "Backward PD 2",
                         "Forward PD 2",
                         "INTERLOCK",
                         "DCDC fail"
                        };

public:
    explicit preamplifier_panel(QWidget *parent = nullptr);
    ~preamplifier_panel();

    friend class channel_panel;

private slots:
    void data_received_and_profed();
    void key_catcher(QObject *key);

    void on_pb_onoff_clicked(bool checked);

    void on_pushButton_clicked();

private:
    Ui::preamplifier_panel *ui;
    int error_code;
};

#endif // PREAMPLIFIER_PANEL_H
