#include "flag_panel.h"
#include "qtimer.h"
#include "ui_flag_panel.h"

#include <QMessageBox>

flag_panel::flag_panel(QWidget *parent) :
    device_panel(parent),
    ui(new Ui::flag_panel)
{
    ui->setupUi(this);
    ID = 0;

    family = "usr";

    delete tmr;
    tmr = new QTimer();
    tmr->setInterval(1400);
    connect(tmr,SIGNAL(timeout()),this,SLOT(auto_telemetry_call()));
    tmr->start();

    connect(this,SIGNAL(enter_event(QObject*)),this,SLOT(key_catcher(QObject*)));
    connect(this,SIGNAL(command_proofed()),this,SLOT(data_received_and_profed()));

    QVBoxLayout *origin = new QVBoxLayout(ui->widget);
    origin->setContentsMargins(9, 27, 9, 0);
    origin->setSpacing(2);
    // for (int i = 0; i < lineCount; i++) {
    for (int i = 0; i < 2; i++) {
        flag_panel_line* line = new flag_panel_line(i);
        lines.append(line);
        origin->addWidget(line);

        if (i > 1) {                        /// delete
            line->setDisabled(true);        /// delete
        }                                   /// delete
    }
    QFrame* hline = new QFrame(this);
    hline->setFrameShape(QFrame::HLine);
    hline->setFrameShadow(QFrame::Sunken);
    origin->addWidget(hline);
    ui->widget->setLayout(origin);

    ui->l_water_thresh->setStyleSheet("QLabel{\n"
                                      " font:11pt;\n"
                                      " font-weight:bold;\n"
                                      "}");

    ui->l_water_speed->setStyleSheet("QLabel{\n"
                                      " font:11pt;\n"
                                      " font-weight:bold;\n"
                                      "}");

    ui->dsb_water_thresh->installEventFilter(this);
}

flag_panel::~flag_panel()
{
    delete ui;
}

void flag_panel::key_catcher(QObject *key)
{
    QMessageBox *mesg = new QMessageBox(QMessageBox::Information,
                                        "Подтверждение",
                                        "Отправить команду блоку usr "+QString::number(ID)+"?",
                                        QMessageBox::Yes | QMessageBox::No);
    if(mesg->exec()==QMessageBox::Yes){
        if(key->objectName() == "dsb_water_thresh"){
            emit sl_data_set("lsconf", ID, QString::number(ui->dsb_water_thresh->value()).replace(",","."));
        }
    }
}

void flag_panel::data_received_and_profed()
{
    if (param_check(raw_params,0) == "lrstatus") {

        emit sl_data_get("lgwater_speed", ID, "");
        if (firstStatus) {
            firstStatus = false;
            emit sl_data_get("lgconf", ID, "");
        }

        for (int i = 3; i < 5; i++) { // fix 5 to 10
            lines[i - 3]->l_input_marker->setEnabled(!param_check(raw_params, i).toInt());
        }
        for (int i = 10; i < 12; i++) { // fix 12 to 17
            lines[i - 10]->l_output_marker->setEnabled(!param_check(raw_params, i).toInt());
        }
        for (int i = 17; i < 19; i++) { // fix 19 to 24
            lines[i - 17]->l_temp_marker->setEnabled(!param_check(raw_params, i).toInt());
        }
        ui->l_water_marker->setEnabled(!param_check(raw_params, 24).toInt());
        ui->l_interlock_1->setEnabled(!param_check(raw_params, 25).toInt());
        ui->l_interlock_2->setEnabled(!param_check(raw_params, 26).toInt());
        ui->l_interlock_alarm->setEnabled(!param_check(raw_params, 27).toInt());
        ui->l_key->setEnabled(!param_check(raw_params, 28).toInt());
    } else if (param_check(raw_params, 0) == "lrconf") {
        ui->l_water_thresh->setText(QString::number(param_check(raw_params, 3).toDouble()) + " Гц");
    } else if (param_check(raw_params,0) == "lrwater_speed") {
        auto prr = raw_params;
        double water_speed = 10000.0 / param_check(raw_params, 3).toDouble();
        ui->l_water_speed->setText(QString::number(water_speed) + " Гц");
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

void flag_panel::on_pb_water_clear_clicked()
{
    emit sl_data_set("lserrclear", ID, "");
}


void flag_panel::on_pushButton_clicked()
{
    emit sl_data_set("lsinitall", ID, "");
}

