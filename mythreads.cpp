#include "mythreads.h"
#include <QDebug>


/// \brief RWThread::.........................
///
void RWThread::run(){

    while(runflag==true){
        switch(mode){
        case ECT:
            //加锁
            lock->lock();
            usb->Read(RxBuffer,bufferlong,&BytesReceived);
            //msleep(100);
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
//    QByteArray bytearray(buffer,bufferlong);
//    QDataStream outbytearray(&bytearray,QIODevice::ReadOnly);
//    outbytearray>>transfer;
    for(int i=0;i<bufferlong;){
        transfer=buffer[i]*255+buffer[i+1];
        trantextfile<<transfer<<' ';
        i+=2;
    }


}
void processThreadobj::transferforTDlasdrawing(char *buffer, int bufferlong)
{
;
}
