#include "channel_all_panel.h"
#include "ui_channel_all_panel.h"

channel_all_panel::channel_all_panel(int num, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::channel_all_panel)
{
    ui->setupUi(this);

    ID = num;
    ui->groupBox->setTitle("All Channels");

    QGridLayout* layout = new QGridLayout();
    layout->setContentsMargins(2, 2, 2, 2);
    QFont titleFont("Arial", 12, QFont::Bold);

    auto *preampCol = new QVBoxLayout();
    auto *preampTitle = new QLabel("Preamp (All)", this);
    preampTitle->setAlignment(Qt::AlignCenter);
    preampTitle->setFont(titleFont);
    preampCol->addWidget(preampTitle);

    preamp = new preamplifier_all_panel();
    preamp->ID = ID;
    preampCol->addWidget(preamp);
    layout->addLayout(preampCol, 0, 0);

    auto *line = new QFrame(this);
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    layout->addWidget(line, 0, 1);

    auto *ampCol = new QVBoxLayout();
    auto *ampTitle = new QLabel("Amp (All)", this);
    ampTitle->setAlignment(Qt::AlignCenter);
    ampTitle->setFont(titleFont);
    ampCol->addWidget(ampTitle);

    amp = new amplifier_all_panel();
    amp->ID = ID;
    ampCol->addWidget(amp);
    layout->addLayout(ampCol, 0, 2);

    ui->groupBox->setLayout(layout);
}

channel_all_panel::~channel_all_panel()
{
    delete ui;
}
