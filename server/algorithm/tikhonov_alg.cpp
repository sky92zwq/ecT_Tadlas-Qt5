#include <iostream>
#include <vector>
#include "cbb/rwhelper.h"
#include "tikhonov_alg.h"


Tikhonov_Alg::Tikhonov_Alg(QString s) :already_init_filtter(false)
{
	laplacian = initial_laplacian();
	filtwindow = initial_filtwindow();
	initial_newL_lap();
	initial_newL_filt();

	filt = s;
	if (s == "laplacian")
		land_worker.set_newL(newL_lap.sparseView());
	else if (s == "filtwindow")
		land_worker.set_newL(newL_filt.sparseView());
	
}


void Tikhonov_Alg::initial_newL_lap()
{
	if (!already_init_filtter)
		std::cerr << "no filter";


	newL_lap = L;
	newL_lap.conservativeResize(L.rows() + N*N, N*N);
	newL_lap.middleRows(L.rows(), N*N) = laplacian;

	/*RWhelper<double> rw_worker;
	int fsize[2] = { 460*400,1 };
	rw_worker.writetxt(newL_lap.data(), fsize, "./Lb/newL_lap.txt");*/

}

void Tikhonov_Alg::initial_newL_filt()
{
	if (!already_init_filtter)
		std::cerr << "no filter";

	newL_filt = L;
	newL_filt.conservativeResize(L.rows() + N*N, N*N);
	newL_filt.middleRows(L.rows(), N*N) = filtwindow;

}


MatrixXd Tikhonov_Alg::initial_laplacian()
{
	MatrixXd laplacian;
	laplacian.resize(N*N, N*N);
	laplacian.setIdentity();//居然没有自动补全
	double ni = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::vector<int> idx;
			ni = 0;
			if (i - 1 >= 0)
			{
				ni++;
				idx.push_back((i - 1)*N + j);
			}
			if (j - 1 >= 0)
			{
				ni++;
				idx.push_back(i*N + j - 1);
			}
			if (i + 1 < N)
			{
				ni++;
				idx.push_back((i + 1)*N + j);
			}
			if (j + 1 < N)
			{
				ni++;
				idx.push_back(i*N + j + 1);
			}
			for (auto c : idx)
			{
				laplacian(i*N + j, c) = -1.0 / ni;
			}

		}
	}
	already_init_filtter = true;
	return laplacian;
}


MatrixXd Tikhonov_Alg::initial_filtwindow()
{
	MatrixXd filtwindow;
	filtwindow.resize(N*N, N*N);
	filtwindow.setZero(N*N, N*N);

	MatrixXd filt(3, 3);
	filt << 1.0 / 12.0, 1.0 / 6.0, 1.0 / 12.0,
		1.0 / 6.0, -1.0, 1.0 / 6,
		1.0 / 12.0, 1.0 / 6.0, 1.0 / 12.0;

	MatrixXd mm(N + 2, N + 2);
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
		{
			mm.setZero(N + 2, N + 2);
			mm(i, j) = filt(1, 1);
			mm(i - 1, j) = filt(1 - 1, 1);
			mm(i - 1, j - 1) = filt(1 - 1, 1 - 1);
			mm(i - 1, j + 1) = filt(1 - 1, 1 + 1);
			mm(i, j - 1) = filt(1, 1 - 1);
			mm(i, j + 1) = filt(1, 1 + 1);
			mm(i + 1, j) = filt(1 + 1, 1);
			mm(i + 1, j - 1) = filt(1 + 1, 1 - 1);
			mm(i + 1, j + 1) = filt(1 + 1, 1 + 1);

			MatrixXd mb = mm.block(1, 1, N, N);
			Map<RowVectorXd> v2(mb.data(), N*N);
			filtwindow.row((i - 1)*N + j - 1) = v2;
		}

	already_init_filtter = true;
	return filtwindow;
}




void Tikhonov_Alg::Tikhonov()
{

	VectorXd newb = VectorXd::Zero(b.rows()+N*N);//行向量？？
	newb.head(b.size()) = b;
	
	/*b.conservativeResize(b.rows() + N*N, 1);
	b.middleRows(b.rows(), N*N).setZero();*/
	land_worker.set_newb(newb);
	land_worker.landweber();

	RWhelper<double> rw_worker;
	int fsize[2] = { 400,1 };
	rw_worker.writetxt(land_worker.x.data(), fsize, QString("./Lb/recb1203") + QString::number(1000, 10) + ".txt");


}
