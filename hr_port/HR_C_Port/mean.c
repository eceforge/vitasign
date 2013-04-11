/*
 * mean.c
 *
 * Code generation for function 'mean'
 *
 * C source code generated on: Tue Apr  2 13:33:13 2013
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
static int32_T div_ssu32_near(int32_T numerator, uint32_T denominator);

/* Function Definitions */
static int32_T div_ssu32_near(int32_T numerator, uint32_T denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  int16_T quotientNeedsNegation;
  uint32_T tempAbsQuotient;
  if (denominator == (uint32_T)0) {
    quotient = numerator >= (int32_T)0 ? MAX_int32_T : MIN_int32_T;
  } else {
    absNumerator = (uint32_T)(numerator >= (int32_T)0 ? numerator : -numerator);
    quotientNeedsNegation = (numerator < (int32_T)0);
    tempAbsQuotient = absNumerator / denominator;
    absNumerator %= denominator;
    if (absNumerator > 2147483647UL) {
      tempAbsQuotient++;
    } else {
      absNumerator <<= 1;
      if ((absNumerator >= denominator) && ((!(uint16_T)quotientNeedsNegation) ||
           (absNumerator > denominator))) {
        tempAbsQuotient++;
      }
    }

    quotient = (uint16_T)quotientNeedsNegation ? -(int32_T)tempAbsQuotient :
      (int32_T)tempAbsQuotient;
  }

  return quotient;
}

int32_T mean(const int32_T x[500])
{
  int32_T sumx;
  int16_T k;
  int32_T q1;
  int32_T qY;
  sumx = x[0];
  for (k = 0; k < 499; k++) {
    q1 = x[1 + k];
    qY = sumx + q1;
    if ((sumx < 0L) && ((q1 < 0L) && (qY >= 0L))) {
      qY = MIN_int32_T;
    } else {
      if ((sumx > 0L) && ((q1 > 0L) && (qY <= 0L))) {
        qY = MAX_int32_T;
      }
    }

    sumx = qY;
  }

  return div_ssu32_near(sumx, 500UL);
}

/* End of code generation (mean.c) */
