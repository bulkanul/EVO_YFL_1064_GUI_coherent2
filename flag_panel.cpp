#include "flag_panel.h"
#include "ui_flag_panel.h"

flag_panel::flag_panel(QWidget *parent) :
    device_panel(parent),
    ui(new Ui::flag_panel)
{
    ui->setupUi(this);
    ID = 0;

    family = "usr";

    connect(this,SIGNAL(command_proofed()),this,SLOT(data_received_and_profed()));

    QVBoxLayout *origin = new QVBoxLayout(ui->groupBox);
    origin->setContentsMargins(9, 27, 9, 9);

    for (int i = 0; i < lineCount; i++) {
        flag_panel_line* line = new flag_panel_line(i);
        lines.append(line);
        origin->addWidget(line);

        if (i == lineCount - 1)
            continue;
        QFrame* hline = new QFrame(this);
        hline->setFrameShape(QFrame::HLine);
        hline->setFrameShadow(QFrame::Sunken);
        origin->addWidget(hline);
    }

    ui->groupBox->setLayout(origin);
}

flag_panel::~flag_panel()
{
    delete ui;
}

void flag_panel::data_received_and_profed()
{
    if (param_check(raw_params,0) == "lrstatus") {
        for (int i = 3; i < 10; i++) {
            lines[i - 3]->l_input_marker->setEnabled(param_check(raw_params, i).toInt());
        }
        for (int i = 10; i < 17; i++) {
            lines[i - 10]->l_output_marker->setEnabled(param_check(raw_params, i).toInt());
        }
        for (int i = 17; i < 24; i++) {
            lines[i - 17]->l_temp_marker->setEnabled(param_check(raw_params, i).toInt());
        }
    }
}

flag_panel_line::flag_panel_line(int num)
{
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);

    l_unit_number = new QLabel(QString::number(num, 'd', 0));
    l_unit_number->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    l_unit_number->setStyleSheet("font-weight:bold;");
    layout->addWidget(l_unit_number);

    l_input_text = new QLabel("Вход. AC");
    layout->addWidget(l_input_text);

    l_input_marker = new QLabel();
    l_input_marker->setStyleSheet("QLabel::disabled{\n"
                                  " border-image: url(:/images/images/round_button_indicator_error.png)\n"
                                  "}\n"
                                  "QLabel::enabled{\n"
                                  " border-image: url(:/images/images/round_button_indicator_on_hover.png);\n"
                                  "}");
    l_input_marker->setMaximumSize(20, 20);
    l_input_marker->setMinimumSize(20, 20);
    layout->addWidget(l_input_marker);

    l_output_text = new QLabel("Выход. DC");
    layout->addWidget(l_output_text);

    l_output_marker = new QLabel();
    l_output_marker->setStyleSheet("QLabel::disabled{\n"
                                   " border-image: url(:/images/images/round_button_indicator_error.png)\n"
                                   "}\n"
                                   "QLabel::enabled{\n"
                                   " border-image: url(:/images/images/round_button_indicator_on_hover.png);\n"
                                   "}");
    l_output_marker->setMaximumSize(20, 20);
    l_output_marker->setMinimumSize(20, 20);
    layout->addWidget(l_output_marker);

    l_temp_text = new QLabel("Темп.");
    layout->addWidget(l_temp_text);

    l_temp_marker = new QLabel();
    l_temp_marker->setStyleSheet("QLabel::disabled{\n"
                                 " border-image: url(:/images/images/round_button_indicator_error.png)\n"
                                 "}\n"
                                 "QLabel::enabled{\n"
                                 " border-image: url(:/images/images/round_button_indicator_on_hover.png);\n"
                                 "}");
    l_temp_marker->setMaximumSize(20, 20);
    l_temp_marker->setMinimumSize(20, 20);
    layout->addWidget(l_temp_marker);

    this->setLayout(layout);
}
