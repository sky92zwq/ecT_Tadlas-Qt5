#include "ectclass.h"


void ECTClass::setelectrode_number(quint8 num)
{
    electrode_number=num;
    measuregapnumber=electrode_number*(electrode_number-1)/2;
}

quint8 ECTClass::iselectrode_number()
{
    return electrode_number;
}

quint16 ECTClass::indicator()
{
    return 0;
}

quint16 ECTClass::measurenumber()
{
    return measuregapnumber;//由电极数决定的每组数据数
}
