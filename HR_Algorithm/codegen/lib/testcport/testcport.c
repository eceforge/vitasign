/*
 * testcport.c
 *
 * Code generation for function 'testcport'
 *
 * C source code generated on: Mon Jan 14 11:04:20 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "testcport.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
real_T testcport(void)
{
  real_T sum;
  int32_T j;

  /* UNTITLED Summary of this function goes here */
  /*    Detailed explanation goes here */
  sum = 0.0;
  for (j = 0; j < 6; j++) {
    sum += 1.0 + (real_T)j;
  }

  return sum;
}

/* End of code generation (testcport.c) */
