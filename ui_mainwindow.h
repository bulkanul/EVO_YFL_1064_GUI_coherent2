/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_23;
    QHBoxLayout *horizontalLayout_59;
    QPushButton *menu_button;
    QSpacerItem *horizontalSpacer_34;
    QPushButton *pb_error_cleaner;
    QLabel *label;
    QStackedWidget *stackedWidget;
    QWidget *admin_page;
    QVBoxLayout *verticalLayout_3;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *all_save_seed;
    QPushButton *all_restore_seed;
    QPushButton *all_save_in_memory;
    QSpacerItem *horizontalSpacer_18;
    QPushButton *all_reset;
    QWidget *connection_page;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox_5;
    QFormLayout *formLayout;
    QRadioButton *rb_serial;
    QGroupBox *group_serial;
    QHBoxLayout *horizontalLayout_17;
    QPushButton *refresh_ports;
    QComboBox *serial_combo_box;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *ip_adress_2;
    QPushButton *connect_btn;
    QSpacerItem *verticalSpacer_4;
    QLabel *version;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1025, 868);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1023, 823));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(3, 3, 3, 3);
        widget_23 = new QWidget(scrollAreaWidgetContents);
        widget_23->setObjectName("widget_23");
        widget_23->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_59 = new QHBoxLayout(widget_23);
        horizontalLayout_59->setObjectName("horizontalLayout_59");
        horizontalLayout_59->setContentsMargins(-1, 3, -1, 3);
        menu_button = new QPushButton(widget_23);
        menu_button->setObjectName("menu_button");
        menu_button->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(menu_button->sizePolicy().hasHeightForWidth());
        menu_button->setSizePolicy(sizePolicy);
        menu_button->setMinimumSize(QSize(0, 0));
        menu_button->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(14);
        menu_button->setFont(font);
        menu_button->setCursor(QCursor(Qt::PointingHandCursor));
        menu_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	text-align: center;\n"
