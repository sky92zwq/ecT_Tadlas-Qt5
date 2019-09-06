#include "MeasureSys.h"




MeasureSys::MeasureSys(CS_ftfunction * u, int bl, int n):bufferlong(bl),usb(u),N(n)
{
}

MeasureSys::~MeasureSys()
{
}

void MeasureSys::beforeconstruct(int N)
{
	emit reconstructN(N);
}

