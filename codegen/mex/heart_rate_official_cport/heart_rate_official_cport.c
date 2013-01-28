/*
 * heart_rate_official_cport.c
 *
 * Code generation for function 'heart_rate_official_cport'
 *
 * C source code generated on: Sat Jan 26 20:24:41 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "max.h"
#include "mrdivide1.h"
#include "heart_rate_official_cport_mexutil.h"
#include "heart_rate_official_cport_data.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 643, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo b_emlrtRSI = { 601, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo c_emlrtRSI = { 600, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo d_emlrtRSI = { 538, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo e_emlrtRSI = { 536, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo f_emlrtRSI = { 413, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo g_emlrtRSI = { 412, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo h_emlrtRSI = { 373, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo i_emlrtRSI = { 362, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo j_emlrtRSI = { 303, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo k_emlrtRSI = { 270, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo l_emlrtRSI = { 110, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo m_emlrtRSI = { 93, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo n_emlrtRSI = { 81, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo o_emlrtRSI = { 77, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo s_emlrtRSI = { 11, "eml_li_find", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/eml/eml_li_find.m" };
static emlrtRSInfo t_emlrtRSI = { 14, "eml_li_find", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/eml/eml_li_find.m" };
static emlrtRSInfo u_emlrtRSI = { 724, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo v_emlrtRSI = { 736, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo w_emlrtRSI = { 749, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo x_emlrtRSI = { 758, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo y_emlrtRSI = { 668, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo ab_emlrtRSI = { 671, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo fb_emlrtRSI = { 22, "mrdivide", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/fixedpoint/@embedded/@fi/mrdivide.m" };
static emlrtRSInfo gb_emlrtRSI = { 49, "rdivide", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/fixedpoint/@embedded/@fi/rdivide.m" };
static emlrtMCInfo b_emlrtMCI = { 77, 1, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtMCInfo c_emlrtMCI = { 81, 1, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtMCInfo d_emlrtMCI = { 93, 1, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtMCInfo g_emlrtMCI = { 14, 5, "eml_li_find", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/eml/eml_li_find.m" };
static emlrtBCInfo emlrtBCI = { -1, -1, 595, 31, "R_peak_indices_channel_3", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo b_emlrtBCI = { -1, -1, 590, 13, "R_peak_indices_channel_3", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo c_emlrtBCI = { -1, -1, 589, 13, "R_peak_vals", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo d_emlrtBCI = { -1, -1, 585, 30, "R_peak_indices_channel_3", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo e_emlrtBCI = { -1, -1, 578, 9, "R_peak_vals", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo f_emlrtBCI = { -1, -1, 577, 9, "R_peak_indices_channel_3", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo g_emlrtBCI = { -1, -1, 550, 13, "R_peak_indices_combined", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo h_emlrtBCI = { -1, -1, 550, 42, "R_peak_indices_channel_2", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo i_emlrtBCI = { -1, -1, 545, 13, "R_peak_indices_combined", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo j_emlrtBCI = { -1, -1, 545, 42, "R_peak_indices_channel_1", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo k_emlrtBCI = { -1, -1, 538, 25, "R_peak_vals", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo l_emlrtBCI = { -1, -1, 536, 25, "R_peak_vals", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo m_emlrtBCI = { -1, -1, 521, 49, "R_peak_indices_channel_2", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo n_emlrtBCI = { -1, -1, 521, 13, "R_peak_indices_channel_1", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo o_emlrtBCI = { -1, -1, 520, 9, "R_peak_indices_combined", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo p_emlrtBCI = { -1, -1, 519, 45, "R_peak_indices_channel_2", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo q_emlrtBCI = { -1, -1, 519, 9, "R_peak_indices_channel_1", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo r_emlrtBCI = { -1, -1, 362, 6, "R_value", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo s_emlrtBCI = { -1, -1, 363, 5, "R_loc", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo t_emlrtBCI = { -1, -1, 363, 27, "left", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo u_emlrtBCI = { -1, -1, 363, 16, "R_loc", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo v_emlrtBCI = { -1, -1, 362, 17, "R_loc", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo w_emlrtBCI = { -1, -1, 362, 45, "right", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo x_emlrtBCI = { -1, -1, 362, 37, "left", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo y_emlrtBCI = { -1, -1, 373, 7, "R_loc", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo ab_emlrtBCI = { -1, -1, 600, 28, "R_peak_indices_channel_3", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo bb_emlrtBCI = { -1, -1, 601, 15, "R_peak_vals", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtDCInfo emlrtDCI = { 17, 37, "eml_li_find", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/eml/eml_li_find.m", 4 };
static emlrtBCInfo cb_emlrtBCI = { -1, -1, 27, 12, "", "eml_li_find", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/eml/eml_li_find.m", 0 };
static emlrtBCInfo db_emlrtBCI = { -1, -1, 28, 13, "", "eml_li_find", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/eml/eml_li_find.m", 0 };
static emlrtBCInfo eb_emlrtBCI = { -1, -1, 40, 12, "", "eml_li_find", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/eml/eml_li_find.m", 0 };
static emlrtBCInfo fb_emlrtBCI = { -1, -1, 718, 16, "R_peak_vals", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo gb_emlrtBCI = { -1, -1, 724, 46, "R_peak_vals", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo hb_emlrtBCI = { -1, -1, 728, 20, "indices", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo ib_emlrtBCI = { -1, -1, 731, 45, "R_peak_vals", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo jb_emlrtBCI = { -1, -1, 745, 42, "R_peak_vals", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo kb_emlrtBCI = { -1, -1, 752, 16, "indices", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo lb_emlrtBCI = { -1, -1, 754, 41, "R_peak_vals", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };

/* Function Declarations */
static void MultiWordUnsignedWrap(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[]);
static uint32_T div_repeat_u32_sat_near(uint32_T numerator, uint32_T denominator, uint32_T nRepeatSub);
static uint32_T div_repeat_us32_sat_near(int32_T numerator, int32_T denominator, uint32_T nRepeatSub);
static void dualThreshold(const uint32_T R_peak_vals_data[1], const int32_T R_peak_vals_sizes[2], uint32_T threshold, uint32_T indices_data[1], int32_T indices_sizes[2], uint32_T max_voltage, uint32_T pos_deviance_threshold, uint32_T neg_deviance_threshold, uint32_T *noise_lvl, uint32_T *signal_lvl);
static void eml_li_find(const boolean_T x_data[1], const int32_T x_sizes[2], int32_T y_data[1], int32_T y_sizes[2]);
static void error(const mxArray *b, emlrtMCInfo *location);
static uint32_T mul_u32_u32_u32_sat(uint32_T a, uint32_T b);
static uint32_T mul_u32_u32_u32_sr15_sat_near(uint32_T a, uint32_T b);
static uint32_T mul_u32_u32_u32_sr16_sat_near(uint32_T a, uint32_T b);
static uint32_T mul_u32_u32_u32_sr26_sat_near(uint32_T a, uint32_T b);
static void mul_wide_u32(uint32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi, uint32_T *ptrOutBitsLo);
static void uLong2MultiWord(uint32_T u, uint32_T y[], int32_T n);
static int32_T uMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int32_T n);
static boolean_T uMultiWordGt(const uint32_T u1[], const uint32_T u2[], int32_T n);
static boolean_T uMultiWordLt(const uint32_T u1[], const uint32_T u2[], int32_T n);
static void uMultiWordShl(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[], int32_T n);

/* Function Definitions */

static void MultiWordUnsignedWrap(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[])
{
    int32_T n1m1;
    int32_T i;
    uint32_T ns;
    n1m1 = n1 - 1;
    for (i = 0; i <= n1m1 - 1; i++) {
        y[i] = u1[i];
    }
    ns = 32U - n2;
    ns = (1U << ns) - 1U;
    y[n1m1] = u1[n1m1] & ns;
}

