/*
 * conv.c
 *
 * Code generation for function 'conv'
 *
 * C source code generated on: Wed Feb 13 22:15:01 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "conv.h"
#include "heart_rate_official_cport_rtwutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
void conv(const uint32_T A0[1000], const uint32_T B0[31], uint32_T Cout[1030])
{
  int16_T jC;
  int16_T jA1;
  int16_T jA2;
  uint32_T qY;
  uint32_T ABZero;
  int16_T k;
  int16_T b_k;
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

    qY = mul_u32_u32_u32_sat(A0[jA1], B0[jC - jA1]);
    ABZero = (qY >> 10) + ((uint16_T)((int16_T)qY & 512) != 0U);
    jA2 -= jA1;
    for (k = 0; k <= jA2; k++) {
      b_k = (jA1 + k) + 1;
      qY = mul_u32_u32_u32_sat(A0[b_k], B0[jC - b_k]);
      qY = (ABZero + (qY >> 10)) + ((uint16_T)((int16_T)qY & 512) != 0U);
      if (qY < ABZero) {
        qY = MAX_uint32_T;
      }

      ABZero = qY;
    }

    Cout[jC] = ABZero;
  }
}

/* End of code generation (conv.c) */
