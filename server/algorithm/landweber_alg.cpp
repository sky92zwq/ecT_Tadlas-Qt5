#include "landweber_alg.h"
#include "cbb/rwhelper.h"

landweber_Alg::landweber_Alg():newL(L),newb(b)
{
	set_lamda();
}

void landweber_Alg::landweber(const SparseMatrix<double> &theL, const VectorXd &theb, int K, VectorXd &x)
{
	VectorXd rxk = theb - theL*x;

	for (int k = 0; k < K; k++)
	{
		x = x + lamda*(theL.transpose()*rxk);
		for (int i=0;i<x.size();i++)
		{
			if (x[i] < 0.0)x[i] = 0.0;
		}
		rxk = theb - theL*x;

	}
	
}

void landweber_Alg::landweber()
{
	VectorXd rxk = newb - newL*x;
	RWhelper<double> rw_worker;
	int fsize[2] = { 20,20 };
	for (int k = 0; k < K; k++)
	{
		x = x + lamda*(newL.transpose()*rxk);
		for (int i = 0; i<x.size(); i++)
		{
			if (x[i] < 0.0)x[i] = 0.0;
		}
		//if(k%2==0)rw_worker.writetxt(x.data(), fsize, QString("./Lb/recb1202")+QString::number(k,10)+".txt");
		rxk = newb - newL*x;

	}
	
}

void landweber_Alg::set_newL(const SparseMatrix<double>& theL)
{
	newL = theL;
	set_lamda();//L change then lamda change
}

void landweber_Alg::set_newb(const VectorXd & theb)
{
	newb = theb;
}


