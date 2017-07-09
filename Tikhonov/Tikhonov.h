/*
 * File: Tikhonov.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 06-Jul-2017 15:36:37
 */

#ifndef __TIKHONOV_H__
#define __TIKHONOV_H__

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "Tikhonov_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void Tikhonov(const double A[24000], const double b[60], int K, const
                       double f0[400], double f_data[], int f_size[2]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for Tikhonov.h
 *
 * [EOF]
 */
