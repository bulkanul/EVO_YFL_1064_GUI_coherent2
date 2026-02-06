QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport network


CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    amplifier_all_panel.cpp \
    amplifier_panel.cpp \
    channel_all_panel.cpp \
    channel_panel.cpp \
    divider_panel.cpp \
    flag_panel.cpp \
    generator_panel.cpp \
    main.cpp \
    device_panel.cpp \
    preamplifier_all_panel.cpp \
    preamplifier_panel.cpp \
    tcp_usb_connector.cpp \
    mainwindow.cpp

HEADERS += \
    amplifier_all_panel.h \
    amplifier_panel.h \
    channel_all_panel.h \
    channel_panel.h \
    device_panel.h \
    divider_panel.h \
    flag_panel.h \
    generator_panel.h \
    preamplifier_all_panel.h \
    preamplifier_panel.h \
    tcp_usb_connector.h \
    mainwindow.h \

FORMS += \
    amplifier_all_panel.ui \
    amplifier_panel.ui \
    channel_all_panel.ui \
    channel_panel.ui \
    divider_panel.ui \
    flag_panel.ui \
    generator_panel.ui \
    mainwindow.ui \
    preamplifier_all_panel.ui \
    preamplifier_panel.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
