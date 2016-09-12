#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createaction();
    createmenus();  //菜单栏
    createToolBars();//工具栏
    createdockwidget();//停靠部件

    datafile=NULL;
    rwthread1=NULL;
    rwthread2=NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
}


//void MainWindow::on_lineEdit_editingFinished()
//{
//    QString strread;
//    strread = ui->lineEdit->text();
//    ui->listWidget->setUpdatesEnabled(false);
//    ui->listWidget->addItem(strread);

//}

void MainWindow::on_open_clicked()
{
    QString num;
    num=QString::number( usb.getnumDEv());
    ui->listWidget_2->addItem(num);

    QString label;
    if(!usb.isopened()){
        label+=usb.status.at(usb.Open(0));
        ui->listWidget_2->addItem(label);
    }
    else
        ui->listWidget_2->addItem("device 0 is allrdeay opened");
}

void MainWindow::on_close_clicked()
{
    QString label;
    if(usb.isopened()){

        label+=usb.status.at(usb.Close());
        ui->listWidget_2->addItem(label);
    }
    else
        ui->listWidget_2->addItem("device 0 is allrdeay closed");
}

void MainWindow::openusb()//closeusb action
{
    statusdock->setVisible(true);//使停靠栏可见

    QString num;
    num=QString::number( usb.getnumDEv());
    num+=" devices";
    ui->listWidget_2->addItem(num);

    QString label;
    if(!usb.isopened()){
        label+=usb.status.at(usb.Open(0));
        ui->listWidget_2->addItem(label);
    }
    else
        ui->listWidget_2->addItem("device 0 is allrdeay opened");

    ui->listWidget_2->scrollToBottom();
}

void MainWindow::closeusb()//closeusb action
{
    statusdock->setVisible(true);//使停靠栏可见

    QString label;
    if(usb.isopened()){

        label+=usb.status.at(usb.Close());
        ui->listWidget_2->addItem(label);
    }
    else
        ui->listWidget_2->addItem("device 0 is allrdeay closed");

    ui->listWidget_2->scrollToBottom();
}

void MainWindow::tdlas()
{
    tdlasDialog tdlasdl;
    tdlasdl.exec();
}

/// \brief MainWindow::dataacquisition
///

void MainWindow::dataacquisition()//数据采集 action
{
    statusdock->setVisible(true);//使停靠栏可见

    if(1){//usb.getnumDEv()
        if(1){//usb.isopened()
            QFileDialog::Options options = QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly;
            //options |= QFileDialog::DontUseNativeDialog;
            savedirectory = QFileDialog::getExistingDirectory(this,
                                                                      tr("Save Directory"),
                                                                      "",
                                                                      options);
            if (savedirectory.isEmpty())
                qDebug()<<"err";
            else{
                ui->listWidget_2->addItem("save at "+savedirectory);
                if(savedirectory=="C:/"){
                    ui->listWidget_2->addItem("do not use C:/ as a saving position");
                    ui->listWidget_2->addItem("change dir and try again");
                    return;
                }
                QDateTime datetime=QDateTime::currentDateTime();//准备文件
                QString dt= datetime.toString("yyyy-MM-dd-HH.mm.ss");
                QDir::setCurrent(savedirectory);//准备文件
                datafile=new QFile(dt+"_acquicition.dat");
                //datafile->open(QIODevice::ReadWrite|QIODevice::Append|QIODevice::Truncate);
                lockthread=new QMutex;
                //THread 1
                rwthread1= new RWThread(&usb,datafile,4096,true,lockthread);
                connect(rwthread1,&RWThread::readbuffer,this,&MainWindow::threadstatus);
                connect(this,&MainWindow::stopacquisition,rwthread1,&RWThread::stoprun);
                connect(rwthread1, &RWThread::finished, rwthread1, &QObject::deleteLater);
                //Thread2
                rwthread2= new RWThread(&usb,datafile,4096,true,lockthread);
                connect(rwthread2,&RWThread::readbuffer,this,&MainWindow::threadstatus);
                connect(this,&MainWindow::stopacquisition,rwthread2,&RWThread::stoprun);
                connect(rwthread2, &RWThread::finished, rwthread2, &QObject::deleteLater);


                QByteArray TxBuffer;//准备写入usb的发送命令
                QDataStream in(&TxBuffer, QIODevice::ReadWrite);
                in<<(quint16)0x8800<<(quint16)4096;
                DWORD BytesReceived;//向下写入发送命令

                if(usb.Write(TxBuffer.data(),4,&BytesReceived)==FT_OK&&BytesReceived==4)
                    ui->listWidget_2->addItem("发送命令写入成功");
                qDebug()<<BytesReceived;

                UCHAR MASK = 0xff;
                UCHAR MODE = 0x40;
                usb.SetBitMode(MASK, MODE);
                rwthread1->start();//开始线程吧
                rwthread2->start();//开始线程吧

            }
        }
        else{
            ui->listWidget_2->addItem("err: ft_device's found, open it first");
        }

    }
    else{
        ui->listWidget_2->addItem("err: find a ft_device first");
    }

    ui->listWidget_2->scrollToBottom();
}

