/*
 * minus.c
 *
 * Code generation for function 'minus'
 *
 * C source code generated on: Mon Mar 11 20:10:04 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "minus.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
int32_T minus(int32_T a0)
{
  int32_T c;
  c = a0 - 1024L;
  if ((a0 < 0L) && (c >= 0L)) {
    c = MIN_int32_T;
  }

  return c;
}

/* End of code generation (minus.c) */
