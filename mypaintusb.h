#ifndef MYPAINTUSB_H
#define MYPAINTUSB_H

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QPoint>
#include "ectclass.h"
#include "mythreads.h"
#include <qtimer.h>

class myPaintusb : public QWidget
{
    Q_OBJECT
public:
    explicit myPaintusb(QWidget *parent=0,int datalong=4096);
    ~myPaintusb();

    void paintEvent(QPaintEvent *);
    void setpoints(QVector<float> &vec, float max, float min);
    void setonecirclepoints(float *vec, float max, float min);
signals:

public slots:
    void updatepoints(argfordraw *arg);
    void updateonencirclepoints(float *v, float max, float min);

public:
    QPen pen;
    QBrush brush;
    QPointF *points;

    int showlong;
    int onecircletimes;
    float maxtext,mintext;
    float showgap;
    float halfheight;
public:
    ECTClass *ect;
};

#endif // MYPAINTUSB_H
