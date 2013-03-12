/*
 * conv.c
 *
 * Code generation for function 'conv'
 *
 * C source code generated on: Mon Mar 11 20:10:04 2013
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
void b_conv(const int32_T A0[500], const int32_T B0[7], int32_T Cout[506])
{
  int16_T jC;
  int16_T jA1;
  int16_T jA2;
  int32_T q1;
  int32_T ABZero;
  int16_T k;
  int16_T b_k;
  int32_T qY;
  for (jC = 0; jC < 506; jC++) {
    if (7 < 2 + jC) {
      jA1 = jC - 6;
    } else {
      jA1 = 0;
    }

    if (500 < 1 + jC) {
      jA2 = 498;
    } else {
      jA2 = jC - 1;
    }

    q1 = mul_s32_s32_s32_sat(A0[jA1], B0[jC - jA1]);
    ABZero = (q1 >> 10) + ((q1 & 512L) != 0L);
    jA2 -= jA1;
    for (k = 0; k <= jA2; k++) {
      b_k = (jA1 + k) + 1;
      q1 = mul_s32_s32_s32_sat(A0[b_k], B0[jC - b_k]);
      q1 = (q1 >> 10) + ((q1 & 512L) != 0L);
      qY = ABZero + q1;
      if ((ABZero < 0L) && ((q1 < 0L) && (qY >= 0L))) {
        qY = MIN_int32_T;
      } else {
        if ((ABZero > 0L) && ((q1 > 0L) && (qY <= 0L))) {
          qY = MAX_int32_T;
        }
      }

      ABZero = qY;
    }

    Cout[jC] = ABZero;
  }
}

void conv(const int32_T A0[500], const int32_T B0[5], int32_T Cout[504])
{
  int16_T jC;
  int16_T jA1;
  int16_T jA2;
  int32_T q1;
  int32_T ABZero;
  int16_T k;
  int16_T b_k;
  int32_T qY;
  for (jC = 0; jC < 504; jC++) {
    if (5 < 2 + jC) {
      jA1 = jC - 4;
    } else {
      jA1 = 0;
    }

    if (500 < 1 + jC) {
      jA2 = 498;
    } else {
      jA2 = jC - 1;
    }

    q1 = mul_s32_s32_s32_sat(A0[jA1], B0[jC - jA1]);
    ABZero = (q1 >> 10) + ((q1 & 512L) != 0L);
    jA2 -= jA1;
    for (k = 0; k <= jA2; k++) {
      b_k = (jA1 + k) + 1;
      q1 = mul_s32_s32_s32_sat(A0[b_k], B0[jC - b_k]);
      q1 = (q1 >> 10) + ((q1 & 512L) != 0L);
      qY = ABZero + q1;
      if ((ABZero < 0L) && ((q1 < 0L) && (qY >= 0L))) {
        qY = MIN_int32_T;
      } else {
        if ((ABZero > 0L) && ((q1 > 0L) && (qY <= 0L))) {
          qY = MAX_int32_T;
        }
      }

      ABZero = qY;
    }

    Cout[jC] = ABZero;
  }
}

/* End of code generation (conv.c) */
