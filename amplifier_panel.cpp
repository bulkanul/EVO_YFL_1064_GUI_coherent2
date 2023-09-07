#include "amplifier_panel.h"
#include "ui_amplifier.h"

amplifier_panel::amplifier_panel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::amplifier)
{
    ui->setupUi(this);
}

amplifier_panel::~amplifier_panel()
{
    delete ui;
}
