/********************************************************************************
** Form generated from reading UI file 'dc_panel.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DC_PANEL_H
#define UI_DC_PANEL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "device_panel.h"

QT_BEGIN_NAMESPACE

class Ui_dc_panel
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_11;
    QLabel *laser_name_label;
    QSpacerItem *horizontalSpacer_14;
    QToolButton *toolButton;
    QWidget *cw_widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_21;
    QPushButton *on_off_button;
    QLabel *label_22;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_4;
    QComboBox *mode;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_24;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_9;
    QProgressBar *indicator;
    QHBoxLayout *horizontalLayout_24;
    QLabel *curr_min_label;
    QSpacerItem *horizontalSpacer_8;
    QLabel *curr_max_label;
    QVBoxLayout *verticalLayout_13;
    QDoubleSpinBox *spin;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_25;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout_14;
    QProgressBar *tem_indicator;
    QHBoxLayout *horizontalLayout_26;
    QLabel *curr_min_label_3;
    QSpacerItem *horizontalSpacer_10;
    QLabel *curr_max_label_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QFrame *line_5;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_11;
    QFormLayout *formLayout_2;
    QLabel *label_28;
    QLabel *power_state_label;
    QLabel *label_31;
    QLabel *current_ld_label;
    QLabel *label_32;
    QLabel *temp_label;
    QLabel *label_error;
    QPushButton *button_error;
    QLabel *label_29;
    QLabel *mode_label;

    void setupUi(device_panel *dc_panel)
    {
        if (dc_panel->objectName().isEmpty())
            dc_panel->setObjectName("dc_panel");
        dc_panel->resize(894, 247);
        verticalLayout_2 = new QVBoxLayout(dc_panel);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(3, 3, 3, 3);
        groupBox = new QGroupBox(dc_panel);
        groupBox->setObjectName("groupBox");
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #ffffff, stop: 1 #FFFFFF);\n"
"    border: 1px solid gray;\n"
"    margin-top: 1ex; /* leave space at the top for the title */\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(3, 3, 3, 3);
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        laser_name_label = new QLabel(groupBox);
        laser_name_label->setObjectName("laser_name_label");
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        laser_name_label->setFont(font);

        horizontalLayout_11->addWidget(laser_name_label);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_14);

        toolButton = new QToolButton(groupBox);
        toolButton->setObjectName("toolButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/conf_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(23, 23));

        horizontalLayout_11->addWidget(toolButton);


        verticalLayout_5->addLayout(horizontalLayout_11);

        cw_widget = new QWidget(groupBox);
        cw_widget->setObjectName("cw_widget");
        cw_widget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cw_widget->sizePolicy().hasHeightForWidth());
        cw_widget->setSizePolicy(sizePolicy);
        cw_widget->setMaximumSize(QSize(16777215, 16777215));
        cw_widget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(cw_widget);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_10 = new QLabel(cw_widget);
        label_10->setObjectName("label_10");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        label_10->setMinimumSize(QSize(150, 0));
        QFont font1;
        font1.setPointSize(12);
        label_10->setFont(font1);
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_10);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName("horizontalLayout_23");
        label_21 = new QLabel(cw_widget);
        label_21->setObjectName("label_21");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy2);
        label_21->setMinimumSize(QSize(30, 25));
        label_21->setMaximumSize(QSize(16777215, 25));
        label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_23->addWidget(label_21);

        on_off_button = new QPushButton(cw_widget);
        on_off_button->setObjectName("on_off_button");
        on_off_button->setEnabled(true);
        on_off_button->setMinimumSize(QSize(75, 27));
        on_off_button->setMaximumSize(QSize(75, 27));
        QFont font2;
        font2.setPointSize(10);
        on_off_button->setFont(font2);
        on_off_button->setFocusPolicy(Qt::NoFocus);
        on_off_button->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-image: url(:/images/images/switch_btn_off_80x25.png);\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	border-image: url(:/images/images/switch_btn_off_hover_80x25.png);\n"
