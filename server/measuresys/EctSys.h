#pragma once
#include "MeasureSys.h"
#include "matlabhelper.h"

class EctSys :
    public MeasureSys
{
public:
    explicit EctSys( int bl, int n);
    ~EctSys();
public:
    void start_acq_command();
    void stop_acq_command();
    void beforeconstruct();
    void reconstruct();
private:
    MatlabHelper *matlabhelper;
    QThread *matlabthread;
};

