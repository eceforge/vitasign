/*
 * plus.c
 *
 * Code generation for function 'plus'
 *
 * C source code generated on: Tue Apr  2 13:33:13 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "plus.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
int32_T plus(int32_T a0)
{
  int32_T c;
  c = a0 + 1024L;
  if ((a0 > 0L) && (c <= 0L)) {
    c = MAX_int32_T;
  }

  return c;
}

/* End of code generation (plus.c) */
