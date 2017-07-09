/*
 * File: normest.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 06-Jul-2017 15:36:37
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tikhonov.h"
#include "normest.h"
#include "rand.h"
#include "div.h"
#include "norm.h"
#include "xgemv.h"

/* Function Definitions */

/*
 * Arguments    : const double S[184000]
 * Return Type  : double
 */
double normest(const double S[184000])
{
  double e;
  int j;
  double x[400];
  int i;
  double b_x[400];
  double e0;
  double Sx[460];
  boolean_T p;
  boolean_T exitg1;
  double normx;
  double c_x[400];
  for (j = 0; j < 400; j++) {
    x[j] = 0.0;
    for (i = 0; i < 460; i++) {
      x[j] += fabs(S[i + 460 * j]);
    }
  }

  e = norm(x);
  if (e == 0.0) {
  } else {
    memcpy(&b_x[0], &x[0], 400U * sizeof(double));
    b_div(b_x, e, x);
    e0 = 0.0;
    while (fabs(e - e0) > 1.0E-6 * e) {
      e0 = e;
      for (j = 0; j < 460; j++) {
        Sx[j] = 0.0;
        for (i = 0; i < 400; i++) {
          Sx[j] += S[j + 460 * i] * x[i];
        }
      }

      p = true;
      j = 0;
      exitg1 = false;
      while ((!exitg1) && (j < 460)) {
        if (Sx[j] != 0.0) {
          p = false;
          exitg1 = true;
        } else {
          j++;
        }
      }

      if (p) {
        for (j = 0; j < 460; j++) {
          Sx[j] = b_rand();
        }
      }

      xgemv(S, Sx, x);
      normx = norm(x);
      e = normx / b_norm(Sx);
      memcpy(&c_x[0], &x[0], 400U * sizeof(double));
      b_div(c_x, normx, x);
    }
  }

  return e;
}

/*
 * File trailer for normest.c
 *
 * [EOF]
 */
