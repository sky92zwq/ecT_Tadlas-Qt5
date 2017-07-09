/*
 * File: landweber.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 06-Jul-2017 15:36:37
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "Tikhonov.h"
#include "landweber.h"
#include "normest.h"

/* Function Definitions */

/*
 * LANDWEBER The classical Landweber method
 *
 *    [X,info,restart] = landweber(A,b,K)
 *    [X,info,restart] = landweber(A,b,K,x0)
 *    [X,info,restart] = landweber(A,b,K,x0,options)
 *
 *  Implements the classical Landweber method for the linear system Ax = b:
 *
 *        x^{k+1} = x^k + lambda_k*A'*(b-A*x^k)
 *
 *  Input:
 *    A        m times n matrix.
 *    b        m times 1 vector containing the right-hand side.
 *    K        Number of iterations. If K is a scalar, then K is the maximum
 *             number of iterations and only the last iterate is saved.
 *             If K is a vector, then the largest value in K is the maximum
 *             number of iterations and only iterates corresponding to the
 *             values in K are saved, together with the last iterate.
 *             If K is empty then a stopping criterion must be specified.
 *    x0       n times 1 starting vector. Default: x0 = 0.
 *    options  Struct with the following fields:
 *        lambda    The relaxation parameter. If lambda is a scalar then
 *                  the corresponding value is used in each iteration;
 *                  default value is 1.9/norm(A)^2.
 *                  If lambda is a string, then it refers to a method to
 *                  determine lambda in each iteration. For this method the
 *                  following strings can be specified:
 *                      'line'    : lambda is chosen using line search.
 *                      'psi1'    : lambda is chosen using the Psi_1-based
 *                                  relaxation method.
 *                      'psi1mod' : lambda is chosen using the modified
 *                                  Psi_1-based relaxation method.
 *                      'psi2'    : lambda is chosen using the Psi_2-based
 *                                  relaxation method.
 *                      'psi2mod' : lambda is chosen using the modified
 *                                  Psi_2-based relaxation method.
 *        stoprule  Struct containing the following information about the
 *                  stopping rule:
 *                      type = 'none' : (Default) the only stopping rule
 *                                      is the maximum number of iterations.
 *                             'NCP'  : Normalized Cumulative Perodogram.
 *                             'DP'   : Discrepancy Principle.
 *                             'ME'   : Monotone Error rule.
 *                      taudelta = product of tau and delta, only needed
 *                                 for DP and ME.
 *        nonneg    Logical; if true then nonnegativity in enforced in
 *                  each iteration.
 *        box       Upper bound L in box constraint [0,L] on pixel values.
 *        restart   Struct that can contain the first singular value s1 of A.
 *
 *  Output:
 *    X         Matrix containing the saved iterations.
 *    info      Information vector with 2 elements.
 *              info(1) = 0 : stopped by maximum number of iterations
 *                        1 : stopped by NCP-rule
 *                        2 : stopped by DP-rule
 *                        3 : stopped by ME-rule.
 *              info(2) = no. of iterations.
 *    restart   Struct containing the largest singular value s1.
 *
 *  See also: cimmino, cav, drop, sart.
 * Arguments    : const double A[184000]
 *                const double b[460]
 *                int K
 *                const double x0[400]
 *                double X_data[]
 *                int X_size[2]
 * Return Type  : void
 */
void landweber(const double A[184000], const double b[460], int K, const double
               x0[400], double X_data[], int X_size[2])
{
  double rxk[460];
  int i1;
  double d0;
  int k;
  double X[400];
  double b_k;
  double sigma1tilde;
  double lambda;
  double xk[400];
  int stop;
  int l;
  double b_A[400];
  double x[400];

  /*  Maria Saxild-Hansen and Per Chr. Hansen, June 10, 2015, DTU Compute. */
  /*  Reference: L. Landweber, An iteration formula for Fredholm integral */
  /*  equations of the first kind, American Journal of Mathematics, 73 (1951), */
  /*  pp. 615-624. */
  /*  Check that at least 3 inputs are given. */
  /*  Check that the sizes of A and b match. */
  /*  Default value for x0. */
  /*  Check the size of x0 */
  for (i1 = 0; i1 < 460; i1++) {
    d0 = 0.0;
    for (k = 0; k < 400; k++) {
      d0 += A[i1 + 460 * k] * x0[k];
    }

    rxk[i1] = b[i1] - d0;
  }

  /*  Check the contents of options if present. */
  /*  Nonnegativity. */
  /*  Box constraints [0,L]. */
  /*  Stopping rules. */
  /*  Determine the maximum number of iterations and initialize the */
  /*  output matrix X. */
  memset(&X[0], 0, 400U * sizeof(double));
  b_k = 0.0;

  /*  end stoprule type specified. */
  /*  Determine the relaxation parameter lambda. */
  /*  Check if the first singular value is given. */
  /*  Calculates the first singular value. */
  sigma1tilde = normest(A);

  /*  If restart is required as output. */
  /*  Define a default constant lambda value. */
  lambda = 1.9 / (sigma1tilde * sigma1tilde);

  /*  end if lambda is a field in options. */
  /*  end if nargin includes options. */
  /*  Initialize the values. */
  memcpy(&xk[0], &x0[0], 400U * sizeof(double));
  stop = 0;
  l = 0;
  while (!(stop != 0)) {
    /*  Update the iteration number k. */
    b_k++;

    /*  Compute the current iteration. */
    /*  Landweber using constant value of lambda. */
    /*  end the different cases of lambda strategies. */
    /*  Nonnegativity and box constraints. */
    for (k = 0; k < 400; k++) {
      b_A[k] = 0.0;
      for (i1 = 0; i1 < 460; i1++) {
        b_A[k] += A[i1 + 460 * k] * rxk[i1];
      }

      xk[k] += lambda * b_A[k];
      x[k] = xk[k];
    }

    for (k = 0; k < 400; k++) {
      if (x[k] >= 0.0) {
        xk[k] = x[k];
      } else {
        xk[k] = 0.0;
      }
    }

    /*  New residual. */
    for (i1 = 0; i1 < 460; i1++) {
      d0 = 0.0;
      for (k = 0; k < 400; k++) {
        d0 += A[i1 + 460 * k] * xk[k];
      }

      rxk[i1] = b[i1] - d0;
    }

    /*  Stopping rules: */
    /*  No stopping rule. */
    if (b_k >= K) {
      stop = 1;
    }

    /*  end stoprule type. */
    /*  If the current iteration is requested saved. */
    if ((b_k == K) || (stop != 0)) {
      l++;

      /*  Save the current iteration. */
      memcpy(&X[0], &xk[0], 400U * sizeof(double));
    }
  }

  if (1 > l) {
    k = -1;
  } else {
    k = 0;
  }

  X_size[0] = 400;
  X_size[1] = k + 1;
  for (i1 = 0; i1 <= k; i1++) {
    memcpy(&X_data[i1 * 400], &X[0], 400U * sizeof(double));
  }
}

/*
 * File trailer for landweber.c
 *
 * [EOF]
 */
