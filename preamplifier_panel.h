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
                         "Backward PD fault 0",   
                         "Forward PD fault 0",    
                         "Backward PD fault 1",   
                         "Forward PD fault 1",    
                         "Interlock",             
                         "System Overheat",       
                         "N\\A",                  
                         "N\\A"                   
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
    void on_pb_reset_clicked();

private:
    Ui::preamplifier_panel *ui;
    int error_code;
};

#endif // PREAMPLIFIER_PANEL_H
