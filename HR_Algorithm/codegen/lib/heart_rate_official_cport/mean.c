/*
 * mean.c
 *
 * Code generation for function 'mean'
 *
 * C source code generated on: Wed Feb 13 22:15:01 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "mean.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static uint32_T div_u32_near(uint32_T numerator, uint32_T denominator);

/* Function Definitions */
static uint32_T div_u32_near(uint32_T numerator, uint32_T denominator)
{
  uint32_T quotient;
  if (denominator == (uint32_T)0) {
    quotient = MAX_uint32_T;
  } else {
    quotient = numerator / denominator;
    numerator %= denominator;
    if ((numerator > 2147483647UL) || ((numerator << 1) >= denominator)) {
      quotient++;
    }
  }

  return quotient;
}

uint32_T mean(const uint32_T x[1000])
{
  uint32_T sumx;
  int16_T k;
  uint32_T qY;
  sumx = x[0];
  for (k = 0; k < 999; k++) {
    qY = sumx + x[1 + k];
    if (qY < sumx) {
      qY = MAX_uint32_T;
    }

    sumx = qY;
  }

  return div_u32_near(sumx, 1000UL);
}

/* End of code generation (mean.c) */
