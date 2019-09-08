#include "myusb.h"


Myusb::Myusb(/* args */)
{
}

Myusb::~Myusb()
{
}

void Myusb::openusb()//closeusb action
{
    statusdock->setVisible(true);//使停靠栏可见

    quint32 numdev;
    QString num;
    usb.GetDeviceInfoList(&numdev);
    num=QString::number((quint16)numdev);
    num+=" devices";
    ui->listWidget_2->addItem(num);

    QString label("dev");
    quint32 i=0;
    if(!usb.isopened()){
        for(;i<numdev;i++){
            if(QString(usb.devInfo[i].Description)==QString("USB 2.0 <-> ECT Core Board A")){
                label+=QString::number(i);
                label+=": ";
                label+=usb.status.at(usb.Open(i));
                ui->listWidget_2->addItem(label);
                break;
            }
        }
    }
    else{
        ui->listWidget_2->addItem("device is allrdeay open");
    }
    usb.Purge(4096);
    ui->listWidget_2->scrollToBottom();
    emit ui->listWidget_2->currentItemChanged(ui->listWidget_2->item(ui->listWidget_2->count()-1)
                                              ,ui->listWidget_2->item(ui->listWidget_2->count()-2));
}

void Myusb::closeusb()//closeusb action
{
    statusdock->setVisible(true);//使停靠栏可见

    QString label;
    if(usb.isopened()&&!needstop){

        label+=usb.status.at(usb.Close());
        ui->listWidget_2->addItem(label);
    }
    else
        ui->listWidget_2->addItem("device  is allrdeay closed");

    ui->listWidget_2->scrollToBottom();
    emit ui->listWidget_2->currentItemChanged(ui->listWidget_2->item(ui->listWidget_2->count()-1)
                                              ,ui->listWidget_2->item(ui->listWidget_2->count()-2));
}



/// \brief Myusb::dataacquisition
///

void Myusb::dataacquisition()//数据采集 action
{
    statusdock->setVisible(true);//使停靠栏可见
    //usb.getnumDEv()
    //usb.isopened()
    QFileDialog::Options options = QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly;
    //options |= QFileDialog::DontUseNativeDialog;
    currentdirectory = QFileDialog::getExistingDirectory(this,
                                                              tr("Save Directory"),
                                                              "",
                                                              options);
    if (currentdirectory.isEmpty()){
        qDebug()<<"err";
        return;
    }
    else{
        savedirectory=currentdirectory;

        if(savedirectory=="C:/"){
            ui->listWidget_2->addItem("do not use C:/ as a saving position");
            ui->listWidget_2->addItem("change dir and try again");
            return;
        }
    }
    ui->listWidget_2->scrollToBottom();
    emit ui->listWidget_2->currentItemChanged(ui->listWidget_2->item(ui->listWidget_2->count()-1)
                                              ,ui->listWidget_2->item(ui->listWidget_2->count()-2));

}

void Myusb::stopdataacquisition()//停止数据采集 action
{
    if(datafile!=NULL&&rwthread1!=NULL){
        stopdataacquisition_action->setEnabled(false);

        rwthread1->disconnect(processthreadobj);
        rwthread2->disconnect(processthreadobj);

        processthreadobj->disconnect();
        if(reconstructflag){
            matlabhelper->disconnect();
            if(matlabthread->isRunning()){
                reconstructflag=false;
                matlabthread->quit();
                processthreadobj->timer.stop();
                //matlabthread->wait();
            }
        }
        processthread->quit();
        processthread->wait();

        emit stopacquisition2(false);
        rwthread2->wait();
        emit stopacquisition1(false);
        rwthread1->wait();


        datafile->close();
        txtfile->flush();
        txtfile->close();

        quint32 BytesReceived;
        measuresys->stop_acq_command();
        if (usb.Write(measuresys->TxBuffer.data(), measuresys->TxBuffer.size(), &BytesReceived) == FT_OK && BytesReceived == measuresys->TxBuffer.size())
        {
            ui->listWidget_2->addItem(QString("stop command ") + measuresys->name);
        }
    }

    startdataacquisition_action->setEnabled(true);
    needstop=false;
    ui->listWidget_2->scrollToBottom();
    emit ui->listWidget_2->currentItemChanged(ui->listWidget_2->item(ui->listWidget_2->count()-1)
                                              ,ui->listWidget_2->item(ui->listWidget_2->count()-2));
}

