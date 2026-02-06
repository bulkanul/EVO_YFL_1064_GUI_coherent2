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
    if (num > 2) {
        // ui->groupBox->setTitle("Channel " + QString::number(num) + " (INACTIVE)");
        ui->groupBox->setTitle("Channel " + QString::number(num));
    } else {
        ui->groupBox->setTitle("Channel " + QString::number(num));
    }

    QGridLayout* layout = new QGridLayout();
    // layout->setMargin(2);

    auto *preampCol = new QVBoxLayout();
    auto *preampTitle = new QLabel(QString("Preamp"), this);
    preampTitle->setAlignment(Qt::AlignCenter);
    QFont titleFont("Arial", 12, QFont::Bold);
    preampTitle->setFont(titleFont);
    preampCol->addWidget(preampTitle);

    preamp = new preamplifier_panel();
    preamp->ID = ID;
    preampCol->addWidget(preamp);
    layout->addLayout(preampCol, 0, 0);

    QFrame *line;
    line = new QFrame(this);
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    layout->addWidget(line, 0, 1);

    auto *ampCol = new QVBoxLayout();
    auto *ampTitle = new QLabel(QString("Amp"), this);
    ampTitle->setAlignment(Qt::AlignCenter);
    ampTitle->setFont(titleFont);
    ampCol->addWidget(ampTitle);

    amp = new amplifier_panel();
    amp->ID = ID;
    ampCol->addWidget(amp);
    layout->addLayout(ampCol, 0, 2);

    ui->groupBox->setLayout(layout);
}

channel_panel::~channel_panel()
{
    delete ui;
}
