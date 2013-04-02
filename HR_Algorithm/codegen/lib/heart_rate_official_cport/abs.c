/*
 * abs.c
 *
 * Code generation for function 'abs'
 *
 * C source code generated on: Wed Feb 13 22:15:01 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "abs.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
void b_abs(const int32_T xfi[1000], int32_T yreturn[1000])
{
  int16_T i;
  int32_T saturatedUnaryMinus;
  for (i = 0; i < 1000; i++) {
    yreturn[i] = 0L;
    if (xfi[i] < 0L) {
      saturatedUnaryMinus = xfi[i];
      if (saturatedUnaryMinus <= MIN_int32_T) {
        saturatedUnaryMinus = MAX_int32_T;
      } else {
        saturatedUnaryMinus = -saturatedUnaryMinus;
      }

      yreturn[i] = saturatedUnaryMinus;
    } else {
      yreturn[i] = xfi[i];
    }
  }
}

void c_abs(const uint32_T xfi[1000], uint32_T yreturn[1000])
{
  int16_T i;
  for (i = 0; i < 1000; i++) {
    yreturn[i] = 0UL;
    yreturn[i] = xfi[i];
  }
}

/* End of code generation (abs.c) */
