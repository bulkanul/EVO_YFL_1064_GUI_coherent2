#include "channel_panel.h"
#include "ui_channel_panel.h"

#include <QFrame>
#include <QGridLayout>

channel_panel::channel_panel(int num, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::channel_panel)
{
    ui->setupUi(this);

    ID = num - 1;

    ui->groupBox->setTitle("Канал " + QString::number(ID));

    QGridLayout* layout = new QGridLayout();
    layout->setMargin(2);


    preamp = new preamplifier_panel();
    preamp->ID = ID;
    layout->addWidget(preamp, 0, 0);

    QFrame *line;
    line = new QFrame(this);
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    layout->addWidget(line, 0, 1);

    amp = new amplifier_panel();
    amp->ID = ID;
    layout->addWidget(amp, 0, 2);

    ui->groupBox->setLayout(layout);
}

channel_panel::~channel_panel()
{
    delete ui;
}
