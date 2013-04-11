/*
 * heart_rate_official_cport.h
 *
 * Code generation for function 'heart_rate_official_cport'
 *
 * C source code generated on: Tue Apr  2 13:33:13 2013
 *
 */

#ifndef __HEART_RATE_OFFICIAL_CPORT_H__
#define __HEART_RATE_OFFICIAL_CPORT_H__
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
extern int32_T div_repeat_s32_sat_near(int32_T numerator, int32_T denominator,
  uint16_T nRepeatSub);
extern int32_T mul_s32_s32_s32_sat(int32_T a, int32_T b);
extern void heart_rate_official_cport(int32_T data[500], uint32_T fs, int32_T threshold_1, int32_T threshold_2, int32_T threshold_3, int32_T pos_deviance_threshold, int32_T neg_deviance_threshold, int32_T prev_hr_delta, int32_T *hr_delta_sum, int32_T toss_thresh, int32_T *num_peak_deltas, int32_T neg_peak_deviance_threshold, uint32_T sample_time, uint32_T shouldOutput, int32_T *heart_rate, int32_T *last_hr_delta);
#endif
/* End of code generation (heart_rate_official_cport.h) */
