#include "mypaintusb.h"

myPaintusb::myPaintusb(QWidget *parent) : QWidget(parent)
{
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);
    setMinimumSize(400,300);

}

void myPaintusb::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

   if(l==300)l=0;
    pen.setColor(QColor(255,0,0));  //设置画笔为红色
    painter.setPen(pen);  //选择画笔
    painter.drawLine(0,0,l,l); //用该红色画笔画一条线，起点(0,0)，终点(100,100)
    painter.end(); //结束绘制。绘制时使用的任何资源都被释放。虽然有时不需要调用end()，析构函数将会执行它
    l+=2;
}
