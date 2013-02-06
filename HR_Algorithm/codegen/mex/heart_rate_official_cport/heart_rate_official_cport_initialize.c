/*
 * heart_rate_official_cport_initialize.c
 *
 * Code generation for function 'heart_rate_official_cport_initialize'
 *
 * C source code generated on: Sat Jan 26 20:24:41 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "heart_rate_official_cport_initialize.h"
#include "heart_rate_official_cport_data.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtMCInfo h_emlrtMCI = { -1, -1, "", "" };
static emlrtMCInfo i_emlrtMCI = { -1, -1, "", "" };
static emlrtMCInfo j_emlrtMCI = { -1, -1, "", "" };
static emlrtMCInfo k_emlrtMCI = { -1, -1, "", "" };

/* Function Declarations */
static const mxArray *b_numerictype(const char * b, boolean_T c, const char * d, const char * e, const char * f, real_T g, const char * h, real_T i, const char * j, real_T k, const char * l, real_T m, const char * n, real_T o, emlrtMCInfo *location);
static const mxArray *fimath(const char * b, const char * c, const char * d, const char * e, const char * f, const char * g, const char * h, real_T i, const char * j, real_T k, const char * l, real_T m, const char * n, real_T o, const char * p, real_T q, const char * r, real_T s, const char * t, real_T u, const char * v, const char * w, const char * x, real_T y, const char * ab, real_T bb, const char * cb, real_T db, const char * eb, real_T fb, const char * gb, real_T hb, const char * ib, real_T jb, const char * kb, real_T lb, const char * mb, boolean_T nb, emlrtMCInfo *location);
static void heart_rate_official_cport_once(void);
static const mxArray *numerictype(const char * b, real_T c, const char * d, real_T e, const char * f, real_T g, const char * h, real_T i, const char * j, real_T k, emlrtMCInfo *location);

/* Function Definitions */

static const mxArray *b_numerictype(const char * b, boolean_T c, const char * d, const char * e, const char * f, real_T g, const char * h, real_T i, const char * j, real_T k, const char * l, real_T m, const char * n, real_T o, emlrtMCInfo *location)
{
    const mxArray *pArrays[14];
    const mxArray *m5;
    pArrays[0] = mxCreateString(b);
    pArrays[1] = mxCreateLogicalScalar(c);
    pArrays[2] = mxCreateString(d);
    pArrays[3] = mxCreateString(e);
    pArrays[4] = mxCreateString(f);
    pArrays[5] = mxCreateDoubleScalar(g);
    pArrays[6] = mxCreateString(h);
    pArrays[7] = mxCreateDoubleScalar(i);
    pArrays[8] = mxCreateString(j);
    pArrays[9] = mxCreateDoubleScalar(k);
    pArrays[10] = mxCreateString(l);
    pArrays[11] = mxCreateDoubleScalar(m);
    pArrays[12] = mxCreateString(n);
    pArrays[13] = mxCreateDoubleScalar(o);
    return emlrtCallMATLAB(1, &m5, 14, pArrays, "numerictype", TRUE, location);
}

static const mxArray *fimath(const char * b, const char * c, const char * d, const char * e, const char * f, const char * g, const char * h, real_T i, const char * j, real_T k, const char * l, real_T m, const char * n, real_T o, const char * p, real_T q, const char * r, real_T s, const char * t, real_T u, const char * v, const char * w, const char * x, real_T y, const char * ab, real_T bb, const char * cb, real_T db, const char * eb, real_T fb, const char * gb, real_T hb, const char * ib, real_T jb, const char * kb, real_T lb, const char * mb, boolean_T nb, emlrtMCInfo *location)
{
    const mxArray *pArrays[38];
    const mxArray *m3;
    pArrays[0] = mxCreateString(b);
    pArrays[1] = mxCreateString(c);
    pArrays[2] = mxCreateString(d);
    pArrays[3] = mxCreateString(e);
    pArrays[4] = mxCreateString(f);
    pArrays[5] = mxCreateString(g);
    pArrays[6] = mxCreateString(h);
    pArrays[7] = mxCreateDoubleScalar(i);
    pArrays[8] = mxCreateString(j);
    pArrays[9] = mxCreateDoubleScalar(k);
    pArrays[10] = mxCreateString(l);
    pArrays[11] = mxCreateDoubleScalar(m);
    pArrays[12] = mxCreateString(n);
    pArrays[13] = mxCreateDoubleScalar(o);
    pArrays[14] = mxCreateString(p);
    pArrays[15] = mxCreateDoubleScalar(q);
    pArrays[16] = mxCreateString(r);
    pArrays[17] = mxCreateDoubleScalar(s);
    pArrays[18] = mxCreateString(t);
    pArrays[19] = mxCreateDoubleScalar(u);
    pArrays[20] = mxCreateString(v);
    pArrays[21] = mxCreateString(w);
    pArrays[22] = mxCreateString(x);
    pArrays[23] = mxCreateDoubleScalar(y);
    pArrays[24] = mxCreateString(ab);
    pArrays[25] = mxCreateDoubleScalar(bb);
    pArrays[26] = mxCreateString(cb);
    pArrays[27] = mxCreateDoubleScalar(db);
    pArrays[28] = mxCreateString(eb);
    pArrays[29] = mxCreateDoubleScalar(fb);
    pArrays[30] = mxCreateString(gb);
    pArrays[31] = mxCreateDoubleScalar(hb);
    pArrays[32] = mxCreateString(ib);
    pArrays[33] = mxCreateDoubleScalar(jb);
    pArrays[34] = mxCreateString(kb);
    pArrays[35] = mxCreateDoubleScalar(lb);
    pArrays[36] = mxCreateString(mb);
    pArrays[37] = mxCreateLogicalScalar(nb);
    return emlrtCallMATLAB(1, &m3, 38, pArrays, "fimath", TRUE, location);
}

