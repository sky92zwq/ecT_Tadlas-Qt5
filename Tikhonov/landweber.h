/*
 * File: landweber.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 06-Jul-2017 15:36:37
 */

#ifndef __LANDWEBER_H__
#define __LANDWEBER_H__

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

  extern void landweber(const double A[184000], const double b[460], int K,
                        const double x0[400], double X_data[], int X_size[2]);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for landweber.h
 *
 * [EOF]
 */
