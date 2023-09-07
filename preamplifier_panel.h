#ifndef PREAMPLIFIER_PANEL_H
#define PREAMPLIFIER_PANEL_H

#include <QWidget>

namespace Ui {
class preamplifier_panel;
}

class preamplifier_panel : public QWidget
{
    Q_OBJECT

public:
    explicit preamplifier_panel(QWidget *parent = nullptr);
    ~preamplifier_panel();

private:
    Ui::preamplifier_panel *ui;
};

#endif // PREAMPLIFIER_PANEL_H