"}\n"
"\n"
"QPushButton::checked  {	\n"
"	border-image: url(:/images/images/switch_btn_on_108x25.png);\n"
"}\n"
"\n"
"QPushButton::hover:checked  {	\n"
"	border-image: url(:/images/images/switch_btn_on_hover_108x25.png);\n"
"}\n"
"\n"
"QPushButton::checked:disabled  {	\n"
"	border-image: url(:/images/images/switch_btn_on_disabled_108x25.png);\n"
"}\n"
"\n"
"QPushButton::disabled  {\n"
"	border-image: url(:/images/images/switch_btn_off_disabled_108x25.png);\n"
"}"));
        on_off_button->setCheckable(true);

        horizontalLayout_23->addWidget(on_off_button);

        label_22 = new QLabel(cw_widget);
        label_22->setObjectName("label_22");
        sizePolicy2.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy2);
        label_22->setMinimumSize(QSize(30, 25));
        label_22->setMaximumSize(QSize(16777215, 25));
        label_22->setAlignment(Qt::AlignCenter);

        horizontalLayout_23->addWidget(label_22);


        verticalLayout->addLayout(horizontalLayout_23);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_2 = new QLabel(cw_widget);
        label_2->setObjectName("label_2");
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        mode = new QComboBox(cw_widget);
        mode->addItem(QString());
        mode->addItem(QString());
        mode->addItem(QString());
        mode->setObjectName("mode");
        mode->setFont(font1);

        verticalLayout_4->addWidget(mode);


        verticalLayout_7->addLayout(verticalLayout_4);


        verticalLayout->addLayout(verticalLayout_7);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        label_24 = new QLabel(cw_widget);
        label_24->setObjectName("label_24");
        label_24->setMinimumSize(QSize(0, 0));
        label_24->setFont(font1);
        label_24->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_24);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName("verticalLayout_9");
        indicator = new QProgressBar(cw_widget);
        indicator->setObjectName("indicator");
        indicator->setMinimumSize(QSize(0, 10));
        indicator->setMaximumSize(QSize(16777215, 10));
        indicator->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    border: 1px solid grey;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"	background-color: rgb(0, 160, 18);\n"
"}\n"
"\n"
"QProgressBar::chunk:disabled {\n"
"	background-color: rgb(150, 150, 150);\n"
"}"));
        indicator->setMinimum(0);
        indicator->setMaximum(250);
        indicator->setValue(200);
        indicator->setTextVisible(false);
        indicator->setTextDirection(QProgressBar::TopToBottom);

        verticalLayout_9->addWidget(indicator);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(0);
        horizontalLayout_24->setObjectName("horizontalLayout_24");
        horizontalLayout_24->setContentsMargins(0, -1, -1, -1);
        curr_min_label = new QLabel(cw_widget);
        curr_min_label->setObjectName("curr_min_label");

        horizontalLayout_24->addWidget(curr_min_label);

        horizontalSpacer_8 = new QSpacerItem(40, 10, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_8);

        curr_max_label = new QLabel(cw_widget);
        curr_max_label->setObjectName("curr_max_label");
        sizePolicy.setHeightForWidth(curr_max_label->sizePolicy().hasHeightForWidth());
        curr_max_label->setSizePolicy(sizePolicy);

        horizontalLayout_24->addWidget(curr_max_label);


        verticalLayout_9->addLayout(horizontalLayout_24);


        horizontalLayout_13->addLayout(verticalLayout_9);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName("verticalLayout_13");
        spin = new QDoubleSpinBox(cw_widget);
        spin->setObjectName("spin");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(100);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(spin->sizePolicy().hasHeightForWidth());
        spin->setSizePolicy(sizePolicy3);
        spin->setMinimumSize(QSize(100, 0));
        spin->setMaximumSize(QSize(16777215, 16777215));
        QFont font3;
        font3.setPointSize(13);
        spin->setFont(font3);
        spin->setFocusPolicy(Qt::ClickFocus);
        spin->setStyleSheet(QString::fromUtf8("background: rgb(255,255,255)"));
        spin->setDecimals(2);
        spin->setMinimum(0.000000000000000);
        spin->setMaximum(25.000000000000000);
        spin->setSingleStep(1.000000000000000);

        verticalLayout_13->addWidget(spin);


        horizontalLayout_13->addLayout(verticalLayout_13);


        verticalLayout_10->addLayout(horizontalLayout_13);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout_10);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName("verticalLayout_12");
        label_25 = new QLabel(cw_widget);
        label_25->setObjectName("label_25");
        label_25->setMinimumSize(QSize(0, 0));
        label_25->setFont(font1);
        label_25->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(label_25);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(0);
        verticalLayout_14->setObjectName("verticalLayout_14");
        tem_indicator = new QProgressBar(cw_widget);
        tem_indicator->setObjectName("tem_indicator");
        tem_indicator->setMinimumSize(QSize(0, 10));
        tem_indicator->setMaximumSize(QSize(16777215, 10));
        tem_indicator->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    border: 1px solid grey;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"	background-color: rgb(0, 160, 18);\n"
