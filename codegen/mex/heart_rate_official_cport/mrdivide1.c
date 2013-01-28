/*
 * mrdivide1.c
 *
 * Code generation for function 'mrdivide1'
 *
 * C source code generated on: Sat Jan 26 20:24:41 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "mrdivide1.h"
#include "heart_rate_official_cport_mexutil.h"
#include "heart_rate_official_cport_data.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

uint32_T mrdivide(uint32_T a, uint32_T b)
{
    uint32_T c;
    EMLRTPUSHRTSTACK(&bb_emlrtRSI);
    EMLRTPUSHRTSTACK(&cb_emlrtRSI);
    c = div_u32_near(a, b);
    EMLRTPOPRTSTACK(&cb_emlrtRSI);
    EMLRTPOPRTSTACK(&bb_emlrtRSI);
    return c;
}
/* End of code generation (mrdivide1.c) */
