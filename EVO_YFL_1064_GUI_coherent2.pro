QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport network


CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    device_panel.cpp \
    dc_panel.cpp \
    cb_panel.cpp \
    tcp_usb_connector.cpp \
    mainwindow.cpp \
    tec_panel.cpp \
    user_panel.cpp

HEADERS += \
    device_panel.h \
    dc_panel.h \
    cb_panel.h \
    tcp_usb_connector.h \
    mainwindow.h \
    tec_panel.h \
    user_panel.h

FORMS += \
    dc_panel.ui \
    cb_panel.ui \
    mainwindow.ui \
    tec_panel.ui \
    user_panel.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
