/*
 * heart_rate_official_cport_api.c
 *
 * Code generation for function 'heart_rate_official_cport_api'
 *
 * C source code generated on: Wed Feb 13 13:34:29 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "heart_rate_official_cport_api.h"
#include "heart_rate_official_cport_data.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, int32_T y[1000]);
static uint32_T c_emlrt_marshallIn(const mxArray *fs, const char_T *identifier);
static uint32_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId);
static uint32_T e_emlrt_marshallIn(const mxArray *threshold_1, const char_T *identifier);
static const mxArray *e_emlrt_marshallOut(uint32_T u);
static void emlrt_marshallIn(const mxArray *data, const char_T *identifier, int32_T y[1000]);
static uint32_T f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId);
static const mxArray *f_emlrt_marshallOut(uint32_T u);
static void g_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, int32_T ret[1000]);
static uint32_T h_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId);
static uint32_T i_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId);

/* Function Definitions */

static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, int32_T y[1000])
{
    int32_T iv3[1];
    iv3[0] = 1000;
    emlrtCheckFiCtxR2011b(&emlrtContextGlobal, parentId, u, FALSE, 1U, iv3, eml_mx, b_eml_mx);
    g_emlrt_marshallIn(emlrtAlias(u), parentId, y);
    emlrtDestroyArray(&u);
}

static uint32_T c_emlrt_marshallIn(const mxArray *fs, const char_T *identifier)
{
    uint32_T y;
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    y = d_emlrt_marshallIn(emlrtAlias(fs), &thisId);
    emlrtDestroyArray(&fs);
    return y;
}

static uint32_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId)
{
    uint32_T y;
    y = h_emlrt_marshallIn(emlrtAlias(u), parentId);
    emlrtDestroyArray(&u);
    return y;
}

static uint32_T e_emlrt_marshallIn(const mxArray *threshold_1, const char_T *identifier)
{
    uint32_T y;
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    y = f_emlrt_marshallIn(emlrtAlias(threshold_1), &thisId);
    emlrtDestroyArray(&threshold_1);
    return y;
}

static const mxArray *e_emlrt_marshallOut(uint32_T u)
{
    const mxArray *y;
    const mxArray *b_y;
    const mxArray *m5;
    y = NULL;
    b_y = NULL;
    m5 = mxCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
    *(uint32_T *)mxGetData(m5) = u;
    emlrtAssign(&b_y, m5);
    emlrtAssign(&y, emlrtCreateFIR2009a(eml_mx, d_eml_mx, "simulinkarray", b_y, TRUE));
    return y;
}

static void emlrt_marshallIn(const mxArray *data, const char_T *identifier, int32_T y[1000])
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    b_emlrt_marshallIn(emlrtAlias(data), &thisId, y);
    emlrtDestroyArray(&data);
}

static uint32_T f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId)
{
    uint32_T y;
    emlrtCheckFiCtxR2011b(&emlrtContextGlobal, parentId, u, FALSE, 0U, 0, eml_mx, c_eml_mx);
    y = i_emlrt_marshallIn(emlrtAlias(u), parentId);
    emlrtDestroyArray(&u);
    return y;
}

static const mxArray *f_emlrt_marshallOut(uint32_T u)
{
    const mxArray *y;
    const mxArray *b_y;
    const mxArray *m6;
    y = NULL;
    b_y = NULL;
    m6 = mxCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
    *(uint32_T *)mxGetData(m6) = u;
    emlrtAssign(&b_y, m6);
    emlrtAssign(&y, emlrtCreateFIR2009a(eml_mx, c_eml_mx, "simulinkarray", b_y, TRUE));
    return y;
}

static void g_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, int32_T ret[1000])
{
    const mxArray *mxInt;
    int32_T i2;
    mxInt = emlrtImportFiIntArrayR2008b(src);
    for (i2 = 0; i2 < 1000; i2++) {
        ret[i2] = (*(int32_T (*)[1000])mxGetData(mxInt))[i2];
    }
    emlrtDestroyArray(&mxInt);
    emlrtDestroyArray(&src);
}

static uint32_T h_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId)
{
    uint32_T ret;
    emlrtCheckBuiltInCtxR2011b(&emlrtContextGlobal, msgId, src, "uint32", FALSE, 0U, 0);
    ret = *(uint32_T *)mxGetData(src);
    emlrtDestroyArray(&src);
    return ret;
}

static uint32_T i_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId)
{
    uint32_T ret;
    const mxArray *mxInt;
    mxInt = emlrtImportFiIntArrayR2008b(src);
    ret = *(uint32_T *)mxGetData(mxInt);
    emlrtDestroyArray(&mxInt);
    emlrtDestroyArray(&src);
    return ret;
}

void heart_rate_official_cport_api(const mxArray * const prhs[10], const mxArray *plhs[2])
{
    int32_T data[1000];
    uint32_T fs;
    uint32_T threshold_1;
    uint32_T threshold_2;
    uint32_T threshold_3;
    uint32_T pos_deviance_threshold;
    uint32_T neg_deviance_threshold;
    uint32_T sample_time;
    uint32_T shouldOutput;
    uint32_T prev_hr_delta;
    uint32_T last_hr_delta;
    uint32_T heart_rate;
    /* Marshall function inputs */
    emlrt_marshallIn(emlrtAliasP(prhs[0]), "data", data);
    fs = c_emlrt_marshallIn(emlrtAliasP(prhs[1]), "fs");
    threshold_1 = e_emlrt_marshallIn(emlrtAliasP(prhs[2]), "threshold_1");
    threshold_2 = e_emlrt_marshallIn(emlrtAliasP(prhs[3]), "threshold_2");
    threshold_3 = e_emlrt_marshallIn(emlrtAliasP(prhs[4]), "threshold_3");
    pos_deviance_threshold = e_emlrt_marshallIn(emlrtAliasP(prhs[5]), "pos_deviance_threshold");
    neg_deviance_threshold = e_emlrt_marshallIn(emlrtAliasP(prhs[6]), "neg_deviance_threshold");
    sample_time = c_emlrt_marshallIn(emlrtAliasP(prhs[7]), "sample_time");
    shouldOutput = c_emlrt_marshallIn(emlrtAliasP(prhs[8]), "shouldOutput");
    prev_hr_delta = e_emlrt_marshallIn(emlrtAliasP(prhs[9]), "prev_hr_delta");
    /* Invoke the target function */
    heart_rate_official_cport(data, fs, threshold_1, threshold_2, threshold_3, pos_deviance_threshold, neg_deviance_threshold, sample_time, shouldOutput, prev_hr_delta, &heart_rate, &last_hr_delta);
    /* Marshall function outputs */
    plhs[0] = e_emlrt_marshallOut(heart_rate);
    plhs[1] = f_emlrt_marshallOut(last_hr_delta);
}
/* End of code generation (heart_rate_official_cport_api.c) */
