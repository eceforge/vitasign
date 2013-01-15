/*
 * heart_rate_official_cport_api.c
 *
 * Code generation for function 'heart_rate_official_cport_api'
 *
 * C source code generated on: Mon Jan 14 13:44:05 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "heart_rate_official_cport_api.h"
#include "heart_rate_official_cport_mexutil.h"
#include "heart_rate_official_cport_data.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static uint32_T b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId);
static int32_T c_emlrt_marshallIn(const mxArray *shouldPlot, const char_T *identifier);
static int32_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId);
static uint32_T e_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId);
static uint32_T emlrt_marshallIn(const mxArray *data, const char_T *identifier);
static int32_T f_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId);

/* Function Definitions */

static uint32_T b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId)
{
    uint32_T y;
    emlrtCheckFiCtxR2011b(&emlrtContextGlobal, parentId, u, FALSE, 0U, 0, eml_mx, b_eml_mx);
    y = e_emlrt_marshallIn(emlrtAlias(u), parentId);
    emlrtDestroyArray(&u);
    return y;
}

static int32_T c_emlrt_marshallIn(const mxArray *shouldPlot, const char_T *identifier)
{
    int32_T y;
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    y = d_emlrt_marshallIn(emlrtAlias(shouldPlot), &thisId);
    emlrtDestroyArray(&shouldPlot);
    return y;
}

static int32_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId)
{
    int32_T y;
    y = f_emlrt_marshallIn(emlrtAlias(u), parentId);
    emlrtDestroyArray(&u);
    return y;
}

static uint32_T e_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId)
{
    uint32_T ret;
    const mxArray *mxInt;
    mxInt = emlrtImportFiIntArrayR2008b(src);
    ret = *(uint32_T *)mxGetData(mxInt);
    emlrtDestroyArray(&mxInt);
    emlrtDestroyArray(&src);
    return ret;
}

static uint32_T emlrt_marshallIn(const mxArray *data, const char_T *identifier)
{
    uint32_T y;
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    y = b_emlrt_marshallIn(emlrtAlias(data), &thisId);
    emlrtDestroyArray(&data);
    return y;
}

static int32_T f_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId)
{
    int32_T ret;
    emlrtCheckBuiltInCtxR2011b(&emlrtContextGlobal, msgId, src, "int32", FALSE, 0U, 0);
    ret = *(int32_T *)mxGetData(src);
    emlrtDestroyArray(&src);
    return ret;
}

void heart_rate_official_cport_api(const mxArray * const prhs[9], const mxArray *plhs[1])
{
    uint32_T data;
    uint32_T fs;
    uint32_T threshold_1;
    uint32_T threshold_2;
    uint32_T threshold_3;
    uint32_T pos_deviance_threshold;
    uint32_T neg_deviance_threshold;
    uint32_T sample_time;
    int32_T shouldPlot;
    /* Marshall function inputs */
    data = emlrt_marshallIn(emlrtAliasP(prhs[0]), "data");
    fs = emlrt_marshallIn(emlrtAliasP(prhs[1]), "fs");
    threshold_1 = emlrt_marshallIn(emlrtAliasP(prhs[2]), "threshold_1");
    threshold_2 = emlrt_marshallIn(emlrtAliasP(prhs[3]), "threshold_2");
    threshold_3 = emlrt_marshallIn(emlrtAliasP(prhs[4]), "threshold_3");
    pos_deviance_threshold = emlrt_marshallIn(emlrtAliasP(prhs[5]), "pos_deviance_threshold");
    neg_deviance_threshold = emlrt_marshallIn(emlrtAliasP(prhs[6]), "neg_deviance_threshold");
    sample_time = emlrt_marshallIn(emlrtAliasP(prhs[7]), "sample_time");
    shouldPlot = c_emlrt_marshallIn(emlrtAliasP(prhs[8]), "shouldPlot");
    /* Invoke the target function */
    data = heart_rate_official_cport(data, fs, threshold_1, threshold_2, threshold_3, pos_deviance_threshold, neg_deviance_threshold, sample_time, shouldPlot);
    /* Marshall function outputs */
    plhs[0] = emlrt_marshallOut(data);
}
/* End of code generation (heart_rate_official_cport_api.c) */