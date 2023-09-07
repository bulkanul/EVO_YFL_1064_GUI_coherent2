#include "channel_panel.h"
#include "ui_channel_panel.h"

#include <QFrame>
#include <QGridLayout>

channel_panel::channel_panel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::channel_panel)
{
    ui->setupUi(this);

    QGridLayout* layout = new QGridLayout();

    preamp = new preamplifier_panel();
    layout->addWidget(preamp, 0, 0);

    QFrame *line;
    line = new QFrame(this);
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    layout->addWidget(line, 0, 1);

    amp = new amplifier_panel();
    layout->addWidget(amp, 0, 2);

    ui->groupBox->setLayout(layout);
}

channel_panel::~channel_panel()
{
    delete ui;
}
