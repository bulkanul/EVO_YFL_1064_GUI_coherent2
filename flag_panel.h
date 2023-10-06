#ifndef FLAG_PANEL_H
#define FLAG_PANEL_H

#include <QLabel>
#include <QList>
#include <QWidget>
#include "device_panel.h"

namespace Ui {
class flag_panel;
}

class flag_panel_line;

class flag_panel : public device_panel
{
    Q_OBJECT

public:
    explicit flag_panel(QWidget *parent = nullptr);
    ~flag_panel();

private slots:
    void key_catcher(QObject *key);
    void data_received_and_profed();

    void on_pb_water_clear_clicked();

private:
    Ui::flag_panel *ui;
    QList<flag_panel_line*> lines;
    const int lineCount = 7;
};

class flag_panel_line : public QWidget {
    Q_OBJECT

public:
    explicit flag_panel_line(int num);

    friend class flag_panel;

private:
    QLabel* l_unit_number;
    QLabel* l_input_text;
    QLabel* l_input_marker;
    QLabel* l_output_text;
    QLabel* l_output_marker;
    QLabel* l_temp_text;
    QLabel* l_temp_marker;
};

#endif // FLAG_PANEL_H
