#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tdlasdialog.h"
#include <QDebug>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),needstop(false),reconstructflag(false),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ect=ECTClass::getInstance();
    ect->setelectrode_number(16);

    createaction();
    createmenus();  //菜单栏
    createToolBars();//工具栏
    createdockwidget();//停靠部件


    datafile=NULL;
    rwthread1=NULL;
    rwthread2=NULL;
    savedirectory="./";

    showwid=new showwidget;
    setCentralWidget(showwid);

	EctSysObj = new EctSys(&usb,4096,48);
	TdlasSysObj = new TdlasSys(&usb, 4096, 20);
	measuresys = EctSysObj;
    if(mode::m_mode==mode::ECT)
        Ect();
    if (mode::m_mode ==mode::TDlas)
        tdlas();
//    stopdataacquisition_action->setEnabled(false);
	openglThread = new QThread;
	tik_worker = new Tikhonov_Alg("laplacian");
}

MainWindow::~MainWindow()
{
    if(needstop)stopdataacquisition();
    delete ui;
//    delete rwthread1;
//    delete rwthread2;
//    delete processthreadobj;
//    delete processthread;
    delete showwid;

    delete statusdock;
    delete electrode_numberbox;
    delete electrode_numberlabel;
    delete ectdocklayout;
    delete ectdockcontent;
    delete ectdock;

    delete LBP;
    delete caldelong;
    delete reconstruct_action;
    delete menualgorithm;

    delete openusb_action;
    delete closeusb_action;
    delete tdlas_action;
    delete ECT_action;
    delete dataacquisition_action;
    delete stopdataacquisition_action;
    delete startdataacquisition_action;

    delete toolmode;
    delete toolusb;
    delete tooldataacquisition;
    delete toolreconstruction;


}

void MainWindow::resizeEvent(QResizeEvent *event)
{

//    QApplication::postEvent(showwid->paintusbect, new QEvent(QEvent::Resize));
//    QApplication::postEvent(showwid->paintusbect_2, new QEvent(QEvent::Resize));
}