"    border: 0px solid gray;\n"
"	vertical-align: bottom;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	text-align: center;\n"
"	color: rgb(170, 0, 0);\n"
"    border: 0px solid gray;\n"
"	vertical-align: bottom;\n"
"}"));
        menu_button->setCheckable(false);
        menu_button->setChecked(false);
        menu_button->setAutoExclusive(false);
        menu_button->setFlat(false);

        horizontalLayout_59->addWidget(menu_button);

        horizontalSpacer_34 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_59->addItem(horizontalSpacer_34);

        pb_error_cleaner = new QPushButton(widget_23);
        pb_error_cleaner->setObjectName("pb_error_cleaner");
        pb_error_cleaner->setMaximumSize(QSize(130, 16777215));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setBold(true);
        font1.setItalic(false);
        pb_error_cleaner->setFont(font1);
        pb_error_cleaner->setStyleSheet(QString::fromUtf8("QPushButton {	\n"
"	background-color: white;\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 8px;\n"
"    border-color: red;\n"
"    font: bold 10px;\n"
"    min-width: 10em;\n"
"    padding: 3px;\n"
"}\n"
"QPushButton::hover { 	\n"
"	background-color:  rgb(221, 242, 255);\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 8px;\n"
"    border-color: red;\n"
"    font: bold 10px;\n"
"    min-width: 10em;\n"
"    padding: 3px; }\n"
""));

        horizontalLayout_59->addWidget(pb_error_cleaner);

        label = new QLabel(widget_23);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMaximumSize(QSize(106, 28));
        label->setPixmap(QPixmap(QString::fromUtf8("images/NordL_logo.png")));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_59->addWidget(label);


        verticalLayout_4->addWidget(widget_23);

        stackedWidget = new QStackedWidget(scrollAreaWidgetContents);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setEnabled(true);
        stackedWidget->setMinimumSize(QSize(30, 0));
        admin_page = new QWidget();
        admin_page->setObjectName("admin_page");
        verticalLayout_3 = new QVBoxLayout(admin_page);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        scrollArea_2 = new QScrollArea(admin_page);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 1015, 781));
        verticalLayout_5 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(3, 3, 3, 3);
        groupBox = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox->setObjectName("groupBox");
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");

        verticalLayout_5->addWidget(groupBox);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_2->setObjectName("groupBox_2");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy2);
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #ffffff, stop: 1 #FFFFFF);\n"
"    border: 1px solid gray;\n"
"    margin-top: 1ex; /* leave space at the top for the title */\n"
"}\n"
""));
        horizontalLayout_18 = new QHBoxLayout(groupBox_2);
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        horizontalLayout_18->setContentsMargins(3, 3, 3, 3);
        all_save_seed = new QPushButton(groupBox_2);
        all_save_seed->setObjectName("all_save_seed");
        QFont font2;
        font2.setPointSize(12);
        all_save_seed->setFont(font2);

        horizontalLayout_18->addWidget(all_save_seed);

        all_restore_seed = new QPushButton(groupBox_2);
        all_restore_seed->setObjectName("all_restore_seed");
        all_restore_seed->setFont(font2);

        horizontalLayout_18->addWidget(all_restore_seed);

        all_save_in_memory = new QPushButton(groupBox_2);
        all_save_in_memory->setObjectName("all_save_in_memory");
        all_save_in_memory->setFont(font2);

        horizontalLayout_18->addWidget(all_save_in_memory);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_18);

        all_reset = new QPushButton(groupBox_2);
        all_reset->setObjectName("all_reset");
        all_reset->setFont(font2);

        horizontalLayout_18->addWidget(all_reset);


        verticalLayout_5->addWidget(groupBox_2);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_3->addWidget(scrollArea_2);

        stackedWidget->addWidget(admin_page);
        connection_page = new QWidget();
        connection_page->setObjectName("connection_page");
        verticalLayout_7 = new QVBoxLayout(connection_page);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(3, 3, 3, 3);
        groupBox_5 = new QGroupBox(connection_page);
        groupBox_5->setObjectName("groupBox_5");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy3);
        formLayout = new QFormLayout(groupBox_5);
        formLayout->setObjectName("formLayout");
        rb_serial = new QRadioButton(groupBox_5);
        rb_serial->setObjectName("rb_serial");
        rb_serial->setChecked(true);

        formLayout->setWidget(0, QFormLayout::LabelRole, rb_serial);

        group_serial = new QGroupBox(groupBox_5);
        group_serial->setObjectName("group_serial");
        sizePolicy2.setHeightForWidth(group_serial->sizePolicy().hasHeightForWidth());
        group_serial->setSizePolicy(sizePolicy2);
        QFont font3;
        font3.setPointSize(8);
        group_serial->setFont(font3);
        horizontalLayout_17 = new QHBoxLayout(group_serial);
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        refresh_ports = new QPushButton(group_serial);
        refresh_ports->setObjectName("refresh_ports");
        sizePolicy1.setHeightForWidth(refresh_ports->sizePolicy().hasHeightForWidth());
        refresh_ports->setSizePolicy(sizePolicy1);
        refresh_ports->setMaximumSize(QSize(16777215, 22));
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        refresh_ports->setIcon(icon);

        horizontalLayout_17->addWidget(refresh_ports);

        serial_combo_box = new QComboBox(group_serial);
        serial_combo_box->setObjectName("serial_combo_box");
        serial_combo_box->setMinimumSize(QSize(250, 0));
        serial_combo_box->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_17->addWidget(serial_combo_box);


        formLayout->setWidget(0, QFormLayout::FieldRole, group_serial);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        formLayout->setItem(1, QFormLayout::LabelRole, horizontalSpacer);

        groupBox_3 = new QGroupBox(groupBox_5);
        groupBox_3->setObjectName("groupBox_3");
        verticalLayout_6 = new QVBoxLayout(groupBox_3);
        verticalLayout_6->setObjectName("verticalLayout_6");
        ip_adress_2 = new QLineEdit(groupBox_3);
        ip_adress_2->setObjectName("ip_adress_2");
        ip_adress_2->setMinimumSize(QSize(0, 0));
        ip_adress_2->setMaximumSize(QSize(1677215, 16777215));
        ip_adress_2->setFont(font2);
        ip_adress_2->setMaxLength(3);

        verticalLayout_6->addWidget(ip_adress_2);


        formLayout->setWidget(1, QFormLayout::FieldRole, groupBox_3);


        verticalLayout_7->addWidget(groupBox_5);

        connect_btn = new QPushButton(connection_page);
        connect_btn->setObjectName("connect_btn");
        sizePolicy1.setHeightForWidth(connect_btn->sizePolicy().hasHeightForWidth());
        connect_btn->setSizePolicy(sizePolicy1);
        connect_btn->setMinimumSize(QSize(0, 27));
        connect_btn->setMaximumSize(QSize(16777215, 27));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial")});
        font4.setPointSize(12);
        connect_btn->setFont(font4);

        verticalLayout_7->addWidget(connect_btn);

        verticalSpacer_4 = new QSpacerItem(20, 260, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_4);

        version = new QLabel(connection_page);
        version->setObjectName("version");
        version->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_7->addWidget(version);

        stackedWidget->addWidget(connection_page);

        verticalLayout_4->addWidget(stackedWidget);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1025, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        menu_button->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\277\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217", nullptr));
        pb_error_cleaner->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\276\321\210\320\270\320\261\320\272\320\270", nullptr));
        label->setText(QString());
        groupBox->setTitle(QString());
        groupBox_2->setTitle(QString());
        all_save_seed->setText(QCoreApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\201\320\270\320\264\320\260", nullptr));
        all_restore_seed->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\321\201\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\201\320\270\320\264\320\260", nullptr));
        all_save_in_memory->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262 \320\277\320\260\320\274\321\217\321\202\321\214", nullptr));
        all_reset->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201 \320\264\320\276 \320\267\320\260\320\262\320\276\320\264\321\201\320\272\320\270\321\205 \320\275\320\260\321\201\321\202\321\200\320\276\320\265\320\272", nullptr));
        groupBox_5->setTitle(QString());
        rb_serial->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\321\213\320\271 \320\277\320\276\321\200\321\202", nullptr));
        group_serial->setTitle(QCoreApplication::translate("MainWindow", "Port", nullptr));
        refresh_ports->setText(QString());
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\220\320\264\321\200\320\265\321\201 \320\272\320\276\320\274\321\203\321\202\320\260\321\206\320\270\320\276\320\275\320\275\320\276\320\263\320\276 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", nullptr));
        ip_adress_2->setText(QCoreApplication::translate("MainWindow", "00a", nullptr));
        connect_btn->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        version->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
