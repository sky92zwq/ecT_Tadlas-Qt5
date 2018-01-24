#include "TdlasSys.h"



TdlasSys::TdlasSys(CS_ftfunction *u, int bl, int n) :MeasureSys::MeasureSys(u, bl, n)
{
	name = "TDLAS";

}


TdlasSys::~TdlasSys()
{
}

void TdlasSys::start_acq_command()
{
	TxBuffer.clear();
	QDataStream in(&TxBuffer, QIODevice::ReadWrite);
	in << (quint16)0x8800 << (quint16)4096;
}

void TdlasSys::stop_acq_command()
{
}

void TdlasSys::beforeconstruct()
{
	openglThread = new QThread;
	tik_worker = new Tikhonov_Alg("laplacian");
	tik_worker->moveToThread(openglThread);
}

void TdlasSys::reconstruct()
{


	tik_worker->Tikhonov();
	tik_worker->land_worker.set_RGB();
	emit reconstructedRGB(tik_worker->land_worker.R.data(),tik_worker->land_worker.G.data(),tik_worker->land_worker.B.data());

}
