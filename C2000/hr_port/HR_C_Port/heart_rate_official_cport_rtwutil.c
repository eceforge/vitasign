/*
 * heart_rate_official_cport_rtwutil.c
 *
 * Code generation for function 'heart_rate_official_cport_rtwutil'
 *
 * C source code generated on: Mon Mar 11 20:10:04 2013
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
void MultiWordSignedWrap(const uint32_T u1[], int16_T n1, uint16_T n2, uint32_T
  y[])
{
  int16_T n1m1;
  int16_T i;
  uint16_T ns;
  uint32_T mask;
  uint32_T ys;
  n1m1 = n1 - 1;
  for (i = 0; i <= n1m1 - 1; i++) {
    y[i] = u1[i];
  }

  ns = 31U - n2;
  mask = 1UL << ns;
  ys = (u1[n1m1] & mask) != 0UL ? MAX_uint32_T : 0UL;
  mask = (mask << 1U) - 1UL;
  y[n1m1] = (u1[n1m1] & mask) | (~mask & ys);
}

int32_T mul_s32_s32_s32_sat(int32_T a, int32_T b)
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

void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
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

void sLong2MultiWord(int32_T u, uint32_T y[], int16_T n)
{
  uint32_T yi;
  int16_T i;
  y[0] = (uint32_T)u;
  yi = u < 0L ? MAX_uint32_T : 0UL;
  for (i = 1; i <= n - 1; i++) {
    y[i] = yi;
  }
}

int16_T sMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int16_T n)
{
  int16_T y;
  uint32_T su1;
  uint32_T su2;
  int16_T i;
  su1 = u1[n - 1] & 2147483648UL;
  su2 = u2[n - 1] & 2147483648UL;
  if ((su1 ^ su2) != 0UL) {
    y = su1 != 0UL ? -1 : 1;
  } else {
    y = 0;
    i = n;
    while ((y == 0) && (i > 0)) {
      i--;
      su1 = u1[i];
      su2 = u2[i];
      if (su1 != su2) {
        y = su1 > su2 ? 1 : -1;
      }
    }
  }

  return y;
}

boolean_T sMultiWordLe(const uint32_T u1[], const uint32_T u2[], int16_T n)
{
  return sMultiWordCmp(u1, u2, n) <= 0 ? TRUE : FALSE;
}

void sMultiWordShl(const uint32_T u1[], int16_T n1, uint16_T n2, uint32_T y[],
                   int16_T n)
{
  int16_T nb;
  uint32_T ys;
  int16_T nc;
  uint32_T u1i;
  int16_T i;
  uint16_T nl;
  uint16_T nr;
  uint32_T yi;
  nb = (int16_T)n2 / 32;
  ys = (u1[n1 - 1] & 2147483648UL) != 0UL ? MAX_uint32_T : 0UL;
  nc = nb > n ? n : nb;
  u1i = 0UL;
  for (i = 0; i <= nc - 1; i++) {
    y[i] = 0UL;
  }

  if (nb < n) {
    nl = n2 - (uint16_T)nb * 32U;
    nb += n1;
    if (nb > n) {
      nb = n;
    }

    nb -= i;
    if (nl > 0U) {
      nr = 32U - nl;
      for (nc = 0; nc <= nb - 1; nc++) {
        yi = u1i >> nr;
        u1i = u1[nc];
        y[i] = yi | u1i << nl;
        i++;
      }

      if (i < n) {
        y[i] = u1i >> nr | ys << nl;
        i++;
      }
    } else {
      for (nc = 0; nc <= nb - 1; nc++) {
        y[i] = u1[nc];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

/* End of code generation (heart_rate_official_cport_rtwutil.c) */