static uint32_T div_repeat_u32_sat_near(uint32_T numerator, uint32_T denominator, uint32_T nRepeatSub)
{
    uint32_T quotient;
    uint8_T overflow;
    uint32_T iRepeatSub;
    uint8_T numeratorExtraBit;
    if (denominator == (uint32_T)0) {
        quotient = MAX_uint32_T;
        emlrtDivisionByZeroErrorR2008a(0);
    } else {
        overflow = (uint8_T)0U;
        quotient = numerator / denominator;
        numerator %= denominator;
        for (iRepeatSub = (uint32_T)0; iRepeatSub < nRepeatSub; iRepeatSub++) {
            numeratorExtraBit = (uint8_T)(numerator >= 2147483648U);
            numerator <<= 1;
            overflow = (uint8_T)(overflow || (quotient >= 2147483648U));
            quotient <<= 1;
            if (numeratorExtraBit || (numerator >= denominator)) {
                quotient++;
                numerator -= denominator;
            }
        }
        if (overflow || (quotient >= MAX_uint32_T)) {
            quotient = MAX_uint32_T;
        } else {
            numeratorExtraBit = (uint8_T)(numerator >= 2147483648U);
            numerator <<= 1;
            if (numeratorExtraBit || (numerator >= denominator)) {
                quotient++;
            }
        }
    }
    return quotient;
}

static uint32_T div_repeat_us32_sat_near(int32_T numerator, int32_T denominator, uint32_T nRepeatSub)
{
    uint32_T quotient;
    uint32_T absNumerator;
    uint32_T absDenominator;
    int32_T quotientNeedsNegation;
    if (denominator == 0) {
        quotient = numerator >= 0 ? MAX_uint32_T : 0U;
        emlrtDivisionByZeroErrorR2008a(0);
    } else {
        absNumerator = (uint32_T)(numerator >= 0 ? numerator : -numerator);
        absDenominator = (uint32_T)(denominator >= 0 ? denominator : -denominator);
        quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
        if ((uint32_T)quotientNeedsNegation) {
            quotient = 0U;
        } else {
            quotient = div_repeat_u32_sat_near(absNumerator, absDenominator, nRepeatSub);
        }
    }
    return quotient;
}

static void dualThreshold(const uint32_T R_peak_vals_data[1], const int32_T R_peak_vals_sizes[2], uint32_T threshold, uint32_T indices_data[1], int32_T indices_sizes[2], uint32_T max_voltage, uint32_T pos_deviance_threshold, uint32_T neg_deviance_threshold, uint32_T *noise_lvl, uint32_T *signal_lvl)
{
    uint32_T noise_sum;
    uint32_T signal_sum;
    uint32_T noise_count;
    int32_T is_neg;
    uint64m_T r3;
    uint64m_T r4;
    uint64m_T r5;
    uint64m_T r6;
    uint32_T deviance;
    uint32_T q0;
    uint64m_T r7;
    uint64m_T r8;
    uint64m_T r9;
    /* DUAL THRESHOLD PROCESSSING */
    /*  Filters out R_peaks which don't meet the threshold reqs */
    /*  asserts that the input parameters are of fixed point */
    /*  asserts that input parameters are of specific fixed point parameters */
    noise_sum = 0U;
    signal_sum = 0U;
    noise_count = 0U;
    *noise_lvl = 0U;
    *signal_lvl = 0U;
    is_neg = 0;
    while (is_neg <= R_peak_vals_sizes[1] - 1) {
        /*  DELETE AFTER DEBUGGING */
        /* if (shouldPlot && channel == 2) */
        /*     fprintf('The peak val is: %f\n',R_peak_vals(index)); */
        /* end */
        emlrtDynamicBoundsCheck(1, 1, R_peak_vals_sizes[1], &fb_emlrtBCI);
        uLong2MultiWord(mul_u32_u32_u32_sat(R_peak_vals_data[0], max_voltage), &r3.chunks[0U], 2);
        MultiWordUnsignedWrap(&r3.chunks[0U], 2, 22U, &r4.chunks[0U]);
        uLong2MultiWord(threshold, &r5.chunks[0U], 2);
        uMultiWordShl(&r5.chunks[0U], 2, 10U, &r6.chunks[0U], 2);
        MultiWordUnsignedWrap(&r6.chunks[0U], 2, 22U, &r3.chunks[0U]);
        if (uMultiWordGt(&r4.chunks[0U], &r3.chunks[0U], 2)) {
            /* fprintf('mv: %f. Threshold is: %f\n', R_peak_vals(index) * max_voltage, threshold); */
            /* R_peak_vals(index) */
            /*  Filters out any signal value which exceeds the allowed deviance from */
            /*  the average signal value  */
            emlrtDynamicBoundsCheck(1, 1, R_peak_vals_sizes[1], &gb_emlrtBCI);
            EMLRTPUSHRTSTACK(&u_emlrtRSI);
            /*  RETURNS TRUE IF THE INPUT SIGNAL VALUE MEETS THE DEVIANCE REQS. NOTE */
            /*  THE THRESHOLD VALUE CHANGES BASED ON WHETHER DEVIANCE IS NEG OR POS */
            /*  asserts that the input parameters are of fixed point */
            /*  asserts that input parameters are of specific fixed point parameters */
            /* Accounts for the first signal value */
            if (*signal_lvl == 0U) {
                is_neg = 1;
            } else {
                if (R_peak_vals_data[0] < *signal_lvl) {
                    EMLRTPUSHRTSTACK(&y_emlrtRSI);
                    EMLRTPUSHRTSTACK(&bb_emlrtRSI);
                    EMLRTPUSHRTSTACK(&cb_emlrtRSI);
                    deviance = *signal_lvl - R_peak_vals_data[0];
                    if (deviance > *signal_lvl) {
                        deviance = 0U;
                    }
                    deviance = div_u32_near(mul_u32_u32_u32_sr15_sat_near(deviance, 3355443200U), *signal_lvl);
                    EMLRTPOPRTSTACK(&cb_emlrtRSI);
                    EMLRTPOPRTSTACK(&bb_emlrtRSI);
                    EMLRTPOPRTSTACK(&y_emlrtRSI);
                    is_neg = 1;
                } else {
                    EMLRTPUSHRTSTACK(&ab_emlrtRSI);
                    EMLRTPUSHRTSTACK(&bb_emlrtRSI);
                    EMLRTPUSHRTSTACK(&cb_emlrtRSI);
                    q0 = R_peak_vals_data[0];
                    deviance = q0 - *signal_lvl;
                    if (deviance > q0) {
                        deviance = 0U;
                    }
                    deviance = div_u32_near(mul_u32_u32_u32_sr15_sat_near(deviance, 3355443200U), *signal_lvl);
                    EMLRTPOPRTSTACK(&cb_emlrtRSI);
                    EMLRTPOPRTSTACK(&bb_emlrtRSI);
                    EMLRTPOPRTSTACK(&ab_emlrtRSI);
                    is_neg = 0;
                }
                /*  Checks value against NEG and POS deviance threshold */
                if (is_neg != 0) {
                    uLong2MultiWord(deviance, &r7.chunks[0U], 2);
                    uMultiWordShl(&r7.chunks[0U], 2, 10U, &r8.chunks[0U], 2);
                    MultiWordUnsignedWrap(&r8.chunks[0U], 2, 22U, &r9.chunks[0U]);
                    uLong2MultiWord(mul_u32_u32_u32_sr15_sat_near(neg_deviance_threshold, 3355443200U), &r7.chunks[0U], 2);
                    MultiWordUnsignedWrap(&r7.chunks[0U], 2, 22U, &r8.chunks[0U]);
                    if (uMultiWordLt(&r9.chunks[0U], &r8.chunks[0U], 2)) {
                        is_neg = 1;
                    } else {
                        is_neg = 0;
                    }
                } else {
                    uLong2MultiWord(deviance, &r9.chunks[0U], 2);
                    uMultiWordShl(&r9.chunks[0U], 2, 10U, &r5.chunks[0U], 2);
                    MultiWordUnsignedWrap(&r5.chunks[0U], 2, 22U, &r6.chunks[0U]);
                    uLong2MultiWord(mul_u32_u32_u32_sr15_sat_near(pos_deviance_threshold, 3355443200U), &r9.chunks[0U], 2);
                    MultiWordUnsignedWrap(&r9.chunks[0U], 2, 22U, &r5.chunks[0U]);
                    if (uMultiWordLt(&r6.chunks[0U], &r5.chunks[0U], 2)) {
                        is_neg = 1;
                    } else {
                        is_neg = 0;
                    }
                }
            }
            EMLRTPOPRTSTACK(&u_emlrtRSI);
            if (!(is_neg != 0)) {
                /*                    fprintf('%f, %f Does not meet the deviance threshold\n', R_peak_vals(index), signal_lvl); */
                /*  Sets all the indices which R_vals don't meet the threshold to 0 */
                emlrtDynamicBoundsCheck(1, 1, indices_sizes[1], &hb_emlrtBCI);
                indices_data[0] = 0U;
                /*  Updates the average noise signal lvl */
                emlrtDynamicBoundsCheck(1, 1, R_peak_vals_sizes[1], &ib_emlrtBCI);
                deviance = noise_sum + R_peak_vals_data[0];
                if (deviance < noise_sum) {
                    deviance = MAX_uint32_T;
                }
                noise_sum = deviance;
                deviance = noise_count + 1024U;
                if (deviance < noise_count) {
                    deviance = MAX_uint32_T;
                }
                noise_count = deviance;
                /*  Calculates the noise level */
                /*                     noise_lvl = noise_sum / noise_count; */
                EMLRTPUSHRTSTACK(&v_emlrtRSI);
                *noise_lvl = div_repeat_u32_sat_near(noise_sum, noise_count, 10U);
                EMLRTPOPRTSTACK(&v_emlrtRSI);
            } else {
                /*  DELETE AFTER DEBUGGING */
                /* if (shouldPlot && channel == 2) */
                /*    fprintf('The peak val is: %f\n',R_peak_vals(index)); */
                /* end */
                /*  Updates the average signal lvl */
                emlrtDynamicBoundsCheck(1, 1, R_peak_vals_sizes[1], &jb_emlrtBCI);
                deviance = signal_sum + R_peak_vals_data[0];
                if (deviance < signal_sum) {
                    deviance = MAX_uint32_T;
                }
                signal_sum = deviance;
                /*  Calculates the signal level */
                EMLRTPUSHRTSTACK(&w_emlrtRSI);
                *signal_lvl = div_repeat_u32_sat_near(signal_sum, signal_sum, 10U);
                EMLRTPOPRTSTACK(&w_emlrtRSI);
            }
        } else {
            /*  Sets all the indices which R_vals don't meet the threshold to 0 */
            emlrtDynamicBoundsCheck(1, 1, indices_sizes[1], &kb_emlrtBCI);
            indices_data[0] = 0U;
            /*  Updates the average noise signal lvl */
            emlrtDynamicBoundsCheck(1, 1, R_peak_vals_sizes[1], &lb_emlrtBCI);
            deviance = noise_sum + R_peak_vals_data[0];
            if (deviance < noise_sum) {
                deviance = MAX_uint32_T;
            }
            noise_sum = deviance;
            deviance = noise_count + 1024U;
            if (deviance < noise_count) {
                deviance = MAX_uint32_T;
            }
            noise_count = deviance;
            /*  Calculates the noise level */
            /*                 noise_lvl = noise_sum / noise_count; */
            EMLRTPUSHRTSTACK(&x_emlrtRSI);
            *noise_lvl = div_repeat_u32_sat_near(noise_sum, noise_count, 10U);
            EMLRTPOPRTSTACK(&x_emlrtRSI);
        }
        is_neg = 1;
        emlrtBreakCheck();
    }
}

