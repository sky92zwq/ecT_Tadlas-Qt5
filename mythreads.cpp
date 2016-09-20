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
            //if(mode==MainWindow::ECT);//发送信号绘图，计算
            lock->unlock();
            //锁
            //lock2.lock();
            infile->writeRawData(RxBuffer,bufferlong);
            //lock2.unlock();
            //runnum++;
            emit readbuffer(BytesReceived);
            break;
        case TDlas:
            break;
        }
    }
    datafile->flush();
    datafile->close();
    free(RxBuffer);

}

void RWThread::stoprun(bool flag)
{
    if(this->isRunning())runflag=flag;

}

/// \brief processThread::run
///
void processThread::run()
{
    switch (mode){
    case ECT:
        while(!outfile->atEnd()){
            outfile->operator >>(transfer);
            trantextfile->operator <<(transfer)<<' ';
            qDebug()<<transfer;
            if (count ==1024/2){
                //emit re;//1024
                count=0;
            }
            count++;
        }
        break;

    case TDlas:
        break;

    }


    datafile->close();
    txtfile->flush();
    txtfile->close();
}
