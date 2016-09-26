#include "mythreads.h"
#include <QDebug>
#include <sys/time.h>


/// \brief RWThread::.........................
///
void RWThread::run(){

    while(runflag==true){
        switch(mode){
        case ECT:
            //0.0001~0.0002s
            //加锁
            lock->lock();
            usb->Read(RxBuffer,bufferlong,&BytesReceived);
            msleep(100);
            lock->unlock();
            //锁
            //lock2.lock();
            infile->writeRawData(RxBuffer,bufferlong);
            //lock2.unlock();
            //runnum++;
            emit sigECTtransfer(RxBuffer,bufferlong);
            break;
        case TDlas:
            lock->lock();
            usb->Read(RxBuffer,bufferlong,&BytesReceived);
            //msleep(100);
            lock->unlock();
            //锁
            //lock2.lock();
            infile->writeRawData(RxBuffer,bufferlong);
            //lock2.unlock();
            emit sigTDlastransfer(RxBuffer,bufferlong);
            break;
        }
    }
    datafile->flush();
    //datafile->close();
    free(RxBuffer);

}

void RWThread::stoprun(bool flag)
{
    if(this->isRunning())runflag=flag;

}

/// \brief processThread::............................
///
void processThreadobj::transferforECTdrawing(char *buffer, int bufferlong)
{
    //0.002s满足ECT
    tranarg.maxtransfer=buffer[0]*256+buffer[1];
    tranarg.mintransfer=tranarg.maxtransfer;

    for(int i=0;i<bufferlong;){
        transfer=buffer[i]*256+buffer[i+1];
        tranarg.tran<<transfer;
        if(transfer>tranarg.maxtransfer)tranarg.maxtransfer=transfer;
        if(transfer<tranarg.mintransfer)tranarg.mintransfer=transfer;
        trantextfile<<transfer<<' ';
        i+=2;
    }

    emit sigdrawECTusbdata(&tranarg);

}
void processThreadobj::transferforTDlasdrawing(char *buffer, int bufferlong)
{
    //30us noway,挑拣,发送
;
}
///
/// \brief processThread::................................
///
void processThread::run()
{
    this->exec();
}
