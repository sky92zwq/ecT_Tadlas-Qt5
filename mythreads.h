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

        //int runnum=0;
    }
    void run(); /* ... here is the expensive or blocking operation ... */

signals:
    void resultReady(const QString &s);

signals:

    void rwcount();
    void readbuffer(char*);
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
class processThread : public QThread
{
    Q_OBJECT
public:
    enum ET{
        ECT,
        TDlas
    };
    ET mode;
public:
    //usb,二进制文件，buffer长度，标志，txt文件，mode
    explicit processThread( QFile *df,const int bl,bool rf,QFile *tf,ET m)
        :datafile(df),bufferlong(bl),runflag(rf),txtfile(tf),mode(m),QThread(){

        //ZeroMemory(RxBuffer,bufferlong);
        count=0;
        RxBuffer=(char*)malloc(bufferlong+1);

        datafile->open(QIODevice::ReadOnly);
        outfile= new QDataStream(datafile);

        txtfile->open(QIODevice::ReadWrite|QIODevice::Append|QIODevice::Truncate);
        trantextfile=new QTextStream(txtfile);
    }
    void run(); /* ... here is the expensive or blocking operation ... */

signals:

    void readbuffer(quint16);




private:

    QFile *datafile;

    bool runflag;

    const int bufferlong;

    char * RxBuffer;

    QDataStream *outfile;
    DWORD BytesReceived;
    QFile *txtfile;
    QTextStream *trantextfile;
    qint16 transfer;

    int count;

};
#endif // MYTHREADS_H
