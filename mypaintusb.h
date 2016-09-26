#ifndef MYPAINTUSB_H
#define MYPAINTUSB_H

#include <QWidget>
#include <QPen>
#include <QPainter>

class myPaintusb : public QWidget
{
    Q_OBJECT
public:
    explicit myPaintusb(QWidget *parent=0);
    void paintEvent(QPaintEvent *);

signals:

public slots:

private:
    QPen pen;
    QBrush brush;

    int l;
};

#endif // MYPAINTUSB_H
