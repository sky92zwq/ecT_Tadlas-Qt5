#ifndef TIKHONOV_ALG_H
#define TIKHONOV_ALG_H
#include <QString>
#include "base_alg.h"
#include "landweber_alg.h"

#include <eigen/Eigen/Eigen>

using namespace Eigen;

class Tikhonov_Alg: public base_Alg
{
public:
	explicit Tikhonov_Alg(QString s);

private:
	QString filt;

    MatrixXd laplacian;
    MatrixXd newL_lap;
    void initial_newL_lap();
    MatrixXd initial_laplacian();
    MatrixXd filtwindow;
    MatrixXd newL_filt;
    void initial_newL_filt();
    MatrixXd initial_filtwindow();
    bool already_init_filtter;

public:
    landweber_Alg land_worker;//TO DO
    void set_K();
    void set_x();

    void Tikhonov();
};

#endif // TIKHONOV_ALG_H
