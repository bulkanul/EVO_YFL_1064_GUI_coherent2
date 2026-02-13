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
    QVBoxLayout *verticalLayout_16;
    QLabel *label_11;
    QFormLayout *formLayout;
    QLabel *label_38;
    QLabel *forward_treashold_label;
    QLabel *label_39;
    QLabel *backward_treashold_label;
    QLabel *label_52;
    QLabel *therm_resis_label;
    QLabel *label_54;
    QLabel *therm_vref_label;
    QLabel *label_53;
    QLabel *therm_beta_label;
    QLabel *label_55;
    QLabel *over_temp_label;
    QFrame *line_2;
    QLabel *label_50;
    QLabel *cur_temp_0;
    QLabel *label_56;
    QLabel *cur_temp_1;
    QLabel *label_40;
    QLabel *pd_forward;
    QLabel *label_41;
    QLabel *pd_backward;
    QLabel *label_error;
    QPushButton *button_error;
    QSpacerItem *verticalSpacer;
    QFrame *line;
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
    QGroupBox *groupBox_19;
    QVBoxLayout *verticalLayout_14;
    QDoubleSpinBox *over_temp;
    QGroupBox *groupBox_14;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QDoubleSpinBox *therm_beta;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QDoubleSpinBox *therm_vref;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QDoubleSpinBox *therm_resis;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_18;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_52;
    QLabel *label_59;
    QHBoxLayout *horizontalLayout_41;
    QDoubleSpinBox *curr_max_3;
    QVBoxLayout *verticalLayout_55;
    QLabel *label_63;
    QHBoxLayout *horizontalLayout_45;
    QDoubleSpinBox *curr_max_6;
    QVBoxLayout *verticalLayout_34;
    QLabel *label_60;
    QHBoxLayout *horizontalLayout_42;
    QDoubleSpinBox *curr_max_1;
    QVBoxLayout *verticalLayout_50;
    QLabel *label_57;
    QHBoxLayout *horizontalLayout_39;
    QDoubleSpinBox *curr_max_0;
    QVBoxLayout *verticalLayout_51;
    QLabel *label_58;
    QHBoxLayout *horizontalLayout_40;
    QDoubleSpinBox *curr_max_2;
    QVBoxLayout *verticalLayout_53;
    QLabel *label_61;
    QHBoxLayout *horizontalLayout_43;
    QDoubleSpinBox *curr_max_4;
    QVBoxLayout *verticalLayout_54;
    QLabel *label_62;
    QHBoxLayout *horizontalLayout_44;
    QDoubleSpinBox *curr_max_5;
    QVBoxLayout *verticalLayout_56;
    QLabel *label_64;
    QHBoxLayout *horizontalLayout_46;
    QDoubleSpinBox *curr_max_7;
    QGroupBox *groupBox_17;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_41;
    QLabel *label_43;
    QHBoxLayout *horizontalLayout_29;
    QDoubleSpinBox *diode_treshold_6;
    QVBoxLayout *verticalLayout_32;
    QLabel *label_30;
    QHBoxLayout *horizontalLayout_22;
    QDoubleSpinBox *diode_treshold_1;
    QVBoxLayout *verticalLayout_39;
    QLabel *label_37;
    QHBoxLayout *horizontalLayout_27;
    QDoubleSpinBox *diode_treshold_4;
    QVBoxLayout *verticalLayout_37;
    QLabel *label_33;
    QHBoxLayout *horizontalLayout_25;
    QDoubleSpinBox *diode_treshold_2;
    QVBoxLayout *verticalLayout_36;
    QLabel *label_32;
    QHBoxLayout *horizontalLayout_24;
    QDoubleSpinBox *diode_treshold_0;
    QVBoxLayout *verticalLayout_38;
    QLabel *label_34;
    QHBoxLayout *horizontalLayout_26;
    QDoubleSpinBox *diode_treshold_3;
    QVBoxLayout *verticalLayout_40;
    QLabel *label_42;
    QHBoxLayout *horizontalLayout_28;
    QDoubleSpinBox *diode_treshold_5;
    QVBoxLayout *verticalLayout_42;
    QLabel *label_46;
    QHBoxLayout *horizontalLayout_30;
    QDoubleSpinBox *diode_treshold_7;
    QGroupBox *groupBox_12;
    QHBoxLayout *horizontalLayout_3;
    QDoubleSpinBox *voltage_pl;

    void setupUi(QWidget *cb_panel)
    {
        if (cb_panel->objectName().isEmpty())
            cb_panel->setObjectName("cb_panel");
        cb_panel->resize(1003, 437);
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
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setObjectName("verticalLayout_16");
        verticalLayout_16->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(ns_widget);
        label_11->setObjectName("label_11");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setMinimumSize(QSize(220, 0));
        label_11->setMaximumSize(QSize(220, 100000));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setKerning(true);
        label_11->setFont(font1);

        verticalLayout_16->addWidget(label_11);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_38 = new QLabel(ns_widget);
        label_38->setObjectName("label_38");
        label_38->setMinimumSize(QSize(120, 0));
        label_38->setMaximumSize(QSize(120, 16777215));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(12);
        label_38->setFont(font2);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_38);

        forward_treashold_label = new QLabel(ns_widget);
        forward_treashold_label->setObjectName("forward_treashold_label");
        forward_treashold_label->setMinimumSize(QSize(80, 0));
        forward_treashold_label->setMaximumSize(QSize(80, 16777215));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        forward_treashold_label->setFont(font3);

        formLayout->setWidget(0, QFormLayout::FieldRole, forward_treashold_label);

        label_39 = new QLabel(ns_widget);
        label_39->setObjectName("label_39");
        label_39->setMinimumSize(QSize(120, 0));
        label_39->setMaximumSize(QSize(120, 16777215));
        label_39->setFont(font2);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_39);

        backward_treashold_label = new QLabel(ns_widget);
        backward_treashold_label->setObjectName("backward_treashold_label");
        backward_treashold_label->setMinimumSize(QSize(80, 0));
        backward_treashold_label->setMaximumSize(QSize(80, 16777215));
        backward_treashold_label->setFont(font3);

        formLayout->setWidget(1, QFormLayout::FieldRole, backward_treashold_label);

        label_52 = new QLabel(ns_widget);
        label_52->setObjectName("label_52");
        label_52->setMinimumSize(QSize(120, 0));
        label_52->setMaximumSize(QSize(120, 16777215));
        label_52->setFont(font2);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_52);

        therm_resis_label = new QLabel(ns_widget);
        therm_resis_label->setObjectName("therm_resis_label");
        therm_resis_label->setMinimumSize(QSize(80, 0));
        therm_resis_label->setMaximumSize(QSize(80, 16777215));
        therm_resis_label->setFont(font3);

        formLayout->setWidget(2, QFormLayout::FieldRole, therm_resis_label);

        label_54 = new QLabel(ns_widget);
        label_54->setObjectName("label_54");
        label_54->setMinimumSize(QSize(120, 0));
        label_54->setMaximumSize(QSize(120, 16777215));
        label_54->setFont(font2);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_54);

        therm_vref_label = new QLabel(ns_widget);
        therm_vref_label->setObjectName("therm_vref_label");
        therm_vref_label->setMinimumSize(QSize(80, 0));
        therm_vref_label->setMaximumSize(QSize(80, 16777215));
        therm_vref_label->setFont(font3);

        formLayout->setWidget(3, QFormLayout::FieldRole, therm_vref_label);

        label_53 = new QLabel(ns_widget);
        label_53->setObjectName("label_53");
        label_53->setMinimumSize(QSize(120, 0));
        label_53->setMaximumSize(QSize(120, 16777215));
        label_53->setFont(font2);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_53);

        therm_beta_label = new QLabel(ns_widget);
        therm_beta_label->setObjectName("therm_beta_label");
        therm_beta_label->setMinimumSize(QSize(80, 0));
        therm_beta_label->setMaximumSize(QSize(80, 16777215));
        therm_beta_label->setFont(font3);

        formLayout->setWidget(4, QFormLayout::FieldRole, therm_beta_label);

        label_55 = new QLabel(ns_widget);
        label_55->setObjectName("label_55");
        label_55->setMinimumSize(QSize(120, 0));
        label_55->setMaximumSize(QSize(120, 16777215));
        label_55->setFont(font2);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_55);

        over_temp_label = new QLabel(ns_widget);
        over_temp_label->setObjectName("over_temp_label");
        over_temp_label->setMinimumSize(QSize(80, 0));
        over_temp_label->setMaximumSize(QSize(80, 16777215));
        over_temp_label->setFont(font3);

        formLayout->setWidget(5, QFormLayout::FieldRole, over_temp_label);

        line_2 = new QFrame(ns_widget);
        line_2->setObjectName("line_2");
        line_2->setMinimumSize(QSize(40, 0));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(6, QFormLayout::SpanningRole, line_2);

        label_50 = new QLabel(ns_widget);
        label_50->setObjectName("label_50");
        label_50->setMinimumSize(QSize(120, 0));
        label_50->setMaximumSize(QSize(120, 16777215));
        label_50->setFont(font2);

        formLayout->setWidget(7, QFormLayout::LabelRole, label_50);

        cur_temp_0 = new QLabel(ns_widget);
        cur_temp_0->setObjectName("cur_temp_0");
        cur_temp_0->setMinimumSize(QSize(80, 0));
        cur_temp_0->setMaximumSize(QSize(80, 16777215));
        cur_temp_0->setFont(font3);

        formLayout->setWidget(7, QFormLayout::FieldRole, cur_temp_0);

        label_56 = new QLabel(ns_widget);
        label_56->setObjectName("label_56");
        label_56->setMinimumSize(QSize(120, 0));
        label_56->setMaximumSize(QSize(120, 16777215));
        label_56->setFont(font2);

        formLayout->setWidget(8, QFormLayout::LabelRole, label_56);

        cur_temp_1 = new QLabel(ns_widget);
        cur_temp_1->setObjectName("cur_temp_1");
        cur_temp_1->setMinimumSize(QSize(80, 0));
        cur_temp_1->setMaximumSize(QSize(80, 16777215));
        cur_temp_1->setFont(font3);

        formLayout->setWidget(8, QFormLayout::FieldRole, cur_temp_1);

        label_40 = new QLabel(ns_widget);
        label_40->setObjectName("label_40");
        label_40->setMinimumSize(QSize(120, 0));
        label_40->setMaximumSize(QSize(120, 16777215));
        label_40->setFont(font2);

        formLayout->setWidget(9, QFormLayout::LabelRole, label_40);

        pd_forward = new QLabel(ns_widget);
        pd_forward->setObjectName("pd_forward");
        pd_forward->setMinimumSize(QSize(80, 0));
        pd_forward->setMaximumSize(QSize(80, 16777215));
        pd_forward->setFont(font3);

        formLayout->setWidget(9, QFormLayout::FieldRole, pd_forward);

        label_41 = new QLabel(ns_widget);
        label_41->setObjectName("label_41");
        label_41->setMinimumSize(QSize(120, 0));
        label_41->setMaximumSize(QSize(120, 16777215));
        label_41->setFont(font2);

        formLayout->setWidget(10, QFormLayout::LabelRole, label_41);

        pd_backward = new QLabel(ns_widget);
        pd_backward->setObjectName("pd_backward");
        pd_backward->setMinimumSize(QSize(80, 0));
        pd_backward->setMaximumSize(QSize(80, 16777215));
        pd_backward->setFont(font3);

        formLayout->setWidget(10, QFormLayout::FieldRole, pd_backward);

        label_error = new QLabel(ns_widget);
        label_error->setObjectName("label_error");
        label_error->setMinimumSize(QSize(120, 0));
        label_error->setMaximumSize(QSize(120, 16777215));
        label_error->setFont(font2);

        formLayout->setWidget(11, QFormLayout::LabelRole, label_error);

        button_error = new QPushButton(ns_widget);
        button_error->setObjectName("button_error");

        formLayout->setWidget(11, QFormLayout::FieldRole, button_error);


        verticalLayout_16->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_16->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_16, 0, 7, 4, 1);

        line = new QFrame(ns_widget);
        line->setObjectName("line");
        line->setMinimumSize(QSize(0, 0));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 6, 7, 1);

        groupBox_16 = new QGroupBox(ns_widget);
        groupBox_16->setObjectName("groupBox_16");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_16->sizePolicy().hasHeightForWidth());
        groupBox_16->setSizePolicy(sizePolicy1);
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
        QFont font4;
        font4.setPointSize(12);
        label_29->setFont(font4);
        label_29->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_31->addWidget(label_29);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        forward_treashold = new QDoubleSpinBox(groupBox_16);
        forward_treashold->setObjectName("forward_treashold");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(100);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(forward_treashold->sizePolicy().hasHeightForWidth());
        forward_treashold->setSizePolicy(sizePolicy2);
        forward_treashold->setMinimumSize(QSize(50, 0));
        forward_treashold->setMaximumSize(QSize(16777215, 16777215));
        QFont font5;
        font5.setPointSize(13);
        forward_treashold->setFont(font5);
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
        label_31->setFont(font4);
        label_31->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_35->addWidget(label_31);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName("horizontalLayout_23");
        backward_treashold = new QDoubleSpinBox(groupBox_16);
        backward_treashold->setObjectName("backward_treashold");
        sizePolicy2.setHeightForWidth(backward_treashold->sizePolicy().hasHeightForWidth());
        backward_treashold->setSizePolicy(sizePolicy2);
        backward_treashold->setMinimumSize(QSize(50, 0));
        backward_treashold->setMaximumSize(QSize(16777215, 16777215));
        backward_treashold->setFont(font5);
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


        gridLayout->addWidget(groupBox_16, 0, 0, 1, 2);

        groupBox_19 = new QGroupBox(ns_widget);
        groupBox_19->setObjectName("groupBox_19");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_19->sizePolicy().hasHeightForWidth());
        groupBox_19->setSizePolicy(sizePolicy3);
        groupBox_19->setFlat(false);
        groupBox_19->setCheckable(false);
        verticalLayout_14 = new QVBoxLayout(groupBox_19);
        verticalLayout_14->setObjectName("verticalLayout_14");
        verticalLayout_14->setContentsMargins(-1, 12, -1, -1);
        over_temp = new QDoubleSpinBox(groupBox_19);
        over_temp->setObjectName("over_temp");
        sizePolicy2.setHeightForWidth(over_temp->sizePolicy().hasHeightForWidth());
        over_temp->setSizePolicy(sizePolicy2);
        over_temp->setMinimumSize(QSize(50, 0));
        over_temp->setMaximumSize(QSize(16777215, 16777215));
        over_temp->setFont(font5);
        over_temp->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        over_temp->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        over_temp->setDecimals(2);
        over_temp->setMinimum(0.000000000000000);
        over_temp->setMaximum(150.000000000000000);
        over_temp->setSingleStep(0.100000000000000);
        over_temp->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        over_temp->setValue(0.000000000000000);

        verticalLayout_14->addWidget(over_temp);


        gridLayout->addWidget(groupBox_19, 1, 1, 1, 1);

        groupBox_14 = new QGroupBox(ns_widget);
        groupBox_14->setObjectName("groupBox_14");
        sizePolicy3.setHeightForWidth(groupBox_14->sizePolicy().hasHeightForWidth());
        groupBox_14->setSizePolicy(sizePolicy3);
        groupBox_14->setFlat(false);
        groupBox_14->setCheckable(false);
        verticalLayout_5 = new QVBoxLayout(groupBox_14);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(-1, 12, -1, -1);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_3 = new QLabel(groupBox_14);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(label_3);

        therm_beta = new QDoubleSpinBox(groupBox_14);
        therm_beta->setObjectName("therm_beta");
        sizePolicy2.setHeightForWidth(therm_beta->sizePolicy().hasHeightForWidth());
        therm_beta->setSizePolicy(sizePolicy2);
        therm_beta->setMinimumSize(QSize(50, 0));
        therm_beta->setMaximumSize(QSize(16777215, 16777215));
        therm_beta->setFont(font5);
        therm_beta->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        therm_beta->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        therm_beta->setDecimals(0);
        therm_beta->setMinimum(0.000000000000000);
        therm_beta->setMaximum(100000.000000000000000);
        therm_beta->setSingleStep(1.000000000000000);
        therm_beta->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        therm_beta->setValue(0.000000000000000);

        verticalLayout_4->addWidget(therm_beta);


        verticalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_2 = new QLabel(groupBox_14);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        therm_vref = new QDoubleSpinBox(groupBox_14);
        therm_vref->setObjectName("therm_vref");
        sizePolicy2.setHeightForWidth(therm_vref->sizePolicy().hasHeightForWidth());
        therm_vref->setSizePolicy(sizePolicy2);
        therm_vref->setMinimumSize(QSize(50, 0));
        therm_vref->setMaximumSize(QSize(16777215, 16777215));
        therm_vref->setFont(font5);
        therm_vref->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        therm_vref->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        therm_vref->setDecimals(3);
        therm_vref->setMinimum(0.000000000000000);
        therm_vref->setMaximum(3.000000000000000);
        therm_vref->setSingleStep(0.100000000000000);
        therm_vref->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        therm_vref->setValue(0.000000000000000);

        verticalLayout_3->addWidget(therm_vref);


        verticalLayout_5->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(groupBox_14);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        therm_resis = new QDoubleSpinBox(groupBox_14);
        therm_resis->setObjectName("therm_resis");
        sizePolicy2.setHeightForWidth(therm_resis->sizePolicy().hasHeightForWidth());
        therm_resis->setSizePolicy(sizePolicy2);
        therm_resis->setMinimumSize(QSize(50, 0));
        therm_resis->setMaximumSize(QSize(16777215, 16777215));
        therm_resis->setFont(font5);
        therm_resis->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        therm_resis->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        therm_resis->setDecimals(0);
        therm_resis->setMinimum(0.000000000000000);
        therm_resis->setMaximum(100000.000000000000000);
        therm_resis->setSingleStep(1.000000000000000);
        therm_resis->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        therm_resis->setValue(0.000000000000000);

        verticalLayout->addWidget(therm_resis);


        verticalLayout_5->addLayout(verticalLayout);


        gridLayout->addWidget(groupBox_14, 0, 2, 2, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 5, 1, 1);

        groupBox_18 = new QGroupBox(ns_widget);
        groupBox_18->setObjectName("groupBox_18");
        sizePolicy1.setHeightForWidth(groupBox_18->sizePolicy().hasHeightForWidth());
        groupBox_18->setSizePolicy(sizePolicy1);
        groupBox_18->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        groupBox_18->setFlat(false);
        groupBox_18->setCheckable(false);
        gridLayout_5 = new QGridLayout(groupBox_18);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setContentsMargins(-1, 12, -1, -1);
        verticalLayout_52 = new QVBoxLayout();
        verticalLayout_52->setObjectName("verticalLayout_52");
        label_59 = new QLabel(groupBox_18);
        label_59->setObjectName("label_59");
        label_59->setMinimumSize(QSize(0, 0));
        label_59->setFont(font4);
        label_59->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_52->addWidget(label_59);

        horizontalLayout_41 = new QHBoxLayout();
        horizontalLayout_41->setObjectName("horizontalLayout_41");
        curr_max_3 = new QDoubleSpinBox(groupBox_18);
        curr_max_3->setObjectName("curr_max_3");
        sizePolicy2.setHeightForWidth(curr_max_3->sizePolicy().hasHeightForWidth());
        curr_max_3->setSizePolicy(sizePolicy2);
        curr_max_3->setMinimumSize(QSize(50, 0));
        curr_max_3->setMaximumSize(QSize(16777215, 16777215));
        curr_max_3->setFont(font5);
        curr_max_3->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        curr_max_3->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        curr_max_3->setDecimals(2);
        curr_max_3->setMinimum(0.000000000000000);
        curr_max_3->setMaximum(3.000000000000000);
        curr_max_3->setSingleStep(0.100000000000000);
        curr_max_3->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        curr_max_3->setValue(0.000000000000000);

        horizontalLayout_41->addWidget(curr_max_3);


        verticalLayout_52->addLayout(horizontalLayout_41);


        gridLayout_5->addLayout(verticalLayout_52, 0, 3, 1, 1);

        verticalLayout_55 = new QVBoxLayout();
        verticalLayout_55->setObjectName("verticalLayout_55");
        label_63 = new QLabel(groupBox_18);
        label_63->setObjectName("label_63");
        label_63->setMinimumSize(QSize(0, 0));
        label_63->setFont(font4);
        label_63->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_55->addWidget(label_63);

        horizontalLayout_45 = new QHBoxLayout();
        horizontalLayout_45->setObjectName("horizontalLayout_45");
        curr_max_6 = new QDoubleSpinBox(groupBox_18);
        curr_max_6->setObjectName("curr_max_6");
        sizePolicy2.setHeightForWidth(curr_max_6->sizePolicy().hasHeightForWidth());
        curr_max_6->setSizePolicy(sizePolicy2);
        curr_max_6->setMinimumSize(QSize(50, 0));
        curr_max_6->setMaximumSize(QSize(16777215, 16777215));
        curr_max_6->setFont(font5);
        curr_max_6->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        curr_max_6->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        curr_max_6->setDecimals(2);
        curr_max_6->setMinimum(0.000000000000000);
        curr_max_6->setMaximum(3.000000000000000);
        curr_max_6->setSingleStep(0.100000000000000);
        curr_max_6->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        curr_max_6->setValue(0.000000000000000);

        horizontalLayout_45->addWidget(curr_max_6);


        verticalLayout_55->addLayout(horizontalLayout_45);


        gridLayout_5->addLayout(verticalLayout_55, 0, 6, 1, 1);

        verticalLayout_34 = new QVBoxLayout();
        verticalLayout_34->setObjectName("verticalLayout_34");
        label_60 = new QLabel(groupBox_18);
        label_60->setObjectName("label_60");
        label_60->setMinimumSize(QSize(0, 0));
        label_60->setFont(font4);
        label_60->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_34->addWidget(label_60);

        horizontalLayout_42 = new QHBoxLayout();
        horizontalLayout_42->setObjectName("horizontalLayout_42");
        curr_max_1 = new QDoubleSpinBox(groupBox_18);
        curr_max_1->setObjectName("curr_max_1");
        sizePolicy2.setHeightForWidth(curr_max_1->sizePolicy().hasHeightForWidth());
        curr_max_1->setSizePolicy(sizePolicy2);
        curr_max_1->setMinimumSize(QSize(50, 0));
        curr_max_1->setMaximumSize(QSize(16777215, 16777215));
        curr_max_1->setFont(font5);
        curr_max_1->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        curr_max_1->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        curr_max_1->setDecimals(2);
        curr_max_1->setMinimum(0.000000000000000);
        curr_max_1->setMaximum(3.000000000000000);
        curr_max_1->setSingleStep(0.100000000000000);
        curr_max_1->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        curr_max_1->setValue(0.000000000000000);

        horizontalLayout_42->addWidget(curr_max_1);


        verticalLayout_34->addLayout(horizontalLayout_42);


        gridLayout_5->addLayout(verticalLayout_34, 0, 1, 1, 1);

        verticalLayout_50 = new QVBoxLayout();
        verticalLayout_50->setObjectName("verticalLayout_50");
        label_57 = new QLabel(groupBox_18);
        label_57->setObjectName("label_57");
        label_57->setMinimumSize(QSize(0, 0));
        label_57->setFont(font4);
        label_57->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_50->addWidget(label_57);

        horizontalLayout_39 = new QHBoxLayout();
        horizontalLayout_39->setObjectName("horizontalLayout_39");
        curr_max_0 = new QDoubleSpinBox(groupBox_18);
        curr_max_0->setObjectName("curr_max_0");
        sizePolicy2.setHeightForWidth(curr_max_0->sizePolicy().hasHeightForWidth());
        curr_max_0->setSizePolicy(sizePolicy2);
        curr_max_0->setMinimumSize(QSize(50, 0));
        curr_max_0->setMaximumSize(QSize(16777215, 16777215));
        curr_max_0->setFont(font5);
        curr_max_0->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        curr_max_0->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        curr_max_0->setDecimals(2);
        curr_max_0->setMinimum(0.000000000000000);
        curr_max_0->setMaximum(3.000000000000000);
        curr_max_0->setSingleStep(0.100000000000000);
        curr_max_0->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        curr_max_0->setValue(0.000000000000000);

        horizontalLayout_39->addWidget(curr_max_0);


        verticalLayout_50->addLayout(horizontalLayout_39);


        gridLayout_5->addLayout(verticalLayout_50, 0, 0, 1, 1);

        verticalLayout_51 = new QVBoxLayout();
        verticalLayout_51->setObjectName("verticalLayout_51");
        label_58 = new QLabel(groupBox_18);
        label_58->setObjectName("label_58");
        label_58->setMinimumSize(QSize(0, 0));
        label_58->setFont(font4);
        label_58->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_51->addWidget(label_58);

        horizontalLayout_40 = new QHBoxLayout();
        horizontalLayout_40->setObjectName("horizontalLayout_40");
        curr_max_2 = new QDoubleSpinBox(groupBox_18);
        curr_max_2->setObjectName("curr_max_2");
        sizePolicy2.setHeightForWidth(curr_max_2->sizePolicy().hasHeightForWidth());
        curr_max_2->setSizePolicy(sizePolicy2);
        curr_max_2->setMinimumSize(QSize(50, 0));
        curr_max_2->setMaximumSize(QSize(16777215, 16777215));
        curr_max_2->setFont(font5);
        curr_max_2->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        curr_max_2->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        curr_max_2->setDecimals(2);
        curr_max_2->setMinimum(0.000000000000000);
        curr_max_2->setMaximum(3.000000000000000);
        curr_max_2->setSingleStep(0.100000000000000);
        curr_max_2->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        curr_max_2->setValue(0.000000000000000);

        horizontalLayout_40->addWidget(curr_max_2);


        verticalLayout_51->addLayout(horizontalLayout_40);


        gridLayout_5->addLayout(verticalLayout_51, 0, 2, 1, 1);

        verticalLayout_53 = new QVBoxLayout();
        verticalLayout_53->setObjectName("verticalLayout_53");
        label_61 = new QLabel(groupBox_18);
        label_61->setObjectName("label_61");
        label_61->setMinimumSize(QSize(0, 0));
        label_61->setFont(font4);
        label_61->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_53->addWidget(label_61);

        horizontalLayout_43 = new QHBoxLayout();
        horizontalLayout_43->setObjectName("horizontalLayout_43");
        curr_max_4 = new QDoubleSpinBox(groupBox_18);
        curr_max_4->setObjectName("curr_max_4");
        sizePolicy2.setHeightForWidth(curr_max_4->sizePolicy().hasHeightForWidth());
        curr_max_4->setSizePolicy(sizePolicy2);
        curr_max_4->setMinimumSize(QSize(50, 0));
        curr_max_4->setMaximumSize(QSize(16777215, 16777215));
        curr_max_4->setFont(font5);
        curr_max_4->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        curr_max_4->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        curr_max_4->setDecimals(2);
        curr_max_4->setMinimum(0.000000000000000);
        curr_max_4->setMaximum(3.000000000000000);
        curr_max_4->setSingleStep(0.100000000000000);
        curr_max_4->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        curr_max_4->setValue(0.000000000000000);

        horizontalLayout_43->addWidget(curr_max_4);


        verticalLayout_53->addLayout(horizontalLayout_43);


        gridLayout_5->addLayout(verticalLayout_53, 0, 4, 1, 1);

        verticalLayout_54 = new QVBoxLayout();
        verticalLayout_54->setObjectName("verticalLayout_54");
        label_62 = new QLabel(groupBox_18);
        label_62->setObjectName("label_62");
        label_62->setMinimumSize(QSize(0, 0));
        label_62->setFont(font4);
        label_62->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_54->addWidget(label_62);

        horizontalLayout_44 = new QHBoxLayout();
        horizontalLayout_44->setObjectName("horizontalLayout_44");
        curr_max_5 = new QDoubleSpinBox(groupBox_18);
        curr_max_5->setObjectName("curr_max_5");
        sizePolicy2.setHeightForWidth(curr_max_5->sizePolicy().hasHeightForWidth());
        curr_max_5->setSizePolicy(sizePolicy2);
        curr_max_5->setMinimumSize(QSize(50, 0));
        curr_max_5->setMaximumSize(QSize(16777215, 16777215));
        curr_max_5->setFont(font5);
        curr_max_5->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        curr_max_5->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        curr_max_5->setDecimals(2);
        curr_max_5->setMinimum(0.000000000000000);
        curr_max_5->setMaximum(3.000000000000000);
        curr_max_5->setSingleStep(0.100000000000000);
        curr_max_5->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        curr_max_5->setValue(0.000000000000000);

        horizontalLayout_44->addWidget(curr_max_5);


        verticalLayout_54->addLayout(horizontalLayout_44);


        gridLayout_5->addLayout(verticalLayout_54, 0, 5, 1, 1);

        verticalLayout_56 = new QVBoxLayout();
        verticalLayout_56->setObjectName("verticalLayout_56");
        label_64 = new QLabel(groupBox_18);
        label_64->setObjectName("label_64");
        label_64->setMinimumSize(QSize(0, 0));
        label_64->setFont(font4);
        label_64->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_56->addWidget(label_64);

        horizontalLayout_46 = new QHBoxLayout();
        horizontalLayout_46->setObjectName("horizontalLayout_46");
        curr_max_7 = new QDoubleSpinBox(groupBox_18);
        curr_max_7->setObjectName("curr_max_7");
        sizePolicy2.setHeightForWidth(curr_max_7->sizePolicy().hasHeightForWidth());
        curr_max_7->setSizePolicy(sizePolicy2);
        curr_max_7->setMinimumSize(QSize(50, 0));
        curr_max_7->setMaximumSize(QSize(16777215, 16777215));
        curr_max_7->setFont(font5);
        curr_max_7->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        curr_max_7->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        curr_max_7->setDecimals(2);
        curr_max_7->setMinimum(0.000000000000000);
        curr_max_7->setMaximum(3.000000000000000);
        curr_max_7->setSingleStep(0.100000000000000);
        curr_max_7->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        curr_max_7->setValue(0.000000000000000);

        horizontalLayout_46->addWidget(curr_max_7);


        verticalLayout_56->addLayout(horizontalLayout_46);


        gridLayout_5->addLayout(verticalLayout_56, 0, 7, 1, 1);


        gridLayout->addWidget(groupBox_18, 3, 0, 1, 3);

        groupBox_17 = new QGroupBox(ns_widget);
        groupBox_17->setObjectName("groupBox_17");
        sizePolicy1.setHeightForWidth(groupBox_17->sizePolicy().hasHeightForWidth());
        groupBox_17->setSizePolicy(sizePolicy1);
        groupBox_17->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        groupBox_17->setFlat(false);
        groupBox_17->setCheckable(false);
        gridLayout_3 = new QGridLayout(groupBox_17);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(-1, 12, -1, -1);
        verticalLayout_41 = new QVBoxLayout();
        verticalLayout_41->setObjectName("verticalLayout_41");
        label_43 = new QLabel(groupBox_17);
        label_43->setObjectName("label_43");
        label_43->setMinimumSize(QSize(0, 0));
        label_43->setFont(font4);
        label_43->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_41->addWidget(label_43);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName("horizontalLayout_29");
        diode_treshold_6 = new QDoubleSpinBox(groupBox_17);
        diode_treshold_6->setObjectName("diode_treshold_6");
        sizePolicy2.setHeightForWidth(diode_treshold_6->sizePolicy().hasHeightForWidth());
        diode_treshold_6->setSizePolicy(sizePolicy2);
        diode_treshold_6->setMinimumSize(QSize(50, 0));
        diode_treshold_6->setMaximumSize(QSize(16777215, 16777215));
        diode_treshold_6->setFont(font5);
        diode_treshold_6->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        diode_treshold_6->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        diode_treshold_6->setDecimals(2);
        diode_treshold_6->setMinimum(0.000000000000000);
        diode_treshold_6->setMaximum(3.000000000000000);
        diode_treshold_6->setSingleStep(0.100000000000000);
        diode_treshold_6->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        diode_treshold_6->setValue(0.000000000000000);

        horizontalLayout_29->addWidget(diode_treshold_6);


        verticalLayout_41->addLayout(horizontalLayout_29);


        gridLayout_3->addLayout(verticalLayout_41, 0, 6, 1, 1);

        verticalLayout_32 = new QVBoxLayout();
        verticalLayout_32->setObjectName("verticalLayout_32");
        label_30 = new QLabel(groupBox_17);
        label_30->setObjectName("label_30");
        label_30->setMinimumSize(QSize(0, 0));
        label_30->setFont(font4);
        label_30->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_32->addWidget(label_30);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName("horizontalLayout_22");
        diode_treshold_1 = new QDoubleSpinBox(groupBox_17);
        diode_treshold_1->setObjectName("diode_treshold_1");
        sizePolicy2.setHeightForWidth(diode_treshold_1->sizePolicy().hasHeightForWidth());
        diode_treshold_1->setSizePolicy(sizePolicy2);
        diode_treshold_1->setMinimumSize(QSize(50, 0));
        diode_treshold_1->setMaximumSize(QSize(16777215, 16777215));
        diode_treshold_1->setFont(font5);
        diode_treshold_1->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        diode_treshold_1->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        diode_treshold_1->setDecimals(2);
        diode_treshold_1->setMinimum(0.000000000000000);
        diode_treshold_1->setMaximum(3.000000000000000);
        diode_treshold_1->setSingleStep(0.100000000000000);
        diode_treshold_1->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        diode_treshold_1->setValue(0.000000000000000);

        horizontalLayout_22->addWidget(diode_treshold_1);


        verticalLayout_32->addLayout(horizontalLayout_22);


        gridLayout_3->addLayout(verticalLayout_32, 0, 1, 1, 1);

        verticalLayout_39 = new QVBoxLayout();
        verticalLayout_39->setObjectName("verticalLayout_39");
        label_37 = new QLabel(groupBox_17);
        label_37->setObjectName("label_37");
        label_37->setMinimumSize(QSize(0, 0));
        label_37->setFont(font4);
        label_37->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_39->addWidget(label_37);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName("horizontalLayout_27");
        diode_treshold_4 = new QDoubleSpinBox(groupBox_17);
        diode_treshold_4->setObjectName("diode_treshold_4");
        sizePolicy2.setHeightForWidth(diode_treshold_4->sizePolicy().hasHeightForWidth());
        diode_treshold_4->setSizePolicy(sizePolicy2);
        diode_treshold_4->setMinimumSize(QSize(50, 0));
        diode_treshold_4->setMaximumSize(QSize(16777215, 16777215));
        diode_treshold_4->setFont(font5);
        diode_treshold_4->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        diode_treshold_4->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        diode_treshold_4->setDecimals(2);
        diode_treshold_4->setMinimum(0.000000000000000);
        diode_treshold_4->setMaximum(3.000000000000000);
        diode_treshold_4->setSingleStep(0.100000000000000);
        diode_treshold_4->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        diode_treshold_4->setValue(0.000000000000000);

        horizontalLayout_27->addWidget(diode_treshold_4);


        verticalLayout_39->addLayout(horizontalLayout_27);


        gridLayout_3->addLayout(verticalLayout_39, 0, 4, 1, 1);

        verticalLayout_37 = new QVBoxLayout();
        verticalLayout_37->setObjectName("verticalLayout_37");
        label_33 = new QLabel(groupBox_17);
        label_33->setObjectName("label_33");
        label_33->setMinimumSize(QSize(0, 0));
        label_33->setFont(font4);
        label_33->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_37->addWidget(label_33);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName("horizontalLayout_25");
        diode_treshold_2 = new QDoubleSpinBox(groupBox_17);
        diode_treshold_2->setObjectName("diode_treshold_2");
        sizePolicy2.setHeightForWidth(diode_treshold_2->sizePolicy().hasHeightForWidth());
        diode_treshold_2->setSizePolicy(sizePolicy2);
        diode_treshold_2->setMinimumSize(QSize(50, 0));
        diode_treshold_2->setMaximumSize(QSize(16777215, 16777215));
        diode_treshold_2->setFont(font5);
        diode_treshold_2->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        diode_treshold_2->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        diode_treshold_2->setDecimals(2);
        diode_treshold_2->setMinimum(0.000000000000000);
        diode_treshold_2->setMaximum(3.000000000000000);
        diode_treshold_2->setSingleStep(0.100000000000000);
        diode_treshold_2->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        diode_treshold_2->setValue(0.000000000000000);

        horizontalLayout_25->addWidget(diode_treshold_2);


        verticalLayout_37->addLayout(horizontalLayout_25);


        gridLayout_3->addLayout(verticalLayout_37, 0, 2, 1, 1);

        verticalLayout_36 = new QVBoxLayout();
        verticalLayout_36->setObjectName("verticalLayout_36");
        label_32 = new QLabel(groupBox_17);
        label_32->setObjectName("label_32");
        label_32->setMinimumSize(QSize(0, 0));
        label_32->setFont(font4);
        label_32->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_36->addWidget(label_32);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName("horizontalLayout_24");
        diode_treshold_0 = new QDoubleSpinBox(groupBox_17);
        diode_treshold_0->setObjectName("diode_treshold_0");
        sizePolicy2.setHeightForWidth(diode_treshold_0->sizePolicy().hasHeightForWidth());
        diode_treshold_0->setSizePolicy(sizePolicy2);
        diode_treshold_0->setMinimumSize(QSize(50, 0));
        diode_treshold_0->setMaximumSize(QSize(16777215, 16777215));
        diode_treshold_0->setFont(font5);
        diode_treshold_0->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        diode_treshold_0->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        diode_treshold_0->setDecimals(2);
        diode_treshold_0->setMinimum(0.000000000000000);
        diode_treshold_0->setMaximum(3.000000000000000);
        diode_treshold_0->setSingleStep(0.100000000000000);
        diode_treshold_0->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        diode_treshold_0->setValue(0.000000000000000);

        horizontalLayout_24->addWidget(diode_treshold_0);


        verticalLayout_36->addLayout(horizontalLayout_24);


        gridLayout_3->addLayout(verticalLayout_36, 0, 0, 1, 1);

        verticalLayout_38 = new QVBoxLayout();
        verticalLayout_38->setObjectName("verticalLayout_38");
        label_34 = new QLabel(groupBox_17);
        label_34->setObjectName("label_34");
        label_34->setMinimumSize(QSize(0, 0));
        label_34->setFont(font4);
        label_34->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_38->addWidget(label_34);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName("horizontalLayout_26");
        diode_treshold_3 = new QDoubleSpinBox(groupBox_17);
        diode_treshold_3->setObjectName("diode_treshold_3");
        sizePolicy2.setHeightForWidth(diode_treshold_3->sizePolicy().hasHeightForWidth());
        diode_treshold_3->setSizePolicy(sizePolicy2);
        diode_treshold_3->setMinimumSize(QSize(50, 0));
        diode_treshold_3->setMaximumSize(QSize(16777215, 16777215));
        diode_treshold_3->setFont(font5);
        diode_treshold_3->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        diode_treshold_3->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        diode_treshold_3->setDecimals(2);
        diode_treshold_3->setMinimum(0.000000000000000);
        diode_treshold_3->setMaximum(3.000000000000000);
        diode_treshold_3->setSingleStep(0.100000000000000);
        diode_treshold_3->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        diode_treshold_3->setValue(0.000000000000000);

        horizontalLayout_26->addWidget(diode_treshold_3);


        verticalLayout_38->addLayout(horizontalLayout_26);


        gridLayout_3->addLayout(verticalLayout_38, 0, 3, 1, 1);

        verticalLayout_40 = new QVBoxLayout();
        verticalLayout_40->setObjectName("verticalLayout_40");
        label_42 = new QLabel(groupBox_17);
        label_42->setObjectName("label_42");
        label_42->setMinimumSize(QSize(0, 0));
        label_42->setFont(font4);
        label_42->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_40->addWidget(label_42);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName("horizontalLayout_28");
        diode_treshold_5 = new QDoubleSpinBox(groupBox_17);
        diode_treshold_5->setObjectName("diode_treshold_5");
        sizePolicy2.setHeightForWidth(diode_treshold_5->sizePolicy().hasHeightForWidth());
        diode_treshold_5->setSizePolicy(sizePolicy2);
        diode_treshold_5->setMinimumSize(QSize(50, 0));
        diode_treshold_5->setMaximumSize(QSize(16777215, 16777215));
        diode_treshold_5->setFont(font5);
        diode_treshold_5->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        diode_treshold_5->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        diode_treshold_5->setDecimals(2);
        diode_treshold_5->setMinimum(0.000000000000000);
        diode_treshold_5->setMaximum(3.000000000000000);
        diode_treshold_5->setSingleStep(0.100000000000000);
        diode_treshold_5->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        diode_treshold_5->setValue(0.000000000000000);

        horizontalLayout_28->addWidget(diode_treshold_5);


        verticalLayout_40->addLayout(horizontalLayout_28);


        gridLayout_3->addLayout(verticalLayout_40, 0, 5, 1, 1);

        verticalLayout_42 = new QVBoxLayout();
        verticalLayout_42->setObjectName("verticalLayout_42");
        label_46 = new QLabel(groupBox_17);
        label_46->setObjectName("label_46");
        label_46->setMinimumSize(QSize(0, 0));
        label_46->setFont(font4);
        label_46->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_42->addWidget(label_46);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setObjectName("horizontalLayout_30");
        diode_treshold_7 = new QDoubleSpinBox(groupBox_17);
        diode_treshold_7->setObjectName("diode_treshold_7");
        sizePolicy2.setHeightForWidth(diode_treshold_7->sizePolicy().hasHeightForWidth());
        diode_treshold_7->setSizePolicy(sizePolicy2);
        diode_treshold_7->setMinimumSize(QSize(50, 0));
        diode_treshold_7->setMaximumSize(QSize(16777215, 16777215));
        diode_treshold_7->setFont(font5);
        diode_treshold_7->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        diode_treshold_7->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        diode_treshold_7->setDecimals(2);
        diode_treshold_7->setMinimum(0.000000000000000);
        diode_treshold_7->setMaximum(3.000000000000000);
        diode_treshold_7->setSingleStep(0.100000000000000);
        diode_treshold_7->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        diode_treshold_7->setValue(0.000000000000000);

        horizontalLayout_30->addWidget(diode_treshold_7);


        verticalLayout_42->addLayout(horizontalLayout_30);


        gridLayout_3->addLayout(verticalLayout_42, 0, 7, 1, 1);


        gridLayout->addWidget(groupBox_17, 2, 0, 1, 3);

        groupBox_12 = new QGroupBox(ns_widget);
        groupBox_12->setObjectName("groupBox_12");
        sizePolicy3.setHeightForWidth(groupBox_12->sizePolicy().hasHeightForWidth());
        groupBox_12->setSizePolicy(sizePolicy3);
        groupBox_12->setFlat(false);
        groupBox_12->setCheckable(false);
        horizontalLayout_3 = new QHBoxLayout(groupBox_12);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(-1, 12, -1, -1);
        voltage_pl = new QDoubleSpinBox(groupBox_12);
        voltage_pl->setObjectName("voltage_pl");
        sizePolicy2.setHeightForWidth(voltage_pl->sizePolicy().hasHeightForWidth());
        voltage_pl->setSizePolicy(sizePolicy2);
        voltage_pl->setMinimumSize(QSize(50, 0));
        voltage_pl->setMaximumSize(QSize(16777215, 16777215));
        voltage_pl->setFont(font5);
        voltage_pl->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        voltage_pl->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        voltage_pl->setDecimals(2);
        voltage_pl->setMinimum(0.000000000000000);
        voltage_pl->setMaximum(26.000000000000000);
        voltage_pl->setSingleStep(0.100000000000000);
        voltage_pl->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        voltage_pl->setValue(0.000000000000000);

        horizontalLayout_3->addWidget(voltage_pl);


        gridLayout->addWidget(groupBox_12, 1, 0, 1, 1);


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
        label_11->setText(QCoreApplication::translate("cb_panel", "Read Values:", nullptr));
        label_38->setText(QCoreApplication::translate("cb_panel", "Level forward:", nullptr));
        forward_treashold_label->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_39->setText(QCoreApplication::translate("cb_panel", "Level backw.:", nullptr));
        backward_treashold_label->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_52->setText(QCoreApplication::translate("cb_panel", "Therm. resis. :", nullptr));
        therm_resis_label->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_54->setText(QCoreApplication::translate("cb_panel", "Therm. Vref:", nullptr));
        therm_vref_label->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_53->setText(QCoreApplication::translate("cb_panel", "Therm. Beta:", nullptr));
        therm_beta_label->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_55->setText(QCoreApplication::translate("cb_panel", "Overheat temp:", nullptr));
        over_temp_label->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_50->setText(QCoreApplication::translate("cb_panel", "Temp.  0:", nullptr));
        cur_temp_0->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_56->setText(QCoreApplication::translate("cb_panel", "Temp.  1:", nullptr));
        cur_temp_1->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_40->setText(QCoreApplication::translate("cb_panel", "PD forward:", nullptr));
        pd_forward->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_41->setText(QCoreApplication::translate("cb_panel", "PD backward:", nullptr));
        pd_backward->setText(QCoreApplication::translate("cb_panel", "N/A", nullptr));
        label_error->setText(QCoreApplication::translate("cb_panel", "Errors:", nullptr));
        button_error->setText(QCoreApplication::translate("cb_panel", "\320\224\320\265\321\202\320\260\320\273\320\270", nullptr));
        groupBox_16->setTitle(QCoreApplication::translate("cb_panel", "Level", nullptr));
        label_29->setText(QCoreApplication::translate("cb_panel", "Forward", nullptr));
        forward_treashold->setSuffix(QString());
        label_31->setText(QCoreApplication::translate("cb_panel", "Backward", nullptr));
        backward_treashold->setSuffix(QString());
        groupBox_19->setTitle(QCoreApplication::translate("cb_panel", "Overheat temperature", nullptr));
        over_temp->setSuffix(QString());
        groupBox_14->setTitle(QCoreApplication::translate("cb_panel", "Thermistor", nullptr));
        label_3->setText(QCoreApplication::translate("cb_panel", "Beta", nullptr));
        therm_beta->setSuffix(QString());
        label_2->setText(QCoreApplication::translate("cb_panel", "Vref", nullptr));
        therm_vref->setSuffix(QString());
        label->setText(QCoreApplication::translate("cb_panel", " Resistanse", nullptr));
        therm_resis->setSuffix(QString());
        groupBox_18->setTitle(QCoreApplication::translate("cb_panel", "HPLD MAX \320\241urrent", nullptr));
        label_59->setText(QCoreApplication::translate("cb_panel", "3", nullptr));
        curr_max_3->setSuffix(QString());
        label_63->setText(QCoreApplication::translate("cb_panel", "6", nullptr));
        curr_max_6->setSuffix(QString());
        label_60->setText(QCoreApplication::translate("cb_panel", "1", nullptr));
        curr_max_1->setSuffix(QString());
        label_57->setText(QCoreApplication::translate("cb_panel", "0", nullptr));
        curr_max_0->setSuffix(QString());
        label_58->setText(QCoreApplication::translate("cb_panel", "2", nullptr));
        curr_max_2->setSuffix(QString());
        label_61->setText(QCoreApplication::translate("cb_panel", "4", nullptr));
        curr_max_4->setSuffix(QString());
        label_62->setText(QCoreApplication::translate("cb_panel", "5", nullptr));
        curr_max_5->setSuffix(QString());
        label_64->setText(QCoreApplication::translate("cb_panel", "7", nullptr));
        curr_max_7->setSuffix(QString());
        groupBox_17->setTitle(QCoreApplication::translate("cb_panel", "HPLD \320\241urrent threshold", nullptr));
        label_43->setText(QCoreApplication::translate("cb_panel", "6", nullptr));
        diode_treshold_6->setSuffix(QString());
        label_30->setText(QCoreApplication::translate("cb_panel", "1", nullptr));
        diode_treshold_1->setSuffix(QString());
        label_37->setText(QCoreApplication::translate("cb_panel", "4", nullptr));
        diode_treshold_4->setSuffix(QString());
        label_33->setText(QCoreApplication::translate("cb_panel", "2", nullptr));
        diode_treshold_2->setSuffix(QString());
        label_32->setText(QCoreApplication::translate("cb_panel", "0", nullptr));
        diode_treshold_0->setSuffix(QString());
        label_34->setText(QCoreApplication::translate("cb_panel", "3", nullptr));
        diode_treshold_3->setSuffix(QString());
        label_42->setText(QCoreApplication::translate("cb_panel", "5", nullptr));
        diode_treshold_5->setSuffix(QString());
        label_46->setText(QCoreApplication::translate("cb_panel", "7", nullptr));
        diode_treshold_7->setSuffix(QString());
        groupBox_12->setTitle(QCoreApplication::translate("cb_panel", "Pilot laser Voltage DAC", nullptr));
        voltage_pl->setSuffix(QString());
    } // retranslateUi

};

namespace Ui {
    class cb_panel: public Ui_cb_panel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CB_PANEL_H
