#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cb_panel.h>
#include <dc_panel.h>
#include "device_panel.h"
#include <tcp_usb_connector.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    dc_panel *dc;
    dc_panel *dc1;
    dc_panel *dc2;
    cb_panel *cb;
    tcp_usb_connector *conn;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
