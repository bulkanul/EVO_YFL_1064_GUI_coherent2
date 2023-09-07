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
    explicit channel_panel(QWidget *parent = nullptr);
    ~channel_panel();

private:
    preamplifier_panel* preamp;
    amplifier_panel* amp;

    Ui::channel_panel *ui;
};

#endif // CHANNEL_PANEL_H
