#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tdlasdialog.h"
#include <QDebug>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),needstop(false),reconstructflag(false),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ECTClass::getInstance()->setelectrode_number(16);

    createaction();
    createmenus();      //菜单栏
    createToolBars();   //工具栏
    createdockwidget(); //停靠部件

    datafile = NULL;
    savedirectory = "./";

    showwid = new showwidget;
    setCentralWidget(showwid);

    if (mode::m_mode == mode::ECT)
        Ect();
    if (mode::m_mode == mode::TDlas)
        tdlas();
    //    stopdataacquisition_action->setEnabled(false);

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


void MainWindow::resizeEvent(QResizeEvent *event)
{

//    QApplication::postEvent(showwid->paintusbect, new QEvent(QEvent::Resize));
//    QApplication::postEvent(showwid->paintusbect_2, new QEvent(QEvent::Resize));
}



void MainWindow::openusb()//closeusb action
{
}

void MainWindow::closeusb()//closeusb action
{
}

void MainWindow::tdlas()
{
    mode::m_mode=mode::TDlas;
    ectdock->setVisible(false);

    tdlas_action->setChecked(true);
    ECT_action->setChecked(false);

    createtdlasview();

    tdlasDialog tdlasdl;
    tdlasdl.exec();
}

void MainWindow::Ect()
{
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

}

void MainWindow::stopdataacquisition()//停止数据采集 action
{
}

void MainWindow::startdataacquisition()//开始采集
{
}

void MainWindow::reconstruct()
{

}

void MainWindow::drawTDlasusbdata()
{

}

void MainWindow::childrenWidstatus(QString &str)//查看 子窗口 状态
{
    ui->listWidget_2->addItem(str);
    ui->listWidget_2->scrollToBottom();
}

void MainWindow::setelectrodenum(const QString &text)
{
    ECTClass::getInstance()->setelectrode_number((quint8)text.toInt());
    qDebug()<<ECTClass::getInstance()->measurenumber();
}

void MainWindow::setectdifference(const QString &differ)
{
    if(differ==QString("difference")&&ECTClass::getInstance()->alreadyVoidcalibtrated())ECTClass::getInstance()->differencemode=true;
    else if(differ==QString("difference")){
        ui->listWidget_2->addItem("void calibration first");
        chosedifferencebox->setCurrentText("origin");
    }
    else {
        ECTClass::getInstance()->differencemode=false;
        chosedifferencebox->setCurrentText("origin");
    }
    qDebug()<<ECTClass::getInstance()->differencemode;
}
void MainWindow::ectvoidCalibration()
{
}

void MainWindow::ectfullCalibration()
{
}


void MainWindow::changelistitemcolor(QListWidgetItem *current, QListWidgetItem *previous)
{
    //current->setBackgroundColor(QColor(199,237,205));
    if(previous!=NULL){
        previous->setBackgroundColor(QColor(199,237,205));
        if(ui->listWidget_2->count()-3>0)ui->listWidget_2->item(ui->listWidget_2->count()-3)->setBackgroundColor(QColor(199,237,205));

    }
}


