/*
 * diff.c
 *
 * Code generation for function 'diff'
 *
 * C source code generated on: Wed Feb 13 13:34:29 2013
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
static emlrtBCInfo ib_emlrtBCI = { 1, 1001, 99, 23, "", "diff", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/datafun/diff.m", 0 };
static emlrtBCInfo jb_emlrtBCI = { 1, 1000, 106, 13, "", "diff", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/datafun/diff.m", 0 };

/* Function Declarations */

/* Function Definitions */

void diff(const real_T x[1001], real_T y[1000])
{
    int32_T ixLead;
    int32_T iyLead;
    real_T work;
    int32_T m;
    real_T tmp2;
    ixLead = 1;
    iyLead = 1;
    work = x[0];
    for (m = 0; m < 1000; m++) {
        emlrtBoundsCheck(ixLead + 1, &ib_emlrtBCI);
        tmp2 = work;
        work = x[ixLead];
        tmp2 = x[ixLead] - tmp2;
        ixLead++;
        y[emlrtBoundsCheck(iyLead, &jb_emlrtBCI) - 1] = tmp2;
        iyLead++;
    }
}
/* End of code generation (diff.c) */
