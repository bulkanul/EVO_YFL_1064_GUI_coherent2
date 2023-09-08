#include "general_panel.h"
#include "ui_general_panel.h"

general_panel::general_panel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::general_panel)
{
    ui->setupUi(this);
}

general_panel::~general_panel()
{
    delete ui;
}
