/*
 * max.c
 *
 * Code generation for function 'max'
 *
 * C source code generated on: Tue Jan 15 00:51:21 2013
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
static emlrtRSInfo x_emlrtRSI = { 55, "max", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/fixedpoint/@embedded/@fi/max.m" };
static emlrtRSInfo y_emlrtRSI = { 15, "eml_min_or_max", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };

/* Function Declarations */

/* Function Definitions */

void b_max(const uint32_T x0_data[1], const int32_T x0_sizes[2], uint32_T *maxval, real_T *indx)
{
    EMLRTPUSHRTSTACK(&x_emlrtRSI);
    EMLRTPUSHRTSTACK(&y_emlrtRSI);
    EMLRTPOPRTSTACK(&y_emlrtRSI);
    EMLRTPOPRTSTACK(&x_emlrtRSI);
    *maxval = x0_data[0];
    *indx = 1.0;
}
/* End of code generation (max.c) */
