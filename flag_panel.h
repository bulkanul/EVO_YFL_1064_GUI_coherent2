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

public:
    explicit flag_panel(QWidget *parent = nullptr);
    ~flag_panel();

private slots:
    // void key_catcher(QObject *key);
    void data_received_and_profed();
    void on_pushButton_clicked();
    void on_pb_stop_onoff_clicked(bool checked);

signals:
    void sig_usr_critical_error(bool show_clear_btn);

private:
    Ui::flag_panel *ui;
};

#endif // FLAG_PANEL_H
