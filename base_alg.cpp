#include "base_alg.h"
#include "rwhelper.h"
#include <iostream>

base_Alg::base_Alg(QObject *parent ):K(1000),N(20)
{
    initial_others();
}

void base_Alg::initial_others()
{
    read_L("./Lb/L.txt");//..
    read_b("./Lb/b.txt");//..
    //set_K(1000);
    set_x();
	R.resizeLike(x);
	G.resizeLike(x);
	B.resizeLike(x);
}

void base_Alg::read_L(QString dir)
{
	RWhelper<double> rw_worker;
	double *ll = new double[num_detec* N*N];
	rw_worker.readtxt(ll,dir);
	Map<MatrixXd> mat(ll, num_detec, N*N);
	L = mat.sparseView();
}

void base_Alg::read_b(QString dir)
{
	RWhelper<double> rw_worker;
	double *bb = new double[num_detec];
	rw_worker.readtxt(bb, dir);
	b=Map<VectorXd> (bb, num_detec);
}

void base_Alg::read_b(double *db)
{
	b = Map<VectorXd>(db, num_detec);
}

void base_Alg::set_K(int k)
{
    K=k;
}

void base_Alg::set_x()
{
	this->x.setZero(N*N);
}

void base_Alg::set_RGB()
{
	double val;
	double max = x.maxCoeff();
	for (int i = 0; i < x.size(); i++)
	{
		val = x[i] /  max* 255;
		//red
		if (val<128)
		{
			R[i] = 0;
		}
		else if (val<192)
		{
			R[i] = 255 / 64 * (val - 128);
		}
		else
		{
			R[i] = 255;
		}

		//green
		if (val<64)
		{
			G[i] = 255 / 64 * val;
		}
		else if (val<192)
		{
			G[i] = 255;
		}
		else
		{
			G[i] = -255 / 63 * (val - 192) + 255;
		}

		//blue
		if (val<64)
		{
			B[i] = 255;
		}
		else if (val<128)
		{
			B[i] = -255 / 63 * (val - 192) + 255;
		}
		else
		{
			B[i] = 0;
		}
		R[i] = R[i] / 255;
		G[i] = G[i] / 255;
		B[i] = B[i] / 255;
	}
}


