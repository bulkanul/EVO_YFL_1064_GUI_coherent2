#include "preamplifier_panel.h"
#include "ui_preamplifier_panel.h"

preamplifier_panel::preamplifier_panel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::preamplifier_panel)
{
    ui->setupUi(this);
}

preamplifier_panel::~preamplifier_panel()
{
    delete ui;
}
