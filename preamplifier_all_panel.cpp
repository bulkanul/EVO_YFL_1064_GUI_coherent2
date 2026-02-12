#include "preamplifier_all_panel.h"
#include "ui_preamplifier_all_panel.h"

#include <QMessageBox>

preamplifier_all_panel::preamplifier_all_panel(QWidget *parent) :
    device_panel(parent),
    ui(new Ui::preamplifier_all_panel)
{
    ui->setupUi(this);
    connect(this,&device_panel::enter_event,this,&device_panel::key_catcher);
    connect(this,&device_panel::command_proofed,this,&preamplifier_all_panel::data_received_and_profed);
    connect(ui->pb_onoff, &QPushButton::clicked, this, &device_panel::on_on_off_button_clicked);

    family="allpreamp";
}

preamplifier_all_panel::~preamplifier_all_panel()
{
    delete ui;
}

void preamplifier_all_panel::auto_telemetry_call(QString family)
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
        sl_data_get("lgonoff", ID, "");   // lgonoff allpreamp
        sl_data_get("lgstatus", ID, "");  // lgstatus allpreamp
    }
}

// void preamplifier_all_panel::on_pb_onoff_clicked(bool checked)
// {
//     // lsonoff allpreamp <id> <value>
//     ui->pb_onoff->setChecked(!checked);
//     send_command("lsonoff " + family, ID, QString::number(checked ? 1 : 0));
// }

void preamplifier_all_panel::data_received_and_profed()
{
    // lrstatus allpreamp <id> <value>
    // [0]       [1]      [2]    [3]
    if (param_check(raw_params,0) == "lrstatus") {
        ui->l_power->setText(QString::number(param_check(raw_params, 3).toDouble(), 'f', 2) + " %");
    }
    else if (param_check(raw_params,0) == "lronoff"){
        // lronoff allpreamp <id> <value>
        int val = param_check(raw_params, 3).toInt();
        ui->pb_onoff->setChecked(val == 4);
    }
}

/*void preamplifier_all_panel::key_catcher(QObject* key)
{
    Q_UNUSED(key);
}*/
