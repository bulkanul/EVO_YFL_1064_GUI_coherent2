#ifndef DC_PANEL_H
#define DC_PANEL_H

#include <QWidget>
#include <device_panel.h>

#define ON_OFF_LASER 16
#define CURRENT_LASER 17
#define TEMP_LASER 18
#define VOLT_IN_LASER 20
#define VOLT_OUT_LASER 38
#define CLR_ERROR_LASER 47
#define ERROR_LASER 48
#define MAX_CURR_LASER 37
#define SAVE_LASER 51
#define MODE_LASER 36

#define CALL_SUFFIX 128
namespace Ui {
class dc_panel;
}

class dc_panel : public device_panel
{
    Q_OBJECT
public:
    explicit dc_panel(QWidget *parent = nullptr);
    ~dc_panel();

    QTimer* tmr;
    int auto_call=6;
    bool connection_lost=true;
    QString internal_address;

public slots:
    void data_received(QString);
    void key_catcher(QObject*);
    void internal_address_write(QString);
    void data_received_and_profed();

private slots:
    void on_on_off_button_clicked(bool checked);
    void on_mode_currentIndexChanged(int index);
    void indicate(double);
    void auto_telemetry_call();
    void enable_widget(bool);
signals:
    void sig_dis_enabled(QWidget*,bool);
    void send_message_window(QString,QString);
    void send_command(QByteArray);

private:
    Ui::dc_panel *ui;
};

#endif // DC_PANEL_H
