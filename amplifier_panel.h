#ifndef AMPLIFIER_PANEL_H
#define AMPLIFIER_PANEL_H

#include <QWidget>
#include <array>
#include "device_panel.h"

namespace Ui {
class amplifier;
}

class amplifier_panel : public device_panel
{
    Q_OBJECT


QStringList errors_list={
                         "PD2 (Back1) fault",
                         "PD1 (Fwd1) fault",
                         "N\\A",                  
                         "QBH fault",             
                         "N\\A",                  
                         "N\\A",                  
                         "Interlock",
                         "AC/DC problem",
                         "System Overheat"
                        };

public:
    explicit amplifier_panel(QWidget *parent = nullptr);
    ~amplifier_panel();
    // Display order: Temp 0, Temp 1, Fwd1, Back1.
    void setLevels(const std::array<double, 4> &values);
    void clearLevels();

    friend class channel_panel;
signals:
    void qbhFaultChanged(bool active);

private slots:
    void data_received_and_profed();
    // void key_catcher(QObject *key);
    // void on_pb_laser_onoff_clicked(bool checked);
    void on_pb_pilot_onoff_clicked(bool checked);
    void on_pushButton_clicked();

private:
    void refreshReadingColors();
    Ui::amplifier *ui;
    int error_code = 0;
    bool qbh_fault = false;
    std::array<QLabel *, 4> level_labels{};
    std::array<double, 4> levels{};
    std::array<double, 4> readings{};
    bool levels_valid = false;
    bool readings_valid = false;
};

#endif // AMPLIFIER_PANEL_H
