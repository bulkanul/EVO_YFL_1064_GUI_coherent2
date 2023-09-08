#ifndef GENERAL_PANEL_H
#define GENERAL_PANEL_H

#include <QWidget>

namespace Ui {
class general_panel;
}

class general_panel : public QWidget
{
    Q_OBJECT

public:
    explicit general_panel(QWidget *parent = nullptr);
    ~general_panel();

private:
    Ui::general_panel *ui;
};

#endif // GENERAL_PANEL_H
