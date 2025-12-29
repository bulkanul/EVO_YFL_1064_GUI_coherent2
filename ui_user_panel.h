/********************************************************************************
** Form generated from reading UI file 'user_panel.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_PANEL_H
#define UI_USER_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_user_panel
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_11;
    QLabel *laser_name_label;
    QSpacerItem *horizontalSpacer_14;
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
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QFrame *line_5;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_11;
    QFormLayout *formLayout_2;
    QLabel *label_28;
    QLabel *power_state_label;
    QLabel *label_31;
    QLabel *current_ld_label;

    void setupUi(QWidget *user_panel)
    {
        if (user_panel->objectName().isEmpty())
            user_panel->setObjectName("user_panel");
        user_panel->resize(789, 193);
        verticalLayout_2 = new QVBoxLayout(user_panel);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(3, 3, 3, 3);
        groupBox = new QGroupBox(user_panel);
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


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

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
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy3);
        label_11->setMinimumSize(QSize(220, 0));
        label_11->setMaximumSize(QSize(220, 16777215));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setUnderline(true);
        font3.setKerning(true);
        label_11->setFont(font3);

        verticalLayout_16->addWidget(label_11);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setContentsMargins(3, 3, 3, 3);
        label_28 = new QLabel(cw_widget);
        label_28->setObjectName("label_28");
        label_28->setMinimumSize(QSize(120, 0));
        label_28->setMaximumSize(QSize(120, 16777215));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial")});
        font4.setPointSize(12);
        label_28->setFont(font4);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_28);

        power_state_label = new QLabel(cw_widget);
        power_state_label->setObjectName("power_state_label");
        power_state_label->setMinimumSize(QSize(80, 0));
        power_state_label->setMaximumSize(QSize(80, 16777215));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Arial")});
        font5.setPointSize(12);
        font5.setBold(true);
        power_state_label->setFont(font5);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, power_state_label);

        label_31 = new QLabel(cw_widget);
        label_31->setObjectName("label_31");
        label_31->setMinimumSize(QSize(120, 0));
        label_31->setMaximumSize(QSize(120, 16777215));
        label_31->setFont(font4);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_31);

        current_ld_label = new QLabel(cw_widget);
        current_ld_label->setObjectName("current_ld_label");
        current_ld_label->setMinimumSize(QSize(80, 0));
        current_ld_label->setMaximumSize(QSize(80, 16777215));
        current_ld_label->setFont(font5);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, current_ld_label);


        verticalLayout_16->addLayout(formLayout_2);


        horizontalLayout->addLayout(verticalLayout_16);


        verticalLayout_5->addWidget(cw_widget);


        verticalLayout_2->addWidget(groupBox);


        retranslateUi(user_panel);

        QMetaObject::connectSlotsByName(user_panel);
    } // setupUi

    void retranslateUi(QWidget *user_panel)
    {
        user_panel->setWindowTitle(QCoreApplication::translate("user_panel", "Form", nullptr));
        groupBox->setTitle(QString());
        laser_name_label->setText(QCoreApplication::translate("user_panel", "User panel", nullptr));
        label_10->setText(QCoreApplication::translate("user_panel", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265", nullptr));
        label_21->setText(QCoreApplication::translate("user_panel", "\320\222\320\253\320\232\320\233", nullptr));
        on_off_button->setText(QString());
        label_22->setText(QCoreApplication::translate("user_panel", "\320\222\320\232\320\233", nullptr));
        label_11->setText(QCoreApplication::translate("user_panel", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213:", nullptr));
        label_28->setText(QCoreApplication::translate("user_panel", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265:", nullptr));
        power_state_label->setText(QCoreApplication::translate("user_panel", "OFF", nullptr));
        label_31->setText(QCoreApplication::translate("user_panel", "\320\234\320\276\321\211\320\275\320\276\321\201\321\202\321\214:", nullptr));
        current_ld_label->setText(QCoreApplication::translate("user_panel", "0.0 A", nullptr));
    } // retranslateUi

};

namespace Ui {
    class user_panel: public Ui_user_panel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_PANEL_H