"}\n"
"\n"
"QProgressBar::chunk:disabled {\n"
"	background-color: rgb(150, 150, 150);\n"
"}"));
        tem_indicator->setMinimum(0);
        tem_indicator->setMaximum(600);
        tem_indicator->setValue(200);
        tem_indicator->setTextVisible(false);
        tem_indicator->setTextDirection(QProgressBar::TopToBottom);

        verticalLayout_14->addWidget(tem_indicator);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(0);
        horizontalLayout_26->setObjectName("horizontalLayout_26");
        horizontalLayout_26->setContentsMargins(0, -1, -1, -1);
        curr_min_label_3 = new QLabel(cw_widget);
        curr_min_label_3->setObjectName("curr_min_label_3");

        horizontalLayout_26->addWidget(curr_min_label_3);

        horizontalSpacer_10 = new QSpacerItem(40, 10, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_26->addItem(horizontalSpacer_10);

        curr_max_label_3 = new QLabel(cw_widget);
        curr_max_label_3->setObjectName("curr_max_label_3");
        sizePolicy.setHeightForWidth(curr_max_label_3->sizePolicy().hasHeightForWidth());
        curr_max_label_3->setSizePolicy(sizePolicy);

        horizontalLayout_26->addWidget(curr_max_label_3);


        verticalLayout_14->addLayout(horizontalLayout_26);


        horizontalLayout_14->addLayout(verticalLayout_14);


        verticalLayout_12->addLayout(horizontalLayout_14);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_4);


        horizontalLayout_2->addLayout(verticalLayout_12);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout_3);

        line_5 = new QFrame(cw_widget);
        line_5->setObjectName("line_5");
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_5);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(0);
        verticalLayout_16->setObjectName("verticalLayout_16");
        label_11 = new QLabel(cw_widget);
        label_11->setObjectName("label_11");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy4);
        label_11->setMinimumSize(QSize(220, 0));
        label_11->setMaximumSize(QSize(220, 16777215));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setUnderline(true);
        font4.setKerning(true);
        label_11->setFont(font4);

        verticalLayout_16->addWidget(label_11);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setContentsMargins(3, 3, 3, 3);
        label_28 = new QLabel(cw_widget);
        label_28->setObjectName("label_28");
        label_28->setMinimumSize(QSize(120, 0));
        label_28->setMaximumSize(QSize(120, 16777215));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Arial")});
        font5.setPointSize(12);
        label_28->setFont(font5);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_28);

        power_state_label = new QLabel(cw_widget);
        power_state_label->setObjectName("power_state_label");
        power_state_label->setMinimumSize(QSize(80, 0));
        power_state_label->setMaximumSize(QSize(80, 16777215));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Arial")});
        font6.setPointSize(12);
        font6.setBold(true);
        power_state_label->setFont(font6);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, power_state_label);

        label_31 = new QLabel(cw_widget);
        label_31->setObjectName("label_31");
        label_31->setMinimumSize(QSize(120, 0));
        label_31->setMaximumSize(QSize(120, 16777215));
        label_31->setFont(font5);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_31);

        current_ld_label = new QLabel(cw_widget);
        current_ld_label->setObjectName("current_ld_label");
        current_ld_label->setMinimumSize(QSize(80, 0));
        current_ld_label->setMaximumSize(QSize(80, 16777215));
        current_ld_label->setFont(font6);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, current_ld_label);

        label_32 = new QLabel(cw_widget);
        label_32->setObjectName("label_32");
        label_32->setMinimumSize(QSize(120, 0));
        label_32->setMaximumSize(QSize(120, 16777215));
        label_32->setFont(font5);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_32);

        temp_label = new QLabel(cw_widget);
        temp_label->setObjectName("temp_label");
        temp_label->setMinimumSize(QSize(80, 0));
        temp_label->setMaximumSize(QSize(80, 16777215));
        temp_label->setFont(font6);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, temp_label);

        label_error = new QLabel(cw_widget);
        label_error->setObjectName("label_error");
        label_error->setMinimumSize(QSize(120, 0));
        label_error->setMaximumSize(QSize(120, 16777215));
        label_error->setFont(font5);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_error);

        button_error = new QPushButton(cw_widget);
        button_error->setObjectName("button_error");

        formLayout_2->setWidget(3, QFormLayout::FieldRole, button_error);

        label_29 = new QLabel(cw_widget);
        label_29->setObjectName("label_29");
        label_29->setMinimumSize(QSize(120, 0));
        label_29->setMaximumSize(QSize(120, 16777215));
        label_29->setFont(font5);
        label_29->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_29);

        mode_label = new QLabel(cw_widget);
        mode_label->setObjectName("mode_label");
        mode_label->setMinimumSize(QSize(80, 36));
        mode_label->setMaximumSize(QSize(80, 36));
        mode_label->setFont(font6);
        mode_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        mode_label->setWordWrap(true);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, mode_label);


        verticalLayout_16->addLayout(formLayout_2);


        horizontalLayout->addLayout(verticalLayout_16);


        verticalLayout_5->addWidget(cw_widget);


        verticalLayout_2->addWidget(groupBox);


        retranslateUi(dc_panel);

        QMetaObject::connectSlotsByName(dc_panel);
    } // setupUi

    void retranslateUi(device_panel *dc_panel)
    {
        dc_panel->setWindowTitle(QCoreApplication::translate("dc_panel", "Form", nullptr));
        groupBox->setTitle(QString());
        laser_name_label->setText(QCoreApplication::translate("dc_panel", "Power DCDC", nullptr));
        toolButton->setText(QCoreApplication::translate("dc_panel", "...", nullptr));
        label_10->setText(QCoreApplication::translate("dc_panel", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265", nullptr));
        label_21->setText(QCoreApplication::translate("dc_panel", "\320\222\320\253\320\232\320\233", nullptr));
        on_off_button->setText(QString());
        label_22->setText(QCoreApplication::translate("dc_panel", "\320\222\320\232\320\233", nullptr));
        label_2->setText(QCoreApplication::translate("dc_panel", "\320\240\320\265\320\266\320\270\320\274", nullptr));
        mode->setItemText(0, QCoreApplication::translate("dc_panel", "Mode CW", nullptr));
        mode->setItemText(1, QCoreApplication::translate("dc_panel", "External TTL", nullptr));
        mode->setItemText(2, QCoreApplication::translate("dc_panel", "External Analog", nullptr));

        label_24->setText(QCoreApplication::translate("dc_panel", "Drive current", nullptr));
        indicator->setFormat(QString());
        curr_min_label->setText(QCoreApplication::translate("dc_panel", "0", nullptr));
        curr_max_label->setText(QCoreApplication::translate("dc_panel", "25", nullptr));
        spin->setSuffix(QCoreApplication::translate("dc_panel", " A", nullptr));
        label_25->setText(QCoreApplication::translate("dc_panel", "Temperature", nullptr));
        tem_indicator->setFormat(QString());
        curr_min_label_3->setText(QCoreApplication::translate("dc_panel", "10", nullptr));
        curr_max_label_3->setText(QCoreApplication::translate("dc_panel", "70", nullptr));
        label_11->setText(QCoreApplication::translate("dc_panel", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213:", nullptr));
        label_28->setText(QCoreApplication::translate("dc_panel", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265:", nullptr));
        power_state_label->setText(QCoreApplication::translate("dc_panel", "OFF", nullptr));
        label_31->setText(QCoreApplication::translate("dc_panel", "\320\234\320\276\321\211\320\275\320\276\321\201\321\202\321\214:", nullptr));
        current_ld_label->setText(QCoreApplication::translate("dc_panel", "0.0 A", nullptr));
        label_32->setText(QCoreApplication::translate("dc_panel", "Temperature:", nullptr));
        temp_label->setText(QCoreApplication::translate("dc_panel", "0.0 C", nullptr));
        label_error->setText(QCoreApplication::translate("dc_panel", "\320\236\321\210\320\270\320\261\320\272\320\270:", nullptr));
        button_error->setText(QCoreApplication::translate("dc_panel", "\320\241\320\277\320\270\321\201\320\276\320\272", nullptr));
        label_29->setText(QCoreApplication::translate("dc_panel", "\320\240\320\265\320\266\320\270\320\274:", nullptr));
        mode_label->setText(QCoreApplication::translate("dc_panel", "Mode CW", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dc_panel: public Ui_dc_panel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DC_PANEL_H
