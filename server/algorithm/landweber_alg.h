#ifndef LANDWEBER_ALG_H
#define LANDWEBER_ALG_H
#include "base_alg.h"
#include <iostream>
#include <eigen/Eigen/Eigen>
#include <eigen/Eigen/Sparse>
using namespace Eigen;

class landweber_Alg:public base_Alg
{
public:
    landweber_Alg();

public:
    void landweber(const SparseMatrix<double> &theL,const VectorXd &theb,int K,
                   VectorXd &x);
	void landweber();

	void set_newL(const SparseMatrix<double> &theL);
	void set_newb(const VectorXd &theb);
	inline void landweber_Alg::set_lamda()
	{

		BDCSVD<MatrixXd> bm = newL.toDense().bdcSvd();
		VectorXd vb = bm.singularValues();

		lamda = 1.9 / (vb[0] * vb[0]);

	};
private:
	double lamda;
	SparseMatrix<double> newL;
	VectorXd newb;
};

#endif // LANDWEBER_ALG_H
