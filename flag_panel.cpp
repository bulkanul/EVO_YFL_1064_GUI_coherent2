#include "flag_panel.h"
#include "ui_flag_panel.h"

flag_panel::flag_panel(QWidget *parent) :
    device_panel(parent),
    ui(new Ui::flag_panel)
{
    ui->setupUi(this);
    ID = 0;
    family = "usr";

    connect(this, SIGNAL(enter_event(QObject*)), this, SLOT(key_catcher(QObject*)));
    connect(this, SIGNAL(command_proofed()), this, SLOT(data_received_and_profed()));
}

flag_panel::~flag_panel()
{
    delete ui;
}

void flag_panel::key_catcher(QObject *key)
{
    Q_UNUSED(key);
}

void flag_panel::data_received_and_profed()
{
    // lrstatus usr <id> <interlock_1> <interlock_2> <emergency> <keylock> <phase_not_ok> <stop>
    //   [0]    [1] [2]     [3]           [4]            [5]        [6]       [7]         [8]
    
    if (param_check(raw_params, 0) == "lrstatus") {
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

        // Clear Errors button show when any critical usr param is 1 (not ok)
        bool has_critical = (interlock_1 || interlock_2 || emergency || phase_not_ok);
        emit sig_usr_critical_error(has_critical);
    }
    else if (param_check(raw_params, 0) == "lrerrclr") {
        emit sig_usr_critical_error(false);
    }
}

void flag_panel::on_pushButton_clicked()
{
    // lsinitall usr <id>
    emit sl_data_set("lsinitall", ID, "");
}

void flag_panel::on_pb_stop_onoff_clicked(bool checked)
{
    // lsstop usr <id> <value>
    ui->pb_stop_onoff->setChecked(!checked); 
    emit sl_data_set("lsstop", ID, QString::number(checked ? 1 : 0));
}
