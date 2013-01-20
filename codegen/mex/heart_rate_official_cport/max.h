/*
 * max.h
 *
 * Code generation for function 'max'
 *
 * C source code generated on: Tue Jan 15 00:51:21 2013
 *
 */

#ifndef __MAX_H__
#define __MAX_H__
/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"

#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blascompat32.h"
#include "rtwtypes.h"
#include "heart_rate_official_cport_types.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern void b_max(const uint32_T x0_data[1], const int32_T x0_sizes[2], uint32_T *maxval, real_T *indx);
#endif
/* End of code generation (max.h) */
