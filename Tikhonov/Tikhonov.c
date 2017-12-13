/*
 * File: Tikhonov.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 10-Jul-2017 15:21:32
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tikhonov.h"
#include "mpower.h"
#include "eye.h"

/* Function Definitions */

/*
 * UNTITLED3 此处显示有关此函数的摘要
 *    此处显示详细说明
 * Arguments    : const double A[24000]
 *                const double b[60]
 *                int K
 *                const double f0[400]
 *                double f[400]
 * Return Type  : void
 */
void Tikhonov(const double A[24000], const double b[60], int K, const double f0
              [400], double f[400])
{
  static double lapcian[160000];
  double idx_data[4];
  int tmp_data[4];
  int i;
  int j;
  int idx_size_idx_1;
  int ni;
  int xs;
  int i0;
  double y;
  int b_i;
  static double b_A[184000];
  static double c_A[160000];
  static double b_lapcian[184000];
  double b_b[460];
  (void)K;
  (void)f0;
  eye(lapcian);
  for (i = 0; i < 20; i++) {
    for (j = 0; j < 20; j++) {
      idx_size_idx_1 = 0;
      ni = 0;
      if (i > 0) {
        ni = 1;
        idx_size_idx_1 = 1;
        idx_data[0] = ((i - 1) * 20 + j) + 1;
      }

      if (j > 0) {
        ni++;
        xs = idx_size_idx_1;
        idx_size_idx_1++;
        idx_data[xs] = (double)((i * 20 + j) + 1) - 1.0;
      }

      if (2 + i <= 20) {
        ni++;
        xs = idx_size_idx_1;
        idx_size_idx_1++;
        idx_data[xs] = ((1 + i) * 20 + j) + 1;
      }

      if (2 + j <= 20) {
        ni++;
        xs = idx_size_idx_1;
        idx_size_idx_1++;
        idx_data[xs] = (double)((i * 20 + j) + 1) + 1.0;
      }

      for (i0 = 0; i0 < idx_size_idx_1; i0++) {
        tmp_data[i0] = (int)idx_data[i0];
      }

      y = -1.0 / (double)ni;
      b_i = i * 20 + j;
      for (i0 = 0; i0 < idx_size_idx_1; i0++) {
        lapcian[b_i + 400 * (tmp_data[i0] - 1)] = y;
      }
    }
  }

  for (i0 = 0; i0 < 400; i0++) {
    memcpy(&b_A[i0 * 460], &A[i0 * 60], 60U * sizeof(double));
    memcpy(&b_A[i0 * 460 + 60], &lapcian[i0 * 400], 400U * sizeof(double));
  }

  for (i0 = 0; i0 < 400; i0++) {
    for (xs = 0; xs < 400; xs++) {
      c_A[i0 + 400 * xs] = 0.0;
      for (b_i = 0; b_i < 460; b_i++) {
        c_A[i0 + 400 * xs] += b_A[b_i + 460 * i0] * b_A[b_i + 460 * xs];
      }
    }
  }

  mpower(c_A, lapcian);
  for (i0 = 0; i0 < 400; i0++) {
    for (xs = 0; xs < 460; xs++) {
      b_lapcian[i0 + 400 * xs] = 0.0;
      for (b_i = 0; b_i < 400; b_i++) {
        b_lapcian[i0 + 400 * xs] += lapcian[i0 + 400 * b_i] * b_A[xs + 460 * b_i];
      }
    }
  }

  memcpy(&b_b[0], &b[0], 60U * sizeof(double));
  memset(&b_b[60], 0, 400U * sizeof(double));
  for (i0 = 0; i0 < 400; i0++) {
    f[i0] = 0.0;
    for (xs = 0; xs < 460; xs++) {
      f[i0] += b_lapcian[i0 + 400 * xs] * b_b[xs];
    }
  }

  /*  options.nonneg =true; */
  /*  if isempty(K) */
  /*      K=1000; */
  /*  end */
  /*  f=landwebercode(A,b,K,f0); */
}

/*
 * File trailer for Tikhonov.c
 *
 * [EOF]
 */
