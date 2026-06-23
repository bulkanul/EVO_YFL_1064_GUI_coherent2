/********************************************************************************
** Form generated from reading UI file 'cb_panel.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CB_PANEL_H
#define UI_CB_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cb_panel
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_28;
    QHBoxLayout *horizontalLayout_11;
    QLabel *laser_name_label;
    QSpacerItem *horizontalSpacer_14;
    QWidget *ns_widget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_16;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_31;
    QLabel *label_29;
    QHBoxLayout *horizontalLayout_21;
    QDoubleSpinBox *forward_treashold;
    QVBoxLayout *verticalLayout_35;
    QLabel *label_31;
    QHBoxLayout *horizontalLayout_23;
    QDoubleSpinBox *backward_treashold;
    QVBoxLayout *verticalLayout_33;
    QLabel *label_33;
    QHBoxLayout *horizontalLayout_25;
    QDoubleSpinBox *forward_treashold_2;
    QVBoxLayout *verticalLayout_36;
    QLabel *label_34;
    QHBoxLayout *horizontalLayout_26;
    QDoubleSpinBox *backward_treashold_2;
    QGroupBox *groupBox_12;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_29;
    QLabel *label_24;
    QHBoxLayout *horizontalLayout_17;
    QDoubleSpinBox *hpld_curr_0;
    QVBoxLayout *verticalLayout_34;
    QLabel *label_30;
    QHBoxLayout *horizontalLayout_22;
    QDoubleSpinBox *hpld_curr_1;
    QGroupBox *groupBox_14;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QDoubleSpinBox *therm_resis;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QDoubleSpinBox *therm_vref;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QDoubleSpinBox *therm_beta;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_19;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_30;
    QLabel *label_25;
    QHBoxLayout *horizontalLayout_18;
    QDoubleSpinBox *over_temp_00;
    QVBoxLayout *verticalLayout_32;
    QLabel *label_26;
    QHBoxLayout *horizontalLayout_19;
    QDoubleSpinBox *over_temp_01;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_11;
    QFormLayout *formLayout;
    QLabel *label_35;
    QLabel *hpld_curr_label_0;
    QLabel *label_36;
    QLabel *hpld_curr_label_1;
    QLabel *label_38;
    QLabel *forward_treashold_label;
    QLabel *label_42;
    QLabel *forward_treashold_label_2;
    QLabel *label_39;
    QLabel *backward_treashold_label;
    QLabel *label_43;
    QLabel *backward_treashold_label_2;
    QLabel *label_52;
    QLabel *therm_resis_label;
    QLabel *label_54;
    QLabel *therm_vref_label;
    QLabel *label_53;
    QLabel *therm_beta_label;
    QLabel *label_55;
    QLabel *over_temp_label_0;
    QFrame *line_2;
    QLabel *label_50;
    QLabel *cur_temp_0;
    QLabel *label_56;
    QLabel *cur_temp_1;
    QLabel *label_40;
    QLabel *pd_forward;
    QLabel *label_44;
    QLabel *pd_forward_2;
    QLabel *label_41;
    QLabel *pd_backward;
    QLabel *label_45;
    QLabel *pd_backward_2;
    QLabel *label_error;
    QPushButton *button_error;
    QLabel *label_57;
    QLabel *over_temp_label_1;
    QSpacerItem *verticalSpacer;
    QFrame *line;

    void setupUi(QWidget *cb_panel)
    {
        if (cb_panel->objectName().isEmpty())
            cb_panel->setObjectName("cb_panel");
        cb_panel->resize(1003, 607);
        verticalLayout_2 = new QVBoxLayout(cb_panel);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(3, 3, 3, 3);
        groupBox = new QGroupBox(cb_panel);
        groupBox->setObjectName("groupBox");
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #ffffff, stop: 1 #FFFFFF);\n"
"    border: 1px solid gray;\n"
"    margin-top: 1ex; /* leave space at the top for the title */\n"
"}"));
        verticalLayout_28 = new QVBoxLayout(groupBox);
        verticalLayout_28->setObjectName("verticalLayout_28");
        verticalLayout_28->setContentsMargins(3, 3, 3, 3);
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        laser_name_label = new QLabel(groupBox);
        laser_name_label->setObjectName("laser_name_label");
        laser_name_label->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        laser_name_label->setFont(font);

        horizontalLayout_11->addWidget(laser_name_label);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_14);


        verticalLayout_28->addLayout(horizontalLayout_11);

        ns_widget = new QWidget(groupBox);
        ns_widget->setObjectName("ns_widget");
        ns_widget->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(ns_widget);
        gridLayout->setObjectName("gridLayout");
        groupBox_16 = new QGroupBox(ns_widget);
        groupBox_16->setObjectName("groupBox_16");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_16->sizePolicy().hasHeightForWidth());
        groupBox_16->setSizePolicy(sizePolicy);
        groupBox_16->setFlat(false);
        groupBox_16->setCheckable(false);
        gridLayout_2 = new QGridLayout(groupBox_16);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(-1, 12, -1, -1);
        verticalLayout_31 = new QVBoxLayout();
        verticalLayout_31->setObjectName("verticalLayout_31");
        label_29 = new QLabel(groupBox_16);
        label_29->setObjectName("label_29");
        label_29->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(12);
        label_29->setFont(font1);
        label_29->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_31->addWidget(label_29);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        forward_treashold = new QDoubleSpinBox(groupBox_16);
        forward_treashold->setObjectName("forward_treashold");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(100);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(forward_treashold->sizePolicy().hasHeightForWidth());
        forward_treashold->setSizePolicy(sizePolicy1);
        forward_treashold->setMinimumSize(QSize(50, 0));
        forward_treashold->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setPointSize(13);
        forward_treashold->setFont(font2);
        forward_treashold->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        forward_treashold->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        forward_treashold->setDecimals(2);
        forward_treashold->setMinimum(0.000000000000000);
        forward_treashold->setMaximum(3.000000000000000);
        forward_treashold->setSingleStep(0.100000000000000);
        forward_treashold->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        forward_treashold->setValue(0.000000000000000);

        horizontalLayout_21->addWidget(forward_treashold);


        verticalLayout_31->addLayout(horizontalLayout_21);


        gridLayout_2->addLayout(verticalLayout_31, 0, 1, 1, 1);

        verticalLayout_35 = new QVBoxLayout();
        verticalLayout_35->setObjectName("verticalLayout_35");
        label_31 = new QLabel(groupBox_16);
        label_31->setObjectName("label_31");
        label_31->setMinimumSize(QSize(0, 0));
        label_31->setFont(font1);
        label_31->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_35->addWidget(label_31);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName("horizontalLayout_23");
        backward_treashold = new QDoubleSpinBox(groupBox_16);
        backward_treashold->setObjectName("backward_treashold");
        sizePolicy1.setHeightForWidth(backward_treashold->sizePolicy().hasHeightForWidth());
        backward_treashold->setSizePolicy(sizePolicy1);
        backward_treashold->setMinimumSize(QSize(50, 0));
        backward_treashold->setMaximumSize(QSize(16777215, 16777215));
        backward_treashold->setFont(font2);
        backward_treashold->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        backward_treashold->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        backward_treashold->setDecimals(2);
        backward_treashold->setMinimum(0.000000000000000);
        backward_treashold->setMaximum(3.000000000000000);
        backward_treashold->setSingleStep(0.100000000000000);
        backward_treashold->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        backward_treashold->setValue(0.000000000000000);

        horizontalLayout_23->addWidget(backward_treashold);


        verticalLayout_35->addLayout(horizontalLayout_23);


        gridLayout_2->addLayout(verticalLayout_35, 0, 2, 1, 1);

        verticalLayout_33 = new QVBoxLayout();
        verticalLayout_33->setObjectName("verticalLayout_33");
        label_33 = new QLabel(groupBox_16);
        label_33->setObjectName("label_33");
        label_33->setMinimumSize(QSize(0, 0));
        label_33->setFont(font1);
        label_33->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_33->addWidget(label_33);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName("horizontalLayout_25");
        forward_treashold_2 = new QDoubleSpinBox(groupBox_16);
        forward_treashold_2->setObjectName("forward_treashold_2");
        sizePolicy1.setHeightForWidth(forward_treashold_2->sizePolicy().hasHeightForWidth());
        forward_treashold_2->setSizePolicy(sizePolicy1);
        forward_treashold_2->setMinimumSize(QSize(50, 0));
        forward_treashold_2->setMaximumSize(QSize(16777215, 16777215));
        forward_treashold_2->setFont(font2);
        forward_treashold_2->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        forward_treashold_2->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        forward_treashold_2->setDecimals(2);
        forward_treashold_2->setMinimum(0.000000000000000);
        forward_treashold_2->setMaximum(3.000000000000000);
        forward_treashold_2->setSingleStep(0.100000000000000);
        forward_treashold_2->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        forward_treashold_2->setValue(0.000000000000000);

        horizontalLayout_25->addWidget(forward_treashold_2);


        verticalLayout_33->addLayout(horizontalLayout_25);


        gridLayout_2->addLayout(verticalLayout_33, 1, 1, 1, 1);

        verticalLayout_36 = new QVBoxLayout();
        verticalLayout_36->setObjectName("verticalLayout_36");
        label_34 = new QLabel(groupBox_16);
        label_34->setObjectName("label_34");
        label_34->setMinimumSize(QSize(0, 0));
        label_34->setFont(font1);
        label_34->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_36->addWidget(label_34);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName("horizontalLayout_26");
        backward_treashold_2 = new QDoubleSpinBox(groupBox_16);
        backward_treashold_2->setObjectName("backward_treashold_2");
        sizePolicy1.setHeightForWidth(backward_treashold_2->sizePolicy().hasHeightForWidth());
        backward_treashold_2->setSizePolicy(sizePolicy1);
        backward_treashold_2->setMinimumSize(QSize(50, 0));
        backward_treashold_2->setMaximumSize(QSize(16777215, 16777215));
        backward_treashold_2->setFont(font2);
        backward_treashold_2->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        backward_treashold_2->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        backward_treashold_2->setDecimals(2);
        backward_treashold_2->setMinimum(0.000000000000000);
        backward_treashold_2->setMaximum(3.000000000000000);
        backward_treashold_2->setSingleStep(0.100000000000000);
        backward_treashold_2->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        backward_treashold_2->setValue(0.000000000000000);

        horizontalLayout_26->addWidget(backward_treashold_2);


        verticalLayout_36->addLayout(horizontalLayout_26);


        gridLayout_2->addLayout(verticalLayout_36, 1, 2, 1, 1);


        gridLayout->addWidget(groupBox_16, 1, 0, 2, 1);

        groupBox_12 = new QGroupBox(ns_widget);
        groupBox_12->setObjectName("groupBox_12");
        sizePolicy.setHeightForWidth(groupBox_12->sizePolicy().hasHeightForWidth());
        groupBox_12->setSizePolicy(sizePolicy);
        groupBox_12->setFlat(false);
        groupBox_12->setCheckable(false);
        horizontalLayout_3 = new QHBoxLayout(groupBox_12);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(-1, 12, -1, -1);
        verticalLayout_29 = new QVBoxLayout();
        verticalLayout_29->setObjectName("verticalLayout_29");
        label_24 = new QLabel(groupBox_12);
        label_24->setObjectName("label_24");
        label_24->setMinimumSize(QSize(0, 0));
        label_24->setFont(font1);
        label_24->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_29->addWidget(label_24);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        hpld_curr_0 = new QDoubleSpinBox(groupBox_12);
        hpld_curr_0->setObjectName("hpld_curr_0");
        sizePolicy1.setHeightForWidth(hpld_curr_0->sizePolicy().hasHeightForWidth());
        hpld_curr_0->setSizePolicy(sizePolicy1);
        hpld_curr_0->setMinimumSize(QSize(50, 0));
        hpld_curr_0->setMaximumSize(QSize(16777215, 16777215));
        hpld_curr_0->setFont(font2);
        hpld_curr_0->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        hpld_curr_0->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        hpld_curr_0->setDecimals(2);
        hpld_curr_0->setMinimum(0.000000000000000);
        hpld_curr_0->setMaximum(26.000000000000000);
        hpld_curr_0->setSingleStep(0.100000000000000);
        hpld_curr_0->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        hpld_curr_0->setValue(0.000000000000000);

        horizontalLayout_17->addWidget(hpld_curr_0);


        verticalLayout_29->addLayout(horizontalLayout_17);


        horizontalLayout_3->addLayout(verticalLayout_29);

        verticalLayout_34 = new QVBoxLayout();
        verticalLayout_34->setObjectName("verticalLayout_34");
        label_30 = new QLabel(groupBox_12);
        label_30->setObjectName("label_30");
        label_30->setMinimumSize(QSize(0, 0));
        label_30->setFont(font1);
        label_30->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_34->addWidget(label_30);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName("horizontalLayout_22");
        hpld_curr_1 = new QDoubleSpinBox(groupBox_12);
        hpld_curr_1->setObjectName("hpld_curr_1");
        sizePolicy1.setHeightForWidth(hpld_curr_1->sizePolicy().hasHeightForWidth());
        hpld_curr_1->setSizePolicy(sizePolicy1);
        hpld_curr_1->setMinimumSize(QSize(50, 0));
        hpld_curr_1->setMaximumSize(QSize(16777215, 16777215));
        hpld_curr_1->setFont(font2);
        hpld_curr_1->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        hpld_curr_1->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        hpld_curr_1->setDecimals(2);
        hpld_curr_1->setMinimum(0.000000000000000);
        hpld_curr_1->setMaximum(26.000000000000000);
        hpld_curr_1->setSingleStep(0.100000000000000);
        hpld_curr_1->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        hpld_curr_1->setValue(0.000000000000000);

        horizontalLayout_22->addWidget(hpld_curr_1);


        verticalLayout_34->addLayout(horizontalLayout_22);


        horizontalLayout_3->addLayout(verticalLayout_34);


        gridLayout->addWidget(groupBox_12, 0, 0, 1, 1);

        groupBox_14 = new QGroupBox(ns_widget);
        groupBox_14->setObjectName("groupBox_14");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_14->sizePolicy().hasHeightForWidth());
        groupBox_14->setSizePolicy(sizePolicy2);
        groupBox_14->setFlat(false);
        groupBox_14->setCheckable(false);
        horizontalLayout_4 = new QHBoxLayout(groupBox_14);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(-1, 12, -1, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(groupBox_14);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        therm_resis = new QDoubleSpinBox(groupBox_14);
        therm_resis->setObjectName("therm_resis");
        sizePolicy1.setHeightForWidth(therm_resis->sizePolicy().hasHeightForWidth());
        therm_resis->setSizePolicy(sizePolicy1);
        therm_resis->setMinimumSize(QSize(50, 0));
        therm_resis->setMaximumSize(QSize(16777215, 16777215));
        therm_resis->setFont(font2);
        therm_resis->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        therm_resis->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        therm_resis->setDecimals(0);
        therm_resis->setMinimum(0.000000000000000);
        therm_resis->setMaximum(100000.000000000000000);
        therm_resis->setSingleStep(1.000000000000000);
        therm_resis->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        therm_resis->setValue(0.000000000000000);

        verticalLayout->addWidget(therm_resis);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_2 = new QLabel(groupBox_14);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        therm_vref = new QDoubleSpinBox(groupBox_14);
        therm_vref->setObjectName("therm_vref");
        sizePolicy1.setHeightForWidth(therm_vref->sizePolicy().hasHeightForWidth());
        therm_vref->setSizePolicy(sizePolicy1);
        therm_vref->setMinimumSize(QSize(50, 0));
        therm_vref->setMaximumSize(QSize(16777215, 16777215));
        therm_vref->setFont(font2);
        therm_vref->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        therm_vref->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        therm_vref->setDecimals(3);
        therm_vref->setMinimum(0.000000000000000);
        therm_vref->setMaximum(3.300000000000000);
        therm_vref->setSingleStep(0.100000000000000);
        therm_vref->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        therm_vref->setValue(0.000000000000000);

        verticalLayout_3->addWidget(therm_vref);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_3 = new QLabel(groupBox_14);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(label_3);

        therm_beta = new QDoubleSpinBox(groupBox_14);
        therm_beta->setObjectName("therm_beta");
        sizePolicy1.setHeightForWidth(therm_beta->sizePolicy().hasHeightForWidth());
        therm_beta->setSizePolicy(sizePolicy1);
        therm_beta->setMinimumSize(QSize(50, 0));
        therm_beta->setMaximumSize(QSize(16777215, 16777215));
        therm_beta->setFont(font2);
        therm_beta->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        therm_beta->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        therm_beta->setDecimals(0);
        therm_beta->setMinimum(0.000000000000000);
        therm_beta->setMaximum(100000.000000000000000);
        therm_beta->setSingleStep(1.000000000000000);
        therm_beta->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        therm_beta->setValue(0.000000000000000);

        verticalLayout_4->addWidget(therm_beta);


        horizontalLayout_4->addLayout(verticalLayout_4);


        gridLayout->addWidget(groupBox_14, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 7, 0, 1, 1);

        groupBox_19 = new QGroupBox(ns_widget);
        groupBox_19->setObjectName("groupBox_19");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_19->sizePolicy().hasHeightForWidth());
        groupBox_19->setSizePolicy(sizePolicy3);
        groupBox_19->setFlat(false);
        groupBox_19->setCheckable(false);
        horizontalLayout = new QHBoxLayout(groupBox_19);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 12, -1, -1);
        verticalLayout_30 = new QVBoxLayout();
        verticalLayout_30->setObjectName("verticalLayout_30");
        label_25 = new QLabel(groupBox_19);
        label_25->setObjectName("label_25");
        label_25->setMinimumSize(QSize(0, 0));
        label_25->setFont(font1);
        label_25->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_30->addWidget(label_25);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        over_temp_00 = new QDoubleSpinBox(groupBox_19);
        over_temp_00->setObjectName("over_temp_00");
        sizePolicy1.setHeightForWidth(over_temp_00->sizePolicy().hasHeightForWidth());
        over_temp_00->setSizePolicy(sizePolicy1);
        over_temp_00->setMinimumSize(QSize(50, 0));
        over_temp_00->setMaximumSize(QSize(16777215, 16777215));
        over_temp_00->setFont(font2);
        over_temp_00->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        over_temp_00->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        over_temp_00->setDecimals(1);
        over_temp_00->setMinimum(0.000000000000000);
        over_temp_00->setMaximum(150.000000000000000);
        over_temp_00->setSingleStep(0.100000000000000);
        over_temp_00->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        over_temp_00->setValue(0.000000000000000);

        horizontalLayout_18->addWidget(over_temp_00);


        verticalLayout_30->addLayout(horizontalLayout_18);


        horizontalLayout->addLayout(verticalLayout_30);

        verticalLayout_32 = new QVBoxLayout();
        verticalLayout_32->setObjectName("verticalLayout_32");
        label_26 = new QLabel(groupBox_19);
        label_26->setObjectName("label_26");
        label_26->setMinimumSize(QSize(0, 0));
        label_26->setFont(font1);
        label_26->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_32->addWidget(label_26);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        over_temp_01 = new QDoubleSpinBox(groupBox_19);
        over_temp_01->setObjectName("over_temp_01");
        sizePolicy1.setHeightForWidth(over_temp_01->sizePolicy().hasHeightForWidth());
        over_temp_01->setSizePolicy(sizePolicy1);
        over_temp_01->setMinimumSize(QSize(50, 0));
        over_temp_01->setMaximumSize(QSize(16777215, 16777215));
        over_temp_01->setFont(font2);
        over_temp_01->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        over_temp_01->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        over_temp_01->setDecimals(1);
        over_temp_01->setMinimum(0.000000000000000);
        over_temp_01->setMaximum(150.000000000000000);
        over_temp_01->setSingleStep(0.100000000000000);
        over_temp_01->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        over_temp_01->setValue(0.000000000000000);

        horizontalLayout_19->addWidget(over_temp_01);


        verticalLayout_32->addLayout(horizontalLayout_19);


        horizontalLayout->addLayout(verticalLayout_32);


        gridLayout->addWidget(groupBox_19, 4, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 5, 1);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setObjectName("verticalLayout_16");
        verticalLayout_16->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(ns_widget);
        label_11->setObjectName("label_11");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy4);
        label_11->setMinimumSize(QSize(220, 0));
        label_11->setMaximumSize(QSize(220, 100000));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setUnderline(true);
        font3.setKerning(true);
        label_11->setFont(font3);

        verticalLayout_16->addWidget(label_11);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_35 = new QLabel(ns_widget);
        label_35->setObjectName("label_35");
        label_35->setMinimumSize(QSize(120, 0));
        label_35->setMaximumSize(QSize(120, 16777215));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial")});
        font4.setPointSize(12);
        label_35->setFont(font4);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_35);

        hpld_curr_label_0 = new QLabel(ns_widget);
        hpld_curr_label_0->setObjectName("hpld_curr_label_0");
        hpld_curr_label_0->setMinimumSize(QSize(80, 0));
        hpld_curr_label_0->setMaximumSize(QSize(80, 16777215));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(true);
        hpld_curr_label_0->setFont(font5);

        formLayout->setWidget(0, QFormLayout::FieldRole, hpld_curr_label_0);

        label_36 = new QLabel(ns_widget);
        label_36->setObjectName("label_36");
        label_36->setMinimumSize(QSize(120, 0));
        label_36->setMaximumSize(QSize(120, 16777215));
        label_36->setFont(font4);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_36);

        hpld_curr_label_1 = new QLabel(ns_widget);
        hpld_curr_label_1->setObjectName("hpld_curr_label_1");
        hpld_curr_label_1->setMinimumSize(QSize(80, 0));
        hpld_curr_label_1->setMaximumSize(QSize(80, 16777215));
        hpld_curr_label_1->setFont(font5);

        formLayout->setWidget(1, QFormLayout::FieldRole, hpld_curr_label_1);

        label_38 = new QLabel(ns_widget);
        label_38->setObjectName("label_38");
        label_38->setMinimumSize(QSize(120, 0));
        label_38->setMaximumSize(QSize(120, 16777215));
        label_38->setFont(font4);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_38);

        forward_treashold_label = new QLabel(ns_widget);
        forward_treashold_label->setObjectName("forward_treashold_label");
        forward_treashold_label->setMinimumSize(QSize(80, 0));
        forward_treashold_label->setMaximumSize(QSize(80, 16777215));
        forward_treashold_label->setFont(font5);

        formLayout->setWidget(2, QFormLayout::FieldRole, forward_treashold_label);

        label_42 = new QLabel(ns_widget);
        label_42->setObjectName("label_42");
        label_42->setMinimumSize(QSize(120, 0));
        label_42->setMaximumSize(QSize(120, 16777215));
        label_42->setFont(font4);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_42);

        forward_treashold_label_2 = new QLabel(ns_widget);
        forward_treashold_label_2->setObjectName("forward_treashold_label_2");
        forward_treashold_label_2->setMinimumSize(QSize(80, 0));
        forward_treashold_label_2->setMaximumSize(QSize(80, 16777215));
        forward_treashold_label_2->setFont(font5);

        formLayout->setWidget(3, QFormLayout::FieldRole, forward_treashold_label_2);

        label_39 = new QLabel(ns_widget);
        label_39->setObjectName("label_39");
        label_39->setMinimumSize(QSize(120, 0));
        label_39->setMaximumSize(QSize(120, 16777215));
        label_39->setFont(font4);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_39);

        backward_treashold_label = new QLabel(ns_widget);
        backward_treashold_label->setObjectName("backward_treashold_label");
        backward_treashold_label->setMinimumSize(QSize(80, 0));
        backward_treashold_label->setMaximumSize(QSize(80, 16777215));
        backward_treashold_label->setFont(font5);

        formLayout->setWidget(4, QFormLayout::FieldRole, backward_treashold_label);

        label_43 = new QLabel(ns_widget);
        label_43->setObjectName("label_43");
        label_43->setMinimumSize(QSize(120, 0));
        label_43->setMaximumSize(QSize(120, 16777215));
        label_43->setFont(font4);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_43);

        backward_treashold_label_2 = new QLabel(ns_widget);
        backward_treashold_label_2->setObjectName("backward_treashold_label_2");
        backward_treashold_label_2->setMinimumSize(QSize(80, 0));
        backward_treashold_label_2->setMaximumSize(QSize(80, 16777215));
        backward_treashold_label_2->setFont(font5);

        formLayout->setWidget(5, QFormLayout::FieldRole, backward_treashold_label_2);

        label_52 = new QLabel(ns_widget);
        label_52->setObjectName("label_52");
        label_52->setMinimumSize(QSize(120, 0));
        label_52->setMaximumSize(QSize(120, 16777215));
        label_52->setFont(font4);

        formLayout->setWidget(6, QFormLayout::LabelRole, label_52);

        therm_resis_label = new QLabel(ns_widget);
        therm_resis_label->setObjectName("therm_resis_label");
        therm_resis_label->setMinimumSize(QSize(80, 0));
        therm_resis_label->setMaximumSize(QSize(80, 16777215));
        therm_resis_label->setFont(font5);

        formLayout->setWidget(6, QFormLayout::FieldRole, therm_resis_label);

        label_54 = new QLabel(ns_widget);
        label_54->setObjectName("label_54");
        label_54->setMinimumSize(QSize(120, 0));
        label_54->setMaximumSize(QSize(120, 16777215));
        label_54->setFont(font4);

        formLayout->setWidget(7, QFormLayout::LabelRole, label_54);

        therm_vref_label = new QLabel(ns_widget);
        therm_vref_label->setObjectName("therm_vref_label");
        therm_vref_label->setMinimumSize(QSize(80, 0));
        therm_vref_label->setMaximumSize(QSize(80, 16777215));
        therm_vref_label->setFont(font5);

        formLayout->setWidget(7, QFormLayout::FieldRole, therm_vref_label);

        label_53 = new QLabel(ns_widget);
        label_53->setObjectName("label_53");
        label_53->setMinimumSize(QSize(120, 0));
        label_53->setMaximumSize(QSize(120, 16777215));
        label_53->setFont(font4);

        formLayout->setWidget(8, QFormLayout::LabelRole, label_53);

        therm_beta_label = new QLabel(ns_widget);
        therm_beta_label->setObjectName("therm_beta_label");
        therm_beta_label->setMinimumSize(QSize(80, 0));
        therm_beta_label->setMaximumSize(QSize(80, 16777215));
        therm_beta_label->setFont(font5);

        formLayout->setWidget(8, QFormLayout::FieldRole, therm_beta_label);

        label_55 = new QLabel(ns_widget);
        label_55->setObjectName("label_55");
        label_55->setMinimumSize(QSize(120, 0));
        label_55->setMaximumSize(QSize(120, 16777215));
        label_55->setFont(font4);

        formLayout->setWidget(9, QFormLayout::LabelRole, label_55);

        over_temp_label_0 = new QLabel(ns_widget);
        over_temp_label_0->setObjectName("over_temp_label_0");
        over_temp_label_0->setMinimumSize(QSize(80, 0));
        over_temp_label_0->setMaximumSize(QSize(80, 16777215));
        over_temp_label_0->setFont(font5);

        formLayout->setWidget(9, QFormLayout::FieldRole, over_temp_label_0);

        line_2 = new QFrame(ns_widget);
        line_2->setObjectName("line_2");
        line_2->setMinimumSize(QSize(40, 0));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(11, QFormLayout::SpanningRole, line_2);

        label_50 = new QLabel(ns_widget);
        label_50->setObjectName("label_50");
        label_50->setMinimumSize(QSize(120, 0));
        label_50->setMaximumSize(QSize(120, 16777215));
        label_50->setFont(font4);

        formLayout->setWidget(12, QFormLayout::LabelRole, label_50);

        cur_temp_0 = new QLabel(ns_widget);
        cur_temp_0->setObjectName("cur_temp_0");
        cur_temp_0->setMinimumSize(QSize(80, 0));
        cur_temp_0->setMaximumSize(QSize(80, 16777215));
        cur_temp_0->setFont(font5);

        formLayout->setWidget(12, QFormLayout::FieldRole, cur_temp_0);

        label_56 = new QLabel(ns_widget);
        label_56->setObjectName("label_56");
        label_56->setMinimumSize(QSize(120, 0));
        label_56->setMaximumSize(QSize(120, 16777215));
        label_56->setFont(font4);

        formLayout->setWidget(13, QFormLayout::LabelRole, label_56);

        cur_temp_1 = new QLabel(ns_widget);
        cur_temp_1->setObjectName("cur_temp_1");
        cur_temp_1->setMinimumSize(QSize(80, 0));
        cur_temp_1->setMaximumSize(QSize(80, 16777215));
        cur_temp_1->setFont(font5);

        formLayout->setWidget(13, QFormLayout::FieldRole, cur_temp_1);

        label_40 = new QLabel(ns_widget);
        label_40->setObjectName("label_40");
        label_40->setMinimumSize(QSize(120, 0));
        label_40->setMaximumSize(QSize(120, 16777215));
        label_40->setFont(font4);

        formLayout->setWidget(14, QFormLayout::LabelRole, label_40);

        pd_forward = new QLabel(ns_widget);
        pd_forward->setObjectName("pd_forward");
        pd_forward->setMinimumSize(QSize(80, 0));
        pd_forward->setMaximumSize(QSize(80, 16777215));
        pd_forward->setFont(font5);

        formLayout->setWidget(14, QFormLayout::FieldRole, pd_forward);

        label_44 = new QLabel(ns_widget);
        label_44->setObjectName("label_44");
        label_44->setMinimumSize(QSize(120, 0));
        label_44->setMaximumSize(QSize(120, 16777215));
        label_44->setFont(font4);

        formLayout->setWidget(15, QFormLayout::LabelRole, label_44);

        pd_forward_2 = new QLabel(ns_widget);
        pd_forward_2->setObjectName("pd_forward_2");
        pd_forward_2->setMinimumSize(QSize(80, 0));
        pd_forward_2->setMaximumSize(QSize(80, 16777215));
        pd_forward_2->setFont(font5);

        formLayout->setWidget(15, QFormLayout::FieldRole, pd_forward_2);

        label_41 = new QLabel(ns_widget);
        label_41->setObjectName("label_41");
        label_41->setMinimumSize(QSize(120, 0));
        label_41->setMaximumSize(QSize(120, 16777215));
        label_41->setFont(font4);

        formLayout->setWidget(16, QFormLayout::LabelRole, label_41);

        pd_backward = new QLabel(ns_widget);
        pd_backward->setObjectName("pd_backward");
        pd_backward->setMinimumSize(QSize(80, 0));
        pd_backward->setMaximumSize(QSize(80, 16777215));
        pd_backward->setFont(font5);

        formLayout->setWidget(16, QFormLayout::FieldRole, pd_backward);

        label_45 = new QLabel(ns_widget);
        label_45->setObjectName("label_45");
        label_45->setMinimumSize(QSize(120, 0));
        label_45->setMaximumSize(QSize(120, 16777215));
        label_45->setFont(font4);

        formLayout->setWidget(17, QFormLayout::LabelRole, label_45);

        pd_backward_2 = new QLabel(ns_widget);
        pd_backward_2->setObjectName("pd_backward_2");
        pd_backward_2->setMinimumSize(QSize(80, 0));
        pd_backward_2->setMaximumSize(QSize(80, 16777215));
        pd_backward_2->setFont(font5);

        formLayout->setWidget(17, QFormLayout::FieldRole, pd_backward_2);

        label_error = new QLabel(ns_widget);
        label_error->setObjectName("label_error");
        label_error->setMinimumSize(QSize(120, 0));
        label_error->setMaximumSize(QSize(120, 16777215));
        label_error->setFont(font4);

        formLayout->setWidget(18, QFormLayout::LabelRole, label_error);

        button_error = new QPushButton(ns_widget);
        button_error->setObjectName("button_error");

        formLayout->setWidget(18, QFormLayout::FieldRole, button_error);

        label_57 = new QLabel(ns_widget);
        label_57->setObjectName("label_57");
        label_57->setMinimumSize(QSize(120, 0));
        label_57->setMaximumSize(QSize(120, 16777215));
        label_57->setFont(font4);

        formLayout->setWidget(10, QFormLayout::LabelRole, label_57);

        over_temp_label_1 = new QLabel(ns_widget);
        over_temp_label_1->setObjectName("over_temp_label_1");
        over_temp_label_1->setMinimumSize(QSize(80, 0));
        over_temp_label_1->setMaximumSize(QSize(80, 16777215));
        over_temp_label_1->setFont(font5);

        formLayout->setWidget(10, QFormLayout::FieldRole, over_temp_label_1);


        verticalLayout_16->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_16->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_16, 0, 7, 5, 1);

        line = new QFrame(ns_widget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 6, 6, 1);


        verticalLayout_28->addWidget(ns_widget);


        verticalLayout_2->addWidget(groupBox);


        retranslateUi(cb_panel);

        QMetaObject::connectSlotsByName(cb_panel);
    } // setupUi

    void retranslateUi(QWidget *cb_panel)
    {
        cb_panel->setWindowTitle(QCoreApplication::translate("cb_panel", "Form", nullptr));
        groupBox->setTitle(QString());
        laser_name_label->setText(QCoreApplication::translate("cb_panel", "Contol Board", nullptr));
        groupBox_16->setTitle(QCoreApplication::translate("cb_panel", "Level", nullptr));
        label_29->setText(QCoreApplication::translate("cb_panel", "Forward 1", nullptr));
        forward_treashold->setSuffix(QString());
        label_31->setText(QCoreApplication::translate("cb_panel", "Backward 1", nullptr));
        backward_treashold->setSuffix(QString());
        label_33->setText(QCoreApplication::translate("cb_panel", "Forward 2", nullptr));
        forward_treashold_2->setSuffix(QString());
        label_34->setText(QCoreApplication::translate("cb_panel", "Backward 2", nullptr));
        backward_treashold_2->setSuffix(QString());
        groupBox_12->setTitle(QCoreApplication::translate("cb_panel", "Current HPLD", nullptr));
        label_24->setText(QCoreApplication::translate("cb_panel", "0", nullptr));
        hpld_curr_0->setSuffix(QString());
        label_30->setText(QCoreApplication::translate("cb_panel", "1", nullptr));
        hpld_curr_1->setSuffix(QString());
        groupBox_14->setTitle(QCoreApplication::translate("cb_panel", "Thermistor", nullptr));
        label->setText(QCoreApplication::translate("cb_panel", " Resistanse", nullptr));
        therm_resis->setSuffix(QString());
        label_2->setText(QCoreApplication::translate("cb_panel", "Vref", nullptr));
        therm_vref->setSuffix(QString());
        label_3->setText(QCoreApplication::translate("cb_panel", "Beta", nullptr));
        therm_beta->setSuffix(QString());
        groupBox_19->setTitle(QCoreApplication::translate("cb_panel", "Overheat temperature", nullptr));
        label_25->setText(QCoreApplication::translate("cb_panel", "0", nullptr));
        over_temp_00->setSuffix(QString());
        label_26->setText(QCoreApplication::translate("cb_panel", "1", nullptr));
        over_temp_01->setSuffix(QString());
        label_11->setText(QCoreApplication::translate("cb_panel", "Read Values:", nullptr));
        label_35->setText(QCoreApplication::translate("cb_panel", "Cur. HPLD 0 :", nullptr));
        hpld_curr_label_0->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_36->setText(QCoreApplication::translate("cb_panel", "Cur. HPLD 1 :", nullptr));
        hpld_curr_label_1->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_38->setText(QCoreApplication::translate("cb_panel", "Level forward 1:", nullptr));
        forward_treashold_label->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_42->setText(QCoreApplication::translate("cb_panel", "Level forward 2:", nullptr));
        forward_treashold_label_2->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_39->setText(QCoreApplication::translate("cb_panel", "Level backw. 1:", nullptr));
        backward_treashold_label->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_43->setText(QCoreApplication::translate("cb_panel", "Level backw. 2:", nullptr));
        backward_treashold_label_2->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_52->setText(QCoreApplication::translate("cb_panel", "Therm. resis. :", nullptr));
        therm_resis_label->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_54->setText(QCoreApplication::translate("cb_panel", "Therm. Vref:", nullptr));
        therm_vref_label->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_53->setText(QCoreApplication::translate("cb_panel", "Therm. Beta:", nullptr));
        therm_beta_label->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_55->setText(QCoreApplication::translate("cb_panel", "Overheat temp.0:", nullptr));
        over_temp_label_0->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_50->setText(QCoreApplication::translate("cb_panel", "Temp.  0:", nullptr));
        cur_temp_0->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_56->setText(QCoreApplication::translate("cb_panel", "Temp.  1:", nullptr));
        cur_temp_1->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_40->setText(QCoreApplication::translate("cb_panel", "PD forward 1:", nullptr));
        pd_forward->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_44->setText(QCoreApplication::translate("cb_panel", "PD forward 2:", nullptr));
        pd_forward_2->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_41->setText(QCoreApplication::translate("cb_panel", "PD backward 1:", nullptr));
        pd_backward->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_45->setText(QCoreApplication::translate("cb_panel", "PD backward 2:", nullptr));
        pd_backward_2->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_error->setText(QCoreApplication::translate("cb_panel", "Errors:", nullptr));
        button_error->setText(QCoreApplication::translate("cb_panel", "\320\224\320\265\321\202\320\260\320\273\320\270", nullptr));
        label_57->setText(QCoreApplication::translate("cb_panel", "Overheat temp.1:", nullptr));
        over_temp_label_1->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cb_panel: public Ui_cb_panel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CB_PANEL_H
