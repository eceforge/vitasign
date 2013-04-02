/*
 * heart_rate_official_cport_rtwutil.c
 *
 * Code generation for function 'heart_rate_official_cport_rtwutil'
 *
 * C source code generated on: Wed Feb 13 22:15:01 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "heart_rate_official_cport_rtwutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
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

void mul_wide_u32(uint32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint16_T in0Hi;
  uint16_T in0Lo;
  uint16_T in1Hi;
  uint16_T in1Lo;
  uint32_T productHiHi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  uint32_T productLoLo;
  int16_T carry;
  uint32_T outBitsLo;
  in0Hi = (uint16_T)(in0 >> 16);
  in0Lo = (uint16_T)in0 & MAX_uint16_T;
  in1Hi = (uint16_T)(in1 >> 16);
  in1Lo = (uint16_T)in1 & MAX_uint16_T;
  productHiHi = (uint32_T)in0Hi * (uint32_T)in1Hi;
  productHiLo = (uint32_T)in0Hi * (uint32_T)in1Lo;
  productLoHi = (uint32_T)in0Lo * (uint32_T)in1Hi;
  productLoLo = (uint32_T)in0Lo * (uint32_T)in1Lo;
  carry = 0;
  outBitsLo = productLoLo + (productLoHi << 16UL);
  if (outBitsLo < productLoLo) {
    carry = 1;
  }

  productLoLo = outBitsLo;
  outBitsLo += productHiLo << 16UL;
  if (outBitsLo < productLoLo) {
    carry++;
  }

  productHiHi = (((uint32_T)carry + productHiHi) + (productLoHi >> 16)) +
    (productHiLo >> 16);
  *ptrOutBitsHi = productHiHi;
  *ptrOutBitsLo = outBitsLo;
}

/* End of code generation (heart_rate_official_cport_rtwutil.c) */
