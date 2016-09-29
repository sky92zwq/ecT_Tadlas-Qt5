#include "mypaintusb.h"

myPaintusb::myPaintusb(QWidget *parent) : QWidget(parent)
{
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);
    setMinimumSize(1000,200);
    onecircletimes=0;
    points=new QPointF[4096];
    onecirclepoints=new QPointF[4096];
    ect=ECTClass::getInstance();
}

myPaintusb::~myPaintusb()
{
    delete points;
    delete onecirclepoints;
}

void myPaintusb::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    pen.setColor(QColor(255,0,0));  //设置画笔为红色
    painter.setPen(pen);  //选择画笔
    //painter.setRenderHint(QPainter::Antialiasing, true);//反走样
    painter.drawPolyline(points,showlong);
//    for(;onecircletimes<showlong/ect->measurenumber();onecircletimes+=10){
        painter.drawPolyline(onecirclepoints+onecircletimes*ect->measurenumber(),ect->measurenumber());

//        this->update();
//    }
        QString str;
        str.setNum(maxtext);
        painter.drawText(0,this->height()/2-4,str);
    painter.end(); //结束绘制。绘制时使用的任何资源都被释放。虽然有时不需要调用end()，析构函数将会执行它
    onecircletimes=0;

}

void myPaintusb::setpoints(QVector<float> &vec,float max,float min)
{

    float maxmingap=max-min;
    showlong=vec.count();
    maxtext=max;
    mintext=min;

    for(int i=0;i<showlong;i++){
        (points+i)->setX((double)(this->size().width())/showlong*i);
        (points+i)->setY((double)(this->size().height()/2)*(vec.at(i)-min)/(maxmingap));
        (onecirclepoints+i)->setX((double)(this->size().width())/ect->measurenumber()*(i % ect->measurenumber()));
        (onecirclepoints+i)->setY((points+i)->y()+(double)this->size().height()/2);


    }

}

void myPaintusb::resizeEvent(QResizeEvent *)
{
    this->resize(parentWidget()->size());

}
