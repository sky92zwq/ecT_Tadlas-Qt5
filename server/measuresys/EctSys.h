#pragma once
#include "MeasureSys.h"
#include "matlabhelper.h"

class EctSys :
	public MeasureSys
{
public:
	explicit EctSys(CS_ftfunction *u, int bl, int n);
	~EctSys();
public:
	void start_acq_command();
	void stop_acq_command();
	void EctSys::beforeconstruct();
	void reconstruct();
private:
	MatlabHelper *matlabhelper;
	QThread *matlabthread;
};

