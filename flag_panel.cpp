#include "flag_panel.h"
#include "ui_flag_panel.h"

flag_panel::flag_panel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::flag_panel)
{
    ui->setupUi(this);
}

flag_panel::~flag_panel()
{
    delete ui;
}
