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

    ui->lscfreq->installEventFilter(this);
    ui->lseaomst->installEventFilter(this);
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
        panel_state.clear();
        panel_state.append(QString::number(ui->lseaomst->value()));
        panel_state.append(QString::number(ui->lseaomdl->value()));

        ui->fp_label_1->setText(QString::number(param_check(raw_params,18).toDouble()));
        ui->fp_label_2->setText(QString::number(param_check(raw_params,19).toDouble()));
        ui->fp_label_3->setText(QString::number(param_check(raw_params,20).toDouble()));
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

