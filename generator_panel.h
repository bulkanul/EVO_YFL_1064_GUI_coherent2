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

public:
    explicit generator_panel(QWidget *parent = nullptr);
    ~generator_panel();

private slots:

    void on_pb_tec_1_onoff_clicked(bool checked);

    void on_pb_tec_2_onoff_clicked(bool checked);

    void data_received_and_profed();
    void key_catcher(QObject *key);
    void on_pb_laser_onoff_clicked(bool checked);

private:
    Ui::generator_panel *ui;

signals:
    void sig_usr_changes(QString, int);

};

#endif // GENERATOR_PANEL_H
