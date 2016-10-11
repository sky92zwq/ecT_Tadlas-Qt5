#include "mythreads.h"
#include <QDebug>
#include <sys/time.h>


/// \brief RWThread::.........................
///
void RWThread::run(){ 
    while(runflag==true){
        //加锁
        lock->lock();
        usb->Read(RxBuffer,bufferlong,&BytesReceived);
        //msleep(190);
        lock->unlock();
        //锁
        //lock2.lock();
        infile->writeRawData((char*)RxBuffer,bufferlong);
        //lock2.unlock();
        //runnum++;
        switch(mode){
        case ECT:
            //0.0001~0.0002s
            emit sigECTtransfer(RxBuffer,bufferlong);
            break;
        case TDlas:
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
    int i=0;
    tranarg.maxtransfer=(buffer[i]*256+buffer[i+1])*256/8*3.14/2/400*2/8192*1000;
    tranarg.mintransfer=tranarg.maxtransfer;
    tranarg.tran.clear();
    for(;i<bufferlong;){
        transfer=(buffer[i]*256+buffer[i+1])*256/8*3.14/2/400*2/8192*1000;
        /*if(transfer!=ect->indicator())*/tranarg.tran<<transfer;
        if(transfer>tranarg.maxtransfer)tranarg.maxtransfer=transfer;
        if(transfer<tranarg.mintransfer)tranarg.mintransfer=transfer;
        trantextfile<<transfer<<endl;

        i+=2;
        if(transfer==ect->indicator())break;
    }

    int nextgo=1;
    int onecirclecount=0;
    for(;i<bufferlong;){
        transfer=(buffer[i]*256+buffer[i+1])*256/8*3.14/2/400*2/8192*1000;
        if(onecirclecount==10){
            emit sigdrawECTonecircledata(&onecirclearg);
            onecirclecount=0;
        }
        if(transfer==ect->indicator())
        {
            onecirclecount++;
            onecirclearg.maxtransfer=(buffer[i+2]*256+buffer[i+3])*256/8*3.14/2/400*2/8192*1000;
            onecirclearg.mintransfer=onecirclearg.maxtransfer;
            onecirclearg.tran.clear();
            nextgo=0;
        }
        if(nextgo<=ect->measurenumber()&&nextgo!=0){

            onecirclearg.tran<<transfer;
            if(transfer>onecirclearg.maxtransfer)onecirclearg.maxtransfer=transfer;
            if(transfer<onecirclearg.mintransfer)onecirclearg.mintransfer=transfer;
        }

        nextgo++;

        /*if(transfer!=ect->indicator())*/tranarg.tran<<transfer;
        if(transfer>tranarg.maxtransfer)tranarg.maxtransfer=transfer;
        if(transfer<tranarg.mintransfer)tranarg.mintransfer=transfer;
        trantextfile<<transfer<<endl;

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
