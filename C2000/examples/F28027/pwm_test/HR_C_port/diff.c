/*
 * diff.c
 *
 * Code generation for function 'diff'
 *
 * C source code generated on: Wed Feb 13 13:34:56 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "diff.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
void diff(const real_T x[1001], real_T y[1000])
{
  int16_T ixLead;
  int16_T iyLead;
  real_T work;
  int16_T m;
  real_T tmp2;
  ixLead = 1;
  iyLead = 0;
  work = x[0];
  for (m = 0; m < 1000; m++) {
    tmp2 = work;
    work = x[ixLead];
    tmp2 = x[ixLead] - tmp2;
    ixLead++;
    y[iyLead] = tmp2;
    iyLead++;
  }
}

/* End of code generation (diff.c) */
