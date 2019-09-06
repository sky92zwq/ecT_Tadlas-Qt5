#pragma once
#include "MeasureSys.h"
#include "Algorithm/tikhonov_alg.h"

class TdlasSys :
	public MeasureSys
{
public:
	TdlasSys(CS_ftfunction *u, int bl, int n) ;
	~TdlasSys();
public:
	void TdlasSys::start_acq_command();
	void TdlasSys::stop_acq_command();
	void TdlasSys::beforeconstruct();
	void TdlasSys::reconstruct();
private:
	Tikhonov_Alg *tik_worker;
	QThread *openglThread;
};

