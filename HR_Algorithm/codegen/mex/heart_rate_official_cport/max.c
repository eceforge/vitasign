/*
 * max.c
 *
 * Code generation for function 'max'
 *
 * C source code generated on: Wed Feb 13 13:34:29 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "max.h"
#include "heart_rate_official_cport_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo w_emlrtRSI = { 55, "max", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/fixedpoint/@embedded/@fi/max.m" };
static emlrtRSInfo x_emlrtRSI = { 15, "eml_min_or_max", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtRSInfo y_emlrtRSI = { 38, "eml_min_or_max", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtRSInfo ab_emlrtRSI = { 73, "eml_min_or_max", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtRSInfo bb_emlrtRSI = { 88, "eml_min_or_max", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtMCInfo d_emlrtMCI = { 41, 9, "eml_min_or_max", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtMCInfo e_emlrtMCI = { 38, 19, "eml_min_or_max", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtMCInfo f_emlrtMCI = { 74, 9, "eml_min_or_max", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtMCInfo g_emlrtMCI = { 73, 19, "eml_min_or_max", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };
static emlrtBCInfo kb_emlrtBCI = { -1, -1, 218, 32, "", "eml_min_or_max", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/eml/eml_min_or_max.m", 0 };
static emlrtBCInfo lb_emlrtBCI = { -1, -1, 219, 28, "", "eml_min_or_max", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/eml/eml_min_or_max.m", 0 };

/* Function Declarations */
static const mxArray *message(const mxArray *b, emlrtMCInfo *location);

/* Function Definitions */

static const mxArray *message(const mxArray *b, emlrtMCInfo *location)
{
    const mxArray *pArray;
    const mxArray *m7;
    pArray = b;
    return emlrtCallMATLAB(1, &m7, 1, &pArray, "message", TRUE, location);
}

int32_T b_max(const int32_T x0[1000])
{
    int32_T maxval;
    int32_T ix;
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
    int32_T ix;
    maxval = x0[0];
    for (ix = 0; ix < 999; ix++) {
        if (x0[ix + 1] > maxval) {
            maxval = x0[ix + 1];
        }
    }
    return maxval;
}

void d_max(const int32_T x0_data[1000], const int32_T x0_sizes[1], int32_T *maxval, real_T *indx)
{
    boolean_T b1;
    const mxArray *y;
    static const int32_T iv1[2] = { 1, 36 };
    const mxArray *m0;
    static const char_T cv0[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o', 'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };
    const mxArray *b_y;
    static const int32_T iv2[2] = { 1, 39 };
    static const char_T cv1[39] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 'm', 'i', 'n', '_', 'o', 'r', '_', 'm', 'a', 'x', '_', 'v', 'a', 'r', 'D', 'i', 'm', 'Z', 'e', 'r', 'o' };
    int32_T itmp;
    int32_T ix;
    EMLRTPUSHRTSTACK(&w_emlrtRSI);
    EMLRTPUSHRTSTACK(&x_emlrtRSI);
    if ((x0_sizes[0] == 1) || (x0_sizes[0] != 1)) {
        b1 = TRUE;
    } else {
        b1 = FALSE;
    }
    if (b1) {
    } else {
        EMLRTPUSHRTSTACK(&y_emlrtRSI);
        y = NULL;
        m0 = mxCreateCharArray(2, iv1);
        emlrtInitCharArray(36, m0, cv0);
        emlrtAssign(&y, m0);
        error(message(y, &d_emlrtMCI), &e_emlrtMCI);
        EMLRTPOPRTSTACK(&y_emlrtRSI);
    }
    if (x0_sizes[0] > 0) {
    } else {
        EMLRTPUSHRTSTACK(&ab_emlrtRSI);
        b_y = NULL;
        m0 = mxCreateCharArray(2, iv2);
        emlrtInitCharArray(39, m0, cv1);
        emlrtAssign(&b_y, m0);
        error(message(b_y, &f_emlrtMCI), &g_emlrtMCI);
        EMLRTPOPRTSTACK(&ab_emlrtRSI);
    }
    EMLRTPUSHRTSTACK(&bb_emlrtRSI);
    *maxval = x0_data[0];
    itmp = 1;
    if (x0_sizes[0] > 1) {
        for (ix = 2; ix <= x0_sizes[0]; ix++) {
            emlrtDynamicBoundsCheck(ix, 1, x0_sizes[0], &kb_emlrtBCI);
            if (x0_data[ix - 1] > *maxval) {
                *maxval = x0_data[emlrtDynamicBoundsCheck(ix, 1, x0_sizes[0], &lb_emlrtBCI) - 1];
                itmp = ix;
            }
        }
    }
    EMLRTPOPRTSTACK(&bb_emlrtRSI);
    EMLRTPOPRTSTACK(&x_emlrtRSI);
    EMLRTPOPRTSTACK(&w_emlrtRSI);
    *indx = (real_T)itmp;
}
/* End of code generation (max.c) */
