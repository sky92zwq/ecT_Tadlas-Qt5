#include "myshowwidget.h"




showwidget::showwidget(QWidget *parent)
{
	mainlayout = new QGridLayout(this);

    mainshowlayout=new QVBoxLayout(NULL);
    ECTpaintframe=new QFrame;
    ECTpaintframe_2=new QFrame;
    paintusbect=new myPaintusb(NULL,4096);
	paintusbect_2=new myPaintusb(NULL,4096);
    mainshowlayout->addWidget(paintusbect_2);
    mainshowlayout->addWidget(paintusbect);

//	openglwid = new myOpenGLwid();
//    QSurfaceFormat format;
//    format.setDepthBufferSize(24);
//    format.setStencilBufferSize(8);
//    format.setVersion(1, 1);
//    format.setProfile(QSurfaceFormat::CoreProfile);
//    openglwid->setFormat(format); // must be called before the widget or its parent window gets shown
    openglwid = new GLWidget;



    mainlayout->addWidget(openglwid,0,0);
	mainlayout->addLayout(mainshowlayout, 0, 1);


}

showwidget::~showwidget()
{
    delete paintusbect_2;
    delete paintusbect;
    delete ECTpaintframe;
    delete ECTpaintframe_2;
    delete openglwid;

    delete mainshowlayout;
	delete mainlayout;
}




