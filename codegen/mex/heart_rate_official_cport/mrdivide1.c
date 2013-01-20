/*
 * mrdivide1.c
 *
 * Code generation for function 'mrdivide1'
 *
 * C source code generated on: Tue Jan 15 00:51:21 2013
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
    EMLRTPUSHRTSTACK(&ib_emlrtRSI);
    EMLRTPUSHRTSTACK(&jb_emlrtRSI);
    c = div_u32_near(a, b);
    EMLRTPOPRTSTACK(&jb_emlrtRSI);
    EMLRTPOPRTSTACK(&ib_emlrtRSI);
    return c;
}
/* End of code generation (mrdivide1.c) */
