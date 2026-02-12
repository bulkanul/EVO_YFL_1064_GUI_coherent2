#ifndef GENERATOR_PANEL_H
#define GENERATOR_PANEL_H

#include <QWidget>
#include <device_panel.h>

namespace Ui {
class generator_panel;
}

class generator_panel : public device_panel
{
    Q_OBJECT
QStringList errors_list={
                         "System Overheat",
                         "PD1 forward under",
                         "PD2 backward over",
                         "N\\A",
                         "N\\A",
                         "N\\A",
                         "N\\A",
                         "N\\A"
                        };

public:
    explicit generator_panel(QWidget *parent = nullptr);
    ~generator_panel();

private slots:
    void data_received_and_profed();
    // void key_catcher(QObject *key);
    // void on_pb_laser_onoff_clicked(bool checked);
    void on_pushButton_clicked();

private:
    Ui::generator_panel *ui;
    int error_code;

signals:
    void sig_usr_changes(QString, int);
    void emission_changed(bool isActive);
};

#endif // GENERATOR_PANEL_H
