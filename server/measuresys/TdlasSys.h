#pragma once
#include "MeasureSys.h"
#include "Algorithm/tikhonov_alg.h"

class TdlasSys :
	public MeasureSys
{
public:
	TdlasSys( int bl, int n) ;
	~TdlasSys();
public:
	void start_acq_command();
	void stop_acq_command();
	void beforeconstruct();
	void reconstruct();
private:
	Tikhonov_Alg *tik_worker;
	QThread *openglThread;
};

