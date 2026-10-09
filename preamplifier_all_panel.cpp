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
    ui->l_power->setVisible(false);
    ui->label_16->setVisible(false);

}

preamplifier_all_panel::~preamplifier_all_panel()
{
    delete ui;
}

void preamplifier_all_panel::data_received_and_profed()
{
    // lrstatus allpreamp <id> <value>
    // [0]       [1]      [2]    [3]
    if (param_check(raw_params,0) == "lrstatus") {
        // ui->l_power->setText(QString::number(param_check(raw_params, 3).toDouble(), 'f', 2) + " %");
    }
    else if (param_check(raw_params,0) == "lronoff"){
        // lronoff allpreamp <id> <value>
        int val = param_check(raw_params, 3).toInt();
        ui->pb_onoff->setChecked(val == 4);
    }
}
