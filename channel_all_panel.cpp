#include "channel_all_panel.h"
#include "ui_channel_all_panel.h"

channel_all_panel::channel_all_panel(int num, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::channel_all_panel)
{
    ui->setupUi(this);

    ID = num;
    ui->groupBox->setTitle("Общий канал");
    // ui->groupBox->setCheckable(true);

    QGridLayout* layout = new QGridLayout();
    layout->setMargin(2);

    preamp = new preamplifier_all_panel();
    preamp->ID = ID;
    layout->addWidget(preamp, 0, 0);

    QFrame *line;
    line = new QFrame(this);
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    layout->addWidget(line, 0, 1);

    amp = new amplifier_all_panel();
    amp->ID = ID;
    layout->addWidget(amp, 0, 2);

    ui->groupBox->setLayout(layout);
}

channel_all_panel::~channel_all_panel()
{
    delete ui;
}
