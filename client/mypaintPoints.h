#ifndef myPaintPoints_H
#define myPaintPoints_H

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QPoint>
#include "cbb/ectclass.h"
#include <qtimer.h>

class myPaintPoints : public QWidget
{
    Q_OBJECT
public:
    explicit myPaintPoints(QWidget *parent=0,int datalong=4096);
    ~myPaintPoints();

    void paintEvent(QPaintEvent *);
    void setpoints(QVector<float> &vec, float max, float min);
    void setonecirclepoints(float *vec, float max, float min);
signals:


public:
    QPen pen;
    QBrush brush;
    QPointF *points;

    int showlong;
    int onecircletimes;
    float maxtext,mintext;
    float showgap;
    float halfheight;
};

#endif // myPaintPoints_H
