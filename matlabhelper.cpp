#include "matlabhelper.h"
#include <QDebug>

MatlabHelper::MatlabHelper(QObject *parent)
	: QObject(parent)
{
    //initialize ECT
    ect=ECTClass::getInstance();
    voidsum=0;
    fullsum=0;
    m_hold_up[0]=0;
	z = new double[ect->measurenumber()];

    //initialize TDLAS
    rwobj.readtxt(tdlas_L,"./L.txt");
    rwobj.readtxt(tdlas_b,"./b.txt");

    ZeroMemory(R_temp,sizeof(R_temp));
    ZeroMemory(G_temp,sizeof(G_temp));
    ZeroMemory(B_temp,sizeof(B_temp));
    ZeroMemory(z,sizeof(z));

}

MatlabHelper::~MatlabHelper()
{
    delete z;

}



void MatlabHelper::adddynamiclinklib()
{
    calderon16lib.setFileName("calderon_circle_16_electrodes_ssj.dll");
    if(!calderon16lib.load())qDebug()<<"matlab load fail";
    usecalderon16=(MatlabHelper::calderon16)calderon16lib.resolve("calderon_circle_16_electrodes_ssj");
    if(usecalderon16==NULL)qDebug()<<"calderon 16 link failed";

}



void MatlabHelper::process1cirledata(float *onearg)
{
    

//    for(int i=0;i<ect->measurenumber();i++)z[i] = onearg[i]-ect->datavoid.data()[i];
////	//matlab .lib
//    time.start();
////    calderon_circle_16_electrodes_ssjwq(z,4,R_temp,G_temp,B_temp);
//    calderon_circle_16_electrodes_ssj(z,4,R_temp,R_size,G_temp,G_size,B_temp,B_size);
////    (*usecalderon16)(z,4,R_temp,R_size,G_temp,G_size,B_temp,B_size);
//    qDebug()<<time.elapsed()/1000.0;
//    qDebug()<<R_temp[0]<<G_temp[0]<<B_temp[0];
        time.start();
    Tikhonov(tdlas_L,tdlas_b,tdlas_k,tdlas_x0,tdlas_f,tdlas_fsize);
        qDebug()<<time.elapsed()/1000.0;
        qDebug()<<R_temp[0]<<G_temp[0]<<B_temp[0];
//    rwobj.writetxt(tdlas_f,tdlas_fsize,"./f0709.txt");
//    emit sigreconstructRGB(R_temp,G_temp,B_temp);
}
