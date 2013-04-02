/*
 * heart_rate_official_cport_rtwutil.h
 *
 * Code generation for function 'heart_rate_official_cport_rtwutil'
 *
 * C source code generated on: Mon Mar 11 20:10:04 2013
 *
 */

#ifndef __HEART_RATE_OFFICIAL_CPORT_RTWUTIL_H__
#define __HEART_RATE_OFFICIAL_CPORT_RTWUTIL_H__
/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rtwtypes.h"
#include "heart_rate_official_cport_types.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern void MultiWordSignedWrap(const uint32_T u1[], int16_T n1, uint16_T n2, uint32_T y[]);
extern int32_T mul_s32_s32_s32_sat(int32_T a, int32_T b);
extern void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T *ptrOutBitsLo);
extern void sLong2MultiWord(int32_T u, uint32_T y[], int16_T n);
extern int16_T sMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int16_T n);
extern boolean_T sMultiWordLe(const uint32_T u1[], const uint32_T u2[], int16_T n);
extern void sMultiWordShl(const uint32_T u1[], int16_T n1, uint16_T n2, uint32_T y[], int16_T n);
#endif
/* End of code generation (heart_rate_official_cport_rtwutil.h) */
