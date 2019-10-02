#include "ectclass.h"

ECTClass::ECTClass()
{
    //do nothing
}

void ECTClass::setelectrode_number(quint8 num)
{
    electrode_number=num;
    measuregapnumber=electrode_number*(electrode_number-1)/2;
}

quint8 ECTClass::iselectrode_number()
{
    return electrode_number;
}

float ECTClass::indicator()
{
    return 0;
}

quint16 ECTClass::measurenumber()
{
    return measuregapnumber;//由电极数决定的每组数据数
}

void ECTClass::setvoidcalibration(unsigned char *rxbuffer)
{
    voidcalibrated=true;
    int i=0;
    double transfer;
    const int bufferlong=4096;
    for(;i<bufferlong;){
        transfer=calculatebuffer(rxbuffer,i);
        i+=2;
        if(transfer==indicator())break;
    }

    for(;i<bufferlong;){
        transfer=calculatebuffer(rxbuffer,i);
        datavoid.append(transfer);
        i+=2;
        if(transfer==indicator())break;
    }

}

void ECTClass::setfullcalibration(unsigned char *rxbuffer)
{
    fullcalibrated=true;
    int i=0;
    float transfer;
    const int bufferlong=4096;
    for(;i<bufferlong;){
        transfer=calculatebuffer(rxbuffer,i);
        i+=2;
        if(transfer==indicator())break;
    }

    for(;i<bufferlong;){
        transfer=calculatebuffer(rxbuffer,i);
        datafull.append(transfer);
        i+=2;
        if(transfer==indicator())break;
    }

}

bool ECTClass::alreadyVoidcalibtrated()
{
    return voidcalibrated;
}

bool ECTClass::alreadyFullcalibtrated()
{
    return fullcalibrated;

}
