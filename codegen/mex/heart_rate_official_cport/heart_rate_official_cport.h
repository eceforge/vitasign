/*
 * heart_rate_official_cport.h
 *
 * Code generation for function 'heart_rate_official_cport'
 *
 * C source code generated on: Tue Jan 15 00:51:21 2013
 *
 */

#ifndef __HEART_RATE_OFFICIAL_CPORT_H__
#define __HEART_RATE_OFFICIAL_CPORT_H__
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
extern uint32_T heart_rate_official_cport(uint32_T data, uint32_T fs, uint32_T threshold_1, uint32_T threshold_2, uint32_T threshold_3, uint32_T pos_deviance_threshold, uint32_T neg_deviance_threshold, uint32_T sample_time, uint32_T shouldPlot);
#endif
/* End of code generation (heart_rate_official_cport.h) */
