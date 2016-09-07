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
private slots:
    void acquisitioncount(){;}

    void threadstatus(FT_STATUS st);//看看子线程的状态
signals:

    void startacquisition(CS_ftfunction &usb,QFile *file);

private:
    void createToolBars();

    void createaction();

    void createmenus();

    void createdockwidget();

private:
    Ui::MainWindow *ui;

    QDateTime datetime;
private:

    QToolBar *toolusb;
    QToolBar *tooldataacquisition;

    QAction *openusb_action;
    QAction *closeusb_action;
    QAction *tdlas_action;
    QAction *dataacquisition_action;
private:
    QDockWidget *statusdock;
public:
    QThread RWthread1;
    QThread RWthread2;

    QByteArray RWbyte;

};
/// \brief The RWBuffer class多线程提供读写者,锁住buffer
///
class RWBuffer:public QObject
{
Q_OBJECT
public:
    explicit RWBuffer(bool run,const int bufferlong)
        :run(run),bufferlong(bufferlong),QObject(){}
public slots:
    void rwbuffer(CS_ftfunction& usb,QFile *datafile){
         char RxBuffer[bufferlong];

         QDataStream infile(datafile);
         DWORD BytesReceived;
         QMutex lock1,lock2;
         while(run==true){
             //加锁
             lock1.lock();

             emit readbuffer(usb.Read(RxBuffer,bufferlong,&BytesReceived));
             lock1.unlock();
             //锁
             lock2.lock();
             infile.writeRawData(RxBuffer,sizeof(char)*bufferlong);//sizeof char就是8位
             lock2.unlock();
         }
    }
signals:

    void rwcount();
    void readbuffer(FT_STATUS);

private:
    uint count;//infinite how?
    const int bufferlong;
    quint8 shangweijibuffer[100];
public:
    bool run;

};


#endif // MAINWINDOW_H
