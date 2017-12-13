/*
 * File: inv.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 09-Jul-2017 23:31:12
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tikhonov.h"
#include "inv.h"
#include "xtrsm.h"
#include "xgetrf.h"

/* Function Declarations */
static void eml_ipiv2perm(const int ipiv[400], int perm[400]);

/* Function Definitions */

/*
 * Arguments    : const int ipiv[400]
 *                int perm[400]
 * Return Type  : void
 */
static void eml_ipiv2perm(const int ipiv[400], int perm[400])
{
  int k;
  int pipk;
  for (k = 0; k < 400; k++) {
    perm[k] = 1 + k;
  }

  for (k = 0; k < 399; k++) {
    if (ipiv[k] > 1 + k) {
      pipk = perm[ipiv[k] - 1];
      perm[ipiv[k] - 1] = perm[k];
      perm[k] = pipk;
    }
  }
}

/*
 * Arguments    : const double x[160000]
 *                double y[160000]
 * Return Type  : void
 */
void invNxN(const double x[160000], double y[160000])
{
  static double b_x[160000];
  int k;
  int ipiv[400];
  int p[400];
  int c;
  int j;
  int i;
  for (k = 0; k < 160000; k++) {
    y[k] = 0.0;
    b_x[k] = x[k];
  }

  xgetrf(b_x, ipiv);
  eml_ipiv2perm(ipiv, p);
  for (k = 0; k < 400; k++) {
    c = p[k] - 1;
    y[k + 400 * (p[k] - 1)] = 1.0;
    for (j = k; j + 1 < 401; j++) {
      if (y[j + 400 * c] != 0.0) {
        for (i = j + 1; i + 1 < 401; i++) {
          y[i + 400 * c] -= y[j + 400 * c] * b_x[i + 400 * j];
        }
      }
    }
  }

  xtrsm(b_x, y);
}

/*
 * File trailer for inv.c
 *
 * [EOF]
 */
