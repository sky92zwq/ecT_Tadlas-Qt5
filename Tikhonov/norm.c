/*
 * File: norm.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 06-Jul-2017 15:36:37
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tikhonov.h"
#include "norm.h"

/* Function Definitions */

/*
 * Arguments    : const double x[460]
 * Return Type  : double
 */
double b_norm(const double x[460])
{
  double y;
  double scale;
  int k;
  double absxk;
  double t;
  y = 0.0;
  scale = 2.2250738585072014E-308;
  for (k = 0; k < 460; k++) {
    absxk = fabs(x[k]);
    if (absxk > scale) {
      t = scale / absxk;
      y = 1.0 + y * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

/*
 * Arguments    : const double x[400]
 * Return Type  : double
 */
double norm(const double x[400])
{
  double y;
  double scale;
  int k;
  double absxk;
  double t;
  y = 0.0;
  scale = 2.2250738585072014E-308;
  for (k = 0; k < 400; k++) {
    absxk = fabs(x[k]);
    if (absxk > scale) {
      t = scale / absxk;
      y = 1.0 + y * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

/*
 * File trailer for norm.c
 *
 * [EOF]
 */