static void eml_li_find(const boolean_T x_data[1], const int32_T x_sizes[2], int32_T y_data[1], int32_T y_sizes[2])
{
    int32_T k;
    int32_T i;
    const mxArray *y;
    const mxArray *m1;
    EMLRTPUSHRTSTACK(&s_emlrtRSI);
    k = 0;
    i = 1;
    while (i <= x_sizes[1]) {
        emlrtDynamicBoundsCheck(1, 1, x_sizes[1], &eb_emlrtBCI);
        if (x_data[0]) {
            k++;
        }
        i = 2;
    }
    EMLRTPOPRTSTACK(&s_emlrtRSI);
    if (k <= x_sizes[1]) {
    } else {
        EMLRTPUSHRTSTACK(&t_emlrtRSI);
        y = NULL;
        m1 = mxCreateString("Assertion failed.");
        emlrtAssign(&y, m1);
        error(y, &g_emlrtMCI);
        EMLRTPOPRTSTACK(&t_emlrtRSI);
    }
    emlrtNonNegativeCheckR2009b((real_T)k, &emlrtDCI);
    y_sizes[0] = 1;
    y_sizes[1] = k;
    k = 1;
    i = 1;
    while (i <= x_sizes[1]) {
        emlrtDynamicBoundsCheck(1, 1, 1, &cb_emlrtBCI);
        if (x_data[0]) {
            emlrtDynamicBoundsCheck(k, 1, y_sizes[1], &db_emlrtBCI);
            y_data[0] = 1;
            k = 2;
        }
        i = 2;
    }
}

static void error(const mxArray *b, emlrtMCInfo *location)
{
    const mxArray *pArray;
    pArray = b;
    emlrtCallMATLAB(0, NULL, 1, &pArray, "error", TRUE, location);
}

static uint32_T mul_u32_u32_u32_sat(uint32_T a, uint32_T b)
{
    uint32_T result;
    uint32_T u32_chi;
    mul_wide_u32(a, b, &u32_chi, &result);
    if (u32_chi) {
        result = MAX_uint32_T;
    }
    return result;
}

static uint32_T mul_u32_u32_u32_sr15_sat_near(uint32_T a, uint32_T b)
{
    uint32_T result;
    uint32_T u32_chi;
    boolean_T roundup;
    mul_wide_u32(a, b, &u32_chi, &result);
    roundup = ((result & 16384U) != 0U);
    result = (u32_chi << 17U | result >> 15U) + (uint32_T)roundup;
    u32_chi = (u32_chi >> 15U) + (uint32_T)(roundup && (result == 0U));
    if (u32_chi) {
        result = MAX_uint32_T;
    }
    return result;
}

static uint32_T mul_u32_u32_u32_sr16_sat_near(uint32_T a, uint32_T b)
{
    uint32_T result;
    uint32_T u32_chi;
    boolean_T roundup;
    mul_wide_u32(a, b, &u32_chi, &result);
    roundup = ((result & 32768U) != 0U);
    result = (u32_chi << 16U | result >> 16U) + (uint32_T)roundup;
    u32_chi = (u32_chi >> 16U) + (uint32_T)(roundup && (result == 0U));
    if (u32_chi) {
        result = MAX_uint32_T;
    }
    return result;
}

static uint32_T mul_u32_u32_u32_sr26_sat_near(uint32_T a, uint32_T b)
{
    uint32_T result;
    uint32_T u32_chi;
    boolean_T roundup;
    mul_wide_u32(a, b, &u32_chi, &result);
    roundup = ((result & 33554432U) != 0U);
    result = (u32_chi << 6U | result >> 26U) + (uint32_T)roundup;
    u32_chi = (u32_chi >> 26U) + (uint32_T)(roundup && (result == 0U));
    if (u32_chi) {
        result = MAX_uint32_T;
    }
    return result;
}

static void mul_wide_u32(uint32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi, uint32_T *ptrOutBitsLo)
{
    int32_T in0Hi;
    int32_T in0Lo;
    int32_T in1Hi;
    int32_T in1Lo;
    uint32_T productHiHi;
    uint32_T productHiLo;
    uint32_T productLoHi;
    uint32_T productLoLo;
    uint32_T outBitsLo;
    in0Hi = (int32_T)(in0 >> 16U);
    in0Lo = (int32_T)(in0 & 65535U);
    in1Hi = (int32_T)(in1 >> 16U);
    in1Lo = (int32_T)(in1 & 65535U);
    productHiHi = (uint32_T)in0Hi * (uint32_T)in1Hi;
    productHiLo = (uint32_T)in0Hi * (uint32_T)in1Lo;
    productLoHi = (uint32_T)in0Lo * (uint32_T)in1Hi;
    productLoLo = (uint32_T)in0Lo * (uint32_T)in1Lo;
    in0Hi = 0;
    outBitsLo = productLoLo + (productLoHi << 16U);
    if (outBitsLo < productLoLo) {
        in0Hi = 1;
    }
    productLoLo = outBitsLo;
    outBitsLo += productHiLo << 16U;
    if (outBitsLo < productLoLo) {
        in0Hi = (int32_T)((uint32_T)in0Hi + 1U);
    }
    productHiHi = (((uint32_T)in0Hi + productHiHi) + (productLoHi >> 16U)) + (productHiLo >> 16U);
    *ptrOutBitsHi = productHiHi;
    *ptrOutBitsLo = outBitsLo;
}

static void uLong2MultiWord(uint32_T u, uint32_T y[], int32_T n)
{
    int32_T i;
    y[0] = u;
    for (i = 1; i <= n - 1; i++) {
        y[i] = 0U;
    }
}

static int32_T uMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
    int32_T y;
    int32_T i;
    uint32_T u1i;
    uint32_T u2i;
    y = 0;
    i = n;
    while ((y == 0) && (i > 0)) {
        i--;
        u1i = u1[i];
        u2i = u2[i];
        if (u1i != u2i) {
            y = u1i > u2i ? 1 : -1;
        }
    }
    return y;
}

