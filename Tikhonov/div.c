/*
 * File: div.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 06-Jul-2017 15:36:37
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tikhonov.h"
#include "div.h"

/* Function Definitions */

/*
 * Arguments    : const double x[400]
 *                double y
 *                double z[400]
 * Return Type  : void
 */
void b_div(const double x[400], double y, double z[400])
{
  int i;
  for (i = 0; i < 400; i++) {
    z[i] = x[i] / y;
  }
}

/*
 * File trailer for div.c
 *
 * [EOF]
 */
