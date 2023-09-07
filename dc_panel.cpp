#include "dc_panel.h"
#include "ui_dc_panel.h"
#include "device_panel.h"

#include <QTimer>
#include <QDebug>
#include <QMessageBox>

dc_panel::dc_panel(QWidget *parent):
    device_panel(parent),
    ui(new Ui::dc_panel)
{
    ui->setupUi(this);
    connect(ui->spin,SIGNAL(valueChanged(double)),this,SLOT(indicate(double)));
    connect(this,SIGNAL(enter_event(QObject*)),this,SLOT(key_catcher(QObject*)));
    connect(this,SIGNAL(command_proofed()),this,SLOT(data_received_and_profed()));


    family="dc";
//    pref_names.append("Макс. ток, А");
//    writed_values.append("-");
    prefs.append(prefs_struct{-1,"Max current, A",4,-1});
    ui->spin->installEventFilter(this);

    ui->mode->installEventFilter(this);
}

dc_panel::~dc_panel()
{
    delete ui;
}

double dc_panel::get_current()
{
    return ui->spin->value();
}

void dc_panel::set_current(double value)
{
    ui->spin->setValue(value);
}

void dc_panel::setTitle(QString postfix)
{
    ui->laser_name_label->setText(ui->laser_name_label->text() + ' ' + postfix);
}

bool dc_panel::get_check_state()
{
    return ui->chb_debug->isChecked();
}

void dc_panel::key_catcher(QObject* key)
{
    QMessageBox *mesg = new QMessageBox(QMessageBox::Information,
                                        "Подтверждение",
                                        "Отправить команду dc "+QString::number(ID)+"?",
                                        QMessageBox::Yes | QMessageBox::No);
    if(mesg->exec()==QMessageBox::Yes){
        if(key->objectName() == "spin"){
            emit sl_data_set("lscurr",ID,QString::number(ui->spin->value()).replace(",","."));
        }
    }
}

void dc_panel::enable_selected(bool checked)
{
    if (ui->chb_debug->isChecked())
        emit sl_data_set("lsonoff",ID,QString::number(checked));
}

void dc_panel::indicate(double count)
{
    ui->indicator->setValue(int(count*10));
}

void dc_panel::indicate_temp(double count)
{
    ui->tem_indicator->setValue(int((10-count)*10));
}

void dc_panel::on_on_off_button_clicked(bool checked)
{
    emit sl_data_set("lsonoff",ID,QString::number(checked));
    silence_counter(2);
//    error_displayer=true;
}

void dc_panel::on_mode_currentIndexChanged(int index)
{
    emit sl_data_set("lsmode",ID,QString::number(index));
}

void dc_panel::data_received_and_profed()
{
    if(param_check(raw_params,0)=="lrstatus"){
        emit sig_usr_changes("l_footer_connection_status",1);
        ui->power_state_label->setText(param_check(raw_params,3).toInt()?"ВКЛ.":"ВЫКЛ.");
        ui->on_off_button->setChecked(param_check(raw_params,3).toInt());
        emit sig_usr_changes("l_footer_emission "+family+" "+QString::number(ID),param_check(raw_params,3).toInt());
        ui->current_ld_label->setText(QString::number(param_check(raw_params,4).toDouble())+" A");
        ui->temp_label->setText(QString::number(param_check(raw_params,5).toDouble())+" C");
        indicate_temp(param_check(raw_params,5).toDouble());
        if(error_displayer){
            call_msg_box(pars_bits(param_check(raw_params,6).toUInt(),errors_dc_list));
        }
        ui->button_error->setVisible(param_check(raw_params,6).toUInt()!=0);
        ui->label_error->setVisible(param_check(raw_params,6).toUInt()!=0);
        enable_widget(param_check(raw_params,6).toUInt()==0);
        if(param_check(raw_params,6).toUInt()!=0)emit sig_usr_changes("pb_error_cleaner",1);

        ui->mode_label->setText(ui->mode->itemText(param_check(raw_params,7).toInt()));
        ui->input_voltage_label->setText(QString::number(param_check(raw_params,8).toDouble())+" В");
        ui->output_voltage_label->setText(QString::number(param_check(raw_params,9).toDouble())+" В");

        panel_state.clear();
        panel_state.append(QString::number(ui->spin->value()));
//        panel_state.append(QString::number(param_check(raw_params,4).toDouble()));
//        panel_state.append(ui->curr_max_label->text());
    }else if(param_check(raw_params,0)=="lrconf"){
        ui->spin->setMaximum(param_check(raw_params,3).toDouble());
        ui->indicator->setMaximum(param_check(raw_params,3).toDouble()*10);
        ui->curr_max_label->setText(param_check(raw_params,3));
    }else if(param_check(raw_params,0)=="lrconf0"){
        ui->spin->setValue(param_check(raw_params,17).toDouble());
        ui->spin->setMaximum(param_check(raw_params,18).toDouble());
        ui->indicator->setMaximum(param_check(raw_params,18).toDouble()*10);
        ui->curr_max_label->setText(param_check(raw_params,18));
    }else if(param_check(raw_params,0)=="lrconf1"){
        ui->spin->setValue(param_check(raw_params,12).toDouble());
        ui->spin->setMaximum(param_check(raw_params,13).toDouble());
        ui->indicator->setMaximum(param_check(raw_params,13).toDouble()*10);
        ui->curr_max_label->setText(param_check(raw_params,13));
    }
    if(param_check(raw_params,0)=="lrerrclr"){
       error_displayer=true;
    }

}

void dc_panel::on_button_error_clicked()
{
    error_displayer=true;
}

