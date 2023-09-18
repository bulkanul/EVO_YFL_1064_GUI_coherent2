#ifndef PREAMPLIFIER_ALL_PANEL_H
#define PREAMPLIFIER_ALL_PANEL_H
#include "device_panel.h"
#include <QWidget>

namespace Ui {
class preamplifier_all_panel;
}

class preamplifier_all_panel : public device_panel
{
    Q_OBJECT

public:
    explicit preamplifier_all_panel(QWidget *parent = nullptr);
    ~preamplifier_all_panel();

    friend class channel_all_panel;

private slots:
    void on_pb_onoff_clicked(bool checked);

    void data_received_and_profed();
    void key_catcher(QObject *key);
private:
    Ui::preamplifier_all_panel *ui;
};

#endif // PREAMPLIFIER_ALL_PANEL_H
