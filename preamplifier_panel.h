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

QStringList errors_list={
                         "PD2 (Back1) fault",
                         "PD1 (Fwd1) fault",
                         "PD4 (Back2) fault",
                         "PD3 (Fwd2) fault",
                         "Interlock",             
                         "System Overheat",       
                         "N\\A",                  
                         "N\\A"                   
                        };

public:
    explicit preamplifier_panel(QWidget *parent = nullptr);
    ~preamplifier_panel();

    friend class channel_panel;

public slots:
    void setAmpQbhFault(bool active);

private slots:
    void data_received_and_profed();
    // void key_catcher(QObject *key);
    // void on_pb_onoff_clicked(bool checked);
    void on_pushButton_clicked();
    void on_pb_reset_clicked();

private:
    void refreshErrorState();

    Ui::preamplifier_panel *ui;
    int displayed_error_state = 0;
    int preamp_error_flags = 0;
    bool amp_qbh_fault = false;
};

#endif // PREAMPLIFIER_PANEL_H
