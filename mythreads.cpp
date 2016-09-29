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
            msleep(30);
            lock->unlock();
            //锁
            //lock2.lock();
            infile->writeRawData((char*)RxBuffer,bufferlong);
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
            infile->writeRawData((char*)RxBuffer,bufferlong);
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
void processThreadobj::transferforECTdrawing(unsigned char *buffer, int bufferlong)
{
    //0.002s满足ECT
    tranarg.maxtransfer=buffer[0]*256+buffer[1];
    tranarg.mintransfer=tranarg.maxtransfer;

    int i=0;
    for(;i<bufferlong;){
        transfer=(buffer[i]*256+buffer[i+1])*256/8*3.14/2/400*2/8192*1000;
        trantextfile<<transfer<<' ';
        i+=2;
        if(transfer==ect->indicator())break;
    }

    count=i;
    tranarg.tran.clear();
    for(;i<bufferlong;){
        transfer=(buffer[i]*256+buffer[i+1])*256/8*3.14/2/400*2/8192*1000;
        if(transfer!=ect->indicator())tranarg.tran<<transfer;
        if(transfer>tranarg.maxtransfer)tranarg.maxtransfer=transfer;
        if(transfer<tranarg.mintransfer)tranarg.mintransfer=transfer;
        trantextfile<<transfer<<' ';

/*        if(count==4*(66+1)){//&&(buffer[i-2]*256+buffer[i-1])==ect->indicator()一次有效数据循环发送
//            onecirclearg.maxtransfer=transfer;
//            onecirclearg.mintransfer=transfer;
//            for(int j=i;j<2*66;){
//                transfer=buffer[j]*256+buffer[j+1];
//                if(transfer!=ect->indicator())onecirclearg.tran<<transfer;
//                if(transfer>onecirclearg.maxtransfer)onecirclearg.maxtransfer=transfer;
//                if(transfer<onecirclearg.mintransfer)onecirclearg.mintransfer=transfer;
//                j+=2;
//            }
//            emit sigdrawECTonecircledata(&onecirclearg);
//        }*/

        i+=2;
    }

    emit sigdrawECTusbdata(&tranarg);

}
void processThreadobj::transferforTDlasdrawing(unsigned char *buffer, int bufferlong)
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
