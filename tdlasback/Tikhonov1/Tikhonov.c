/*
 * File: Tikhonov.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 10-Jul-2017 15:33:55
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tikhonov.h"
#include "landwebercode.h"
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
  static double b_A[184000];
  double b_b[460];
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
      xs = i * 20 + j;
      for (i0 = 0; i0 < idx_size_idx_1; i0++) {
        lapcian[xs + 400 * (tmp_data[i0] - 1)] = y;
      }
    }
  }

  /*  f=(A'*A)^-1*A'*b; */
  /*  f=real(f); */
  for (i = 0; i < 400; i++) {
    f[i] = f0[i];
    memcpy(&b_A[i * 460], &A[i * 60], 60U * sizeof(double));
    memcpy(&b_A[i * 460 + 60], &lapcian[i * 400], 400U * sizeof(double));
  }

  memcpy(&b_b[0], &b[0], 60U * sizeof(double));
  memset(&b_b[60], 0, 400U * sizeof(double));
  landwebercode(b_A, b_b, K, f);
}

/*
 * File trailer for Tikhonov.c
 *
 * [EOF]
 */
