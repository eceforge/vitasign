/*
 * heart_rate_official_cport_terminate.c
 *
 * Code generation for function 'heart_rate_official_cport_terminate'
 *
 * C source code generated on: Tue Jan 15 00:51:21 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "heart_rate_official_cport_terminate.h"
#include "heart_rate_official_cport_data.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

void heart_rate_official_cport_atexit(void)
{
    emlrtExitTimeCleanup(&emlrtContextGlobal);
    emlrtDestroyArray(&eml_mx);
    emlrtDestroyArray(&b_eml_mx);
    emlrtDestroyArray(&c_eml_mx);
}

void heart_rate_official_cport_terminate(void)
{
    emlrtLeaveRtStack(&emlrtContextGlobal);
}
/* End of code generation (heart_rate_official_cport_terminate.c) */
