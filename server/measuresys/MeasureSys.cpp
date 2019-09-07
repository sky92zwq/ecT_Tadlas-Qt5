#include "MeasureSys.h"




MeasureSys::MeasureSys( int bl, int n):bufferlong(bl),N(n)
{
}

MeasureSys::~MeasureSys()
{
}

void MeasureSys::beforeconstruct(int N)
{
    emit reconstructN(N);
}

