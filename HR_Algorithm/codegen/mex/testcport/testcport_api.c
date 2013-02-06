/*
 * testcport_api.c
 *
 * Code generation for function 'testcport_api'
 *
 * C source code generated on: Mon Jan 14 21:36:44 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "testcport.h"
#include "testcport_api.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static const mxArray *emlrt_marshallOut(real_T u);

/* Function Definitions */

static const mxArray *emlrt_marshallOut(real_T u)
{
    const mxArray *y;
    const mxArray *m0;
    y = NULL;
    m0 = mxCreateDoubleScalar(u);
    emlrtAssign(&y, m0);
    return y;
}

void testcport_api(const mxArray *plhs[1])
{
    /* Invoke the target function */
    /* Marshall function outputs */
    plhs[0] = emlrt_marshallOut(testcport());
}
/* End of code generation (testcport_api.c) */
