#ifndef BASE_ALG_H
#define BASE_ALG_H
#include <eigen/Eigen/Eigen>
#include <eigen/Eigen/Sparse>
#include <QString>
#include <QObject>

using namespace Eigen;

class base_Alg:public QObject
{
Q_OBJECT

public:
    base_Alg(QObject *parent = NULL);

    void initial_others();
public:
	int N;
	const int num_detec = 60;
    SparseMatrix<double> L;
    void read_L(QString dir);
    VectorXd b;
    void read_b(QString dir);
    void read_b(double *db);
    int K;
    VectorXd x;

    void set_K(int k);
    void set_x();
public:
	VectorXd R, G, B;
	void set_RGB();


};

#endif // BASE_ALG_H
