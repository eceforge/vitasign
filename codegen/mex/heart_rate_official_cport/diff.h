/*
 * diff.h
 *
 * Code generation for function 'diff'
 *
 * C source code generated on: Tue Jan 15 00:51:21 2013
 *
 */

#ifndef __DIFF_H__
#define __DIFF_H__
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
extern real_T diff(const real_T x[2]);
#ifdef __WATCOMC__
#pragma aux diff value [8087];
#endif
#endif
/* End of code generation (diff.h) */
