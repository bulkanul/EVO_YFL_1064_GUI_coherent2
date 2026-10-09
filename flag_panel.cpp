#include "flag_panel.h"
#include "ui_flag_panel.h"

#include <QDebug>
#include <cmath>

flag_panel::flag_panel(QWidget *parent) :
    device_panel(parent),
    ui(new Ui::flag_panel)
{
    ui->setupUi(this);
    ID = 0;
    family = "usr";

    connect(this,&device_panel::enter_event,this,&device_panel::key_catcher);
    connect(this,&device_panel::command_proofed,this,&flag_panel::data_received_and_profed);
    ui->w_error_box->hide();
    ui->pushButton->setVisible(false);
}

flag_panel::~flag_panel()
{
    delete ui;
}

void flag_panel::data_received_and_profed()
{
    // lrstatus usr <id> <interlock_1> <interlock_2> <emergency> <keylock> <phase_not_ok> <stop>
    //              <alarm_interlock_1> <alarm_interlock_2> <alarm_emergency>
    //              <alarm_keylock> <alarm_phase_not_ok> <alarm_stop>

    if (param_check(raw_params, 0) == "lrstatus") {
        if (raw_params.size() < 15) {
            qWarning() << "Incomplete usr status:" << raw_params;
            return;
        }

        QStringList current_alarms;
        for (int i = 0; i < errors_list.size(); ++i) {
            bool ok = false;
            const int alarm = raw_params[9 + i].toInt(&ok);
            if (!ok || (alarm != 0 && alarm != 1)) {
                qWarning() << "Invalid usr alarm flag:" << raw_params[9 + i];
                return;
            }
            if (alarm == 1) {
                current_alarms.append(errors_list[i]);
            }
        }

        int interlock_1  = param_check(raw_params, 3).toInt();
        int interlock_2  = param_check(raw_params, 4).toInt();
        int emergency    = param_check(raw_params, 5).toInt();
        int keylock      = param_check(raw_params, 6).toInt();
        int phase_not_ok = param_check(raw_params, 7).toInt();
        int stop         = param_check(raw_params, 8).toInt();
        
        ui->l_interlock_1->setEnabled(!interlock_1);
        ui->l_interlock_2->setEnabled(!interlock_2);
        ui->l_interlock_alarm->setEnabled(!emergency);
        ui->l_key->setEnabled(!keylock);
        ui->l_phase_not_ok->setEnabled(!phase_not_ok);
        ui->l_stop->setText(stop ? "Active" : "Inactive");
        ui->pb_stop_onoff->setChecked(stop);

        device_alarms = current_alarms;
        refreshErrorState();
    }
    else if (param_check(raw_params, 0) == "lrlvls") {
        if (first_pref_cmd) return;
        // if (raw_params.size() == 4 && raw_params[3] == "ERR") {
        //     first_pref_cmd = true;
        //     qWarning() << "Could not read levels:" << raw_params;
        //     return;
        // }
        constexpr int level_count = 44;
        if (raw_params.size() != 3 + level_count) {
            qWarning() << "Invalid levels response, expected 44 values:" << raw_params;
            return;
        }
        QVector<double> values(level_count);
        for (int i = 0; i < level_count; ++i) {
            bool ok = false;
            const double value = raw_params[i + 3].toDouble(&ok);
            if (!ok || !std::isfinite(value)) {
                qWarning() << "Invalid level at index" << i << raw_params[i + 3];
                return;
            }
            values[i] = value;
        }
        first_pref_cmd = true;
        emit levels_received(values);
    }
    else if (param_check(raw_params, 0) == "lrerrclr") {
        device_alarms.clear();
        refreshErrorState();
    }
}

void flag_panel::setCommunicationError(const QString &unit, bool active)
{
    if (active) {
        communication_errors.insert(unit);
    } else {
        communication_errors.remove(unit);
    }
    refreshErrorState();
}

void flag_panel::refreshErrorState()
{
    active_alarms = device_alarms;
    QStringList units = communication_errors.values();
    units.sort(Qt::CaseInsensitive);
    for (const QString &unit : units) {
        active_alarms.append("Communication lost with emitting unit: " + unit);
    }
    check_error_state(active_alarms.size(), alarm_count, ui->w_error_box, ui->pushButton);
}

void flag_panel::on_pushButton_init_clicked()
{
    // lsinitall usr <id>
    emit sl_data_set("lsinitall", ID, "");
}

void flag_panel::on_pushButton_clicked()
{
    call_msg_box(active_alarms.join(QChar(10)));
}

void flag_panel::on_pb_stop_onoff_clicked(bool checked)
{
    // lsstop usr <id> <value>
    ui->pb_stop_onoff->setChecked(!checked); 
    emit sl_data_set("lsstop", ID, QString::number(checked ? 1 : 0));
}
