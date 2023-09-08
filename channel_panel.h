#ifndef CHANNEL_PANEL_H
#define CHANNEL_PANEL_H

#include <QWidget>
#include "preamplifier_panel.h"
#include "amplifier_panel.h"

namespace Ui {
class channel_panel;
}

class channel_panel : public QWidget
{
    Q_OBJECT

public:
    explicit channel_panel(int num, QWidget *parent = nullptr);
    ~channel_panel();

    preamplifier_panel* preamp;
    amplifier_panel* amp;

private:
    Ui::channel_panel *ui;
    int ID;
};

#endif // CHANNEL_PANEL_H