static boolean_T uMultiWordGt(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
    return uMultiWordCmp(u1, u2, n) > 0 ? TRUE : FALSE;
}

static boolean_T uMultiWordLt(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
    return uMultiWordCmp(u1, u2, n) < 0 ? TRUE : FALSE;
}

static void uMultiWordShl(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[], int32_T n)
{
    int32_T nb;
    uint32_T ys;
    int32_T nc;
    uint32_T u1i;
    int32_T i;
    uint32_T nl;
    uint32_T nr;
    uint32_T yi;
    nb = (int32_T)n2 / 32;
    ys = (u1[n1 - 1] & 2147483648U) != 0U ? MAX_uint32_T : 0U;
    nc = nb > n ? n : nb;
    u1i = 0U;
    for (i = 0; i <= nc - 1; i++) {
        y[i] = 0U;
    }
    if (nb < n) {
        nl = n2 - (uint32_T)nb * 32U;
        nb += n1;
        if (nb > n) {
            nb = n;
        }
        nb -= i;
        if (nl > 0U) {
            nr = 32U - nl;
            for (nc = 0; nc <= nb - 1; nc++) {
                yi = u1i >> nr;
                u1i = u1[nc];
                y[i] = yi | u1i << nl;
                i++;
            }
            if (i < n) {
                y[i] = u1i >> nr | ys << nl;
                i++;
            }
        } else {
            for (nc = 0; nc <= nb - 1; nc++) {
                y[i] = u1[nc];
                i++;
            }
        }
    }
    while (i < n) {
        y[i] = ys;
        i++;
    }
}

