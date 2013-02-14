/*
 * mean.c
 *
 * Code generation for function 'mean'
 *
 * C source code generated on: Wed Feb 13 13:34:29 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "mean.h"
#include "heart_rate_official_cport_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo u_emlrtRSI = { 58, "mean", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/fixedpoint/@embedded/@fi/mean.m" };

/* Function Declarations */

/* Function Definitions */

uint32_T mean(const uint32_T x[1000])
{
    uint32_T sumx;
    int32_T k;
    uint32_T qY;
    sumx = x[0];
    for (k = 0; k < 999; k++) {
        qY = sumx + x[1 + k];
        if (qY < sumx) {
            qY = MAX_uint32_T;
        }
        sumx = qY;
    }
    EMLRTPUSHRTSTACK(&u_emlrtRSI);
    EMLRTPOPRTSTACK(&u_emlrtRSI);
    return div_u32_near(sumx, 1000U);
}
/* End of code generation (mean.c) */
