/*
 * heart_rate_official_cport_mexutil.c
 *
 * Code generation for function 'heart_rate_official_cport_mexutil'
 *
 * C source code generated on: Mon Jan 14 13:44:05 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "heart_rate_official_cport_mexutil.h"
#include "heart_rate_official_cport_data.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

uint32_T div_u32_near(uint32_T numerator, uint32_T denominator)
{
    uint32_T quotient;
    if (denominator == (uint32_T)0) {
        quotient = MAX_uint32_T;
        emlrtDivisionByZeroErrorR2008a(0);
    } else {
        quotient = numerator / denominator;
        numerator %= denominator;
        if ((numerator > 2147483647U) || ((numerator << 1) >= denominator)) {
            quotient++;
        }
    }
    return quotient;
}

const mxArray *emlrt_marshallOut(uint32_T u)
{
    const mxArray *y;
    const mxArray *b_y;
    const mxArray *m2;
    y = NULL;
    b_y = NULL;
    m2 = mxCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
    *(uint32_T *)mxGetData(m2) = u;
    emlrtAssign(&b_y, m2);
    emlrtAssign(&y, emlrtCreateFIR2009a(eml_mx, b_eml_mx, "simulinkarray", b_y, TRUE));
    return y;
}
/* End of code generation (heart_rate_official_cport_mexutil.c) */
