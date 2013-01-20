/*
 * testcport_mex.c
 *
 * Code generation for function 'testcport'
 *
 * C source code generated on: Mon Jan 14 21:36:44 2013
 *
 */

/* Include files */
#include "mex.h"
#include "testcport_api.h"
#include "testcport_initialize.h"
#include "testcport_terminate.h"

/* Type Definitions */

/* Function Declarations */
static void testcport_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]);

/* Variable Definitions */
emlrtContext emlrtContextGlobal = { true, false, EMLRT_VERSION_INFO, NULL, "testcport", NULL, false, NULL, false, 1, false };

/* Function Definitions */
static void testcport_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Temporary copy for mex outputs. */
  mxArray *outputs[1];
  int n = 0;
  int nOutputs = (nlhs < 1 ? 1 : nlhs);
  /* Check for proper number of arguments. */
  if(nrhs != 0) {
    mexErrMsgIdAndTxt("emlcoder:emlmex:WrongNumberOfInputs","0 inputs required for entry-point 'testcport'.");
  } else if(nlhs > 1) {
    mexErrMsgIdAndTxt("emlcoder:emlmex:TooManyOutputArguments","Too many output arguments for entry-point 'testcport'.");
  }
  /* Module initialization. */
  testcport_initialize(&emlrtContextGlobal);
  /* Call the function. */
  testcport_api((const mxArray**)outputs);
  /* Copy over outputs to the caller. */
  for (n = 0; n < nOutputs; ++n) {
    plhs[n] = emlrtReturnArrayR2009a(outputs[n]);
  }
  /* Module finalization. */
  testcport_terminate();
}
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(testcport_atexit);
  emlrtClearAllocCount(&emlrtContextGlobal, 0, 0, NULL);
  /* Dispatch the entry-point. */
  testcport_mexFunction(nlhs, plhs, nrhs, prhs);
}
/* End of code generation (testcport_mex.c) */
