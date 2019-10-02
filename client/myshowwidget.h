#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H
#include <QtCore>
#include <QVBoxLayout>
#include <QFrame>
#include "myPaintPoints.h"
#include "glwidget.h"

///
/// \brief The showwidget class
///
class showwidget : public QWidget
{
    Q_OBJECT
public:
    explicit showwidget(QWidget *parent = 0);
    ~showwidget();


public:
    QVBoxLayout *mainshowlayout;
    QGridLayout *mainlayout;

    QFrame *ECTpaintframe;
    QFrame *ECTpaintframe_2;
    myPaintPoints *paintusbect;
    myPaintPoints *paintusbect_2;

    GLWidget * openglwid;

};

#endif // SHOWWIDGET_H
