#ifndef GENERATOR_PANEL_H
#define GENERATOR_PANEL_H

#include <QWidget>
#include <array>
#include <device_panel.h>

namespace Ui {
class generator_panel;
}

class generator_panel : public device_panel
{
    Q_OBJECT
QStringList errors_list={
                         "System Overheat",
                         "PD1 forward under",
                         "PD2 backward over",
                         "N\\A",
                         "N\\A",
                         "N\\A",
                         "N\\A",
                         "N\\A"
                        };

public:
    explicit generator_panel(QWidget *parent = nullptr);
    ~generator_panel();
    // Display order: Temp 1, Temp 2, PD1 forward, PD2 backward.
    void setLevels(const std::array<double, 4> &values);
    void clearLevels();

private slots:
    void data_received_and_profed();
    void on_pushButton_clicked();

private:
    void refreshReadingColors();
    Ui::generator_panel *ui;
    int error_code;
    std::array<QLabel *, 4> level_labels{};
    std::array<double, 4> levels{};
    std::array<double, 4> readings{};
    bool levels_valid = false;
    bool readings_valid = false;

signals:
    void sig_usr_changes(QString, int);
    void emission_changed(bool isActive);
};

#endif // GENERATOR_PANEL_H
