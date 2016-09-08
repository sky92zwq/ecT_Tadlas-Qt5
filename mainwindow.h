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

    void stopacquisition();
private slots:
    void acquisitioncount(){;}

    void threadstatus(FT_STATUS st);//看看子线程的状态
signals:

    void startacquisition(CS_ftfunction &usb,QString savedirectory);

private:
    void createToolBars();

    void createaction();

    void createmenus();

    void createdockwidget();

private:
    Ui::MainWindow *ui;

    QDateTime datetime;
    QFile *datafile;
private:

    QToolBar *toolusb;
    QToolBar *tooldataacquisition;

    QAction *openusb_action;
    QAction *closeusb_action;
    QAction *tdlas_action;
    QAction *dataacquisition_action;
    QAction *stopacquisition_action;
private:
    QDockWidget *statusdock;
public:
    QThread RWthread1;
    QThread RWthread2;

    QByteArray RWbyte;

};


/// \brief The RWThread class
///
class RWThread : public QThread
  {
      Q_OBJECT
public:
    explicit RWThread(CS_ftfunction *u, QFile *df,const int bl)
        :usb(u),datafile(df),bufferlong(bl),QThread(){}
    void run();
          /* ... here is the expensive or blocking operation ... */
signals:
    void resultReady(const QString &s);

signals:

    void rwcount();
    void readbuffer(FT_STATUS);

private:
    CS_ftfunction *usb;
    QFile *datafile;
    QString savedirectory;
    uint count;//infinite how?
    const int bufferlong;
    quint8 shangweijibuffer[100];


  };



#endif // MAINWINDOW_H
