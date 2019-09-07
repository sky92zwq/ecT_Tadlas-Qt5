#pragma once
#include <qbytearray.h>
#include <qdatastream.h>
#include "qthread.h"
#include <QObject>

class MeasureSys :public QObject
{
    Q_OBJECT
public:
    explicit MeasureSys( int bl, int n);
    ~MeasureSys();
public://methods
    virtual void start_acq_command() = 0;
    virtual void stop_acq_command() = 0;
    virtual void beforeconstruct() = 0;
    virtual void beforeconstruct(int N);
    virtual void reconstruct() = 0;
public://var
    int bufferlong;
    int N;
    QByteArray TxBuffer;//–¥»Î√¸¡Ó”√
    QString name;

signals:
    void reconstructN(int N);
signals:
    void reconstructedRGB(double*R, double*G, double*B);
signals:
    void sigOneFrame(float *);
};

