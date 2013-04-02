/*
 * heart_rate_official_cport_mexutil.c
 *
 * Code generation for function 'heart_rate_official_cport_mexutil'
 *
 * C source code generated on: Wed Feb 13 13:34:29 2013
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

void error(const mxArray *b, emlrtMCInfo *location)
{
    const mxArray *pArray;
    pArray = b;
    emlrtCallMATLAB(0, NULL, 1, &pArray, "error", TRUE, location);
}

uint32_T mul_u32_u32_u32_sat(uint32_T a, uint32_T b)
{
    uint32_T result;
    uint32_T u32_chi;
    mul_wide_u32(a, b, &u32_chi, &result);
    if (u32_chi) {
        result = MAX_uint32_T;
    }
    return result;
}

void mul_wide_u32(uint32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi, uint32_T *ptrOutBitsLo)
{
    int32_T in0Hi;
    int32_T in0Lo;
    int32_T in1Hi;
    int32_T in1Lo;
    uint32_T productHiHi;
    uint32_T productHiLo;
    uint32_T productLoHi;
    uint32_T productLoLo;
    uint32_T outBitsLo;
    in0Hi = (int32_T)(in0 >> 16U);
    in0Lo = (int32_T)(in0 & 65535U);
    in1Hi = (int32_T)(in1 >> 16U);
    in1Lo = (int32_T)(in1 & 65535U);
    productHiHi = (uint32_T)in0Hi * (uint32_T)in1Hi;
    productHiLo = (uint32_T)in0Hi * (uint32_T)in1Lo;
    productLoHi = (uint32_T)in0Lo * (uint32_T)in1Hi;
    productLoLo = (uint32_T)in0Lo * (uint32_T)in1Lo;
    in0Hi = 0;
    outBitsLo = productLoLo + (productLoHi << 16U);
    if (outBitsLo < productLoLo) {
        in0Hi = 1;
    }
    productLoLo = outBitsLo;
    outBitsLo += productHiLo << 16U;
    if (outBitsLo < productLoLo) {
        in0Hi = (int32_T)((uint32_T)in0Hi + 1U);
    }
    productHiHi = (((uint32_T)in0Hi + productHiHi) + (productLoHi >> 16U)) + (productHiLo >> 16U);
    *ptrOutBitsHi = productHiHi;
    *ptrOutBitsLo = outBitsLo;
}
/* End of code generation (heart_rate_official_cport_mexutil.c) */