uint32_T heart_rate_official_cport(int32_T data, uint32_T fs, uint32_T threshold_1, uint32_T threshold_2, uint32_T threshold_3, uint32_T pos_deviance_threshold, uint32_T neg_deviance_threshold, uint32_T sample_time, uint32_T shouldPlot)
{
    uint32_T heart_rate;
    const mxArray *y;
    const mxArray *m0;
    boolean_T poss_reg;
    const mxArray *b_y;
    real_T d0;
    uint32_T qY;
    const mxArray *c_y;
    int32_T d_y;
    const mxArray *e_y;
    const mxArray *f_y;
    uint32_T x1;
    uint32_T x5;
    uint32_T x6[31];
    int32_T i;
    uint64m_T r0;
    uint64m_T r1;
    uint64m_T r2;
    int32_T ii_sizes_idx_0;
    int32_T ii_sizes_idx_1;
    int32_T left_sizes_idx_0;
    int32_T left_sizes_idx_1;
    int32_T R_value_sizes[2];
    int32_T loop_ub;
    uint32_T R_value_data[1];
    int8_T R_loc_data[1];
    uint32_T x1_data[1];
    int32_T tmp_sizes[2];
    boolean_T b_R_loc_data[1];
    int32_T R_loc_sizes[2];
    int32_T tmp_data[1];
    int8_T c_R_loc_data[1];
    uint32_T R_peak_vals_data[1];
    uint32_T R_peak_indices_combined_data[1];
    int32_T R_peak_indices_channel_1_sizes[2];
    uint32_T R_peak_indices_channel_1_data[1];
    uint32_T signal_lvl_channel_1;
    uint32_T noise_lvl_channel_1;
    int32_T R_peak_indices_channel_2_sizes[2];
    uint32_T R_peak_indices_channel_2_data[1];
    uint32_T signal_lvl_channel_2;
    uint32_T noise_lvl_channel_2;
    boolean_T guard2 = FALSE;
    boolean_T guard1 = FALSE;
    int32_T R_peak_indices_combined_sizes[2];
    int32_T R_peak_vals_sizes[2];
    /* ------ Heart Rate Detection Algorithm ---------- */
    /*   Detects and calculates Heart rate from an EKG Signal.  */
    /*   The QRS Detection algorithm is based on Pan-Tompkin's famous paper */
    /*  */
    /*  Inputs:  */
    /*    data                    EKG data */
    /*    fs                      sampling rate */
    /*    threshold_1             threshold for filtering out peaks for channel 1 */
    /*                            used in dual threshold processing */
    /*    threshold_2             threshold for filtering out peaks for channel 2 */
    /*                            use in dual threshold processing */
    /*    threshold_3             threshold for filtering out peaks for channel 3  */
    /*                            used in 4th level processing */
    /*    pos_deviance_threshold  threshold for filtering out peak values which  */
    /*                            deviate above the average peak values  */
    /*    neg_deviance_threshold  threshold for filtering out peak values which */
    /*                            devivate below an average EKG signal */
    /*                             */
    /*    sample_time   length in time(s) over which HR is estimated */
    /*     */
    /*  */
    /*  Outputs: */
    /*    heart_rate  Estimated heart rate in beats per minute */
    /*  */
    /*  % % % % % % % % % % % % % % % */
    /*  */
    /*  Gbenga Badipe */
    /*  QRS Detection */
    /*  shows the effect of each filter according to Pan-Tompkins algorithm. */
    /*  Note that, the decision  algorithm is different then the mentioned algorithm. */
    /*  by Faruk UYSAL */
    /*  Clears outputs and figures */
    /* clc */
    /* close all */
    /*  Ensures the the input args are of the correct data type */
    /*  Defines Signed and Unsigned Fixed point objects */
    /*  DEBUG CODE */
    /*  fipref('DataTypeOverride', 'TrueDoubles', 'LoggingMode', 'on'); % turns on datatype override to see the dynamic range of algo's values */
    /*  fipref('DataTypeOverride', 'ForceOff'); % turns off datatype override */
    /*  F.sub(fi(3), fi(2)) */
    /*  asserts that the input parameters are of fixed point */
    /*  asserts that input parameters are of specific fixed point parameters */
    /*  assert(isequal(numerictype(fs),Fixed_Point_Properties) && isequal(fimath(fs), F)); */
    /*  assert(isequal(numerictype(sample_time),Fixed_Point_Properties) && isequal(fimath(sample_time), F)); */
    /*   Assures that the first threshold is less than the second threshold */
    if (threshold_1 < threshold_2) {
    } else {
        EMLRTPUSHRTSTACK(&o_emlrtRSI);
        y = NULL;
        m0 = mxCreateString("Assertion failed.");
        emlrtAssign(&y, m0);
        error(y, &b_emlrtMCI);
        EMLRTPOPRTSTACK(&o_emlrtRSI);
    }
    /*   Assures that the third threshold is in between the first and the second */
    /*  threshold */
    if ((threshold_3 < threshold_2) && (threshold_3 > threshold_1)) {
        poss_reg = TRUE;
    } else {
        poss_reg = FALSE;
    }
    if (poss_reg) {
    } else {
        EMLRTPUSHRTSTACK(&n_emlrtRSI);
        b_y = NULL;
        m0 = mxCreateString("Assertion failed.");
        emlrtAssign(&b_y, m0);
        error(b_y, &c_emlrtMCI);
        EMLRTPOPRTSTACK(&n_emlrtRSI);
    }
    /* x1 = load('ecg3.dat'); % load the ECG signal from the file */
    /*  figure(30) */
    /*  plot(data); */
    /*  Signal length */
    /*  t = (0:N-1)/fs;        % time index */
    /*  NFFT = 2 ^(ceil(log2(N))); % Next power of 2 from length of the signal */
    /*  Assures that the number of samples sent in aren't greater than the */
    /*  specified sample size */
    d0 = 1.0 / (real_T)fs;
    d0 = d0 < 0.0 ? muDoubleScalarCeil(d0 - 0.5) : muDoubleScalarFloor(d0 + 0.5);
    if (d0 < 4.294967296E+9) {
        if (d0 >= 0.0) {
            qY = (uint32_T)d0;
        } else {
            qY = 0U;
        }
    } else if (d0 >= 4.294967296E+9) {
        qY = MAX_uint32_T;
    } else {
        qY = 0U;
    }
    if (qY >= sample_time) {
    } else {
        EMLRTPUSHRTSTACK(&m_emlrtRSI);
        c_y = NULL;
        m0 = mxCreateString("Assertion failed.");
        emlrtAssign(&c_y, m0);
        error(c_y, &d_emlrtMCI);
        EMLRTPOPRTSTACK(&m_emlrtRSI);
    }
    /*  UNCOMMENT TO SEE PLOT OF ORIGINAL EKG */
    /* figure(1) */
    /* sub%plot(2,1,1) */
    /* plot(t,x1) */
    /* xlabel('second');ylabel('Volts');title('Input ECG Signal') */
    /* sub%plot(2,1,2) */
    /* plot(t(200:600),x1(200:600)) */
    /* xlabel('second');ylabel('Volts');title('Input ECG Signal 1-3 second') */
    /* xlim([1 3]); */
    /* CANCELLATION DC DRIFT AND NORMALIZATION */
    /* x1 = x1 - mean (x1 );    % cancel DC conponents */
    /*  x1 = x1/ max( abs(x1 )); % normalize to one */
    if (data < 0) {
        if (data <= MIN_int32_T) {
            d_y = MAX_int32_T;
        } else {
            d_y = -data;
        }
    } else {
        d_y = data;
    }
    e_y = NULL;
    f_y = NULL;
    m0 = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int32_T *)mxGetData(m0) = d_y;
    emlrtAssign(&f_y, m0);
    emlrtAssign(&e_y, emlrtCreateFIR2009a(eml_mx, b_eml_mx, "simulinkarray", f_y, TRUE));
    emlrtDisplayR2011a(e_y, "ans");
    EMLRTPUSHRTSTACK(&l_emlrtRSI);
    if (data < 0) {
        if (data <= MIN_int32_T) {
            d_y = MAX_int32_T;
        } else {
            d_y = -data;
        }
    } else {
        d_y = data;
    }
    x1 = div_repeat_us32_sat_near(data, d_y, 10U);
    EMLRTPOPRTSTACK(&l_emlrtRSI);
    /*  normalize to one */
    /*  UNCOMMENT TO SEE PLOT OF EKG AFTER NORMALIZATION AND REMOVAL OF DC DRIFT */
    /*  UNCOMMENT TO SEE FFT OF ORIGINAL EKG */
    /* ------ MOST FILTERING NOW OCCURS IN ANALOG SEE 'front_end_filters.m' FOR EMULATED FRONT END FILTERS */
    /* LOW PASS FILTERING */
    /*  LPF (1-z^-6)^2/(1-z^-1)^2 */
    /* b=[1 0 0 0 0 0 -2 0 0 0 0 0 1]; */
    /* a=[1 -2 1]; */
    /* h_LP=filter(b,a,[1 zeros(1,12)]); % transfer function of LPF */
    /* if(shouldPlot) */
    /* figure(21) */
    /* freqz(b,a,1000,fs) */
    /* end */
    /*  x2 = conv (x1 ,h_LP); */
    /*  Fc  = 16; */
    /*  low_pass_order = 2;   % FIR filter order */
    /*  low_pass_spec = fdesign.lowpass('N,Fc',low_pass_order,Fc,fs); */
    /*  low_pass = design(low_pass_spec,'window','window',@hamming); */
    /*  x2 = filter(low_pass, x1); */
    /* x2 = x2 (6+[1: N]); %cancle delay */
    /*  x2 = x2/ max( abs(x2 )); % normalize , for convenience . */
    /*  UNCOMMENT TO SEE PLOT OF EKG AFTER BEING LOW PASSED */
    /* figure(3) */
    /* sub%plot(2,1,1) */
    /* plot([0:length(x2)-1]/fs,x2) */
    /* xlabel('second');ylabel('Volts');title(' ECG Signal after LPF') */
    /* xlim([0 max(t)]); */
    /* sub%plot(2,1,2) */
    /* plot(t(200:600),x2(200:600)) */
    /* xlabel('second');ylabel('Volts');title(' ECG Signal 1-3 second') */
    /* xlim([1 3]); */
    /*  UNCOMMENT TO SEE FFT PLOT OF EKG AFTER BEING LOW PASSED */
    /* if(shouldPlot) */
    /*  Takes the fft of the signal % */
    /* transform=fft(x2,NFFT)/N;% Transform from discrete values to the frequency domain */
    /*  Plots the fft of the filtered signal */
    /*    transform=transform; */
    /* windows=[windows,abs(transform)]; */
    /* freq = fs/2*linspace(0,1,NFFT/2+1);%Frequency index */
    /*     fprintf('Plotting\n'); */
    /* figure(4) */
    /* plot(freq,2*abs(transform(1:NFFT/2+1))); */
    /* title('FFT LP Filtered EKG Signal'); */
    /* xlabel('Frequency (Hz)'); */
    /* ylabel('|X(f)|'); */
    /* end */
    /* HIGH PASS FILTERING */
    /*  HPF = Allpass-(Lowpass) = z^-16-[(1-z^-32)/(1-z^-1)] */
    /* b = [-1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 32 -32 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1]; */
    /* a = [1 -1]; */
    /* h_HP=filter(b,a,[1 zeros(1,32)]); % impulse response iof HPF */
    /* if(shouldPlot) */
    /*      freqz(h_HP); */
    /* end */
    /*  Fc  = 5; */
    /*  high_pass_order = 2;   % FIR filter order */
    /*  high_pass_spec = fdesign.highpass('N,Fc',high_pass_order,Fc,fs); */
    /*  high_pass = design(high_pass_spec,'window','window',@hamming); */
    /* x3 = conv (x2 ,h_HP); */
    /* x3 = x3 (16+[1: N]); %cancle delay */
    /*  x3 = filter(high_pass, x2); */
    /*  x3 = x3/ max( abs(x3 )); */
    /*  UNCOMMENT TO SEE PLOT OF EKG AFTER BEING HIGH PASSED */
    /* figure(5) */
    /* sub%plot(2,1,1) */
    /* plot([0:length(x3)-1]/fs,x3) */
    /* xlabel('second');ylabel('Volts');title(' ECG Signal after HPF') */
    /* xlim([0 max(t)]); */
    /* sub%plot(2,1,2) */
    /* plot(t(200:600),x3(200:600)) */
    /* xlabel('second');ylabel('Volts');title(' ECG Signal 1-3 second') */
    /* xlim([1 3]); */
    /*  UNCOMMENT TO SEE FFT PLOT OF EKG AFTER BEING HIGH PASSED */
    /* if(shouldPlot) */
    /*  Takes the fft of the signal % */
    /* transform=fft(x3,NFFT)/N;% Transform from discrete values to the frequency domain */
    /*  Plots the fft of the filtered signal */
    /*   transform=transform; */
    /* windows=[windows,abs(transform)]; */
    /* freq = fs/2*linspace(0,1,NFFT/2+1);%Frequency index */
    /* fprintf('Plotting\n'); */
    /* figure(6) */
    /* plot(freq,2*abs(transform(1:NFFT/2+1))); */
    /* title('FFT HP Filtered EKG Signal'); */
    /* xlabel('Frequency (Hz)'); */
    /* ylabel('|X(f)|'); */
    /* end */
    /* DERIVATIVE FILTER */
    /*  Make impulse response */
    /* h = [-1 -2 0 2 1]/8; */
    /*  Apply filter */
    /* x4 = conv (x1 ,h); */
    /* x4 = x4 (2+ (1: N)); */
    /* x4 = x4/ max( abs(x4 )); */
    /*  UNCOMMENT TO SEE PLOT OF EKG AFTER BEING A DERIVATIVE FILTER IS APPLIED */
    /* figure(7) */
    /* subplot(2,1,1) */
    /* plot([0:length(x4)-1]/fs,x4) */
    /* xlabel('second');ylabel('Volts');title(' ECG Signal after Derivative') */
    /* subplot(2,1,2) */
    /* plot(t(200:600),x4(200:600)) */
    /* xlabel('second');ylabel('Volts');title(' ECG Signal 1-3 second') */
    /* xlim([1 3]); */
    /* SQUARING */
    qY = mul_u32_u32_u32_sat(x1, x1);
    x5 = (qY >> 10) + ((qY & 512U) != 0U);
    /* assert(isequal(numerictype(x5),Fixed_Point_Properties) && isequal(fimath(x5), F)); */
    /* x5 = mpower(x1, 2); */
    /* x5 = x5/ max( abs(x5 )); */
    EMLRTPUSHRTSTACK(&k_emlrtRSI);
    x5 = div_repeat_u32_sat_near(x5, x5, 10U);
    EMLRTPOPRTSTACK(&k_emlrtRSI);
    /*  normalize to one */
    /*  figure(24) */
    /*  plot(x5); */
    /*  assert(isequal(numerictype(x5),Fixed_Point_Properties) && isequal(fimath(x5), F)); */
    /*  UNCOMMENT TO SEE PLOT OF EKG AFTER SQUARING */
    /* MOVING WINDOW INTEGRATION */
    /*  Make impulse response */
    /*  Delay = 15; % Delay in samples */
    /*  Apply filter */
    for (i = 0; i < 31; i++) {
        qY = mul_u32_u32_u32_sr26_sat_near(x5, 2216757314U);
        x6[i] = (qY >> 10) + ((qY & 512U) != 0U);
    }
    /*  Normalizes the signal  */
    /*  x6 = x6 / max( abs(x6 )); */
    EMLRTPUSHRTSTACK(&j_emlrtRSI);
    x5 = x6[15];
    x5 = div_repeat_u32_sat_near(x6[15], x5, 10U);
    EMLRTPOPRTSTACK(&j_emlrtRSI);
    /*  normalize to one */
    /*  figure(25) */
    /*  plot(x6); */
    /*  UNCOMMENT TO SEE PLOT OF EKG AFTER A MWI IS APPLIED */
    /* FIND QRS POINTS. NOTE: THE PEAK FINDING IS DIFFERENT THAN PAN-TOMPKINS ALGORITHM */
    /* figure(7) */
    /* subplot(2,1,1) */
    /*  Outputs an array with each value indicating whether the value at that */
    /*  index is greater than thresh * max_h */
    uLong2MultiWord(x5, &r0.chunks[0U], 2);
    uMultiWordShl(&r0.chunks[0U], 2, 10U, &r1.chunks[0U], 2);
    MultiWordUnsignedWrap(&r1.chunks[0U], 2, 22U, &r2.chunks[0U]);
    uLong2MultiWord(mul_u32_u32_u32_sat(x5, x5), &r0.chunks[0U], 2);
    MultiWordUnsignedWrap(&r0.chunks[0U], 2, 22U, &r1.chunks[0U]);
    poss_reg = uMultiWordGt(&r2.chunks[0U], &r1.chunks[0U], 2);
    /*  UNCOMMENT TO SEE PLOT OF EKG AFTER BEING INTEGRATED? */
    /* figure (10) */
    /* subplot(2,1,1) */
    /* hold on */
    /* plot (t(200:600),x1(200:600)/max(x1)) */
    /* box on */
    /* xlabel('second');ylabel('Integrated') */
    /* xlim([1 3]); */
    /* subplot(2,1,2) */
    /* plot (t(200:600),x6(200:600)/max(x6)) */
    /* xlabel('second');ylabel('Integrated') */
    /* xlim([1 3]); */
    /*   Finds(the indices) all the heart beats which are preceded by a non-beat */
    if (poss_reg == 1) {
        ii_sizes_idx_0 = 1;
        ii_sizes_idx_1 = 1;
    } else {
        ii_sizes_idx_0 = 0;
        ii_sizes_idx_1 = 0;
    }
    left_sizes_idx_0 = ii_sizes_idx_0;
    left_sizes_idx_1 = ii_sizes_idx_1;
    /*  Gets all the indices in the resultant diff vector for which X[n] - X[n-1] = 1 */
    /*  Finds all the heart beats where  the heart beats are proceeded by a */
    /*  non-beat */
    /* left(1:10); */
    if (-poss_reg == -1) {
        ii_sizes_idx_0 = 1;
        ii_sizes_idx_1 = 1;
    } else {
        ii_sizes_idx_0 = 0;
        ii_sizes_idx_1 = 0;
    }
    /* left=left-(6+16);  % cancel delay because of LP and HP */
    /* right=right-(6+16);% cancel delay because of LP and HP */
    R_value_sizes[0] = 1;
    R_value_sizes[1] = left_sizes_idx_1;
    loop_ub = left_sizes_idx_1 - 1;
    i = 0;
    while (i <= loop_ub) {
        R_value_data[0] = 0U;
        i = 1;
    }
    loop_ub = left_sizes_idx_1 - 1;
    i = 0;
    while (i <= loop_ub) {
        R_loc_data[0] = 0;
        i = 1;
    }
    if ((left_sizes_idx_0 == 0) || (left_sizes_idx_1 == 0)) {
        d_y = -1;
    } else {
        d_y = 0;
    }
    i = 0;
    while (i <= d_y) {
        emlrtDynamicBoundsCheck(1, 1, left_sizes_idx_0 * left_sizes_idx_1, &x_emlrtBCI);
        emlrtDynamicBoundsCheck(1, 1, ii_sizes_idx_0 * ii_sizes_idx_1, &w_emlrtBCI);
        EMLRTPUSHRTSTACK(&i_emlrtRSI);
        tmp_sizes[0] = 1;
        tmp_sizes[1] = 1;
        x1_data[0] = x1;
        b_max(x1_data, tmp_sizes, &qY, &d0);
        EMLRTPOPRTSTACK(&i_emlrtRSI);
        emlrtDynamicBoundsCheck(1, 1, R_value_sizes[1], &r_emlrtBCI);
        R_value_data[0] = qY;
        emlrtDynamicBoundsCheck(1, 1, left_sizes_idx_1, &v_emlrtBCI);
        R_loc_data[0] = 1;
        emlrtDynamicBoundsCheck(1, 1, left_sizes_idx_1, &s_emlrtBCI);
        emlrtDynamicBoundsCheck(1, 1, left_sizes_idx_1, &u_emlrtBCI);
        emlrtDynamicBoundsCheck(1, 1, left_sizes_idx_0 * left_sizes_idx_1, &t_emlrtBCI);
        R_loc_data[0] = 1;
        /*  add offset */
        /*      [Q_value(i) Q_loc(i)] = min( x1(left(i):R_loc(i)) ); */
        /*      Q_loc(i) = Q_loc(i)-1+left(i); % add offset */
        /*      [S_value(i) S_loc(i)] = min( x1(left(i):right(i)) ); */
        /*      S_loc(i) = S_loc(i)-1+left(i); % add offset */
        i = 1;
        emlrtBreakCheck();
    }
    /*  there is no selective wave */
    EMLRTPUSHRTSTACK(&h_emlrtRSI);
    R_loc_sizes[0] = 1;
    R_loc_sizes[1] = left_sizes_idx_1;
    loop_ub = left_sizes_idx_1 - 1;
    i = 0;
    while (i <= loop_ub) {
        b_R_loc_data[0] = (R_loc_data[0] != 0);
        i = 1;
    }
    eml_li_find(b_R_loc_data, R_loc_sizes, tmp_data, tmp_sizes);
    loop_ub = tmp_sizes[1] - 1;
    for (i = 0; i <= loop_ub; i++) {
        c_R_loc_data[i] = R_loc_data[emlrtDynamicBoundsCheck(tmp_data[tmp_sizes[0] * i], 1, left_sizes_idx_1, &y_emlrtBCI) - 1];
    }
    loop_ub = tmp_sizes[1] - 1;
    for (i = 0; i <= loop_ub; i++) {
        R_loc_data[i] = c_R_loc_data[i];
    }
    EMLRTPOPRTSTACK(&h_emlrtRSI);
    /*  Q_loc=Q_loc(find(Q_loc~=0)); */
    /*  S_loc=S_loc(find(S_loc~=0)); */
    /*  UNCOMMENT TO SEE RESULTS OF THE QRS DETECTION */
    /* figure(11) */
    /* subplot(2,1,1) */
    /* title('ECG Signal with R points'); */
    /* plot (t,x1/max(x1) , t(R_loc) ,R_value , 'r^', t(S_loc) ,S_value, '*',t(Q_loc) , Q_value, 'o'); */
    /* legend('ECG','R','S','Q'); */
    /* subplot(2,1,2) */
    /* plot (t,x1/max(x1) , t(R_loc) ,R_value , 'r^', t(S_loc) ,S_value, '*',t(Q_loc) , Q_value, 'o'); */
    /* xlim([1 3]); */
    /*  VITASIGN'S CODE BELOW */
    /*  Level 1 Detection: Detects all peaks  */
    loop_ub = R_value_sizes[1] - 1;
    i = 0;
    while (i <= loop_ub) {
        R_peak_vals_data[0] = R_value_data[0];
        i = 1;
    }
    /*  Level 2 Detection: Uses two channels to detect heart beats based on two threshold */
    /*  [num_rows_vals, num_cols_vals] = size(R_peak_vals); */
    /*  Creates a copy of the indices which store the indices where the 'R' peaks */
    /*  lie */
    /*  NEEDS OPTIMIZATION. NEED TO AVOID COPYING LARGE ARRAYS  */
    if (1 > tmp_sizes[1]) {
        i = -1;
    } else {
        i = 0;
    }
    if (1 > tmp_sizes[1]) {
        d_y = -1;
    } else {
        d_y = 0;
    }
    if (1 > tmp_sizes[1]) {
        ii_sizes_idx_1 = -1;
    } else {
        ii_sizes_idx_1 = 0;
    }
    loop_ub = ii_sizes_idx_1;
    ii_sizes_idx_0 = 0;
    while (ii_sizes_idx_0 <= loop_ub) {
        R_peak_indices_combined_data[0] = (uint32_T)R_loc_data[0];
        ii_sizes_idx_0 = 1;
    }
    /*  REPLACE THIS WITH A ZEROS ARRAY */
    /*  UNCOMMENT TO SEE THE NUMBER OF PEAKS BEFORE CHANNEL 1 PROCESSING */
    EMLRTPUSHRTSTACK(&g_emlrtRSI);
    R_peak_indices_channel_1_sizes[0] = 1;
    R_peak_indices_channel_1_sizes[1] = i + 1;
    loop_ub = i;
    i = 0;
    while (i <= loop_ub) {
        i = (int32_T)R_loc_data[0];
        i = (int32_T)(real32_T)muDoubleScalarFloor((real_T)i + 0.5);
        R_peak_indices_channel_1_data[0] = (uint32_T)i;
        i = 1;
    }
    dualThreshold(R_value_data, R_value_sizes, threshold_1, R_peak_indices_channel_1_data, R_peak_indices_channel_1_sizes, x5, pos_deviance_threshold, neg_deviance_threshold, &noise_lvl_channel_1, &signal_lvl_channel_1);
    EMLRTPOPRTSTACK(&g_emlrtRSI);
    EMLRTPUSHRTSTACK(&f_emlrtRSI);
    R_peak_indices_channel_2_sizes[0] = 1;
    R_peak_indices_channel_2_sizes[1] = d_y + 1;
    loop_ub = d_y;
    i = 0;
    while (i <= loop_ub) {
        i = (int32_T)R_loc_data[0];
        i = (int32_T)(real32_T)muDoubleScalarFloor((real_T)i + 0.5);
        R_peak_indices_channel_2_data[0] = (uint32_T)i;
        i = 1;
    }
    dualThreshold(R_value_data, R_value_sizes, threshold_2, R_peak_indices_channel_2_data, R_peak_indices_channel_2_sizes, x5, pos_deviance_threshold, neg_deviance_threshold, &noise_lvl_channel_2, &signal_lvl_channel_2);
    EMLRTPOPRTSTACK(&f_emlrtRSI);
    /*  Ensures that noise and signal levels are fixed point */
    /*  UNCOMMENT TO SEE THE NUMBER OF PEAKS AFTER CHANNEL 1 PROCESSING */
    /*  UNCOMMENT TO SEE PLOT OF EKG AFTER BEING PASSED THROUGH THE FIRST CHANNEL */
    /*  UNCOMMENT TO SEE PLOT OF EKG AFTER BEING PASSED THROUGH THE SECOND CHANNEL */
    /*  Level 3 DETECTION: REFINES HEART BEAT DETECTION ACCURACY BY CHANNEL */
    /*  COMPARISON */
    /*  UNCOMMENT TO SEE THE NUMBER OF PEAKS BEFORE LEVEL 3 PROCESSING */
    /* if (shouldPlot) */
    /*     fprintf('\nCombined Original: There are %i non-zero values\n',length(find(R_peak_indices_combined ~= 0))); */
    /* end */
    /*  Combines both channels to refine beat detection */
    i = 0;
    while (i <= ii_sizes_idx_1) {
        /*  Documents the other cases % */
        /*  If the signal's amplitude passes both the channels then there is a */
        /*  high chance of a beat */
        /* if (R_peak_indices_channel_1(i) ~= 0 && R_peak_indices_channel_2(i) ~=0) */
        /*  If the signal's amplitude is less than channel 1's threshold(the */
        /*  lower threshold) and higher than channel 2's threshold(the higher */
        /*  threshold) then there's a chance that there is a beat */
        /* This case will not happen b/c channel 1's threshold is < channel's 2 threshold */
        /* if (R_peak_indices_channel_1(i) == 0 && R_peak_indices_channel_2(i) ~=0)    */
        /*  If the signal's amplitude fails both the channels then there is a */
        /*  high chance that the it's not a beat */
        emlrtDynamicBoundsCheck(1, 1, R_peak_indices_channel_1_sizes[1], &q_emlrtBCI);
        guard2 = FALSE;
        if (R_peak_indices_channel_1_data[0] == 0U) {
            emlrtDynamicBoundsCheck(1, 1, R_peak_indices_channel_2_sizes[1], &p_emlrtBCI);
            if (R_peak_indices_channel_2_data[0] == 0U) {
                emlrtDynamicBoundsCheck(1, 1, ii_sizes_idx_1 + 1, &o_emlrtBCI);
                R_peak_indices_combined_data[0] = 0U;
            } else {
                guard2 = TRUE;
            }
        } else {
            guard2 = TRUE;
        }
        if (guard2 == TRUE) {
            emlrtDynamicBoundsCheck(1, 1, R_peak_indices_channel_1_sizes[1], &n_emlrtBCI);
            if (R_peak_indices_channel_1_data[0] != 0U) {
                emlrtDynamicBoundsCheck(1, 1, R_peak_indices_channel_2_sizes[1], &m_emlrtBCI);
                if (R_peak_indices_channel_2_data[0] == 0U) {
                    /*  DELETE DEBUGGING */
                    /* if (shouldPlot) */
                    /*    fprintf('The peak val is: %f\n',R_peak_vals(i)); */
                    /* end */
                    /*  Uses the decision of the channel w/ the highest Detection. */
                    /*  Ensures that Ds is between 0 and 1 */
                    /*  strength(Ds) */
                    /*          signal_lvl_channel_1 */
                    /*          noise_lvl_channel_1 */
                    /*            fprintf('In here'); */
                    /*            diff1 = ((R_peak_vals(i) - noise_lvl_channel_1) * 100) / (signal_lvl_channel_1 - noise_lvl_channel_1) */
                    /*            diff2 = ((R_peak_vals(i) - noise_lvl_channel_2) * 100) / (signal_lvl_channel_2 - noise_lvl_channel_2) */
                    /*          minlog(diff1) */
                    /*          minlog(diff2) */
                    emlrtDynamicBoundsCheck(1, 1, R_value_sizes[1], &l_emlrtBCI);
                    EMLRTPUSHRTSTACK(&e_emlrtRSI);
                    EMLRTPUSHRTSTACK(&bb_emlrtRSI);
                    EMLRTPUSHRTSTACK(&cb_emlrtRSI);
                    x1 = R_value_data[0];
                    qY = x1 - noise_lvl_channel_1;
                    if (qY > x1) {
                        qY = 0U;
                    }
                    x5 = signal_lvl_channel_1 - noise_lvl_channel_1;
                    if (x5 > signal_lvl_channel_1) {
                        x5 = 0U;
                    }
                    qY = div_u32_near(mul_u32_u32_u32_sr15_sat_near(qY, 3355443200U), x5);
                    EMLRTPOPRTSTACK(&cb_emlrtRSI);
                    EMLRTPOPRTSTACK(&bb_emlrtRSI);
                    if (1024U > qY) {
                        d_y = (int32_T)qY;
                    } else {
                        d_y = 1024;
                    }
                    EMLRTPOPRTSTACK(&e_emlrtRSI);
                    emlrtDynamicBoundsCheck(1, 1, R_value_sizes[1], &k_emlrtBCI);
                    EMLRTPUSHRTSTACK(&d_emlrtRSI);
                    x1 = R_value_data[0];
                    qY = x1 - noise_lvl_channel_2;
                    if (qY > x1) {
                        qY = 0U;
                    }
                    x5 = signal_lvl_channel_2 - noise_lvl_channel_2;
                    if (x5 > signal_lvl_channel_2) {
                        x5 = 0U;
                    }
                    x5 = mrdivide(mul_u32_u32_u32_sr15_sat_near(qY, 3355443200U), x5);
                    if (1024U > x5) {
                        ii_sizes_idx_0 = (int32_T)x5;
                    } else {
                        ii_sizes_idx_0 = 1024;
                    }
                    EMLRTPOPRTSTACK(&d_emlrtRSI);
                    if ((uint32_T)d_y > (uint32_T)ii_sizes_idx_0) {
                        /* if(shouldPlot) */
                        /* fprintf('Ds1: %f Ds2: %f Ds1 wins\n', Ds_1, Ds_2); */
                        /* end */
                        emlrtDynamicBoundsCheck(1, 1, ii_sizes_idx_1 + 1, &i_emlrtBCI);
                        emlrtDynamicBoundsCheck(1, 1, R_peak_indices_channel_1_sizes[1], &j_emlrtBCI);
                        R_peak_indices_combined_data[0] = R_peak_indices_channel_1_data[0];
                    } else {
                        /* if(shouldPlot) */
                        /* fprintf('Ds1: %f Ds2: %f Ds2 wins\n', Ds_1, Ds_2); */
                        /* end */
                        emlrtDynamicBoundsCheck(1, 1, ii_sizes_idx_1 + 1, &g_emlrtBCI);
                        emlrtDynamicBoundsCheck(1, 1, R_peak_indices_channel_2_sizes[1], &h_emlrtBCI);
                        R_peak_indices_combined_data[0] = 0U;
                    }
                }
            }
        }
        i = 1;
        emlrtBreakCheck();
    }
    /*  UNCOMMENT TO SEE THE NUMBER OF PEAKS AFTER LEVEL 3 PROCESSING */
    /*  Grabs the result of both channels     */
    /*  UNCOMMENT TO SEE THE NUMBER OF PEAKS AFTER LEVEL 4 PROCESSING */
    /* if (shouldPlot) */
    /*     fprintf('\n4th level Original: There are %i non-zero values\n',length(find(R_peak_indices_channel_3 ~= 0))); */
    /* end */
    /*  UNCOMMENT TO USE LEVEL 4 PROCESSING  */
    /* [R_peak_indices_channel_3, noise_lvl_channel_3, signal_lvl_channel_3] = fourth_level_process(threshold_3, R_peak_indices_channel_3); */
    /* if (shouldPlot) */
    /*     fprintf('4th level Post: There are %i non-zero values\n',length(find(R_peak_indices_channel_3 ~= 0))); */
    /* end */
    /*  Sets R values to zero which failed any of the previous phases */
    x5 = 0U;
    i = 0;
    while (i <= R_value_sizes[1] - 1) {
        emlrtDynamicBoundsCheck(1, 1, ii_sizes_idx_1 + 1, &f_emlrtBCI);
        if (R_peak_indices_combined_data[0] == 0U) {
            emlrtDynamicBoundsCheck(1, 1, R_value_sizes[1], &e_emlrtBCI);
            R_peak_vals_data[0] = 0U;
            /*  Level 5 Detection: Refines heart beat detection by considering a heart */
            /*  beat's refactory period  */
        } else {
            /*  Filters out any R_values which happen too soon after a previous */
            /*  beat detection */
            emlrtDynamicBoundsCheck(1, 1, ii_sizes_idx_1 + 1, &d_emlrtBCI);
            guard1 = FALSE;
            if (x5 != 0U) {
                d0 = (real_T)R_peak_indices_combined_data[0] * 1024.0;
                d0 = muDoubleScalarFloor(d0 + 0.5);
                if (d0 < 4.294967296E+9) {
                    x1 = (uint32_T)d0;
                } else {
                    x1 = MAX_uint32_T;
                }
                qY = x1 - 1024U;
                if (qY > x1) {
                    qY = 0U;
                }
                qY = mul_u32_u32_u32_sat(qY, 3U);
                x1 = (qY >> 10) + ((qY & 512U) != 0U);
                qY = x5 - 1024U;
                if (qY > x5) {
                    qY = 0U;
                }
                qY = mul_u32_u32_u32_sat(qY, 3U);
                qY = (x1 - (qY >> 10)) - ((qY & 512U) != 0U);
                if (qY > x1) {
                    qY = 0U;
                }
                if (qY < 205U) {
                    /* fprintf('Getting rid of a value\n'); */
                    emlrtDynamicBoundsCheck(1, 1, R_value_sizes[1], &c_emlrtBCI);
                    R_peak_vals_data[0] = 0U;
                    emlrtDynamicBoundsCheck(1, 1, ii_sizes_idx_1 + 1, &b_emlrtBCI);
                    R_peak_indices_combined_data[0] = 0U;
                    /*  Updates the last index if the R_value is valid */
                } else {
                    guard1 = TRUE;
                }
            } else {
                guard1 = TRUE;
            }
            if (guard1 == TRUE) {
                /*  Updates the last index */
                emlrtDynamicBoundsCheck(1, 1, ii_sizes_idx_1 + 1, &emlrtBCI);
                d0 = (real_T)R_peak_indices_combined_data[0] * 1024.0;
                d0 = muDoubleScalarFloor(d0 + 0.5);
                if (d0 < 4.294967296E+9) {
                    x5 = (uint32_T)d0;
                } else {
                    x5 = MAX_uint32_T;
                }
            }
        }
        i = 1;
        emlrtBreakCheck();
    }
    /*  Removes all zero values from both the indice and value array */
    EMLRTPUSHRTSTACK(&c_emlrtRSI);
    R_peak_indices_combined_sizes[0] = 1;
    R_peak_indices_combined_sizes[1] = ii_sizes_idx_1 + 1;
    loop_ub = ii_sizes_idx_1;
    i = 0;
    while (i <= loop_ub) {
        b_R_loc_data[0] = (R_peak_indices_combined_data[0] != 0U);
        i = 1;
    }
    eml_li_find(b_R_loc_data, R_peak_indices_combined_sizes, tmp_data, tmp_sizes);
    d_y = tmp_sizes[1];
    loop_ub = tmp_sizes[1] - 1;
    for (i = 0; i <= loop_ub; i++) {
        emlrtDynamicBoundsCheck(tmp_data[tmp_sizes[0] * i], 1, ii_sizes_idx_1 + 1, &ab_emlrtBCI);
    }
    EMLRTPOPRTSTACK(&c_emlrtRSI);
    EMLRTPUSHRTSTACK(&b_emlrtRSI);
    R_peak_vals_sizes[0] = 1;
    R_peak_vals_sizes[1] = R_value_sizes[1];
    loop_ub = R_value_sizes[1] - 1;
    i = 0;
    while (i <= loop_ub) {
        b_R_loc_data[0] = (R_peak_vals_data[0] != 0U);
        i = 1;
    }
    eml_li_find(b_R_loc_data, R_peak_vals_sizes, tmp_data, tmp_sizes);
    loop_ub = tmp_sizes[0] * tmp_sizes[1] - 1;
    for (i = 0; i <= loop_ub; i++) {
        emlrtDynamicBoundsCheck(tmp_data[i], 1, R_value_sizes[1], &bb_emlrtBCI);
    }
    EMLRTPOPRTSTACK(&b_emlrtRSI);
    /* plots R peaks after all level processing */
    /* xlim([1 3]); */
    /* plot (t(R_peak_indices_channel_3) ,R_peak_vals, 'r^'); */
    /* plot (t,x1/max(x1) , t(R_loc) ,R_value , 'r^', t(S_loc) ,S_value, '*',t(Q_loc) , Q_value, 'o'); */
    /* xlabel('Seconds'); ylabel('Normalized Magnitude');title('R peaks'); */
    /* %plot(R_peak_vals, 'r+'); */
    /*  CALCULATES HEART RATE */
    /*  NOTE: This will assume that only 1-min windows of the EKG are sent in as */
    /*  the data type */
    x5 = 0U;
    /*  Counts how many R peak counts are found in N seconds */
    i = 0;
    while (i <= d_y - 1) {
        /*  Counts how many R wave peaks are found in a  */
        qY = x5 + 1024U;
        if (qY < x5) {
            qY = MAX_uint32_T;
        }
        x5 = qY;
        i = 1;
        emlrtBreakCheck();
    }
    /*  R_peak_count */
    EMLRTPUSHRTSTACK(&emlrtRSI);
    EMLRTPUSHRTSTACK(&fb_emlrtRSI);
    EMLRTPUSHRTSTACK(&gb_emlrtRSI);
    EMLRTPOPRTSTACK(&gb_emlrtRSI);
    EMLRTPOPRTSTACK(&fb_emlrtRSI);
    heart_rate = mul_u32_u32_u32_sr16_sat_near(div_u32_near(x5, sample_time), 4026531840U);
    EMLRTPOPRTSTACK(&emlrtRSI);
    return heart_rate;
}
/* End of code generation (heart_rate_official_cport.c) */
