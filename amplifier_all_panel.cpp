#include "amplifier_all_panel.h"
#include "ui_amplifier_all_panel.h"

#include <QMessageBox>

amplifier_all_panel::amplifier_all_panel(QWidget *parent) :
    device_panel(parent),
    ui(new Ui::amplifier_all_panel)
{
    ui->setupUi(this);
    connect(this,&device_panel::enter_event,this,&amplifier_all_panel::key_catcher);
    connect(this,&device_panel::command_proofed,this,&amplifier_all_panel::data_received_and_profed);
    family="allamp";

    ui->dsb_power->installEventFilter(this);
}

amplifier_all_panel::~amplifier_all_panel()
{
    delete ui;
}

void amplifier_all_panel::auto_telemetry_call(QString family)
{
    if (count_no_responce > 6) {
        enable_widget(false);
        first_pref_cmd = false;
        first_status_cmd = true;
        first_calib = true;
    }
    if (family == this->family + QString::number(ID)) {
        count_no_responce++;
        count++;
        sl_data_get("lgonoff", ID, "");   // lgonoff allamp
        sl_data_get("lgstatus", ID, "");  // lgstatus allamp
    }
}

void amplifier_all_panel::data_received_and_profed()
{
    // lrstatus allamp <id> <value>
    // [0]       [1]   [2]    [3]
    
    if (param_check(raw_params,0) == "lrstatus") {
        ui->l_power->setText(QString::number(param_check(raw_params, 3).toDouble(), 'f', 2) + " %");
    }
    else if (param_check(raw_params,0) == "lronoff"){
        // lronoff allamp <id> <value>
        int val = param_check(raw_params, 3).toInt();
        ui->pb_laser_onoff->setChecked(val == 4);
    }
    else if (param_check(raw_params,0) == "lrpilotonoff"){
    }
    else if (param_check(raw_params,0) == "lrpower"){
        ui->l_power->setText(QString::number(param_check(raw_params, 3).toDouble(), 'f', 2) + " %");
    }
}

void amplifier_all_panel::key_catcher(QObject* key)
{
    QMessageBox *mesg = new QMessageBox(QMessageBox::Information,
                                        "Confirm",
                                        "Send command to all amplifiers?",
                                        QMessageBox::Yes | QMessageBox::No);
    if(mesg->exec()==QMessageBox::Yes){
        if(key->objectName() == "dsb_power"){
            // lspower allamp <id> <value>
            emit sl_data_set("lspower", ID, QString::number(ui->dsb_power->value(), 'f', 2).replace(",", "."));
        }
    }
    delete mesg;
}

void amplifier_all_panel::on_pb_laser_onoff_clicked(bool checked)
{
    // lsonoff allamp <id> <value>
    send_command("lsonoff " + family, ID, QString::number(checked ? 1 : 0));
}