void Myusb::startdataacquisition()//开始采集
{
    if(usb.isopened()){//usb.isopened()

        startdataacquisition_action->setEnabled(false);
        ui->listWidget_2->addItem("save at "+savedirectory);

        QDateTime datetime=QDateTime::currentDateTime();//准备文件二进制
        QString dt= datetime.toString("yyyy-MM-dd_HH：mm：ss");
        QDir::setCurrent(savedirectory);
        datafile=new QFile(measuresys->name+dt+"_acquisition.bin");//准备文件
        //datafile->open(QIODevice::ReadWrite|QIODevice::Append|QIODevice::Truncate);
         //datetime=QDateTime::currentDateTime();//准备文件txt
         //dt= datetime.toString("yyyy-MM-dd_HH：mm：ss");
        QDir::setCurrent(savedirectory);
        txtfile=new QFile(measuresys->name+dt+"_acquisition.txt");
        txtfile->open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text);//准备文件


        lockthread=new QMutex;

        //THread 1
        rwthread1= new RWThread(&usb,datafile,4096,true,lockthread);
        connect(rwthread1,&RWThread::readbuffer,this,&Myusb::threadstatus);
        connect(this,&Myusb::stopacquisition1,rwthread1,&RWThread::stoprun,Qt::DirectConnection);
        connect(rwthread1, &RWThread::finished, rwthread1, &QObject::deleteLater);
        connect(rwthread1, &RWThread::finished, this, &Myusb::setrwthread1null);
        //Thread2
        rwthread2= new RWThread(&usb,datafile,4096,true,lockthread);
        connect(rwthread2,&RWThread::readbuffer,this,&Myusb::threadstatus);
        connect(this,&Myusb::stopacquisition2,rwthread2,&RWThread::stoprun,Qt::DirectConnection);
        connect(rwthread2, &RWThread::finished, rwthread2, &QObject::deleteLater);
        connect(rwthread2, &RWThread::finished, this, &Myusb::setrwthread2null);
        connect(rwthread2, &RWThread::finished, this, &Myusb::deletemylock);
        //processThread
        processthread=new QThread();
        processthreadobj=new processThreadobj(datafile,4096,true,txtfile);
        processthreadobj->moveToThread(processthread);
        connect(rwthread1,&RWThread::sigECTtransfer,processthreadobj,&processThreadobj::transferforECTdrawing);
        connect(rwthread1,&RWThread::sigTDlastransfer,processthreadobj,&processThreadobj::transferforTDlasdrawing);

        connect(rwthread2,&RWThread::sigECTtransfer,processthreadobj,&processThreadobj::transferforECTdrawing);
        connect(rwthread2,&RWThread::sigTDlastransfer,processthreadobj,&processThreadobj::transferforTDlasdrawing);
        //connect(rwthread2, &RWThread::quitprocess, processthread, &QThread::quit);
        //connect(rwthread2, &RWThread::finished, processthread, &QThread::quit);

        connect(processthreadobj,&processThreadobj::sigdrawECTusbdata,showwid->paintusbect,&myPaintusb::updatepoints,Qt::DirectConnection);//同步！！
        connect(processthreadobj,&processThreadobj::sigdrawECTonecircledata,showwid->paintusbect_2,&myPaintusb::updateonencirclepoints);//异步！！
        connect(processthreadobj,&processThreadobj::sigdrawECTdifference,showwid->paintusbect_2,&myPaintusb::updateonencirclepoints);//异步！！
        connect(processthreadobj,&processThreadobj::sigdrawTDlasusbdata,this,&Myusb::drawTDlasusbdata);
        connect(&(processthreadobj->timer), SIGNAL(timeout()), processthreadobj, SLOT(tomatlabhelper()), Qt::DirectConnection);//sigECTonecircledata
        connect(processthreadobj, &processThreadobj::sigECTonecircledata, measuresys, &MeasureSys::sigOneFrame);
        connect(processthread,&QThread::finished, processthread, &QObject::deleteLater);
        connect(processthread,&QThread::finished, processthreadobj, &QObject::deleteLater);

        quint32 BytesReceived;
        measuresys->start_acq_command();
        if(usb.Write(measuresys->TxBuffer.data(), measuresys->TxBuffer.size(),
            &BytesReceived)==FT_OK && BytesReceived==measuresys->TxBuffer.size())
            ui->listWidget_2->addItem(QString("start command ")+measuresys->name);
        usb.SetTimeouts(5000, 1000);

        //if(mode::m_mode==mode::TDlas){
        //    in<<(quint16)0x8800<<(quint16)4096;
        //    if(usb.Write(TxBuffer.data(),4,&BytesReceived)==FT_OK&&BytesReceived==4)
        //        ui->listWidget_2->addItem("start TDLAS commond");
        //    qDebug()<<BytesReceived;
        //    UCHAR MASK = 0xff;
        //    UCHAR MODE = 0x40;
        //    usb.SetBitMode(MASK, MODE);
        //    usb.SetTimeouts(5000,1000);// Set read timeout of 5sec, write timeout of 1sec


        rwthread1->start();//开始线程吧
        rwthread2->start();//开始线程吧
        processthread->start();//开始线程吧

        stopdataacquisition_action->setEnabled(true);
        needstop=true;
    }
    else
        ui->listWidget_2->addItem("open usb first");
    ui->listWidget_2->scrollToBottom();
    emit ui->listWidget_2->currentItemChanged(ui->listWidget_2->item(ui->listWidget_2->count()-1)
                                              ,ui->listWidget_2->item(ui->listWidget_2->count()-2));
}


void Myusb::setrwthread1null()
{
    rwthread1=NULL;
}

void Myusb::setrwthread2null()
{
    rwthread2=NULL;
}

void Myusb::deletemylock()
{
    delete lockthread;
    lockthread=NULL;
}





