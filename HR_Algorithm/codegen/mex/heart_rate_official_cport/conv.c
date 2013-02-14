/*
 * conv.c
 *
 * Code generation for function 'conv'
 *
 * C source code generated on: Wed Feb 13 13:34:29 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "conv.h"
#include "heart_rate_official_cport_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtBCInfo fb_emlrtBCI = { 1, 31, 165, 53, "", "conv", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/fixedpoint/@embedded/@fi/conv.m", 0 };
static emlrtBCInfo gb_emlrtBCI = { 1, 1000, 173, 50, "", "conv", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/fixedpoint/@embedded/@fi/conv.m", 0 };
static emlrtBCInfo hb_emlrtBCI = { 1, 31, 173, 55, "", "conv", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/fixedpoint/@embedded/@fi/conv.m", 0 };

/* Function Declarations */

/* Function Definitions */

void conv(const uint32_T A0[1000], const uint32_T B0[31], uint32_T Cout[1030])
{
    int32_T jC;
    int32_T jA1;
    int32_T jA2;
    uint32_T qY;
    uint32_T ABZero;
    int32_T k;
    int32_T b_k;
    for (jC = 0; jC < 1030; jC++) {
        if (31 < 2 + jC) {
            jA1 = jC - 30;
        } else {
            jA1 = 0;
        }
        if (1000 < 1 + jC) {
            jA2 = 998;
        } else {
            jA2 = jC - 1;
        }
        emlrtBoundsCheck((jC - jA1) + 1, &fb_emlrtBCI);
        qY = mul_u32_u32_u32_sat(A0[jA1], B0[jC - jA1]);
        ABZero = (qY >> 10) + ((qY & 512U) != 0U);
        jA2 -= jA1;
        for (k = 0; k <= jA2; k++) {
            b_k = (jA1 + k) + 1;
            emlrtBoundsCheck(b_k + 1, &gb_emlrtBCI);
            emlrtBoundsCheck((jC - b_k) + 1, &hb_emlrtBCI);
            qY = mul_u32_u32_u32_sat(A0[b_k], B0[jC - b_k]);
            qY = (ABZero + (qY >> 10)) + ((qY & 512U) != 0U);
            if (qY < ABZero) {
                qY = MAX_uint32_T;
            }
            ABZero = qY;
        }
        Cout[jC] = ABZero;
    }
}
/* End of code generation (conv.c) */
