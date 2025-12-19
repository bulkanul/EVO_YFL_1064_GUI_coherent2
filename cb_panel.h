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
    QTimer* tmr;
    int auto_call=6;
    int max_curr_call=0;
    bool connection_lost=true;
    QString internal_address;
    QStringList errors_cb_list={"backward PD 0",
                                "forward PD 0",
                                "backward PD 1",
                                "forward PD 1",
                                "ITERLOCK",
                                "Internal ERROR",
                                "Temperature 1",
                                "Temperature 2" };
//    QList<QDoubleSpinBox*> dsb_list;
    QList<QLabel*> label_list;
public slots:
    void data_received_and_profed();
    void key_catcher(QObject*);
    void internal_address_write(QString);
    void telemetry_call(QString);
signals:
    void send_message_window(QString,QString);
    void send_command(QByteArray);
    void call_ui_buttons(QString,bool);
   private slots:
    void on_button_error_clicked();

   private:
    Ui::cb_panel *ui;
};
#endif // DC_PANEL_H
