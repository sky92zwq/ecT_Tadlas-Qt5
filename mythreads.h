#ifndef MYTHREADS_H
#define MYTHREADS_H

#include <QObject>
#include "cs_ftfunction.h"
#include <qtoolbar.h>
#include <QFile>
#include <QTextStream>
#include <qdatetime.h>
#include <qthread.h>
#include <qmutex.h>
#include <qmath.h>


/// \brief The RWThread class
///
class RWThread : public QThread
  {
      Q_OBJECT
public:
    enum ET{
        ECT,
        TDlas
    };
    ET mode;
public:
    //usb,二进制文件，buffer长度，标志，锁
    explicit RWThread(CS_ftfunction *u, QFile *df,const int bl,bool rf,QMutex *lk,ET m)
        :usb(u),datafile(df),bufferlong(bl),runflag(rf),lock(lk),mode(m),QThread(){
        //ZeroMemory(RxBuffer,bufferlong);
        RxBuffer=(char*)malloc(bufferlong+1);
        datafile->open(QIODevice::ReadWrite|QIODevice::Append|QIODevice::Truncate);
        infile= new QDataStream(datafile);

    }
    void run(); /* ... here is the expensive or blocking operation ... */
signals:
    void sigECTtransfer(char*,int);
    void sigTDlastransfer(char*,int );
signals:
    void rwcount();
    void readbuffer(quint16 st);
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
    char * RxBuffer;
    QDataStream *infile;
    DWORD BytesReceived;
};

///
/// \brief The processThread class
///
class processThreadobj : public QObject
{
    Q_OBJECT
public:
    enum ET{
        ECT,
        TDlas
    };
    ET mode;
public:
    //二进制文件，buffer长度，标志，txt文件，mode
    explicit processThreadobj( QFile *df,const int bl,bool rf,QFile *tf,ET m)
        :datafile(df),bufferlong(bl),runflag(rf),txtfile(tf),mode(m),QObject(){

        //ZeroMemory(RxBuffer,bufferlong);
        count=0;

        datafile->open(QIODevice::ReadOnly);
        outfile.setDevice(datafile);

        txtfile->open(QIODevice::ReadWrite|QIODevice::Append|QIODevice::Truncate);
        trantextfile.setDevice(txtfile);
    }


signals:

    void readbuffer(quint16);

private:
    QFile *datafile;
    bool runflag;
    const int bufferlong;
    char * RxBuffer;

    QDataStream outfile;
    DWORD BytesReceived;
    QFile *txtfile;
    QTextStream trantextfile;
    qint16 transfer;

    int count;
public slots:
    void transferforECTdrawing(char*buffer, int bufferlong);
    void transferforTDlasdrawing(char*buffer, int bufferlong);

};
#endif // MYTHREADS_H
