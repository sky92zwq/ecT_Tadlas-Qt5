/*
 * File: landwebercode.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 10-Jul-2017 15:33:55
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tikhonov.h"
#include "landwebercode.h"
#include "norm.h"

/* Function Definitions */

/*
 * UNTITLED2 此处显示有关此函数的摘要
 *    此处显示详细说明
 * Arguments    : const double A[184000]
 *                const double b[460]
 *                int K
 *                double x0[400]
 * Return Type  : void
 */
void landwebercode(const double A[184000], const double b[460], int K, double
                   x0[400])
{
  int i1;
  double d0;
  int k;
  double rxk[460];
  double xpre[400];
  int stop;
  double b_k;
  boolean_T exitg1;
  double b_A[400];
  double b_xpre[400];
  double x[400];
  for (i1 = 0; i1 < 460; i1++) {
    d0 = 0.0;
    for (k = 0; k < 400; k++) {
      d0 += A[i1 + 460 * k] * x0[k];
    }

    rxk[i1] = b[i1] - d0;
  }

  memcpy(&xpre[0], &x0[0], 400U * sizeof(double));
  stop = 0;
  b_k = 0.0;
  exitg1 = false;
  while ((!exitg1) && (!(stop != 0))) {
    b_k++;
    if (b_k >= K) {
      stop = 1;
    }

    for (k = 0; k < 400; k++) {
      b_A[k] = 0.0;
      for (i1 = 0; i1 < 460; i1++) {
        b_A[k] += A[i1 + 460 * k] * rxk[i1];
      }

      x0[k] += 0.002 * b_A[k];
      x[k] = x0[k];
      if (x[k] >= 0.0) {
        x0[k] = x[k];
      } else {
        x0[k] = 0.0;
      }

      b_xpre[k] = xpre[k] - x0[k];
    }

    if (norm(b_xpre) / norm(x0) < 1.0E-8) {
      exitg1 = true;
    } else {
      for (i1 = 0; i1 < 460; i1++) {
        d0 = 0.0;
        for (k = 0; k < 400; k++) {
          d0 += A[i1 + 460 * k] * x0[k];
        }

        rxk[i1] = b[i1] - d0;
      }

      memcpy(&xpre[0], &x0[0], 400U * sizeof(double));
    }
  }
}

/*
 * File trailer for landwebercode.c
 *
 * [EOF]
 */
