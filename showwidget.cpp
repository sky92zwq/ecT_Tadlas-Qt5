#include "showwidget.h"


showwidget::showwidget(QWidget *parent)
{
    mainshowlayout=new QVBoxLayout(this);
    ECTpaintframe=new QFrame;
    ECTpaintframe_2=new QFrame;
    mainshowlayout->addWidget(ECTpaintframe_2);
    mainshowlayout->addWidget(ECTpaintframe);
    paintusbect=new myPaintusb(ECTpaintframe);

    paintusbect_2=new myPaintusb(ECTpaintframe_2);


}

showwidget::~showwidget()
{
    delete paintusbect_2;
    delete paintusbect;
    delete ECTpaintframe;
    delete ECTpaintframe_2;

    delete mainshowlayout;
}
