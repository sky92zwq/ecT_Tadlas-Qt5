#ifndef MYPAINTUSB_H
#define MYPAINTUSB_H

#include <QWidget>
#include <QPen>
#include <QPainter>
#include <QPoint>
#include "ectclass.h"

class myPaintusb : public QWidget
{
    Q_OBJECT
public:
    explicit myPaintusb(QWidget *parent=0);
    ~myPaintusb();
    void paintEvent(QPaintEvent *);
    void setpoints(QVector<float> &vec, float max, float min);
    void resizeEvent(QResizeEvent *);

signals:

public slots:

private:
    QPen pen;
    QBrush brush;
    QPointF *points,*onecirclepoints;
    int showlong;

    int onecircletimes;
    float maxtext,mintext;
public:
    ECTClass *ect;
};

#endif // MYPAINTUSB_H