void MainWindow::stopdataacquisition()//停止数据采集 action
{
    emit stopacquisition(false);

    if(datafile!=NULL){
        rwthread1->wait();
        rwthread2->wait();
        datafile->open(QIODevice::ReadOnly);
        QDataStream outfile(datafile);
        QByteArray array;
        QDataStream arrayin(&array,QIODevice::ReadWrite);
        qint8 transfer;
        while(!outfile.atEnd()){
            outfile>>transfer;
            arrayin<<transfer;
        }

        //qDebug()<<outfile.readRawData(s,4096);

        QDateTime datetime=QDateTime::currentDateTime();//准备文件
        QString dt= datetime.toString("yyyy-MM-dd-HH.mm.ss");
        QDir::setCurrent(savedirectory);//准备文件
        QFile *txtfile=new QFile(dt+"_acquicition.txt");
        txtfile->open(QIODevice::ReadWrite|QIODevice::Append|QIODevice::Truncate);
        QTextStream trantextfile(txtfile);
        int i=0;
        while(i<array.size()){

            trantextfile<<(int)(array.at(i++));
        }
        datafile->close();
        txtfile->flush();
        txtfile->close();
    }
}

void MainWindow::threadstatus(quint16 st)//slot
{
    QString label;
    label=QString::number(st);
    ui->listWidget_2->addItem(label);
    ui->listWidget_2->scrollToBottom();
}


///
/// \brief MainWindow::creating...............
///
void MainWindow::createToolBars()
{
    toolusb=addToolBar("usb");
    toolusb->addAction(openusb_action);
    toolusb->addAction(closeusb_action);


    tooldataacquisition=addToolBar("data_acquisition");
    tooldataacquisition->addAction(dataacquisition_action);
    tooldataacquisition->addAction(stopdataacquisition_action);
    //insert here

}

void MainWindow::createaction()
{
    openusb_action= new QAction("openusb",this);
    connect(openusb_action,SIGNAL(triggered()),this,SLOT(openusb()));

    closeusb_action=new QAction("closeusb",this);
    connect(closeusb_action,SIGNAL(triggered()),this,SLOT(closeusb()));

    tdlas_action=new QAction("tdlas",this);
    connect(tdlas_action,SIGNAL(triggered()),this,SLOT(tdlas()));

    dataacquisition_action=new QAction("data acquisition",this);
    connect(dataacquisition_action,SIGNAL(triggered()),this,SLOT(dataacquisition()));

    stopdataacquisition_action= new QAction("stop data acquisition",this);
    connect(stopdataacquisition_action,SIGNAL(triggered()),this,SLOT(stopdataacquisition()));

}

void MainWindow::createmenus()//insert codes
{
    ui->menu->addAction(tdlas_action);
    ui->menu->addAction(openusb_action);
}

void MainWindow::createdockwidget()
{
    statusdock=new QDockWidget(tr("status"),this);
    statusdock->setWidget(ui->listWidget_2);
    addDockWidget(Qt::RightDockWidgetArea,statusdock);
}



void RWThread::run(){
    char RxBuffer[bufferlong];ZeroMemory(RxBuffer,bufferlong);
    datafile->open(QIODevice::ReadWrite|QIODevice::Append|QIODevice::Truncate);
    QDataStream infile(datafile);
    DWORD BytesReceived;
    QMutex lock1,lock2;
    usb->SetTimeouts(5000,1000);// Set read timeout of 5sec, write timeout of 1sec
    int runnum=0;
    while(runflag==true){
        //加锁
        lock->lock();

        usb->Read(RxBuffer,bufferlong,&BytesReceived);
        emit readbuffer(BytesReceived);
        sleep(1);
        //if(mode==MainWindow::ECT);//发送信号绘图，计算
        lock->unlock();
        //锁
        //lock2.lock();
        infile.writeRawData(RxBuffer,bufferlong);
        //lock2.unlock();
        runnum++;
    }
    datafile->flush();
    datafile->close();

}

void RWThread::stoprun(bool flag)
{
    if(this->isRunning())runflag=flag;
}
