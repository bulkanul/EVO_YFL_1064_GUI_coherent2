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
    QGroupBox *groupBox_15;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_37;
    QLabel *label_29;
    QHBoxLayout *horizontalLayout_22;
    QDoubleSpinBox *curr_lvl_0;
    QVBoxLayout *verticalLayout_38;
    QLabel *label_22;
    QHBoxLayout *horizontalLayout_15;
    QDoubleSpinBox *curr_lvl_1;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_11;
    QFormLayout *formLayout;
    QLabel *label_35;
    QLabel *forward_label_0;
    QLabel *label_36;
    QLabel *forward_label_1;
    QLabel *label_42;
    QLabel *backward_label_0;
    QLabel *label_43;
    QLabel *backward_label_1;
    QLabel *label_38;
    QLabel *forward_level_label_0;
    QLabel *label_39;
    QLabel *forward_level_label_1;
    QLabel *label_44;
    QLabel *backward_level_label_0;
    QLabel *label_45;
    QLabel *backward_level_label_1;
    QLabel *label_47;
    QLabel *temp_label_0;
    QLabel *label_49;
    QLabel *temp_label_1;
    QLabel *label_50;
    QLabel *temp_level_label_0;
    QLabel *label_51;
    QLabel *temp_level_label_1;
    QLabel *label_error;
    QPushButton *button_error;
    QLabel *label_52;
    QLabel *label_53;
    QLabel *curr_level_label_0;
    QLabel *curr_level_label_1;
    QSpacerItem *verticalSpacer;
    QFrame *line;
    QGroupBox *groupBox_13;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_32;
    QLabel *label_25;
    QHBoxLayout *horizontalLayout_18;
    QDoubleSpinBox *backward_treashold_0;
    QVBoxLayout *verticalLayout_33;
    QLabel *label_26;
    QHBoxLayout *horizontalLayout_19;
    QDoubleSpinBox *backward_treashold_1;
    QGroupBox *groupBox_14;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_35;
    QLabel *label_27;
    QHBoxLayout *horizontalLayout_20;
    QDoubleSpinBox *temp_level_0;
    QGroupBox *groupBox_12;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_29;
    QLabel *label_24;
    QHBoxLayout *horizontalLayout_17;
    QDoubleSpinBox *forward_treashold_0;
    QVBoxLayout *verticalLayout_30;
    QLabel *label_21;
    QHBoxLayout *horizontalLayout_14;
    QDoubleSpinBox *forward_treashold_1;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *cb_panel)
    {
        if (cb_panel->objectName().isEmpty())
            cb_panel->setObjectName("cb_panel");
        cb_panel->resize(1003, 508);
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
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_16->sizePolicy().hasHeightForWidth());
        groupBox_16->setSizePolicy(sizePolicy);
        groupBox_16->setFlat(false);
        groupBox_16->setCheckable(false);
        horizontalLayout_4 = new QHBoxLayout(groupBox_16);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(-1, 12, -1, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(groupBox_16);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        therm_resis = new QDoubleSpinBox(groupBox_16);
        therm_resis->setObjectName("therm_resis");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(100);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(therm_resis->sizePolicy().hasHeightForWidth());
        therm_resis->setSizePolicy(sizePolicy1);
        therm_resis->setMinimumSize(QSize(50, 0));
        therm_resis->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setPointSize(13);
        therm_resis->setFont(font1);
        therm_resis->setFocusPolicy(Qt::ClickFocus);
        therm_resis->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        therm_resis->setDecimals(0);
        therm_resis->setMinimum(0.000000000000000);
        therm_resis->setMaximum(100000.000000000000000);
        therm_resis->setSingleStep(1.000000000000000);
        therm_resis->setStepType(QAbstractSpinBox::DefaultStepType);
        therm_resis->setValue(0.000000000000000);

        verticalLayout->addWidget(therm_resis);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_2 = new QLabel(groupBox_16);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        therm_vref = new QDoubleSpinBox(groupBox_16);
        therm_vref->setObjectName("therm_vref");
        sizePolicy1.setHeightForWidth(therm_vref->sizePolicy().hasHeightForWidth());
        therm_vref->setSizePolicy(sizePolicy1);
        therm_vref->setMinimumSize(QSize(50, 0));
        therm_vref->setMaximumSize(QSize(16777215, 16777215));
        therm_vref->setFont(font1);
        therm_vref->setFocusPolicy(Qt::ClickFocus);
        therm_vref->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        therm_vref->setDecimals(3);
        therm_vref->setMinimum(0.000000000000000);
        therm_vref->setMaximum(3.000000000000000);
        therm_vref->setSingleStep(0.100000000000000);
        therm_vref->setStepType(QAbstractSpinBox::DefaultStepType);
        therm_vref->setValue(0.000000000000000);

        verticalLayout_3->addWidget(therm_vref);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_3 = new QLabel(groupBox_16);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_3);

        therm_beta = new QDoubleSpinBox(groupBox_16);
        therm_beta->setObjectName("therm_beta");
        sizePolicy1.setHeightForWidth(therm_beta->sizePolicy().hasHeightForWidth());
        therm_beta->setSizePolicy(sizePolicy1);
        therm_beta->setMinimumSize(QSize(50, 0));
        therm_beta->setMaximumSize(QSize(16777215, 16777215));
        therm_beta->setFont(font1);
        therm_beta->setFocusPolicy(Qt::ClickFocus);
        therm_beta->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        therm_beta->setDecimals(0);
        therm_beta->setMinimum(0.000000000000000);
        therm_beta->setMaximum(100000.000000000000000);
        therm_beta->setSingleStep(1.000000000000000);
        therm_beta->setStepType(QAbstractSpinBox::DefaultStepType);
        therm_beta->setValue(0.000000000000000);

        verticalLayout_4->addWidget(therm_beta);


        horizontalLayout_4->addLayout(verticalLayout_4);


        gridLayout->addWidget(groupBox_16, 1, 1, 1, 2);

        groupBox_15 = new QGroupBox(ns_widget);
        groupBox_15->setObjectName("groupBox_15");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_15->sizePolicy().hasHeightForWidth());
        groupBox_15->setSizePolicy(sizePolicy2);
        groupBox_15->setFlat(false);
        groupBox_15->setCheckable(false);
        horizontalLayout_5 = new QHBoxLayout(groupBox_15);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(-1, 12, -1, -1);
        verticalLayout_37 = new QVBoxLayout();
        verticalLayout_37->setObjectName("verticalLayout_37");
        label_29 = new QLabel(groupBox_15);
        label_29->setObjectName("label_29");
        label_29->setMinimumSize(QSize(0, 0));
        QFont font2;
        font2.setPointSize(12);
        label_29->setFont(font2);
        label_29->setAlignment(Qt::AlignCenter);

        verticalLayout_37->addWidget(label_29);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName("horizontalLayout_22");
        curr_lvl_0 = new QDoubleSpinBox(groupBox_15);
        curr_lvl_0->setObjectName("curr_lvl_0");
        sizePolicy1.setHeightForWidth(curr_lvl_0->sizePolicy().hasHeightForWidth());
        curr_lvl_0->setSizePolicy(sizePolicy1);
        curr_lvl_0->setMinimumSize(QSize(50, 0));
        curr_lvl_0->setMaximumSize(QSize(16777215, 16777215));
        curr_lvl_0->setFont(font1);
        curr_lvl_0->setFocusPolicy(Qt::ClickFocus);
        curr_lvl_0->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        curr_lvl_0->setDecimals(2);
        curr_lvl_0->setMinimum(0.000000000000000);
        curr_lvl_0->setMaximum(26.000000000000000);
        curr_lvl_0->setSingleStep(0.100000000000000);
        curr_lvl_0->setStepType(QAbstractSpinBox::DefaultStepType);
        curr_lvl_0->setValue(0.000000000000000);

        horizontalLayout_22->addWidget(curr_lvl_0);


        verticalLayout_37->addLayout(horizontalLayout_22);


        horizontalLayout_5->addLayout(verticalLayout_37);

        verticalLayout_38 = new QVBoxLayout();
        verticalLayout_38->setObjectName("verticalLayout_38");
        label_22 = new QLabel(groupBox_15);
        label_22->setObjectName("label_22");
        label_22->setMinimumSize(QSize(0, 0));
        label_22->setFont(font2);
        label_22->setAlignment(Qt::AlignCenter);

        verticalLayout_38->addWidget(label_22);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        curr_lvl_1 = new QDoubleSpinBox(groupBox_15);
        curr_lvl_1->setObjectName("curr_lvl_1");
        sizePolicy1.setHeightForWidth(curr_lvl_1->sizePolicy().hasHeightForWidth());
        curr_lvl_1->setSizePolicy(sizePolicy1);
        curr_lvl_1->setMinimumSize(QSize(50, 0));
        curr_lvl_1->setMaximumSize(QSize(16777215, 16777215));
        curr_lvl_1->setFont(font1);
        curr_lvl_1->setFocusPolicy(Qt::ClickFocus);
        curr_lvl_1->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        curr_lvl_1->setDecimals(2);
        curr_lvl_1->setMinimum(0.000000000000000);
        curr_lvl_1->setMaximum(26.000000000000000);
        curr_lvl_1->setSingleStep(0.100000000000000);
        curr_lvl_1->setStepType(QAbstractSpinBox::DefaultStepType);
        curr_lvl_1->setValue(0.000000000000000);

        horizontalLayout_15->addWidget(curr_lvl_1);


        verticalLayout_38->addLayout(horizontalLayout_15);


        horizontalLayout_5->addLayout(verticalLayout_38);


        gridLayout->addWidget(groupBox_15, 1, 0, 1, 1);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setObjectName("verticalLayout_16");
        verticalLayout_16->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(ns_widget);
        label_11->setObjectName("label_11");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy3);
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

        forward_label_0 = new QLabel(ns_widget);
        forward_label_0->setObjectName("forward_label_0");
        forward_label_0->setMinimumSize(QSize(80, 0));
        forward_label_0->setMaximumSize(QSize(80, 16777215));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(true);
        forward_label_0->setFont(font5);

        formLayout->setWidget(0, QFormLayout::FieldRole, forward_label_0);

        label_36 = new QLabel(ns_widget);
        label_36->setObjectName("label_36");
        label_36->setMinimumSize(QSize(120, 0));
        label_36->setMaximumSize(QSize(120, 16777215));
        label_36->setFont(font4);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_36);

        forward_label_1 = new QLabel(ns_widget);
        forward_label_1->setObjectName("forward_label_1");
        forward_label_1->setMinimumSize(QSize(80, 0));
        forward_label_1->setMaximumSize(QSize(80, 16777215));
        forward_label_1->setFont(font5);

        formLayout->setWidget(1, QFormLayout::FieldRole, forward_label_1);

        label_42 = new QLabel(ns_widget);
        label_42->setObjectName("label_42");
        label_42->setMinimumSize(QSize(120, 0));
        label_42->setMaximumSize(QSize(120, 16777215));
        label_42->setFont(font4);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_42);

        backward_label_0 = new QLabel(ns_widget);
        backward_label_0->setObjectName("backward_label_0");
        backward_label_0->setMinimumSize(QSize(80, 0));
        backward_label_0->setMaximumSize(QSize(80, 16777215));
        backward_label_0->setFont(font5);

        formLayout->setWidget(2, QFormLayout::FieldRole, backward_label_0);

        label_43 = new QLabel(ns_widget);
        label_43->setObjectName("label_43");
        label_43->setMinimumSize(QSize(120, 0));
        label_43->setMaximumSize(QSize(120, 16777215));
        label_43->setFont(font4);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_43);

        backward_label_1 = new QLabel(ns_widget);
        backward_label_1->setObjectName("backward_label_1");
        backward_label_1->setMinimumSize(QSize(80, 0));
        backward_label_1->setMaximumSize(QSize(80, 16777215));
        backward_label_1->setFont(font5);

        formLayout->setWidget(3, QFormLayout::FieldRole, backward_label_1);

        label_38 = new QLabel(ns_widget);
        label_38->setObjectName("label_38");
        label_38->setMinimumSize(QSize(120, 0));
        label_38->setMaximumSize(QSize(120, 16777215));
        label_38->setFont(font4);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_38);

        forward_level_label_0 = new QLabel(ns_widget);
        forward_level_label_0->setObjectName("forward_level_label_0");
        forward_level_label_0->setMinimumSize(QSize(80, 0));
        forward_level_label_0->setMaximumSize(QSize(80, 16777215));
        forward_level_label_0->setFont(font5);

        formLayout->setWidget(4, QFormLayout::FieldRole, forward_level_label_0);

        label_39 = new QLabel(ns_widget);
        label_39->setObjectName("label_39");
        label_39->setMinimumSize(QSize(120, 0));
        label_39->setMaximumSize(QSize(120, 16777215));
        label_39->setFont(font4);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_39);

        forward_level_label_1 = new QLabel(ns_widget);
        forward_level_label_1->setObjectName("forward_level_label_1");
        forward_level_label_1->setMinimumSize(QSize(80, 0));
        forward_level_label_1->setMaximumSize(QSize(80, 16777215));
        forward_level_label_1->setFont(font5);

        formLayout->setWidget(5, QFormLayout::FieldRole, forward_level_label_1);

        label_44 = new QLabel(ns_widget);
        label_44->setObjectName("label_44");
        label_44->setMinimumSize(QSize(120, 0));
        label_44->setMaximumSize(QSize(120, 16777215));
        label_44->setFont(font4);

        formLayout->setWidget(6, QFormLayout::LabelRole, label_44);

        backward_level_label_0 = new QLabel(ns_widget);
        backward_level_label_0->setObjectName("backward_level_label_0");
        backward_level_label_0->setMinimumSize(QSize(80, 0));
        backward_level_label_0->setMaximumSize(QSize(80, 16777215));
        backward_level_label_0->setFont(font5);

        formLayout->setWidget(6, QFormLayout::FieldRole, backward_level_label_0);

        label_45 = new QLabel(ns_widget);
        label_45->setObjectName("label_45");
        label_45->setMinimumSize(QSize(120, 0));
        label_45->setMaximumSize(QSize(120, 16777215));
        label_45->setFont(font4);

        formLayout->setWidget(7, QFormLayout::LabelRole, label_45);

        backward_level_label_1 = new QLabel(ns_widget);
        backward_level_label_1->setObjectName("backward_level_label_1");
        backward_level_label_1->setMinimumSize(QSize(80, 0));
        backward_level_label_1->setMaximumSize(QSize(80, 16777215));
        backward_level_label_1->setFont(font5);

        formLayout->setWidget(7, QFormLayout::FieldRole, backward_level_label_1);

        label_47 = new QLabel(ns_widget);
        label_47->setObjectName("label_47");
        label_47->setMinimumSize(QSize(120, 0));
        label_47->setMaximumSize(QSize(120, 16777215));
        label_47->setFont(font4);

        formLayout->setWidget(8, QFormLayout::LabelRole, label_47);

        temp_label_0 = new QLabel(ns_widget);
        temp_label_0->setObjectName("temp_label_0");
        temp_label_0->setMinimumSize(QSize(80, 0));
        temp_label_0->setMaximumSize(QSize(80, 16777215));
        temp_label_0->setFont(font5);

        formLayout->setWidget(8, QFormLayout::FieldRole, temp_label_0);

        label_49 = new QLabel(ns_widget);
        label_49->setObjectName("label_49");
        label_49->setMinimumSize(QSize(120, 0));
        label_49->setMaximumSize(QSize(120, 16777215));
        label_49->setFont(font4);

        formLayout->setWidget(9, QFormLayout::LabelRole, label_49);

        temp_label_1 = new QLabel(ns_widget);
        temp_label_1->setObjectName("temp_label_1");
        temp_label_1->setMinimumSize(QSize(80, 0));
        temp_label_1->setMaximumSize(QSize(80, 16777215));
        temp_label_1->setFont(font5);

        formLayout->setWidget(9, QFormLayout::FieldRole, temp_label_1);

        label_50 = new QLabel(ns_widget);
        label_50->setObjectName("label_50");
        label_50->setMinimumSize(QSize(120, 0));
        label_50->setMaximumSize(QSize(120, 16777215));
        label_50->setFont(font4);

        formLayout->setWidget(10, QFormLayout::LabelRole, label_50);

        temp_level_label_0 = new QLabel(ns_widget);
        temp_level_label_0->setObjectName("temp_level_label_0");
        temp_level_label_0->setMinimumSize(QSize(80, 0));
        temp_level_label_0->setMaximumSize(QSize(80, 16777215));
        temp_level_label_0->setFont(font5);

        formLayout->setWidget(10, QFormLayout::FieldRole, temp_level_label_0);

        label_51 = new QLabel(ns_widget);
        label_51->setObjectName("label_51");
        label_51->setMinimumSize(QSize(120, 0));
        label_51->setMaximumSize(QSize(120, 16777215));
        label_51->setFont(font4);

        formLayout->setWidget(11, QFormLayout::LabelRole, label_51);

        temp_level_label_1 = new QLabel(ns_widget);
        temp_level_label_1->setObjectName("temp_level_label_1");
        temp_level_label_1->setMinimumSize(QSize(80, 0));
        temp_level_label_1->setMaximumSize(QSize(80, 16777215));
        temp_level_label_1->setFont(font5);

        formLayout->setWidget(11, QFormLayout::FieldRole, temp_level_label_1);

        label_error = new QLabel(ns_widget);
        label_error->setObjectName("label_error");
        label_error->setMinimumSize(QSize(120, 0));
        label_error->setMaximumSize(QSize(120, 16777215));
        label_error->setFont(font4);

        formLayout->setWidget(14, QFormLayout::LabelRole, label_error);

        button_error = new QPushButton(ns_widget);
        button_error->setObjectName("button_error");

        formLayout->setWidget(14, QFormLayout::FieldRole, button_error);

        label_52 = new QLabel(ns_widget);
        label_52->setObjectName("label_52");
        label_52->setMinimumSize(QSize(120, 0));
        label_52->setMaximumSize(QSize(120, 16777215));
        label_52->setFont(font4);

        formLayout->setWidget(12, QFormLayout::LabelRole, label_52);

        label_53 = new QLabel(ns_widget);
        label_53->setObjectName("label_53");
        label_53->setMinimumSize(QSize(120, 0));
        label_53->setMaximumSize(QSize(120, 16777215));
        label_53->setFont(font4);

        formLayout->setWidget(13, QFormLayout::LabelRole, label_53);

        curr_level_label_0 = new QLabel(ns_widget);
        curr_level_label_0->setObjectName("curr_level_label_0");
        curr_level_label_0->setMinimumSize(QSize(80, 0));
        curr_level_label_0->setMaximumSize(QSize(80, 16777215));
        curr_level_label_0->setFont(font5);

        formLayout->setWidget(12, QFormLayout::FieldRole, curr_level_label_0);

        curr_level_label_1 = new QLabel(ns_widget);
        curr_level_label_1->setObjectName("curr_level_label_1");
        curr_level_label_1->setMinimumSize(QSize(80, 0));
        curr_level_label_1->setMaximumSize(QSize(80, 16777215));
        curr_level_label_1->setFont(font5);

        formLayout->setWidget(13, QFormLayout::FieldRole, curr_level_label_1);


        verticalLayout_16->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_16->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_16, 0, 4, 4, 1);

        line = new QFrame(ns_widget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 3, 3, 1);

        groupBox_13 = new QGroupBox(ns_widget);
        groupBox_13->setObjectName("groupBox_13");
        sizePolicy2.setHeightForWidth(groupBox_13->sizePolicy().hasHeightForWidth());
        groupBox_13->setSizePolicy(sizePolicy2);
        groupBox_13->setFlat(false);
        groupBox_13->setCheckable(false);
        horizontalLayout_2 = new QHBoxLayout(groupBox_13);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(-1, 12, -1, -1);
        verticalLayout_32 = new QVBoxLayout();
        verticalLayout_32->setObjectName("verticalLayout_32");
        label_25 = new QLabel(groupBox_13);
        label_25->setObjectName("label_25");
        label_25->setMinimumSize(QSize(0, 0));
        label_25->setFont(font2);
        label_25->setAlignment(Qt::AlignCenter);

        verticalLayout_32->addWidget(label_25);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        backward_treashold_0 = new QDoubleSpinBox(groupBox_13);
        backward_treashold_0->setObjectName("backward_treashold_0");
        sizePolicy1.setHeightForWidth(backward_treashold_0->sizePolicy().hasHeightForWidth());
        backward_treashold_0->setSizePolicy(sizePolicy1);
        backward_treashold_0->setMinimumSize(QSize(50, 0));
        backward_treashold_0->setMaximumSize(QSize(16777215, 16777215));
        backward_treashold_0->setFont(font1);
        backward_treashold_0->setFocusPolicy(Qt::ClickFocus);
        backward_treashold_0->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        backward_treashold_0->setDecimals(2);
        backward_treashold_0->setMinimum(0.000000000000000);
        backward_treashold_0->setMaximum(3.300000000000000);
        backward_treashold_0->setSingleStep(0.100000000000000);
        backward_treashold_0->setStepType(QAbstractSpinBox::DefaultStepType);
        backward_treashold_0->setValue(0.000000000000000);

        horizontalLayout_18->addWidget(backward_treashold_0);


        verticalLayout_32->addLayout(horizontalLayout_18);


        horizontalLayout_2->addLayout(verticalLayout_32);

        verticalLayout_33 = new QVBoxLayout();
        verticalLayout_33->setObjectName("verticalLayout_33");
        label_26 = new QLabel(groupBox_13);
        label_26->setObjectName("label_26");
        label_26->setMinimumSize(QSize(0, 0));
        label_26->setFont(font2);
        label_26->setAlignment(Qt::AlignCenter);

        verticalLayout_33->addWidget(label_26);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        backward_treashold_1 = new QDoubleSpinBox(groupBox_13);
        backward_treashold_1->setObjectName("backward_treashold_1");
        sizePolicy1.setHeightForWidth(backward_treashold_1->sizePolicy().hasHeightForWidth());
        backward_treashold_1->setSizePolicy(sizePolicy1);
        backward_treashold_1->setMinimumSize(QSize(50, 0));
        backward_treashold_1->setMaximumSize(QSize(16777215, 16777215));
        backward_treashold_1->setFont(font1);
        backward_treashold_1->setFocusPolicy(Qt::ClickFocus);
        backward_treashold_1->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        backward_treashold_1->setDecimals(2);
        backward_treashold_1->setMinimum(0.000000000000000);
        backward_treashold_1->setMaximum(3.300000000000000);
        backward_treashold_1->setSingleStep(0.100000000000000);
        backward_treashold_1->setStepType(QAbstractSpinBox::DefaultStepType);
        backward_treashold_1->setValue(0.000000000000000);

        horizontalLayout_19->addWidget(backward_treashold_1);


        verticalLayout_33->addLayout(horizontalLayout_19);


        horizontalLayout_2->addLayout(verticalLayout_33);


        gridLayout->addWidget(groupBox_13, 0, 1, 1, 1);

        groupBox_14 = new QGroupBox(ns_widget);
        groupBox_14->setObjectName("groupBox_14");
        sizePolicy2.setHeightForWidth(groupBox_14->sizePolicy().hasHeightForWidth());
        groupBox_14->setSizePolicy(sizePolicy2);
        groupBox_14->setFlat(false);
        groupBox_14->setCheckable(false);
        horizontalLayout_3 = new QHBoxLayout(groupBox_14);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(-1, 12, -1, -1);
        verticalLayout_35 = new QVBoxLayout();
        verticalLayout_35->setObjectName("verticalLayout_35");
        label_27 = new QLabel(groupBox_14);
        label_27->setObjectName("label_27");
        label_27->setMinimumSize(QSize(0, 0));
        label_27->setFont(font2);
        label_27->setAlignment(Qt::AlignCenter);

        verticalLayout_35->addWidget(label_27);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        temp_level_0 = new QDoubleSpinBox(groupBox_14);
        temp_level_0->setObjectName("temp_level_0");
        sizePolicy1.setHeightForWidth(temp_level_0->sizePolicy().hasHeightForWidth());
        temp_level_0->setSizePolicy(sizePolicy1);
        temp_level_0->setMinimumSize(QSize(50, 0));
        temp_level_0->setMaximumSize(QSize(16777215, 16777215));
        temp_level_0->setFont(font1);
        temp_level_0->setFocusPolicy(Qt::ClickFocus);
        temp_level_0->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        temp_level_0->setDecimals(2);
        temp_level_0->setMinimum(0.000000000000000);
        temp_level_0->setMaximum(70.000000000000000);
        temp_level_0->setSingleStep(0.100000000000000);
        temp_level_0->setStepType(QAbstractSpinBox::DefaultStepType);
        temp_level_0->setValue(0.000000000000000);

        horizontalLayout_20->addWidget(temp_level_0);


        verticalLayout_35->addLayout(horizontalLayout_20);


        horizontalLayout_3->addLayout(verticalLayout_35);


        gridLayout->addWidget(groupBox_14, 0, 2, 1, 1);

        groupBox_12 = new QGroupBox(ns_widget);
        groupBox_12->setObjectName("groupBox_12");
        sizePolicy2.setHeightForWidth(groupBox_12->sizePolicy().hasHeightForWidth());
        groupBox_12->setSizePolicy(sizePolicy2);
        groupBox_12->setFlat(false);
        groupBox_12->setCheckable(false);
        horizontalLayout = new QHBoxLayout(groupBox_12);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 12, -1, -1);
        verticalLayout_29 = new QVBoxLayout();
        verticalLayout_29->setObjectName("verticalLayout_29");
        label_24 = new QLabel(groupBox_12);
        label_24->setObjectName("label_24");
        label_24->setMinimumSize(QSize(0, 0));
        label_24->setFont(font2);
        label_24->setAlignment(Qt::AlignCenter);

        verticalLayout_29->addWidget(label_24);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        forward_treashold_0 = new QDoubleSpinBox(groupBox_12);
        forward_treashold_0->setObjectName("forward_treashold_0");
        sizePolicy1.setHeightForWidth(forward_treashold_0->sizePolicy().hasHeightForWidth());
        forward_treashold_0->setSizePolicy(sizePolicy1);
        forward_treashold_0->setMinimumSize(QSize(50, 0));
        forward_treashold_0->setMaximumSize(QSize(16777215, 16777215));
        forward_treashold_0->setFont(font1);
        forward_treashold_0->setFocusPolicy(Qt::ClickFocus);
        forward_treashold_0->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        forward_treashold_0->setDecimals(2);
        forward_treashold_0->setMinimum(0.000000000000000);
        forward_treashold_0->setMaximum(3.300000000000000);
        forward_treashold_0->setSingleStep(0.100000000000000);
        forward_treashold_0->setStepType(QAbstractSpinBox::DefaultStepType);
        forward_treashold_0->setValue(0.000000000000000);

        horizontalLayout_17->addWidget(forward_treashold_0);


        verticalLayout_29->addLayout(horizontalLayout_17);


        horizontalLayout->addLayout(verticalLayout_29);

        verticalLayout_30 = new QVBoxLayout();
        verticalLayout_30->setObjectName("verticalLayout_30");
        label_21 = new QLabel(groupBox_12);
        label_21->setObjectName("label_21");
        label_21->setMinimumSize(QSize(0, 0));
        label_21->setFont(font2);
        label_21->setAlignment(Qt::AlignCenter);

        verticalLayout_30->addWidget(label_21);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        forward_treashold_1 = new QDoubleSpinBox(groupBox_12);
        forward_treashold_1->setObjectName("forward_treashold_1");
        sizePolicy1.setHeightForWidth(forward_treashold_1->sizePolicy().hasHeightForWidth());
        forward_treashold_1->setSizePolicy(sizePolicy1);
        forward_treashold_1->setMinimumSize(QSize(50, 0));
        forward_treashold_1->setMaximumSize(QSize(16777215, 16777215));
        forward_treashold_1->setFont(font1);
        forward_treashold_1->setFocusPolicy(Qt::ClickFocus);
        forward_treashold_1->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        forward_treashold_1->setDecimals(2);
        forward_treashold_1->setMinimum(0.000000000000000);
        forward_treashold_1->setMaximum(3.300000000000000);
        forward_treashold_1->setSingleStep(0.100000000000000);
        forward_treashold_1->setStepType(QAbstractSpinBox::DefaultStepType);
        forward_treashold_1->setValue(0.000000000000000);

        horizontalLayout_14->addWidget(forward_treashold_1);


        verticalLayout_30->addLayout(horizontalLayout_14);


        horizontalLayout->addLayout(verticalLayout_30);


        gridLayout->addWidget(groupBox_12, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 4, 1, 1, 1);


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
        groupBox_16->setTitle(QCoreApplication::translate("cb_panel", "Thermistor", nullptr));
        label->setText(QCoreApplication::translate("cb_panel", " Resistanse", nullptr));
        therm_resis->setSuffix(QString());
        label_2->setText(QCoreApplication::translate("cb_panel", "Vref", nullptr));
        therm_vref->setSuffix(QString());
        label_3->setText(QCoreApplication::translate("cb_panel", "Beta", nullptr));
        therm_beta->setSuffix(QString());
        groupBox_15->setTitle(QCoreApplication::translate("cb_panel", "\320\237\320\276\321\200\320\276\320\263\320\270 \321\202\320\276\320\272\320\276\320\262 DCDC", nullptr));
        label_29->setText(QCoreApplication::translate("cb_panel", "0", nullptr));
        curr_lvl_0->setSuffix(QString());
        label_22->setText(QCoreApplication::translate("cb_panel", "1", nullptr));
        curr_lvl_1->setSuffix(QString());
        label_11->setText(QCoreApplication::translate("cb_panel", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213:", nullptr));
        label_35->setText(QCoreApplication::translate("cb_panel", "\320\237\321\200\321\217\320\274\320\276\320\271 \321\204\320\276\321\202\320\276 1:", nullptr));
        forward_label_0->setText(QCoreApplication::translate("cb_panel", "0.0", nullptr));
        label_36->setText(QCoreApplication::translate("cb_panel", "\320\237\321\200\321\217\320\274\320\276\320\271 \321\204\320\276\321\202\320\276 2:", nullptr));
        forward_label_1->setText(QCoreApplication::translate("cb_panel", "0.0", nullptr));
        label_42->setText(QCoreApplication::translate("cb_panel", "\320\236\320\261\321\200. \321\204\320\276\321\202\320\276 1:", nullptr));
        backward_label_0->setText(QCoreApplication::translate("cb_panel", "0.0", nullptr));
        label_43->setText(QCoreApplication::translate("cb_panel", "\320\236\320\261\321\200. \321\204\320\276\321\202\320\276 2:", nullptr));
        backward_label_1->setText(QCoreApplication::translate("cb_panel", "0.0", nullptr));
        label_38->setText(QCoreApplication::translate("cb_panel", "\320\237\320\276\321\200\320\276\320\263 \320\277\321\200\321\217\320\274\320\276\320\271 1:", nullptr));
        forward_level_label_0->setText(QCoreApplication::translate("cb_panel", "0.0", nullptr));
        label_39->setText(QCoreApplication::translate("cb_panel", "\320\237\320\276\321\200\320\276\320\263 \320\277\321\200\321\217\320\274\320\276\320\271 2:", nullptr));
        forward_level_label_1->setText(QCoreApplication::translate("cb_panel", "0.0", nullptr));
        label_44->setText(QCoreApplication::translate("cb_panel", "\320\237\320\276\321\200\320\276\320\263 \320\276\320\261\321\200. 1:", nullptr));
        backward_level_label_0->setText(QCoreApplication::translate("cb_panel", "0.0", nullptr));
        label_45->setText(QCoreApplication::translate("cb_panel", "\320\237\320\276\321\200\320\276\320\263 \320\276\320\261\321\200. 2:", nullptr));
        backward_level_label_1->setText(QCoreApplication::translate("cb_panel", "0.0", nullptr));
        label_47->setText(QCoreApplication::translate("cb_panel", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260 1:", nullptr));
        temp_label_0->setText(QCoreApplication::translate("cb_panel", "0.0", nullptr));
        label_49->setText(QCoreApplication::translate("cb_panel", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260 2:", nullptr));
        temp_label_1->setText(QCoreApplication::translate("cb_panel", "0.0", nullptr));
        label_50->setText(QCoreApplication::translate("cb_panel", "\320\237\320\276\321\200\320\276\320\263 \321\202\320\265\320\274\320\277\320\265\321\200. 1:", nullptr));
        temp_level_label_0->setText(QCoreApplication::translate("cb_panel", "0.0", nullptr));
        label_51->setText(QCoreApplication::translate("cb_panel", "\320\237\320\276\321\200\320\276\320\263 \321\202\320\265\320\274\320\277\320\265\321\200. 2:", nullptr));
        temp_level_label_1->setText(QCoreApplication::translate("cb_panel", "0.0", nullptr));
        label_error->setText(QCoreApplication::translate("cb_panel", "\320\236\321\210\320\270\320\261\320\272\320\270:", nullptr));
        button_error->setText(QCoreApplication::translate("cb_panel", "\320\241\320\277\320\270\321\201\320\276\320\272", nullptr));
        label_52->setText(QCoreApplication::translate("cb_panel", "\320\237-\320\263 \321\202\320\276\320\272\320\260 DC. 1:", nullptr));
        label_53->setText(QCoreApplication::translate("cb_panel", "\320\237-\320\263 \321\202\320\276\320\272\320\260 DC. 2:", nullptr));
        curr_level_label_0->setText(QCoreApplication::translate("cb_panel", "0.0", nullptr));
        curr_level_label_1->setText(QCoreApplication::translate("cb_panel", "0.0", nullptr));
        groupBox_13->setTitle(QCoreApplication::translate("cb_panel", "\320\237\320\276\321\200\320\276\320\263\320\270 \320\264\320\273\321\217 \320\276\320\261\321\200\320\260\321\202\320\275\321\213\321\205", nullptr));
        label_25->setText(QCoreApplication::translate("cb_panel", "0", nullptr));
        backward_treashold_0->setSuffix(QString());
        label_26->setText(QCoreApplication::translate("cb_panel", "1", nullptr));
        backward_treashold_1->setSuffix(QString());
        groupBox_14->setTitle(QCoreApplication::translate("cb_panel", "\320\237\320\276\321\200\320\276\320\263\320\270 \321\202\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200", nullptr));
        label_27->setText(QCoreApplication::translate("cb_panel", "0", nullptr));
        temp_level_0->setSuffix(QString());
        groupBox_12->setTitle(QCoreApplication::translate("cb_panel", "\320\237\320\276\321\200\320\276\320\263\320\270 \320\264\320\273\321\217 \320\277\321\200\321\217\320\274\321\213\321\205", nullptr));
        label_24->setText(QCoreApplication::translate("cb_panel", "0", nullptr));
        forward_treashold_0->setSuffix(QString());
        label_21->setText(QCoreApplication::translate("cb_panel", "1", nullptr));
        forward_treashold_1->setSuffix(QString());
    } // retranslateUi

};

namespace Ui {
    class cb_panel: public Ui_cb_panel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CB_PANEL_H
