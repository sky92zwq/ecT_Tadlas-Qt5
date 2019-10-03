#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QFrame>
#include <QFile>
#include <QPainter>
#include <qopengl.h>
#include <QOpenGLWidget>
#include <qlayout.h>
#include <qtoolbar.h>
#include <qdockwidget.h>
#include <qfiledialog.h>
#include <qdatetime.h>
#include <qthread.h>
#include <qmath.h>
#include <qmutex.h>
#include <qcombobox.h>
#include <qlabel.h>
#include <QPushButton>
#include <QListWidgetItem>

#include "tdlasdialog.h"
#include "myPaintPoints.h"
#include "cbb/ectclass.h"
#include "cbb/mode.h"
#include "cbb/Command.h"
#include <myshowwidget.h>
#include "myTCPClient.h"


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
protected slots:
    void openusb();

    void closeusb();

    void tdlas();

    void Ect();

    void dataacquisition();

    void stopdataacquisition();

    void startdataacquisition();

    void reconstruct();

    void drawTDlasusbdata();


    private slots:
    void acquisitioncount() { ; }


    void childrenWidstatus(QString &str);//看子窗口

    void setelectrodenum(const QString &text);
    void setectdifference(const QString &differ);
    void ectvoidCalibration();
    void ectfullCalibration();
signals:

    void startacquisition( QString savedirectory);
    void stopacquisition1(bool);
    void stopacquisition2(bool);
signals:
    void transmitusb();

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
    QString savedirectory, currentdirectory;
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
    public slots:
    void changelistitemcolor(QListWidgetItem *current, QListWidgetItem *previous);
private:
    QDockWidget *statusdock;
    class mystatuscontent :public QWidget
    {
    public:
        QSize sizeHint() const
        {
            return QSize(900, 100); /* 在这里定义dock的初始大小 */
        }

    };
    mystatuscontent*statuscontent;
    QGridLayout *statuslayout;
    QWidget     *ectdockcontent;
    QDockWidget *ectdock;
    QGridLayout *ectdocklayout;
    QComboBox   *electrode_numberbox;
    QLabel      *electrode_numberlabel;
    QPushButton *voidbutton, *fullbutton;
    QLabel      *chosedifference;
    QComboBox   *chosedifferencebox;



private:
    bool needstop;
    bool reconstructflag;
private:
    MyTcpClient Tcpclt;
    Invoker CommandInvoker;
};




#endif // MAINWINDOW_H
