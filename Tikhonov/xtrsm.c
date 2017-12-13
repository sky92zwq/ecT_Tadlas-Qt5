/*
 * File: xtrsm.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 10-Jul-2017 15:21:32
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tikhonov.h"
#include "xtrsm.h"

/* Function Definitions */

/*
 * Arguments    : const double A[160000]
 *                double B[160000]
 * Return Type  : void
 */
void xtrsm(const double A[160000], double B[160000])
{
  int j;
  int jBcol;
  int k;
  int kAcol;
  int i;
  for (j = 0; j < 400; j++) {
    jBcol = 400 * j;
    for (k = 399; k >= 0; k += -1) {
      kAcol = 400 * k;
      if (B[k + jBcol] != 0.0) {
        B[k + jBcol] /= A[k + kAcol];
        for (i = 0; i + 1 <= k; i++) {
          B[i + jBcol] -= B[k + jBcol] * A[i + kAcol];
        }
      }
    }
  }
}

/*
 * File trailer for xtrsm.c
 *
 * [EOF]
 */
