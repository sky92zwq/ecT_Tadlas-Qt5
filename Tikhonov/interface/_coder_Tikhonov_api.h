/*
 * File: _coder_Tikhonov_api.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 10-Jul-2017 15:21:32
 */

#ifndef ___CODER_TIKHONOV_API_H__
#define ___CODER_TIKHONOV_API_H__

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_Tikhonov_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void Tikhonov(real_T A[24000], real_T b[60], int32_T K, real_T f0[400],
                       real_T f[400]);
  extern void Tikhonov_api(const mxArray *prhs[4], const mxArray *plhs[1]);
  extern void Tikhonov_atexit(void);
  extern void Tikhonov_initialize(void);
  extern void Tikhonov_terminate(void);
  extern void Tikhonov_xil_terminate(void);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_Tikhonov_api.h
 *
 * [EOF]
 */
