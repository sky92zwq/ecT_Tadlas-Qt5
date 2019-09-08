#include "mythreads.h"
#include <QDebug>



/// \brief RWThread::.........................
///
void RWThread::run(){ 
    while(runflag==true){
        //加锁
        lock->lock();
        CS_ftfunction::Instance()->Read(RxBuffer,bufferlong,&BytesReceived);
        //msleep(190);
        lock->unlock();
        //锁
        //lock2.lock();
        infile->writeRawData((char*)RxBuffer,bufferlong);
        //lock2.unlock();
        //runnum++;
        switch(mode::m_mode){
        case mode::ECT:
            //0.0001~0.0002s
            emit sigECTtransfer(RxBuffer,bufferlong);
            break;
        case mode::TDlas:
            emit sigTDlastransfer(RxBuffer,bufferlong);
            break;
        }
    }
    datafile->flush();
    //datafile->close();
    free(RxBuffer);
    emit quitprocess();

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
    tranarg.maxtransfer=calculatebuffer(buffer,i);
    tranarg.mintransfer=tranarg.maxtransfer;
    tranarg.tran.clear();
    for(;i<bufferlong;){
        transfer=calculatebuffer(buffer,i);
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
        transfer=calculatebuffer(buffer,i);
        if(nextgo==ect->measurenumber()){
            differencearg.maxtransfer=onecirclearg.tran.data()[0]-ect->datavoid.data()[0];
            differencearg.mintransfer=onecirclearg.tran.data()[0]-ect->datavoid.data()[0];
            for(int t=0;t<ect->measurenumber();t++){
                storeonecircle[t]=onecirclearg.tran.data()[t];
                storedifference[t]=onecirclearg.tran.data()[t]-ect->datavoid.data()[t];
                differencearg.maxtransfer=(std::max)(differencearg.maxtransfer,storedifference[t]);
                differencearg.mintransfer=(std::min)(differencearg.mintransfer,storedifference[t]);
            }
        }
        if(onecirclecount==10){
            if(ect->differencemode)
                emit sigdrawECTdifference(storedifference,differencearg.maxtransfer,differencearg.mintransfer);
            else
                emit sigdrawECTonecircledata(storeonecircle,onecirclearg.maxtransfer,onecirclearg.mintransfer);
           // emit sigECTonecircledata(&onecirclearg);
            onecirclecount=0;
        }
        if(transfer==ect->indicator())
        {
            onecirclecount++;
            onecirclearg.maxtransfer=calculatebuffer(buffer,i+2);
            onecirclearg.mintransfer=onecirclearg.maxtransfer;
            onecirclearg.tran.clear();
            //D-value
//            if(ect->differencemode){
//                differencearg.maxtransfer=onecirclearg.maxtransfer-ect->datavoid.data()[0];
//                differencearg.mintransfer=differencearg.maxtransfer;
//                differencearg.tran.clear();
//            }
            nextgo=0;
        }
        if(nextgo<=ect->measurenumber()&&nextgo!=0){
            onecirclearg.tran<<transfer;
            if(transfer>onecirclearg.maxtransfer)onecirclearg.maxtransfer=transfer;
            if(transfer<onecirclearg.mintransfer)onecirclearg.mintransfer=transfer;
            //D-value
//            if(ect->differencemode){
//                differencearg.tran<<transfer-ect->datavoid.data()[nextgo-1];
//                if(differencearg.tran.last()>differencearg.maxtransfer)
//                    differencearg.maxtransfer=differencearg.tran.last();
//                if(differencearg.tran.last()<differencearg.mintransfer)
//                    differencearg.mintransfer=differencearg.tran.last();
//            }
        }

        nextgo++;

        /*if(transfer!=ect->indicator())*/
        tranarg.tran<<transfer;
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

void processThreadobj::tomatlabhelper()
{
    //if(onecirclearg.tran.count()==ect->measurenumber())
    {
        emit sigECTonecircledata(storeonecircle);
    }
}
