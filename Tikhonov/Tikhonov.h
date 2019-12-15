/*
 * File: Tikhonov.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 10-Jul-2017 15:21:32
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
                       double f0[400], double f[400]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for Tikhonov.h
 *
 * [EOF]
 */