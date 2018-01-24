#include "EctSys.h"


EctSys::EctSys(CS_ftfunction *u=nullptr, int bl=4096, int n=48)
	:MeasureSys::MeasureSys(u,bl,n)
{
	name = "ECT";
}


EctSys::~EctSys()
{
}

void EctSys::start_acq_command()
{
	TxBuffer.clear();
	QDataStream in(&TxBuffer, QIODevice::ReadWrite);
	in << (quint8)0x88;

}
void EctSys::stop_acq_command()
{
	TxBuffer.clear();
	QDataStream in(&TxBuffer,QIODevice::ReadWrite);
	in << (quint8)0x77;

}

void EctSys::beforeconstruct()
{
	matlabthread = new QThread;
	matlabhelper = new MatlabHelper;
	matlabhelper->moveToThread(matlabthread);
	
	connect(this, &MeasureSys::sigOneFrame,matlabhelper, &MatlabHelper::process1cirledata);
	connect(matlabhelper, &MatlabHelper::sigreconstructRGB, this, &MeasureSys::reconstructedRGB);


	connect(matlabthread, &QThread::finished, matlabhelper, &QObject::deleteLater);
	connect(matlabthread, &QThread::finished, matlabthread, &QObject::deleteLater);

}



void EctSys::reconstruct()
{


	matlabthread->start();


	
}
