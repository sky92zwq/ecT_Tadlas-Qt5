/*
 * File: main.c
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 10-Jul-2017 15:33:55
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "rt_nonfinite.h"
#include "Tikhonov.h"
#include "main.h"
#include "Tikhonov_terminate.h"
#include "Tikhonov_initialize.h"

/* Function Declarations */
static void argInit_400x1_real_T(double result[400]);
static void argInit_60x1_real_T(double result[60]);
static void argInit_60x400_real_T(double result[24000]);
static int argInit_int32_T(void);
static double argInit_real_T(void);
static void main_Tikhonov(void);

/* Function Definitions */

/*
 * Arguments    : double result[400]
 * Return Type  : void
 */
static void argInit_400x1_real_T(double result[400])
{
  int idx0;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 400; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[60]
 * Return Type  : void
 */
static void argInit_60x1_real_T(double result[60])
{
  int idx0;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 60; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[24000]
 * Return Type  : void
 */
static void argInit_60x400_real_T(double result[24000])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 60; idx0++) {
    for (idx1 = 0; idx1 < 400; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + 60 * idx1] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : void
 * Return Type  : int
 */
static int argInit_int32_T(void)
{
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_Tikhonov(void)
{
  static double dv0[24000];
  double dv1[60];
  double dv2[400];
  double f[400];

  /* Initialize function 'Tikhonov' input arguments. */
  /* Initialize function input argument 'A'. */
  /* Initialize function input argument 'b'. */
  /* Initialize function input argument 'f0'. */
  /* Call the entry-point 'Tikhonov'. */
  argInit_60x400_real_T(dv0);
  argInit_60x1_real_T(dv1);
  argInit_400x1_real_T(dv2);
  Tikhonov(dv0, dv1, argInit_int32_T(), dv2, f);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  Tikhonov_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_Tikhonov();

  /* Terminate the application.
     You do not need to do this more than one time. */
  Tikhonov_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