void MainWindow::openusb()//closeusb action
{
    statusdock->setVisible(true);//使停靠栏可见

    DWORD numdev;
    QString num;
    usb.GetDeviceInfoList(&numdev);
    num=QString::number((quint16)numdev);
    num+=" devices";
    ui->listWidget_2->addItem(num);

    QString label("dev");
    DWORD i=0;
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

void MainWindow::closeusb()//closeusb action
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

void MainWindow::tdlas()
{
	measuresys = TdlasSysObj;
    mode::m_mode=mode::TDlas;
    ectdock->setVisible(false);

    tdlas_action->setChecked(true);
    ECT_action->setChecked(false);

    createtdlasview();

    tdlasDialog tdlasdl;
    connect(this,&MainWindow::transmitusb,&tdlasdl,&tdlasDialog::acceptusb);
    connect(&tdlasdl,&tdlasDialog::mystatus,this,&MainWindow::childrenWidstatus);
    emit transmitusb(&usb);
    tdlasdl.exec();
}

void MainWindow::Ect()
{
	measuresys = EctSysObj;
    mode::m_mode=mode::ECT;
    if(!ectdock->isVisible())ectdock->setVisible(true);

    ECT_action->setChecked(true);

    createectview();

    tdlas_action->setChecked(false);
}

/// \brief MainWindow::dataacquisition
///

void MainWindow::dataacquisition()//数据采集 action
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

void MainWindow::stopdataacquisition()//停止数据采集 action
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

		DWORD BytesReceived;
		measuresys->stop_acq_command();
		if (usb.Write(measuresys->TxBuffer.data(), measuresys->TxBuffer.size(), &BytesReceived) == FT_OK
			&& BytesReceived == measuresys->TxBuffer.size())
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

void MainWindow::startdataacquisition()//开始采集
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
        connect(rwthread1,&RWThread::readbuffer,this,&MainWindow::threadstatus);
        connect(this,&MainWindow::stopacquisition1,rwthread1,&RWThread::stoprun,Qt::DirectConnection);
        connect(rwthread1, &RWThread::finished, rwthread1, &QObject::deleteLater);
        connect(rwthread1, &RWThread::finished, this, &MainWindow::setrwthread1null);
        //Thread2
        rwthread2= new RWThread(&usb,datafile,4096,true,lockthread);
        connect(rwthread2,&RWThread::readbuffer,this,&MainWindow::threadstatus);
        connect(this,&MainWindow::stopacquisition2,rwthread2,&RWThread::stoprun,Qt::DirectConnection);
        connect(rwthread2, &RWThread::finished, rwthread2, &QObject::deleteLater);
        connect(rwthread2, &RWThread::finished, this, &MainWindow::setrwthread2null);
        connect(rwthread2, &RWThread::finished, this, &MainWindow::deletemylock);
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
        connect(processthreadobj,&processThreadobj::sigdrawTDlasusbdata,this,&MainWindow::drawTDlasusbdata);
		connect(&(processthreadobj->timer), SIGNAL(timeout()), processthreadobj, SLOT(tomatlabhelper()), Qt::DirectConnection);//sigECTonecircledata
		connect(processthreadobj, &processThreadobj::sigECTonecircledata, measuresys, &MeasureSys::sigOneFrame);
        connect(processthread,&QThread::finished, processthread, &QObject::deleteLater);
        connect(processthread,&QThread::finished, processthreadobj, &QObject::deleteLater);

		DWORD BytesReceived;
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

void MainWindow::reconstruct()
{
	if (!reconstructflag && needstop)
	{
		connect(measuresys, &MeasureSys::reconstructN, showwid->openglwid, &GLWidget::updateReconstructN);
		connect(measuresys, &MeasureSys::reconstructedRGB, showwid->openglwid, &GLWidget::updateReconstructRGB);
		measuresys->beforeconstruct(measuresys->N);
		measuresys->beforeconstruct();
		measuresys->reconstruct();
		processthreadobj->timer.start(10);

	}

    ui->listWidget_2->scrollToBottom();
    emit ui->listWidget_2->currentItemChanged(ui->listWidget_2->item(ui->listWidget_2->count()-1)
                                              ,ui->listWidget_2->item(ui->listWidget_2->count()-2));

}

void MainWindow::drawTDlasusbdata(argfordraw *arg)
{

}

void MainWindow::setrwthread1null()
{
    rwthread1=NULL;
}

void MainWindow::setrwthread2null()
{
    rwthread2=NULL;
}

void MainWindow::deletemylock()
{
    delete lockthread;
    lockthread=NULL;
}

void MainWindow::threadstatus(double st)//slot
{
    QString label;
    label.setNum(st);
    ui->listWidget_2->addItem(label);
    ui->listWidget_2->scrollToBottom();

}

void MainWindow::childrenWidstatus(QString &str)//查看 子窗口 状态
{
    ui->listWidget_2->addItem(str);
    ui->listWidget_2->scrollToBottom();
}

void MainWindow::setelectrodenum(const QString &text)
{
    ect->setelectrode_number((quint8)text.toInt());
    qDebug()<<ect->measurenumber();
}

void MainWindow::setectdifference(const QString &differ)
{
    if(differ==QString("difference")&&ect->alreadyVoidcalibtrated())ect->differencemode=true;
    else if(differ==QString("difference")){
        ui->listWidget_2->addItem("void calibration first");
        chosedifferencebox->setCurrentText("origin");
    }
    else {
        ect->differencemode=false;
        chosedifferencebox->setCurrentText("origin");
    }
    qDebug()<<ect->differencemode;
}
void MainWindow::ectvoidCalibration()
{
    if(usb.isopened()&& !needstop){
        //prepare files
        QDateTime datetime = QDateTime::currentDateTime();//׼���ļ�txt
        QString dt = datetime.toString("yyyy-MM-dd-HH：mm：ss");
        QDir::setCurrent(savedirectory);
        QFile *txtvoidfile = new QFile("ECT_" + dt + "_void.txt");
        txtvoidfile->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
        QTextStream txtstreamvoid(txtvoidfile);

        QByteArray TxBuffer;//׼��������д��usb�ķ�������
        TxBuffer.clear();
        QDataStream in(&TxBuffer, QIODevice::ReadWrite);
        DWORD BytesReceived;//end׼��
        in << (quint8)0x88;
        if (usb.Write(TxBuffer.data(), 1, &BytesReceived) == FT_OK&&BytesReceived == 1)
            ui->listWidget_2->addItem("voidcalibration 写入");
        usb.SetTimeouts(5000, 1000);// Set read timeout of 5sec, write timeout of 1sec

        const int bfl=4096;
        unsigned char rxbuffer[bfl+1];
        if (usb.Read(rxbuffer, bfl, &BytesReceived) == FT_OK&&BytesReceived == bfl){
            TxBuffer.clear();
            in << (quint8)0x77;
            usb.Write(TxBuffer.data(), 1, &BytesReceived);

            ect->setvoidcalibration(rxbuffer);
            argfordraw void1circle;
            float voidcircle[120];
            void1circle.maxtransfer=ect->datavoid.data()[0];
            void1circle.mintransfer=void1circle.maxtransfer;
            for(int i=0;i<ect->datavoid.count();i++)
            {
                txtstreamvoid<<ect->datavoid.at(i)<<endl;
                void1circle.tran.append(ect->datavoid.at(i));
                voidcircle[i]=void1circle.tran.last();
                if(void1circle.tran.last()>void1circle.maxtransfer)
                    void1circle.maxtransfer=void1circle.tran.last();
                if(void1circle.tran.last()<void1circle.mintransfer)
                    void1circle.mintransfer=void1circle.tran.last();
            }
            showwid->paintusbect_2->updateonencirclepoints(voidcircle,void1circle.maxtransfer,void1circle.mintransfer);
            txtvoidfile->close();
            delete voidcircle;

            ui->listWidget_2->addItem("voidcalibration ok");
        }
        else
            ui->listWidget_2->addItem("voidcalibration failed");

    }
    else
        ui->listWidget_2->addItem("open usb first for void calibration or runnning");
    ui->listWidget_2->scrollToBottom();
    emit ui->listWidget_2->currentItemChanged(ui->listWidget_2->item(ui->listWidget_2->count()-1)
                                              ,ui->listWidget_2->item(ui->listWidget_2->count()-2));
}

void MainWindow::ectfullCalibration()
{
    if(usb.isopened()&&!needstop){
         //prepare files
        QDateTime datetime = QDateTime::currentDateTime();//txt
        QString dt = datetime.toString("yyyy-MM-dd-HH：mm：ss");
        QDir::setCurrent(savedirectory);
        QFile *txtfullfile = new QFile("ECT_" + dt + "_full.txt");
        txtfullfile->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
        QTextStream txtstreamfull(txtfullfile);

        QByteArray TxBuffer;//
        TxBuffer.clear();
        QDataStream in(&TxBuffer, QIODevice::ReadWrite);
        DWORD BytesReceived;//end
        in << (quint8)0x88;
        if (usb.Write(TxBuffer.data(), 1, &BytesReceived) == FT_OK&&BytesReceived == 1)
            ui->listWidget_2->addItem("fullcalibration写入");
        usb.SetTimeouts(5000, 1000);// Set read timeout of 5sec, write timeout of 1sec

        const int bfl=4096;
        unsigned char rxbuffer[bfl+1];
        if (usb.Read(rxbuffer, bfl, &BytesReceived) == FT_OK&&BytesReceived == bfl){
            TxBuffer.clear();
            in << (quint8)0x77;
            usb.Write(TxBuffer.data(), 1, &BytesReceived);

            ect->setfullcalibration(rxbuffer);
            argfordraw full1circle;
            float fullcircle[120];
            full1circle.maxtransfer=ect->datavoid.data()[0];
            full1circle.mintransfer=full1circle.maxtransfer;
            for(int i=0;i<ect->datafull.count();i++)
            {
                txtstreamfull<<ect->datafull.at(i)<<endl;
                full1circle.tran.append(ect->datafull.at(i));
                fullcircle[i]=full1circle.tran.last();
                if(full1circle.tran.last()>full1circle.maxtransfer)
                    full1circle.maxtransfer=full1circle.tran.last();
                if(full1circle.tran.last()<full1circle.mintransfer)
                    full1circle.mintransfer=full1circle.tran.last();
            }
            showwid->paintusbect_2->updateonencirclepoints(fullcircle,full1circle.maxtransfer,full1circle.mintransfer);

            txtfullfile->close();

            ui->listWidget_2->addItem("fullcalibration ok");
        }
        else
            ui->listWidget_2->addItem("fullcalibration faild");
    }
    else
        ui->listWidget_2->addItem("open usb first for full calibration or running");
    ui->listWidget_2->scrollToBottom();
    emit ui->listWidget_2->currentItemChanged(ui->listWidget_2->item(ui->listWidget_2->count()-1)
                                              ,ui->listWidget_2->item(ui->listWidget_2->count()-2));
}


///
/// \brief MainWindow::creating...............
///
void MainWindow::createToolBars()
{
    toolmode=addToolBar("mode");
    toolmode->addAction(ECT_action);
    toolmode->addAction(tdlas_action);

    toolusb=addToolBar("usb");
    toolusb->addAction(openusb_action);
    toolusb->addAction(closeusb_action);


    tooldataacquisition=addToolBar("data_acquisition");
    tooldataacquisition->addAction(dataacquisition_action);
    tooldataacquisition->addAction(startdataacquisition_action);
    tooldataacquisition->addAction(stopdataacquisition_action);

    toolreconstruction=addToolBar("reconstruction");
    toolreconstruction->addAction(reconstruct_action);
    //insert here

}

void MainWindow::createaction()
{
    openusb_action= new QAction(QIcon(":/new/prefix1/images/usb1.png"),"openusb",this);
    connect(openusb_action,SIGNAL(triggered()),this,SLOT(openusb()));

    closeusb_action=new QAction(QIcon(":/new/prefix1/images/lan-break.png"),"closeusb",this);
    connect(closeusb_action,SIGNAL(triggered()),this,SLOT(closeusb()));

    tdlas_action=new QAction("tdlas",this);
    connect(tdlas_action,SIGNAL(triggered()),this,SLOT(tdlas()));
    tdlas_action->setCheckable(true);

    ECT_action= new QAction("ECT",this);
    connect(ECT_action,SIGNAL(triggered()),this,SLOT(Ect()));
    ECT_action->setCheckable(true);

    dataacquisition_action=new QAction(QIcon(":/new/prefix1/images/directory.png"),"Dir of data acquisition",this);
    connect(dataacquisition_action,SIGNAL(triggered()),this,SLOT(dataacquisition()));

    stopdataacquisition_action= new QAction(QIcon(":/new/prefix1/images/stop.png"),"stop",this);
    connect(stopdataacquisition_action,SIGNAL(triggered()),this,SLOT(stopdataacquisition()));

    startdataacquisition_action= new QAction(QIcon(":/new/prefix1/images/start.png"),"start",this);
    connect(startdataacquisition_action,SIGNAL(triggered()),this,SLOT(startdataacquisition()));

    reconstruct_action=new QAction("reconstruct",this);
    connect(reconstruct_action,SIGNAL(triggered()),SLOT(reconstruct()));

    LBP=new QAction("LBP",this);

    caldelong=new QAction("caldelong",this);
}

void MainWindow::createmenus()//insert codes
{
    ui->menu->addAction(tdlas_action);
    ui->menu->addAction(ECT_action);
    ui->menu->addAction(openusb_action);

    menualgorithm=new QMenu("algorithm");
    ui->menureconstruct->addMenu(menualgorithm);
    ui->menureconstruct->addAction(reconstruct_action);
    menualgorithm->addAction(LBP);
    menualgorithm->addAction(caldelong);
}

void MainWindow::createdockwidget()
{
   if(mode::m_mode==mode::ECT)
       createectWidget();

    statusdock=new QDockWidget(tr("status"),this);
    statuscontent=new mystatuscontent;
    statuslayout=new QGridLayout(statuscontent);
    connect(ui->listWidget_2,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
            this,SLOT(changelistitemcolor(QListWidgetItem*,QListWidgetItem*)));
    ui->listWidget_2->setAutoScroll(true);
    statuscontent->setPalette(QPalette(QColor(199,237,204)));
    statuscontent->setAutoFillBackground(true);
    statuslayout->addWidget(ui->listWidget_2);

    statusdock->setWidget(statuscontent);

    addDockWidget(Qt::BottomDockWidgetArea,statusdock);

}

void MainWindow::createtdlasview()
{

}

void MainWindow::createtdlasWidget()
{

}

void MainWindow::createectview()
{
    if(!showwid->paintusbect->isVisible()){
        showwid->paintusbect->setVisible(true);
     }

}

void MainWindow::createectWidget()
{
    ectdock=new QDockWidget(tr("ECT"),this);
    ectdockcontent=new QWidget;
    ectdockcontent->setPalette(QPalette(Qt::white));
    ectdockcontent->setAutoFillBackground(true);
    ectdocklayout=new QGridLayout(ectdockcontent);
    ectdocklayout->setContentsMargins(0,0,0,0);
    electrode_numberbox=new QComboBox;
    QStringList list;
    list<<"16"<<"12"<<"8";
    electrode_numberbox->addItems(list);
    connect(electrode_numberbox,SIGNAL(activated(QString)),this,SLOT(setelectrodenum(QString)));
    electrode_numberlabel=new QLabel("electrode_number");
    ectdocklayout->addWidget(electrode_numberlabel,0,0);
    ectdocklayout->addWidget(electrode_numberbox,0,1);

    chosedifference=new QLabel("measurement data");
    chosedifferencebox=new QComboBox;
    list.clear();
    list<<"origin"<<"difference";
    chosedifferencebox->addItems(list);
    connect(chosedifferencebox,SIGNAL(activated(QString)),this,SLOT(setectdifference(QString)));
    ectdocklayout->addWidget(chosedifference,1,0);
    ectdocklayout->addWidget(chosedifferencebox,1,1);

    voidbutton = new QPushButton(tr("void"),ectdockcontent);
    connect(voidbutton, SIGNAL(clicked()), this, SLOT(ectvoidCalibration()));
    fullbutton = new QPushButton(tr("full"),ectdockcontent);
    connect(fullbutton, SIGNAL(clicked()), this, SLOT(ectfullCalibration()));
    ectdocklayout->addWidget(voidbutton,2,0);
    ectdocklayout->addWidget(fullbutton,2,1);


    ectdock->setWidget(ectdockcontent);
    ectdock->layout()->setSizeConstraint(QLayout::SetDefaultConstraint);
    addDockWidget(Qt::RightDockWidgetArea,ectdock);
}

void MainWindow::changelistitemcolor(QListWidgetItem *current, QListWidgetItem *previous)
{
    //current->setBackgroundColor(QColor(199,237,205));
    if(previous!=NULL){
        previous->setBackgroundColor(QColor(199,237,205));
        if(ui->listWidget_2->count()-3>0)ui->listWidget_2->item(ui->listWidget_2->count()-3)->setBackgroundColor(QColor(199,237,205));

    }
}


