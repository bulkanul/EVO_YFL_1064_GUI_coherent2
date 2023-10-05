#ifndef DIVIDER_PANEL_H
#define DIVIDER_PANEL_H

#include <QWidget>
#include "device_panel.h"

namespace Ui {
class divider_panel;
}

class divider_panel : public device_panel
{
    Q_OBJECT

public:
    explicit divider_panel(QWidget *parent = nullptr);
    ~divider_panel();

private slots:
    void data_received_and_profed();
    void key_catcher(QObject *key);

private:
    Ui::divider_panel *ui;
};

#endif // DIVIDER_PANEL_H
