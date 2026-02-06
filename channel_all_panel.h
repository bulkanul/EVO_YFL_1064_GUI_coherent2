#ifndef CHANNEL_ALL_PANEL_H
#define CHANNEL_ALL_PANEL_H
#include "amplifier_all_panel.h"
#include "preamplifier_all_panel.h"
#include <QWidget>

namespace Ui {
class channel_all_panel;
}

class channel_all_panel : public QWidget
{
    Q_OBJECT

public:
    explicit channel_all_panel(int num, QWidget *parent = nullptr);
    ~channel_all_panel();
    preamplifier_all_panel* preamp;
    amplifier_all_panel* amp;

private:
    Ui::channel_all_panel *ui;
    int ID;
};

#endif // CHANNEL_ALL_PANEL_H
