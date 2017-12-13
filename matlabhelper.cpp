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
    rwobj.readtxt(tdlas_L,"./Lb/L.txt");
    rwobj.readtxt(tdlas_b,"./Lb/b.txt");

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

void MatlabHelper::graytoRGB(double *R, double *G, double *B, double *f,double maxf)
{
        //red
    double val=f[0]/maxf*255;
        if (val<128)
        {
            R[0] = 0;
        }
        else if (val<192)
        {
            R[0] = 255/64*(val-128);
        }
        else
        {
            R[0]=255;
        }

        //green
        if (val<64)
        {
            G[0] = 255/64*val;
        }
        else if (val<192)
        {
            G[0] = 255;
        }
        else
        {
            G[0]= -255/63*(val - 192)+255;
        }

        //blue
        if (val<64)
        {
            B[0] = 255;
        }
        else if (val<128)
        {
            B[0] = -255/63*(val - 192)+255;
        }
        else
        {
            B[0]=0;
        }
  R[0]=R[0]/255;
  G[0]=G[0]/255;
  B[0]=B[0]/255;
}

double MatlabHelper::maxf(double *f, int len)
{
    double max=0;
    for(int i=0;i<len;i++)
    {
        if(f[i]>max)
        {
            max=f[i];
        }
    }
    return max;
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
    Tikhonov(tdlas_L,tdlas_b,tdlas_k,tdlas_x0,tdlas_f);
        qDebug()<<time.elapsed()/1000.0;
        qDebug()<<R_temp[0]<<G_temp[0]<<B_temp[0];
        double max=maxf(tdlas_f,sizeof(tdlas_f)/sizeof(tdlas_f[0]));
        for(int i=0;i<400;i++)
        {
            graytoRGB(tdlas_R_temp+i,tdlas_G_temp+i,tdlas_B_temp+i,tdlas_f+i,max);
        }
    rwobj.writetxt(tdlas_f,tdlas_fsize,"./f0710.txt");
    emit sigreconstructRGB(tdlas_R_temp,tdlas_G_temp,tdlas_B_temp);
}
