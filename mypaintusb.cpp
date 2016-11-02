#include "mypaintusb.h"

myPaintusb::myPaintusb(QWidget *parent, int datalong) : QWidget(parent)
{
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);
//    setMinimumSize(1000,200);
    pen.setColor(QColor(255,0,0));  //设置画笔为红色
    points=(QPointF*)malloc(sizeof(QPointF)*datalong);

    ect=ECTClass::getInstance();

    onecircletimes=0;
    maxtext=0;
    showlong=0;

}

myPaintusb::~myPaintusb()
{
    free(points);
}

void myPaintusb::paintEvent(QPaintEvent *)
{
    QPainter painter(this);


    painter.setPen(pen);  //选择画笔
    //painter.setRenderHint(QPainter::Antialiasing, true);//反走样
    painter.drawPolyline(points,showlong);
    QString str;
    str.setNum(maxtext);
    painter.drawText(0,this->height()/2,str);
    painter.end(); //结束绘制。绘制时使用的任何资源都被释放。虽然有时不需要调用end()，析构函数将会执行它

}

void myPaintusb::setpoints(QVector<float> &vec,float max,float min)
{

    double maxmingap;
    if (max == min) min=0;
    maxmingap=max-min;
    showlong=vec.count();
    maxtext=max;
    mintext=min;
    showgap=(double)this->width()/showlong;


    for(int i=0;i<showlong;i++){
        (points+i)->setX(showgap*i);
        (points+i)->setY((double)(this->size().height()-10)*(1-(vec.at(i)-min)/(maxmingap)));


    }

    update();
}


