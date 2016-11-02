#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H
#include <QtCore>
#include <QVBoxLayout>
#include <QFrame>
#include "mypaintusb.h"
#include "myopenglwid.h"

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
    myPaintusb *paintusbect;
    myPaintusb *paintusbect_2;

	myOpenGLwid *openglwid;

};

#endif // SHOWWIDGET_H
