#ifndef FLAG_PANEL_H
#define FLAG_PANEL_H

#include <QWidget>

namespace Ui {
class flag_panel;
}

class flag_panel : public QWidget
{
    Q_OBJECT

public:
    explicit flag_panel(QWidget *parent = nullptr);
    ~flag_panel();

private:
    Ui::flag_panel *ui;
};

#endif // FLAG_PANEL_H
