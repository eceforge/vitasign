/*
 * testcport_terminate.c
 *
 * Code generation for function 'testcport_terminate'
 *
 * C source code generated on: Mon Jan 14 11:03:44 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "testcport.h"
#include "testcport_terminate.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

void testcport_atexit(void)
{
    emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void testcport_terminate(void)
{
    emlrtLeaveRtStack(&emlrtContextGlobal);
}
/* End of code generation (testcport_terminate.c) */
