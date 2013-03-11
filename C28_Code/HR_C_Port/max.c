/*
 * max.c
 *
 * Code generation for function 'max'
 *
 * C source code generated on: Sun Mar 10 21:17:39 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "max.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
int32_T b_max(const int32_T x0[500])
{
  int32_T maxval;
  int16_T ix;
  maxval = x0[0];
  for (ix = 0; ix < 499; ix++) {
    if (x0[ix + 1] > maxval) {
      maxval = x0[ix + 1];
    }
  }

  return maxval;
}

/* End of code generation (max.c) */
