#ifndef DEVICE_PANEL_H
#define DEVICE_PANEL_H

#include <QDialog>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QVector>
#include <QWidget>
#include "level_placeholders.h"

class device_panel : public QWidget
{
    Q_OBJECT
public:
    explicit device_panel(QWidget *parent = nullptr);
    void setLevels(const QVector<double> &values);
    void clearLevels();
    int count=0;
    int count_no_responce=0;
    int ID=404;
    int silence_count=0;
    QString family;
    QTimer* tmr;
    bool key=true;
    bool connection_lost=true;
    bool error_displayer=true;
    bool first_status_cmd=true;

    bool first_pref_cmd=false;
    bool first_pref=true;
    bool first_calib=true;

    QStringList raw_params;
    QStringList double_localizator(QByteArray data);
    QString param_check(QStringList,int);
    void check_error_state(int flags, int &error_code_member, QWidget* error_widget, QPushButton* details_btn);
    QList<QString> pref_names;
    QList<QString> writed_values;
    QList<QLabel*> container_values;
    QList<QDoubleSpinBox*> spiners;
    QDialog* dialog=nullptr;
    QLabel* pref_status;
    struct prefs_struct;
    QList<prefs_struct> prefs;

    typedef struct prefs_struct
    {
        int a;
        QString title;
        int precision;
        double value;
    }prefs_struct;

public slots:
    void data_received(QStringList);
    void send_laser(QString,QString);
    void sl_data_set(QString, int ,QString);
    void sl_data_get(QString, int ,QString);

    void auto_telemetry_call(QString family);
    void enable_widget(bool);

    QString parse_bits(int mess,QStringList);
    void call_msg_box(QString);
    void silence_counter(int);
    void resetEmissionCommunicationTracking();
    void key_catcher(QObject *key);
    void on_on_off_button_clicked(bool checked);

private slots:

    void on_toolButton_clicked();
    void send_pref();
signals:
    void sig_dis_enabled(QWidget*,bool);
    void send_message_window(QString,QString);
    void send_command(QString,int,QString);
    void enter_event(QObject*);
    void sl_data_set(QString,QString);
    void command_proofed();
    void sig_device_error(bool has_error);
    void emittingCommunicationChanged(bool alarmActive);

protected:
    bool eventFilter(QObject *target, QEvent *event) override;
    using LimitKind = level_placeholders::LimitKind;
    struct Sensor {
        QLabel *value_label;
        QLabel *level_label;
        int status_field;
        LimitKind kind;
        QString unit;
        int precision;
        double value = 0;
        double limit = 0;
    };
    QVector<Sensor> sensors;
    void updateSensors(const QStringList &message);

private:
    void refreshReadingColors();
    bool readings_valid = false;
    bool levels_valid = false;
    bool has_confirmed_emission = false;
    bool last_confirmed_emission = false;
    bool emitting_communication_alarm = false;
};

#endif // DEVICE_PANEL_H
