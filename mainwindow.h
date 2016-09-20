#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cs_ftfunction.h"
#include "tdlasdialog.h"
#include <qdockwidget.h>
#include <qtoolbar.h>
#include <QFile>
#include <qfiledialog.h>
#include <qdatetime.h>
#include <qthread.h>
#include <qreadwritelock.h>
#include <qmutex.h>
#include <qmath.h>
#include "mythreads.h"

namespace Ui {
class MainWindow;
}


/// \brief The MainWindow class
///
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

    void Ect();

    void dataacquisition();

    void stopdataacquisition();

    void startdataacquisition();
private slots:
    void acquisitioncount(){;}

    void threadstatus(quint16 st);//看看子线程的状态

    void childrenWidstatus(QString &str);//看子窗口
signals:

    void startacquisition(CS_ftfunction &usb,QString savedirectory);
    void stopacquisition1(bool);
    void stopacquisition2(bool);
signals:
    void transmitusb(CS_ftfunction *);

private:
    void createToolBars();

    void createaction();

    void createmenus();

    void createdockwidget();

    void createtdlasview();

    void createectview();
private:
    Ui::MainWindow *ui;

    QDateTime datetime;
    QFile *datafile;
    QString savedirectory;
private:
    QToolBar *toolmode;
    QToolBar *toolusb;
    QToolBar *tooldataacquisition;

    QAction *openusb_action;
    QAction *closeusb_action;
    QAction *tdlas_action;
    QAction *ECT_action;
    QAction *dataacquisition_action;
    QAction *stopdataacquisition_action;
    QAction *startdataacquisition_action;
private:
    QDockWidget *statusdock;
public:
    QMutex *lockthread;
    RWThread *rwthread1;
    RWThread *rwthread2;
    processThread *processthread;

    QByteArray RWbyte;
public:
    enum ET{
        ECT,
        TDlas
    };
    ET mode;
    int RunSyn;
public:
    inline bool usbwrite();

};





#endif // MAINWINDOW_H
