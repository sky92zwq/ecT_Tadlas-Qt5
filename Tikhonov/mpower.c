/*
 * File: mpower.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 09-Jul-2017 23:31:12
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tikhonov.h"
#include "mpower.h"
#include "inv.h"

/* Function Definitions */

/*
 * Arguments    : const double a[160000]
 *                double c[160000]
 * Return Type  : void
 */
void mpower(const double a[160000], double c[160000])
{
  invNxN(a, c);
}

/*
 * File trailer for mpower.c
 *
 * [EOF]
 */
