/*
 * heart_rate_official_cport.h
 *
 * Code generation for function 'heart_rate_official_cport'
 *
 * C source code generated on: Wed Feb 13 13:34:56 2013
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
extern uint32_T div_repeat_u32_sat_near(uint32_T numerator, uint32_T denominator,
  uint16_T nRepeatSub);
extern void heart_rate_official_cport(const int32_T data[1000], uint32_T fs, uint32_T threshold_1, uint32_T threshold_2, uint32_T threshold_3, uint32_T pos_deviance_threshold, uint32_T neg_deviance_threshold, uint32_T sample_time, uint32_T shouldOutput, uint32_T prev_hr_delta, uint32_T *heart_rate, uint32_T *last_hr_delta);
#endif
/* End of code generation (heart_rate_official_cport.h) */
