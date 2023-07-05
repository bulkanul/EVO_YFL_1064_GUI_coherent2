#ifndef CB_PANEL_H
#define CB_PANEL_H

#include <QWidget>
#include <device_panel.h>

namespace Ui {
class cb_panel;
}

class cb_panel : public device_panel
{
    Q_OBJECT
public:
    explicit cb_panel(QWidget *parent = nullptr);
    ~cb_panel();
    QStringList panel_state;
public slots:
    void data_received_and_profed();
    void key_catcher(QObject*);

private slots:
    void on_mode_currentIndexChanged(int index);
    void on_button_error_clicked();
    void on_pb_on_off_seed_clicked(bool checked);
    void on_pb_on_off_eaom_clicked(bool checked);

    void on_cb_mode_activated(int index);
    void on_cb_width_mode_activated(int index);

    void on_lssave_clicked();

signals:
    void send_message_window(QString,QString);
    void sig_usr_changes(QString,int);
private:
    Ui::cb_panel *ui;
};

#endif // DC_PANEL_H
