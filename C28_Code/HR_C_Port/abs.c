/*
 * abs.c
 *
 * Code generation for function 'abs'
 *
 * C source code generated on: Sun Mar 10 21:17:39 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "abs.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
int32_T b_abs(int32_T xfi)
{
  int32_T yreturn;
  if (xfi < 0L) {
    if (xfi <= MIN_int32_T) {
      yreturn = MAX_int32_T;
    } else {
      yreturn = -xfi;
    }
  } else {
    yreturn = xfi;
  }

  return yreturn;
}

int32_T c_abs(int32_T xfi)
{
  int32_T yreturn;
  if (xfi < 0L) {
    if (xfi <= MIN_int32_T) {
      yreturn = MAX_int32_T;
    } else {
      yreturn = -xfi;
    }
  } else {
    yreturn = xfi;
  }

  return yreturn;
}

/* End of code generation (abs.c) */
