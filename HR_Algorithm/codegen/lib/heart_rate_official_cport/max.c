/*
 * max.c
 *
 * Code generation for function 'max'
 *
 * C source code generated on: Wed Feb 13 22:15:01 2013
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
int32_T b_max(const int32_T x0[1000])
{
  int32_T maxval;
  int16_T ix;
  maxval = x0[0];
  for (ix = 0; ix < 999; ix++) {
    if (x0[ix + 1] > maxval) {
      maxval = x0[ix + 1];
    }
  }

  return maxval;
}

uint32_T c_max(const uint32_T x0[1000])
{
  uint32_T maxval;
  int16_T ix;
  maxval = x0[0];
  for (ix = 0; ix < 999; ix++) {
    if (x0[ix + 1] > maxval) {
      maxval = x0[ix + 1];
    }
  }

  return maxval;
}

void d_max(const int32_T x0_data[1000], const int16_T x0_sizes[1], int32_T
           *maxval, real_T *indx)
{
  int16_T itmp;
  int16_T ix;
  *maxval = x0_data[0];
  itmp = 1;
  if (x0_sizes[0] > 1) {
    for (ix = 1; ix + 1 <= x0_sizes[0]; ix++) {
      if (x0_data[ix] > *maxval) {
        *maxval = x0_data[ix];
        itmp = ix + 1;
      }
    }
  }

  *indx = (real_T)itmp;
}

/* End of code generation (max.c) */