static void heart_rate_official_cport_once(void)
{
    emlrtAssignP(&d_eml_mx, NULL);
    emlrtAssignP(&c_eml_mx, NULL);
    emlrtAssignP(&b_eml_mx, NULL);
    emlrtAssignP(&eml_mx, NULL);
    emlrtAssignP(&d_eml_mx, b_numerictype("SignednessBool", FALSE, "Signedness", "Unsigned", "WordLength", 32.0, "FractionLength", 20.0, "BinaryPoint", 20.0, "Slope", 9.5367431640625E-7, "FixedExponent", -20.0, &k_emlrtMCI));
    emlrtAssignP(&c_eml_mx, b_numerictype("SignednessBool", FALSE, "Signedness", "Unsigned", "WordLength", 32.0, "FractionLength", 10.0, "BinaryPoint", 10.0, "Slope", 0.0009765625, "FixedExponent", -10.0, &j_emlrtMCI));
    emlrtAssignP(&b_eml_mx, numerictype("WordLength", 32.0, "FractionLength", 10.0, "BinaryPoint", 10.0, "Slope", 0.0009765625, "FixedExponent", -10.0, &i_emlrtMCI));
    emlrtAssignP(&eml_mx, fimath("RoundMode", "nearest", "OverflowMode", "saturate", "ProductMode", "SpecifyPrecision", "ProductWordLength", 32.0, "MaxProductWordLength", 32.0, "ProductFractionLength", 20.0, "ProductFixedExponent", -20.0, "ProductSlope", 9.5367431640625E-7, "ProductSlopeAdjustmentFactor", 1.0, "ProductBias", 0.0, "SumMode", "SpecifyPrecision", "SumWordLength", 32.0, "MaxSumWordLength", 32.0, "SumFractionLength", 10.0, "SumFixedExponent", -10.0, "SumSlope", 0.0009765625, "SumSlopeAdjustmentFactor", 1.0, "SumBias", 0.0, "CastBeforeSum", TRUE, &h_emlrtMCI));
}

static const mxArray *numerictype(const char * b, real_T c, const char * d, real_T e, const char * f, real_T g, const char * h, real_T i, const char * j, real_T k, emlrtMCInfo *location)
{
    const mxArray *pArrays[10];
    const mxArray *m4;
    pArrays[0] = mxCreateString(b);
    pArrays[1] = mxCreateDoubleScalar(c);
    pArrays[2] = mxCreateString(d);
    pArrays[3] = mxCreateDoubleScalar(e);
    pArrays[4] = mxCreateString(f);
    pArrays[5] = mxCreateDoubleScalar(g);
    pArrays[6] = mxCreateString(h);
    pArrays[7] = mxCreateDoubleScalar(i);
    pArrays[8] = mxCreateString(j);
    pArrays[9] = mxCreateDoubleScalar(k);
    return emlrtCallMATLAB(1, &m4, 10, pArrays, "numerictype", TRUE, location);
}

void heart_rate_official_cport_initialize(emlrtContext *context)
{
    emlrtEnterRtStack(&emlrtContextGlobal);
    if (emlrtFirstTime(context)) {
        heart_rate_official_cport_once();
    }
}
/* End of code generation (heart_rate_official_cport_initialize.c) */
