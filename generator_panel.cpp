#include "generator_panel.h"
#include "ui_generator_panel.h"

generator_panel::generator_panel(QWidget *parent) :
    device_panel(parent),
    ui(new Ui::generator_panel)
{
    ui->setupUi(this);
    connect(this,SIGNAL(enter_event(QObject*)),this,SLOT(key_catcher(QObject*)));
    connect(this,SIGNAL(command_proofed()),this,SLOT(data_received_and_profed()));
    family="gen";
}

generator_panel::~generator_panel()
{
    delete ui;
}

void generator_panel::on_pb_tec_1_onoff_clicked(bool checked)
{
    send_command("lsteconoff gen", ID, QString::number(checked) + " 0");
}


void generator_panel::on_pb_tec_2_onoff_clicked(bool checked)
{
    send_command("lsteconoff gen", ID, QString::number(checked) + " 1");

}

