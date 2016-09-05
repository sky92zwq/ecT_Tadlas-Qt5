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
#include <qbuffer.h>


namespace Ui {
class MainWindow;
}
///
/// \brief The RWBuffer class多线程提供读写者,锁住buffer
///
class RWBuffer:public QObject
{
Q_OBJECT
public slots:
    void rwbuffer(CS_ftfunction& usb){
         char RxBuffer[bufferlong];

         QDataStream infile(&datafile, QIODevice::ReadWrite);
         DWORD BytesReceived;
         while(){
             //加锁
             usb.Read(&RxBuffer,bufferlong,&BytesReceived);
             //锁
             infile.writeRawData(RxBuffer,sizeof(char)*bufferlong);//sizeof char就是8位

         }
    }
signals:

    void rwcount();

private:
    uint count;//infinite how?
    const int bufferlong;
    quint8 shangweijibuffer[100];

};
///
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
signals:

    void startacquisition();

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
    QThread RWthread;
    QBuffer RWbuffer;
    QByteArray RWbyte;
    friend RWBuffer  BufferRWer;

};


#endif // MAINWINDOW_H
