#ifndef AMPLIFIER_PANEL_H
#define AMPLIFIER_PANEL_H

#include <QWidget>

namespace Ui {
class amplifier;
}

class amplifier_panel : public QWidget
{
    Q_OBJECT

public:
    explicit amplifier_panel(QWidget *parent = nullptr);
    ~amplifier_panel();

private:
    Ui::amplifier *ui;
};

#endif // AMPLIFIER_PANEL_H
