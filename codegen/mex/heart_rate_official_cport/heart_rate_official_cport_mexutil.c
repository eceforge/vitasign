/*
 * heart_rate_official_cport_mexutil.c
 *
 * Code generation for function 'heart_rate_official_cport_mexutil'
 *
 * C source code generated on: Tue Jan 15 00:51:21 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "heart_rate_official_cport_mexutil.h"

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
/* End of code generation (heart_rate_official_cport_mexutil.c) */
