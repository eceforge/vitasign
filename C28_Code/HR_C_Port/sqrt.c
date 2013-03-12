/*
 * sqrt.c
 *
 * Code generation for function 'sqrt'
 *
 * C source code generated on: Mon Mar 11 20:10:04 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "sqrt.h"
#include "heart_rate_official_cport_rtwutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
int16_T b_sqrt(int32_T x)
{
  int16_T yreturn;
  int16_T i;
  int16_T c;
  int32_T qY;
  int64m_T r0;
  int64m_T r1;
  int64m_T r2;
  int64m_T r3;
  int32_T q0;
  int32_T q1;
  int32_T b_qY;
  yreturn = 0;
  if (x <= 0L) {
  } else {
    for (i = 14; i > -1; i += -1) {
      c = yreturn | 1 << (uint16_T)i;
      qY = (int32_T)c * (int32_T)c;
      if (qY > 2097151L) {
        qY = MAX_int32_T;
      } else if (qY <= -2097152L) {
        qY = MIN_int32_T;
      } else {
        qY <<= 10;
      }

      sLong2MultiWord(qY, &r0.chunks[0U], 2);
      MultiWordSignedWrap(&r0.chunks[0U], 2, 22U, &r1.chunks[0U]);
      sLong2MultiWord(x, &r2.chunks[0U], 2);
      sMultiWordShl(&r2.chunks[0U], 2, 10U, &r3.chunks[0U], 2);
      MultiWordSignedWrap(&r3.chunks[0U], 2, 22U, &r0.chunks[0U]);
      if (sMultiWordLe(&r1.chunks[0U], &r0.chunks[0U], 2)) {
        yreturn = c;
      }
    }

    if (yreturn < ~(1 << 15)) {
      c = yreturn + 1;
      qY = (int32_T)c * (int32_T)c;
      if (qY > 2097151L) {
        q0 = MAX_int32_T;
      } else if (qY <= -2097152L) {
        q0 = MIN_int32_T;
      } else {
        q0 = qY << 10;
      }

      if ((uint32_T)x > 2097151UL) {
        q1 = MAX_int32_T;
      } else {
        q1 = x << 10;
      }

      b_qY = q0 - q1;
      if ((q0 < 0L) && (b_qY >= 0L)) {
        b_qY = MIN_int32_T;
      }

      if ((uint32_T)x > 2097151UL) {
        q0 = MAX_int32_T;
      } else {
        q0 = x << 10;
      }

      qY = (int32_T)yreturn * (int32_T)yreturn;
      if (qY > 2097151L) {
        q1 = MAX_int32_T;
      } else if (qY <= -2097152L) {
        q1 = MIN_int32_T;
      } else {
        q1 = qY << 10;
      }

      qY = q0 - q1;
      if ((q1 < 0L) && (qY < 0L)) {
        qY = MAX_int32_T;
      }

      if (b_qY < qY) {
        yreturn = c;
      }
    }
  }

  return yreturn;
}

/* End of code generation (sqrt.c) */
