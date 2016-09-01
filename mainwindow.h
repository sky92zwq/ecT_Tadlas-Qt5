#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cs_ftfunction.h"
#include "tdlasdialog.h"
#include <qdockwidget.h>
#include <qtoolbar.h>
#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    CS_ftfunction usb;

private slots:

    void on_open_clicked();

    void on_close_clicked();
protected slots:
    void openusb();

    void closeusb();

    void tdlas();

    void dataacquisition();
private:
    void createToolBars();

    void createaction();

    void createmenus();

    void createdockwidget();

private:
    Ui::MainWindow *ui;
private:

    QToolBar *toolusb;
    QToolBar *tooldataacquisition;

    QAction *openusb_action;
    QAction *closeusb_action;
    QAction *tdlas_action;
    QAction *dataacquisition_action;

    QDockWidget *statusdock;
};

#endif // MAINWINDOW_H
