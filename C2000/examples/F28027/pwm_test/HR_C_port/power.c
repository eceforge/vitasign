/*
 * power.c
 *
 * Code generation for function 'power'
 *
 * C source code generated on: Wed Feb 13 13:34:56 2013
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
static void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo);

/* Function Definitions */
static int32_T mul_s32_s32_s32_sat(int32_T a, int32_T b)
{
  int32_T result;
  uint32_T u32_clo;
  uint32_T u32_chi;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  if (((int32_T)u32_chi > 0L) || ((u32_chi == 0UL) && (u32_clo >= 2147483648UL)))
  {
    result = MAX_int32_T;
  } else if (((int32_T)u32_chi < -1L) || (((int32_T)u32_chi == -1L) && (u32_clo <
    2147483648UL))) {
    result = MIN_int32_T;
  } else {
    result = (int32_T)u32_clo;
  }

  return result;
}

static void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo)
{
  uint32_T absIn0;
  uint32_T absIn1;
  int16_T negativeProduct;
  uint16_T in0Hi;
  uint16_T in0Lo;
  uint16_T in1Hi;
  uint16_T in1Lo;
  uint32_T productLoHi;
  uint32_T productLoLo;
  int16_T carry;
  uint32_T outBitsLo;
  absIn0 = (uint32_T)(in0 < 0L ? -in0 : in0);
  absIn1 = (uint32_T)(in1 < 0L ? -in1 : in1);
  negativeProduct = !((in0 == 0L) || ((in1 == 0L) || ((in0 > 0L) == (in1 > 0L))));
  in0Hi = (uint16_T)(absIn0 >> 16);
  in0Lo = (uint16_T)absIn0 & MAX_uint16_T;
  in1Hi = (uint16_T)(absIn1 >> 16);
  in1Lo = (uint16_T)absIn1 & MAX_uint16_T;
  absIn0 = (uint32_T)in0Hi * (uint32_T)in1Hi;
  absIn1 = (uint32_T)in0Hi * (uint32_T)in1Lo;
  productLoHi = (uint32_T)in0Lo * (uint32_T)in1Hi;
  productLoLo = (uint32_T)in0Lo * (uint32_T)in1Lo;
  carry = 0;
  outBitsLo = productLoLo + (productLoHi << 16UL);
  if (outBitsLo < productLoLo) {
    carry = 1;
  }

  productLoLo = outBitsLo;
  outBitsLo += absIn1 << 16UL;
  if (outBitsLo < productLoLo) {
    carry++;
  }

  absIn0 = (((uint32_T)carry + absIn0) + (productLoHi >> 16)) + (absIn1 >> 16);
  if (negativeProduct) {
    absIn0 = ~absIn0;
    outBitsLo = ~outBitsLo;
    outBitsLo++;
    if (outBitsLo == 0UL) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = outBitsLo;
}

void power(const int32_T a[1000], int32_T yout[1000])
{
  int16_T i;
  for (i = 0; i < 1000; i++) {
    yout[i] = mul_s32_s32_s32_sat(a[i], a[i]);
  }
}

/* End of code generation (power.c) */
