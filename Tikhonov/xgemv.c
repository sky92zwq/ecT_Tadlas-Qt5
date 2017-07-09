/*
 * File: xgemv.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 06-Jul-2017 15:36:37
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tikhonov.h"
#include "xgemv.h"

/* Function Definitions */

/*
 * Arguments    : const double A[184000]
 *                const double x[460]
 *                double y[400]
 * Return Type  : void
 */
void xgemv(const double A[184000], const double x[460], double y[400])
{
  int iy;
  int iac;
  int ix;
  double c;
  int ia;
  for (iy = 0; iy < 400; iy++) {
    y[iy] = 0.0;
  }

  iy = 0;
  for (iac = 0; iac <= 183541; iac += 460) {
    ix = 0;
    c = 0.0;
    for (ia = iac; ia + 1 <= iac + 460; ia++) {
      c += A[ia] * x[ix];
      ix++;
    }

    y[iy] += c;
    iy++;
  }
}

/*
 * File trailer for xgemv.c
 *
 * [EOF]
 */
