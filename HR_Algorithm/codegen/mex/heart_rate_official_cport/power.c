/*
 * power.c
 *
 * Code generation for function 'power'
 *
 * C source code generated on: Wed Feb 13 13:34:29 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "power.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static int32_T mul_s32_s32_s32_sat(int32_T a, int32_T b);
static void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T *ptrOutBitsLo);

/* Function Definitions */

static int32_T mul_s32_s32_s32_sat(int32_T a, int32_T b)
{
    int32_T result;
    uint32_T u32_clo;
    uint32_T u32_chi;
    mul_wide_s32(a, b, &u32_chi, &u32_clo);
    if (((int32_T)u32_chi > 0) || ((u32_chi == 0U) && (u32_clo >= 2147483648U))) {
        result = MAX_int32_T;
    } else if (((int32_T)u32_chi < -1) || (((int32_T)u32_chi == -1) && (u32_clo < 2147483648U))) {
        result = MIN_int32_T;
    } else {
        result = (int32_T)u32_clo;
    }
    return result;
}

static void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T *ptrOutBitsLo)
{
    uint32_T absIn0;
    uint32_T absIn1;
    int32_T negativeProduct;
    int32_T in0Hi;
    int32_T in0Lo;
    int32_T in1Hi;
    int32_T in1Lo;
    uint32_T productLoHi;
    uint32_T productLoLo;
    uint32_T outBitsLo;
    absIn0 = (uint32_T)(in0 < 0 ? -in0 : in0);
    absIn1 = (uint32_T)(in1 < 0 ? -in1 : in1);
    negativeProduct = !((in0 == 0) || ((in1 == 0) || ((in0 > 0) == (in1 > 0))));
    in0Hi = (int32_T)(absIn0 >> 16U);
    in0Lo = (int32_T)(absIn0 & 65535U);
    in1Hi = (int32_T)(absIn1 >> 16U);
    in1Lo = (int32_T)(absIn1 & 65535U);
    absIn0 = (uint32_T)in0Hi * (uint32_T)in1Hi;
    absIn1 = (uint32_T)in0Hi * (uint32_T)in1Lo;
    productLoHi = (uint32_T)in0Lo * (uint32_T)in1Hi;
    productLoLo = (uint32_T)in0Lo * (uint32_T)in1Lo;
    in0Hi = 0;
    outBitsLo = productLoLo + (productLoHi << 16U);
    if (outBitsLo < productLoLo) {
        in0Hi = 1;
    }
    productLoLo = outBitsLo;
    outBitsLo += absIn1 << 16U;
    if (outBitsLo < productLoLo) {
        in0Hi = (int32_T)((uint32_T)in0Hi + 1U);
    }
    absIn0 = (((uint32_T)in0Hi + absIn0) + (productLoHi >> 16U)) + (absIn1 >> 16U);
    if (negativeProduct) {
        absIn0 = ~absIn0;
        outBitsLo = ~outBitsLo;
        outBitsLo++;
        if (outBitsLo == 0U) {
            absIn0++;
        }
    }
    *ptrOutBitsHi = absIn0;
    *ptrOutBitsLo = outBitsLo;
}

void power(const int32_T a[1000], int32_T yout[1000])
{
    int32_T i;
    for (i = 0; i < 1000; i++) {
        yout[i] = mul_s32_s32_s32_sat(a[i], a[i]);
    }
}
/* End of code generation (power.c) */
