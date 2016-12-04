#include "matlabhelper.h"
#include <QDebug>

MatlabHelper::MatlabHelper(QObject *parent)
	: QObject(parent)
{
    ect=ECTClass::getInstance();
    voidsum=0;
    fullsum=0;
    //readsenMatrix();
    m_hold_up[0]=0;
	z = new double[ect->measurenumber()];
    ZeroMemory(R_temp,sizeof(R_temp));
    ZeroMemory(G_temp,sizeof(G_temp));
    ZeroMemory(B_temp,sizeof(B_temp));
    ZeroMemory(z,sizeof(z));

}

MatlabHelper::~MatlabHelper()
{
    delete z;

}

void MatlabHelper::readsenMatrix()
{
    QFile senfile("./matlab/Sen_matrix_16.txt");
    if (!senfile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream outsenfile(&senfile);
    outsenfile.skipWhiteSpace();
    for(int i=0;i<1716*120;i++) {
        outsenfile>>senmatrix_16[i];
    }
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
    
//    for(int i=0;i<ect->measurenumber();i++)
//    {
//        voidsum += (onearg->tran.at(i) - ect->datavoid.at(i));
////        fullsum += (onearg->tran.at(i) - ect->datafull.at(i));

//    }
//    if (voidsum < 0.05)
//            ZeroMemory(z,sizeof(z));
//    else if (fullsum < 0.05)
//        for(int i=0;i<ect->measurenumber();i++)z[i] = 1;
//    else
//        if (ect->alreadyFullcalibtrated())
//             for(int i=0;i<ect->measurenumber();i++)
//                 z[i] = (onearg->tran.at(i) - ect->datavoid.at(i))
//                  / (ect->datafull.at(i) - ect->datavoid.at(i));
//        else
//    fromthread=onearg->tran;
             for(int i=0;i<ect->measurenumber();i++)z[i] = onearg[i]-ect->datavoid.data()[i];
//	//matlab .lib
    time.start();
    calderon_circle_16_electrodes_ssjwq(z,4,R_temp,G_temp,B_temp);
    //(*usecalderon16)(z,4,R_temp,R_size,G_temp,G_size,B_temp,B_size);
    qDebug()<<time.elapsed()/1000.0;
    qDebug()<<R_temp[0]<<G_temp[0]<<B_temp[0];
    emit sigreconstructRGB(R_temp,G_temp,B_temp);
}
