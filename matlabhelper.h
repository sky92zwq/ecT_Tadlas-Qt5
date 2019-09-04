#ifndef MATLABHELPER_H
#define MATLABHELPER_H

#include <QObject>
#include <QFile>
#include <QLibrary>
#include "ectclass.h"
#include "mythreads.h"

#include "./matlab/rtwtypes.h"
#include "./matlab/calderon_circle_16_electrodes_ssj.h"
#include "./matlab/calderon_circle_16_electrodes_ssj_types.h"
#include "./matlabdynamic/calderon_circle_16_electrodes_ssjwq.h"

#include "tdlasclass.h"
#include "Tikhonov/Tikhonov.h"

#include <QTime>
#include "rwhelper.h"
class MatlabHelper : public QObject
{
    Q_OBJECT

public:
    MatlabHelper(QObject *parent = NULL);
    ~MatlabHelper();

    void graytoRGB(double *R, double *G, double *B, double *f, double maxf);
    double maxf(double *f, int len);
    RWhelper<double> rwobj;

private:
    TDLASclass tdlasobj;
    double tdlas_L[60 * 400] = {0};
    double tdlas_b[60] = {0};
    int tdlas_k = 1000;
    double tdlas_x0[400] = {0};
    double tdlas_f[400] = {0};
    int tdlas_fsize[2] = {400, 1};
    double tdlas_R_temp[400];
    double tdlas_G_temp[400];
    double tdlas_B_temp[400];

private:
    ECTClass *ect;
    float voidsum;
    float fullsum;
    double *z;
    double senmatrix_16[1716 * 120];
    double R_temp[48 * 48];
    double G_temp[48 * 48];
    double B_temp[48 * 48];
    double m_hold_up[1];
    int R_size[1], G_size[1], B_size[1];

private:
    QTime time;
    QVector<float> fromthread;

public slots:
    void process1cirledata(float *onearg);
signals:
    void sigreconstructRGB(double *, double *, double *);
};

#endif // MATLABHELPER_H
