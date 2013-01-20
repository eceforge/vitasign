/*
 * heart_rate_official_cport_mex.c
 *
 * Code generation for function 'heart_rate_official_cport'
 *
 * C source code generated on: Tue Jan 15 00:51:21 2013
 *
 */

/* Include files */
#include "mex.h"
#include "heart_rate_official_cport_api.h"
#include "heart_rate_official_cport_initialize.h"
#include "heart_rate_official_cport_terminate.h"

/* Type Definitions */

/* Function Declarations */
static void heart_rate_official_cport_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]);

/* Variable Definitions */
emlrtContext emlrtContextGlobal = { true, false, EMLRT_VERSION_INFO, NULL, "heart_rate_official_cport", NULL, false, NULL, false, 1, false };

/* Function Definitions */
static void heart_rate_official_cport_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Temporary copy for mex outputs. */
  mxArray *outputs[1];
  int n = 0;
  int nOutputs = (nlhs < 1 ? 1 : nlhs);
  /* Check for proper number of arguments. */
  if(nrhs != 9) {
    mexErrMsgIdAndTxt("emlcoder:emlmex:WrongNumberOfInputs","9 inputs required for entry-point 'heart_rate_official_cport'.");
  } else if(nlhs > 1) {
    mexErrMsgIdAndTxt("emlcoder:emlmex:TooManyOutputArguments","Too many output arguments for entry-point 'heart_rate_official_cport'.");
  }
  /* Module initialization. */
  heart_rate_official_cport_initialize(&emlrtContextGlobal);
  /* Call the function. */
  heart_rate_official_cport_api(prhs,(const mxArray**)outputs);
  /* Copy over outputs to the caller. */
  for (n = 0; n < nOutputs; ++n) {
    plhs[n] = emlrtReturnArrayR2009a(outputs[n]);
  }
  /* Module finalization. */
  heart_rate_official_cport_terminate();
}
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(heart_rate_official_cport_atexit);
  emlrtClearAllocCount(&emlrtContextGlobal, 0, 3, "ForceOff");
  /* Dispatch the entry-point. */
  heart_rate_official_cport_mexFunction(nlhs, plhs, nrhs, prhs);
}
/* End of code generation (heart_rate_official_cport_mex.c) */
