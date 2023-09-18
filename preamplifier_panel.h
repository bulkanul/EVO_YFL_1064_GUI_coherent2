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

public:
    explicit preamplifier_panel(QWidget *parent = nullptr);
    ~preamplifier_panel();

    friend class channel_panel;

private slots:
    void on_pb_onoff_clicked(bool checked);

    void data_received_and_profed();
    void key_catcher(QObject *key);
private:
    Ui::preamplifier_panel *ui;
};

#endif // PREAMPLIFIER_PANEL_H
