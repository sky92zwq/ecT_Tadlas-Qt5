#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cs_ftfunction.h"
#include "tdlasdialog.h"
#include <qdockwidget.h>
#include <qtoolbar.h>
#include <QFile>
#include <qfiledialog.h>
#include <qdatetime.h>
#include <qthread.h>
#include <qmutex.h>
#include <qmath.h>
#include "mythreads.h"
#include <QPainter>
#include "mypaintusb.h"
#include <qlayout.h>
#include <QVBoxLayout>
#include <QFrame>
#include <qopengl.h>
#include <QOpenGLWidget>
#include "ectclass.h"
#include <qcombobox.h>
#include <qlabel.h>
#include <myshowwidget.h>


namespace Ui {
class MainWindow;
}


/// \brief The MainWindow class
///
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void resizeEvent(QResizeEvent *event);
public:
    CS_ftfunction usb;

    ECTClass *ect;



protected slots:
    void openusb();

    void closeusb();

    void tdlas();

    void Ect();

    void dataacquisition();

    void stopdataacquisition();

    void startdataacquisition();

    void reconstruct();

    void drawECTusbdata(argfordraw *arg);

    void drawECTonecircledata(argfordraw *arg);

    void drawTDlasusbdata(argfordraw *arg);

    void setrwthread1null();

    void setrwthread2null();

    void deletemylock();
private slots:
    void acquisitioncount(){;}

    void threadstatus(double st);//看看子线程的状态

    void childrenWidstatus(QString &str);//看子窗口

    void setelectrodenum(const QString &text);
signals:

    void startacquisition(CS_ftfunction &usb,QString savedirectory);
    void stopacquisition1(bool);
    void stopacquisition2(bool);
signals:
    void transmitusb(CS_ftfunction *);

private:
    void createToolBars();

    void createaction();

    void createmenus();

    void createdockwidget();

    void createtdlasview();

    void createtdlasWidget();

    void createectview();

    void createectWidget();
private:
    Ui::MainWindow *ui;

    QDateTime datetime;
    QFile *datafile;
    QFile *txtfile;
    QString savedirectory,currentdirectory;
private:
    QMenu *menualgorithm;

    QToolBar *toolmode;
    QToolBar *toolusb;
    QToolBar *tooldataacquisition;
    QToolBar *toolreconstruction;

    QAction *openusb_action;
    QAction *closeusb_action;
    QAction *tdlas_action;
    QAction *ECT_action;
    QAction *dataacquisition_action;
    QAction *stopdataacquisition_action;
    QAction *startdataacquisition_action;
    //QAction *drawdata_action;
    QAction *reconstruct_action;
    QAction *LBP;
    QAction *caldelong;

    showwidget *showwid;

private:
    QDockWidget *statusdock;
    QWidget *ectdockcontent;
    QDockWidget *ectdock;
    QGridLayout *ectdocklayout;
    QComboBox *electrode_numberbox;
    QLabel *electrode_numberlabel;


public:
    QMutex *lockthread;
    RWThread *rwthread1;
    RWThread *rwthread2;
    processThreadobj *processthreadobj;
    processThread *processthread;

    QByteArray RWbyte;
public:
    enum ET{
        ECT,
        TDlas
    };
    ET mode;
private:
    bool needstop;

};




#endif // MAINWINDOW_H
