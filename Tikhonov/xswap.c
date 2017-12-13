/*
 * File: xswap.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 10-Jul-2017 15:21:32
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tikhonov.h"
#include "xswap.h"

/* Function Definitions */

/*
 * Arguments    : double x[160000]
 *                int ix0
 *                int iy0
 * Return Type  : void
 */
void xswap(double x[160000], int ix0, int iy0)
{
  int ix;
  int iy;
  int k;
  double temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 400; k++) {
    temp = x[ix];
    x[ix] = x[iy];
    x[iy] = temp;
    ix += 400;
    iy += 400;
  }
}

/*
 * File trailer for xswap.c
 *
 * [EOF]
 */
