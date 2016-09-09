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


namespace Ui {
class MainWindow;
}
/// \brief The RWThread class
///
class RWThread : public QThread
  {
      Q_OBJECT
public:
    explicit RWThread(CS_ftfunction *u, QFile *df,const int bl,bool rf,QMutex *lk)
        :usb(u),datafile(df),bufferlong(bl),runflag(rf),lock(lk),QThread(){}
    void run();
          /* ... here is the expensive or blocking operation ... */
signals:
    void resultReady(const QString &s);

signals:

    void rwcount();
    void readbuffer(quint16);
public slots:
    void stoprun(bool flag);

private:
    CS_ftfunction *usb;
    QFile *datafile;
    QMutex *lock;
    bool runflag;
    uint count;//infinite how?
    const int bufferlong;
    quint8 shangweijibuffer[100];
};

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

    void dataacquisition();

    void stopdataacquisition();
private slots:
    void acquisitioncount(){;}

    void threadstatus(quint16 st);//看看子线程的状态
signals:

    void startacquisition(CS_ftfunction &usb,QString savedirectory);
    void stopacquisition(bool);

private:
    void createToolBars();

    void createaction();

    void createmenus();

    void createdockwidget();

private:
    Ui::MainWindow *ui;

    QDateTime datetime;
    QFile *datafile;
    QString savedirectory;
private:

    QToolBar *toolusb;
    QToolBar *tooldataacquisition;

    QAction *openusb_action;
    QAction *closeusb_action;
    QAction *tdlas_action;
    QAction *dataacquisition_action;
    QAction *stopdataacquisition_action;
private:
    QDockWidget *statusdock;
public:
    QMutex *lockthread;
    RWThread *rwthread1;
    RWThread *rwthread2;

    QByteArray RWbyte;
public:
    enum{
        ECT,
        TDlas
    };
    int mode;

};





#endif // MAINWINDOW_H
