/*
 * File: eye.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 06-Jul-2017 15:36:37
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tikhonov.h"
#include "eye.h"

/* Function Definitions */

/*
 * Arguments    : double I[160000]
 * Return Type  : void
 */
void eye(double I[160000])
{
  int k;
  memset(&I[0], 0, 160000U * sizeof(double));
  for (k = 0; k < 400; k++) {
    I[k + 400 * k] = 1.0;
  }
}

/*
 * File trailer for eye.c
 *
 * [EOF]
 */
