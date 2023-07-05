#include "cb_panel.h"
#include "ui_cb_panel.h"
#include "device_panel.h"

#include <QTimer>
#include <QDebug>
#include <QMessageBox>

cb_panel::cb_panel(QWidget *parent):
    device_panel(parent),
    ui(new Ui::cb_panel)
{
    ui->setupUi(this);
//    connect(ui->spin,SIGNAL(valueChanged(double)),this,SLOT(indicate(double)));
    connect(this,SIGNAL(enter_event(QObject*)),this,SLOT(key_catcher(QObject*)));
    connect(this,SIGNAL(command_proofed()),this,SLOT(data_received_and_profed()));


    family="cb";
    prefs.append(prefs_struct{-1,"Resistance at 25C, Ohm",0,-1});
    prefs.append(prefs_struct{-1,"Thermistor beta",0,-1});
    prefs.append(prefs_struct{-1,"Diff PD alarm level, V",2,-1});

    ui->lssyncst->installEventFilter(this);
    ui->lsbfreq->installEventFilter(this);
    ui->lscfreq->installEventFilter(this);
    ui->lseaomst->installEventFilter(this);
    ui->lsbfreq->installEventFilter(this);
    ui->lsfedaldl->installEventFilter(this);
    ui->lsnspulsw->installEventFilter(this);
    ui->lssyncdl->installEventFilter(this);
    ui->lsfedalst->installEventFilter(this);
    ui->lseaomdl->installEventFilter(this);
}

cb_panel::~cb_panel()
{
    delete ui;
}

void cb_panel::key_catcher(QObject* key)
{
    QMessageBox *mesg = new QMessageBox(QMessageBox::Information,
                                        "Подтверждение",
                                        "Отправить команду в cb "+QString::number(ID)+"?",
                                        QMessageBox::Yes | QMessageBox::No);
    if(mesg->exec()==QMessageBox::Yes){
        QDoubleSpinBox *target = static_cast<QDoubleSpinBox*>(key);
        emit sl_data_set(target->objectName(),ID,QString::number(target->value()).replace(",","."));

//        if(key->objectName() == "ns_freq"){
//            emit sl_data_set("lsbfreq",ID,QString::number(ui->ns_freq->value()).replace(",","."));
//        }else   if(key->objectName() == "eaom_freq"){
//            emit sl_data_set("lscfreq",ID,QString::number(ui->eaom_freq->value()).replace(",","."));
//        }else   if(key->objectName() == "ns_freq"){
//            emit sl_data_set("lsbfreq",ID,QString::number(ui->ns_freq->value()).replace(",","."));
//        }else   if(key->objectName() == "ns_freq"){
//            emit sl_data_set("lsbfreq",ID,QString::number(ui->ns_freq->value()).replace(",","."));
//        }else   if(key->objectName() == "ns_freq"){
//            emit sl_data_set("lsbfreq",ID,QString::number(ui->ns_freq->value()).replace(",","."));
//        }else
    }
}

void cb_panel::on_mode_currentIndexChanged(int index)
{
    emit sl_data_set("lsmode",ID,QString::number(index));
}

void cb_panel::data_received_and_profed()
{
    if(param_check(raw_params,0)=="lrstatus"){
        emit sig_usr_changes("l_footer_connection_status",1);
        ui->seed_state_label->setText(param_check(raw_params,3).toInt()?"ВКЛ.":"ВЫКЛ.");
        ui->pb_on_off_seed->setChecked(param_check(raw_params,3).toInt());
        ui->power_state_label->setText(param_check(raw_params,4).toInt()?"ВКЛ.":"ВЫКЛ.");
        ui->pb_on_off_eaom->setChecked(param_check(raw_params,4).toInt());
        ui->mode_label->setText(param_check(raw_params,5).toInt()?"External":"Internal");

        ui->bfreq_label->setText(QString::number(param_check(raw_params,6).toDouble())+" Hz");
        ui->cfreq_label->setText(QString::number(param_check(raw_params,7).toDouble())+" Hz");
        ui->ns_width_label->setText(QString::number(param_check(raw_params,8).toDouble())+" ns");
        ui->width_mode_label->setText(param_check(raw_params,9).toInt()?(param_check(raw_params,9).toInt()==1?"1 us":"0.1 us"):"10 us");
        ui->eaom_start->setText(QString::number(param_check(raw_params,10).toDouble())+" nS");
        ui->eaom_delay->setText(QString::number(param_check(raw_params,11).toDouble())+" nS");
        ui->fedal_start->setText(QString::number(param_check(raw_params,12).toDouble())+" nS");
        ui->fedal_delay->setText(QString::number(param_check(raw_params,13).toDouble())+" nS");
        ui->sync_start->setText(QString::number(param_check(raw_params,14).toDouble())+" nS");
        ui->sync_delay->setText(QString::number(param_check(raw_params,15).toDouble())+" nS");
        //base_freq
        //cut_freq
        //ns_ctrl_pulse_width
        //width_mode
        //eaom_start
        //eaom_delay
        //fedal_start
        //fedal_delay
        //sync_start
        //sync_delay
        panel_state.clear();
        panel_state.append(QString::number(ui->lseaomst->value()));
        panel_state.append(QString::number(ui->lseaomdl->value()));

        ui->fedal_temp_1->setText(QString::number(param_check(raw_params,16).toDouble())+" C");
        ui->fedal_temp_2->setText(QString::number(param_check(raw_params,17).toDouble())+" C");
        ui->fp_label_1->setText(QString::number(param_check(raw_params,18).toDouble()));
        ui->fp_label_2->setText(QString::number(param_check(raw_params,19).toDouble()));
        ui->fp_label_3->setText(QString::number(param_check(raw_params,20).toDouble()));
        ui->pf_diff->setText(QString::number(param_check(raw_params,21).toDouble()));
        //diff_photo
    }else if(param_check(raw_params,0)=="lrconf0"){
        ui->lseaomst->setValue(param_check(raw_params,19).toDouble());
        ui->lseaomdl->setValue(param_check(raw_params,20).toDouble());
    }else if(param_check(raw_params,0)=="lrconf1"){
        ui->lseaomst->setValue(param_check(raw_params,14).toDouble());
        ui->lseaomdl->setValue(param_check(raw_params,15).toDouble());
    }
    if(param_check(raw_params,0)=="lrerrclr"){
       error_displayer=true;
    }

}

void cb_panel::on_button_error_clicked()
{
    error_displayer=true;
}

void cb_panel::on_pb_on_off_seed_clicked(bool checked)
{
    emit sl_data_set("lsseed",ID,QString::number(checked));
    silence_counter(2);
}

void cb_panel::on_pb_on_off_eaom_clicked(bool checked)
{
    emit sl_data_set("lsqeaom",ID,QString::number(checked));
    silence_counter(2);
}


void cb_panel::on_cb_mode_activated(int index)
{
    emit sl_data_set("lsmode",ID,QString::number(index));
}


void cb_panel::on_cb_width_mode_activated(int index)
{
    emit sl_data_set("lswmode",ID,QString::number(index));
}


void cb_panel::on_lssave_clicked()
{
    emit sl_data_set("lssave",ID,QString::number(1));
}

