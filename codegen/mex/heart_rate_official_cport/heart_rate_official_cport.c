/*
 * heart_rate_official_cport.c
 *
 * Code generation for function 'heart_rate_official_cport'
 *
 * C source code generated on: Mon Jan 14 13:44:05 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "max.h"
#include "mrdivide1.h"
#include "diff.h"
#include "heart_rate_official_cport_mexutil.h"
#include "heart_rate_official_cport_data.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 567, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo b_emlrtRSI = { 525, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo c_emlrtRSI = { 524, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo d_emlrtRSI = { 470, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo e_emlrtRSI = { 468, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo f_emlrtRSI = { 362, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo g_emlrtRSI = { 361, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo h_emlrtRSI = { 322, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo i_emlrtRSI = { 311, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo j_emlrtRSI = { 257, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo k_emlrtRSI = { 232, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo l_emlrtRSI = { 79, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo m_emlrtRSI = { 63, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo n_emlrtRSI = { 63, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo o_emlrtRSI = { 58, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo p_emlrtRSI = { 53, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo q_emlrtRSI = { 49, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo t_emlrtRSI = { 22, "mrdivide", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/fixedpoint/@embedded/@fi/mrdivide.m" };
static emlrtRSInfo u_emlrtRSI = { 49, "rdivide", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/fixedpoint/@embedded/@fi/rdivide.m" };
static emlrtRSInfo v_emlrtRSI = { 22, "mrdivide", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/fixedpoint/@embedded/@fi/mrdivide.m" };
static emlrtRSInfo w_emlrtRSI = { 49, "rdivide", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/fixedpoint/@embedded/@fi/rdivide.m" };
static emlrtRSInfo bb_emlrtRSI = { 11, "eml_li_find", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/eml/eml_li_find.m" };
static emlrtRSInfo cb_emlrtRSI = { 14, "eml_li_find", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/eml/eml_li_find.m" };
static emlrtRSInfo db_emlrtRSI = { 670, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo eb_emlrtRSI = { 661, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo fb_emlrtRSI = { 649, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo gb_emlrtRSI = { 640, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo hb_emlrtRSI = { 617, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtRSInfo ib_emlrtRSI = { 591, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtMCInfo b_emlrtMCI = { 49, 1, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtMCInfo c_emlrtMCI = { 53, 1, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtMCInfo d_emlrtMCI = { 63, 1, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtMCInfo g_emlrtMCI = { 14, 5, "eml_li_find", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/eml/eml_li_find.m" };
static emlrtMCInfo h_emlrtMCI = { 617, 9, "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m" };
static emlrtBCInfo emlrtBCI = { -1, -1, 519, 28, "R_peak_indices_channel_3", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo b_emlrtBCI = { -1, -1, 515, 13, "R_peak_indices_channel_3", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo c_emlrtBCI = { -1, -1, 514, 13, "R_peak_vals", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo d_emlrtBCI = { 1, 1, 512, 35, "t", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo e_emlrtBCI = { -1, -1, 511, 27, "R_peak_indices_channel_3", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo f_emlrtBCI = { -1, -1, 505, 9, "R_peak_vals", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo g_emlrtBCI = { -1, -1, 504, 9, "R_peak_indices_channel_3", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo h_emlrtBCI = { -1, -1, 482, 13, "R_peak_indices_combined", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo i_emlrtBCI = { -1, -1, 482, 42, "R_peak_indices_channel_2", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo j_emlrtBCI = { -1, -1, 477, 13, "R_peak_indices_combined", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo k_emlrtBCI = { -1, -1, 477, 42, "R_peak_indices_channel_1", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo l_emlrtBCI = { -1, -1, 470, 24, "R_peak_vals", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo m_emlrtBCI = { -1, -1, 468, 24, "R_peak_vals", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo n_emlrtBCI = { -1, -1, 460, 49, "R_peak_indices_channel_2", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo o_emlrtBCI = { -1, -1, 460, 13, "R_peak_indices_channel_1", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo p_emlrtBCI = { -1, -1, 459, 9, "R_peak_indices_combined", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo q_emlrtBCI = { -1, -1, 458, 45, "R_peak_indices_channel_2", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo r_emlrtBCI = { -1, -1, 458, 9, "R_peak_indices_channel_1", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo s_emlrtBCI = { -1, -1, 311, 6, "R_value", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo t_emlrtBCI = { -1, -1, 312, 5, "R_loc", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo u_emlrtBCI = { -1, -1, 312, 27, "left", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo v_emlrtBCI = { -1, -1, 312, 16, "R_loc", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo w_emlrtBCI = { -1, -1, 311, 17, "R_loc", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo x_emlrtBCI = { -1, -1, 311, 45, "right", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo y_emlrtBCI = { -1, -1, 311, 37, "left", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo ab_emlrtBCI = { -1, -1, 322, 7, "R_loc", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo bb_emlrtBCI = { -1, -1, 524, 28, "R_peak_indices_channel_3", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo cb_emlrtBCI = { -1, -1, 525, 15, "R_peak_vals", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtDCInfo emlrtDCI = { 17, 37, "eml_li_find", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/eml/eml_li_find.m", 4 };
static emlrtBCInfo db_emlrtBCI = { -1, -1, 27, 12, "", "eml_li_find", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/eml/eml_li_find.m", 0 };
static emlrtBCInfo eb_emlrtBCI = { -1, -1, 28, 13, "", "eml_li_find", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/eml/eml_li_find.m", 0 };
static emlrtBCInfo fb_emlrtBCI = { -1, -1, 40, 12, "", "eml_li_find", "/usr/local/MATLAB/R2011b/toolbox/eml/lib/matlab/eml/eml_li_find.m", 0 };
static emlrtBCInfo gb_emlrtBCI = { -1, -1, 635, 16, "R_peak_vals", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo hb_emlrtBCI = { -1, -1, 640, 46, "R_peak_vals", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo ib_emlrtBCI = { -1, -1, 645, 45, "R_peak_vals", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo jb_emlrtBCI = { -1, -1, 657, 42, "R_peak_vals", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo kb_emlrtBCI = { -1, -1, 666, 41, "R_peak_vals", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo lb_emlrtBCI = { -1, -1, 664, 16, "indices", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };
static emlrtBCInfo mb_emlrtBCI = { -1, -1, 643, 20, "indices", "heart_rate_official_cport", "/home/iventio/vitasign/heart_rate_official_cport.m", 0 };

/* Function Declarations */
static void MultiWordUnsignedWrap(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[]);
static uint32_T div_repeat_u32_sat_near(uint32_T numerator, uint32_T denominator, uint32_T nRepeatSub);
static void dualThreshold(const uint32_T R_peak_vals_data[1], const int32_T R_peak_vals_sizes[2], uint32_T threshold, real_T indices_data[1], int32_T indices_sizes[2], uint32_T max_voltage, uint32_T pos_deviance_threshold, uint32_T neg_deviance_threshold, uint32_T *noise_lvl, uint32_T *signal_lvl);
static void eml_li_find(const boolean_T x_data[1], const int32_T x_sizes[2], int32_T y_data[1], int32_T y_sizes[2]);
static void error(const mxArray *b, emlrtMCInfo *location);
static uint32_T mul_u32_u32_u32_sr10_sat_near(uint32_T a, uint32_T b);
static uint32_T mul_u32_u32_u32_sr16_sat_near(uint32_T a, uint32_T b);
static uint32_T mul_u32_u32_u32_sr36_near(uint32_T a, uint32_T b);
static void mul_wide_u32(uint32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi, uint32_T *ptrOutBitsLo);
static void uLong2MultiWord(uint32_T u, uint32_T y[], int32_T n);
static int32_T uMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int32_T n);
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

static void dualThreshold(const uint32_T R_peak_vals_data[1], const int32_T R_peak_vals_sizes[2], uint32_T threshold, real_T indices_data[1], int32_T indices_sizes[2], uint32_T max_voltage, uint32_T pos_deviance_threshold, uint32_T neg_deviance_threshold, uint32_T *noise_lvl, uint32_T *signal_lvl)
{
    const mxArray *y;
    const mxArray *m5;
    uint32_T noise_sum;
    uint32_T signal_sum;
    uint32_T noise_count;
    int32_T b_index;
    int32_T meets_deviance_req;
    uint32_T q0;
    uint32_T qY;
    uint64m_T r0;
    uint64m_T r1;
    uint64m_T r2;
    /* DUAL THRESHOLD PROCESSSING */
    /*  Filters out R_peaks which don't meet the threshold reqs */
    /*  Asserts that the input parameters are of fixed point */
    EMLRTPUSHRTSTACK(&hb_emlrtRSI);
    y = NULL;
    m5 = mxCreateString("Assertion failed.");
    emlrtAssign(&y, m5);
    error(y, &h_emlrtMCI);
    EMLRTPOPRTSTACK(&hb_emlrtRSI);
    /*  Asserts that input parameters are of specific fixed point parameters */
    noise_sum = 0U;
    signal_sum = 0U;
    noise_count = 0U;
    *noise_lvl = 0U;
    *signal_lvl = 0U;
    b_index = 0;
    while (0 <= R_peak_vals_sizes[1] - 1) {
        /*  DELETE AFTER DEBUGGING */
        /* if (shouldPlot && channel == 2) */
        /*     fprintf('The peak val is: %f\n',R_peak_vals(index)); */
        /* end */
        emlrtDynamicBoundsCheck((int32_T)(1.0 + (real_T)b_index), 1, R_peak_vals_sizes[1], &gb_emlrtBCI);
        if (mul_u32_u32_u32_sr16_sat_near(R_peak_vals_data[(int32_T)(1.0 + (real_T)b_index) - 1], max_voltage) > threshold) {
            /* fprintf('mv: %f. Threshold is: %f\n', R_peak_vals(index) * max_voltage, threshold); */
            /* R_peak_vals(index) */
            /*  Filters out any signal value which exceeds the allowed deviance from */
            /*  the average signal value  */
            EMLRTPUSHRTSTACK(&gb_emlrtRSI);
            emlrtDynamicBoundsCheck((int32_T)(1.0 + (real_T)b_index), 1, R_peak_vals_sizes[1], &hb_emlrtBCI);
            /*  RETURNS TRUE IF THE INPUT SIGNAL VALUE MEETS THE DEVIANCE REQS. NOTE */
            /*  THE THRESHOLD VALUE CHANGES BASED ON WHETHER DEVIANCE IS NEG OR POS */
            /*  Asserts that the input parameters are of fixed point */
            /*  Asserts that input parameters are of specific fixed point parameters */
            /* Accounts for the first signal value */
            if (*signal_lvl == 0U) {
                meets_deviance_req = 1;
            } else {
                EMLRTPUSHRTSTACK(&ib_emlrtRSI);
                EMLRTPUSHRTSTACK(&jb_emlrtRSI);
                EMLRTPUSHRTSTACK(&kb_emlrtRSI);
                EMLRTPOPRTSTACK(&kb_emlrtRSI);
                EMLRTPOPRTSTACK(&jb_emlrtRSI);
                EMLRTPOPRTSTACK(&ib_emlrtRSI);
                /*  APPLIES CHECK  */
                q0 = R_peak_vals_data[(int32_T)(1.0 + (real_T)b_index) - 1];
                qY = q0 - *signal_lvl;
                if (qY > q0) {
                    qY = 0U;
                }
                uLong2MultiWord(div_u32_near(qY, *signal_lvl), &r0.chunks[0U], 2);
                uMultiWordShl(&r0.chunks[0U], 2, 16U, &r1.chunks[0U], 2);
                MultiWordUnsignedWrap(&r1.chunks[0U], 2, 16U, &r2.chunks[0U]);
                uLong2MultiWord(pos_deviance_threshold, &r0.chunks[0U], 2);
                MultiWordUnsignedWrap(&r0.chunks[0U], 2, 16U, &r1.chunks[0U]);
                if (uMultiWordLt(&r2.chunks[0U], &r1.chunks[0U], 2)) {
                    meets_deviance_req = 1;
                } else {
                    meets_deviance_req = 0;
                }
            }
            EMLRTPOPRTSTACK(&gb_emlrtRSI);
            if (!(meets_deviance_req != 0)) {
                /* fprintf('%f, %f Does not meet the deviance threshold\n', R_peak_vals(index), signal_lvl); */
                /*  Sets all the indices which R_vals don't meet the threshold to 0 */
                indices_data[emlrtDynamicBoundsCheck((int32_T)(1.0 + (real_T)b_index), 1, indices_sizes[1], &mb_emlrtBCI) - 1] = 0.0;
                /*  Updates the average noise signal lvl */
                emlrtDynamicBoundsCheck((int32_T)(1.0 + (real_T)b_index), 1, R_peak_vals_sizes[1], &ib_emlrtBCI);
                qY = noise_sum + R_peak_vals_data[(int32_T)(1.0 + (real_T)b_index) - 1];
                if (qY < noise_sum) {
                    qY = MAX_uint32_T;
                }
                noise_sum = qY;
                qY = noise_count + 65536U;
                if (qY < noise_count) {
                    qY = MAX_uint32_T;
                }
                noise_count = qY;
                /*  Calculates the noise level */
                /*                     noise_lvl = noise_sum / noise_count; */
                EMLRTPUSHRTSTACK(&fb_emlrtRSI);
                *noise_lvl = div_repeat_u32_sat_near(noise_sum, noise_count, 16U);
                EMLRTPOPRTSTACK(&fb_emlrtRSI);
            } else {
                /*  DELETE AFTER DEBUGGING */
                /* if (shouldPlot && channel == 2) */
                /*    fprintf('The peak val is: %f\n',R_peak_vals(index)); */
                /* end */
                /*  Updates the average signal lvl */
                emlrtDynamicBoundsCheck((int32_T)(1.0 + (real_T)b_index), 1, R_peak_vals_sizes[1], &jb_emlrtBCI);
                qY = signal_sum + R_peak_vals_data[(int32_T)(1.0 + (real_T)b_index) - 1];
                if (qY < signal_sum) {
                    qY = MAX_uint32_T;
                }
                signal_sum = qY;
                /*  Calculates the signal level */
                /*                 signal_lvl = signal_sum / signal_count; */
                EMLRTPUSHRTSTACK(&eb_emlrtRSI);
                *signal_lvl = div_repeat_u32_sat_near(signal_sum, signal_sum, 16U);
                EMLRTPOPRTSTACK(&eb_emlrtRSI);
            }
        } else {
            /*  Sets all the indices which R_vals don't meet the threshold to 0 */
            indices_data[emlrtDynamicBoundsCheck((int32_T)(1.0 + (real_T)b_index), 1, indices_sizes[1], &lb_emlrtBCI) - 1] = 0.0;
            /*  Updates the average noise signal lvl */
            emlrtDynamicBoundsCheck((int32_T)(1.0 + (real_T)b_index), 1, R_peak_vals_sizes[1], &kb_emlrtBCI);
            qY = noise_sum + R_peak_vals_data[(int32_T)(1.0 + (real_T)b_index) - 1];
            if (qY < noise_sum) {
                qY = MAX_uint32_T;
            }
            noise_sum = qY;
            qY = noise_count + 65536U;
            if (qY < noise_count) {
                qY = MAX_uint32_T;
            }
            noise_count = qY;
            /*  Calculates the noise level */
            /*                 noise_lvl = noise_sum / noise_count; */
            EMLRTPUSHRTSTACK(&db_emlrtRSI);
            *noise_lvl = div_repeat_u32_sat_near(noise_sum, noise_count, 16U);
            EMLRTPOPRTSTACK(&db_emlrtRSI);
        }
        b_index++;
        emlrtBreakCheck();
    }
}

static void eml_li_find(const boolean_T x_data[1], const int32_T x_sizes[2], int32_T y_data[1], int32_T y_sizes[2])
{
    int32_T k;
    int32_T i;
    const mxArray *y;
    const mxArray *m1;
    EMLRTPUSHRTSTACK(&bb_emlrtRSI);
    k = 0;
    i = 1;
    while (i <= x_sizes[1]) {
        emlrtDynamicBoundsCheck(1, 1, x_sizes[1], &fb_emlrtBCI);
        if (x_data[0]) {
            k++;
        }
        i = 2;
    }
    EMLRTPOPRTSTACK(&bb_emlrtRSI);
    if (k <= x_sizes[1]) {
    } else {
        EMLRTPUSHRTSTACK(&cb_emlrtRSI);
        y = NULL;
        m1 = mxCreateString("Assertion failed.");
        emlrtAssign(&y, m1);
        error(y, &g_emlrtMCI);
        EMLRTPOPRTSTACK(&cb_emlrtRSI);
    }
    emlrtNonNegativeCheckR2009b((real_T)k, &emlrtDCI);
    y_sizes[0] = 1;
    y_sizes[1] = k;
    k = 1;
    i = 1;
    while (i <= x_sizes[1]) {
        emlrtDynamicBoundsCheck(1, 1, 1, &db_emlrtBCI);
        if (x_data[0]) {
            emlrtDynamicBoundsCheck(k, 1, y_sizes[1], &eb_emlrtBCI);
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

static uint32_T mul_u32_u32_u32_sr10_sat_near(uint32_T a, uint32_T b)
{
    uint32_T result;
    uint32_T u32_chi;
    boolean_T roundup;
    mul_wide_u32(a, b, &u32_chi, &result);
    roundup = ((result & 512U) != 0U);
    result = (u32_chi << 22U | result >> 10U) + (uint32_T)roundup;
    u32_chi = (u32_chi >> 10U) + (uint32_T)(roundup && (result == 0U));
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

static uint32_T mul_u32_u32_u32_sr36_near(uint32_T a, uint32_T b)
{
    uint32_T result;
    uint32_T u32_chi;
    mul_wide_u32(a, b, &u32_chi, &result);
    return (u32_chi >> 4U) + (uint32_T)((u32_chi & 8U) != 0U);
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

uint32_T heart_rate_official_cport(uint32_T data, uint32_T fs, uint32_T threshold_1, uint32_T threshold_2, uint32_T threshold_3, uint32_T pos_deviance_threshold, uint32_T neg_deviance_threshold, uint32_T sample_time, int32_T shouldPlot)
{
    uint32_T heart_rate;
    const mxArray *y;
    const mxArray *m0;
    boolean_T poss_reg;
    const mxArray *b_y;
    const mxArray *c_y;
    uint32_T x1;
    uint32_T d_y;
    uint32_T c[31];
    int32_T i;
    uint32_T x6;
    int32_T ii_sizes_idx_0;
    int32_T ii_sizes_idx_1;
    int32_T left_sizes_idx_0;
    int32_T left_sizes_idx_1;
    real_T b_poss_reg[2];
    int32_T R_value_sizes[2];
    int32_T loop_ub;
    uint32_T R_value_data[1];
    int8_T R_loc_data[1];
    int32_T last_R_index;
    uint32_T x1_data[1];
    int32_T tmp_sizes[2];
    real_T d0;
    boolean_T b_R_loc_data[1];
    int32_T R_loc_sizes[2];
    int32_T tmp_data[1];
    int8_T c_R_loc_data[1];
    uint32_T R_peak_vals_data[1];
    int8_T R_peak_indices_channel_3_data[1];
    int32_T R_peak_indices_channel_1_sizes[2];
    real_T R_peak_indices_channel_1_data[1];
    uint32_T signal_lvl_channel_1;
    uint32_T noise_lvl_channel_1;
    int32_T R_peak_indices_channel_2_sizes[2];
    real_T R_peak_indices_channel_2_data[1];
    uint32_T signal_lvl_channel_2;
    uint32_T noise_lvl_channel_2;
    boolean_T guard1 = FALSE;
    int32_T R_peak_indices_channel_3_sizes[2];
    int32_T R_peak_vals_sizes[2];
    /* TO DO - */
    /*  Uncomment the line: */
    /*  REMOVE AFTER TESTING */
    /* indices(i) = 0; */
    /* data - EKG data */
    /* fs - sampling rate */
    /* threshold_1 - threshold for filtering out peaks for channel 1 */
    /* threshold_2 - threshold for filtering out peaks for channel 2 */
    /* threshold_3 - threshold for filtering out peaks for channel 3 */
    /* sample_time - length in time(s) over which HR is estimated */
    /*  QRS Detection */
    /*  shows the effect of each filter according to Pan-Tompkins algorithm. */
    /*  Note that, the decision  algorithm is different then the mentioned algorithm. */
    /*  by Faruk UYSAL */
    /* clear all */
    /* close all */
    /* [GB] Ensures the the input args are of the correct data type */
    /*  T4 = numerictype('WordLength', 80, 'FractionLength', 40); */
    /*  F.sub(fi(3), fi(2)) */
    /*  Asserts that the input parameters are of fixed point */
    /*  Asserts that input parameters are of specific fixed point parameters */
    /*  [GB] Assures that the first threshold is less than the second threshold */
    if (threshold_1 < threshold_2) {
    } else {
        EMLRTPUSHRTSTACK(&q_emlrtRSI);
        y = NULL;
        m0 = mxCreateString("Assertion failed.");
        emlrtAssign(&y, m0);
        error(y, &b_emlrtMCI);
        EMLRTPOPRTSTACK(&q_emlrtRSI);
    }
    /*  [GB] Assures that the third threshold is in between the first and the second */
    /*  threshold */
    if ((threshold_3 < threshold_2) && (threshold_3 > threshold_1)) {
        poss_reg = TRUE;
    } else {
        poss_reg = FALSE;
    }
    if (poss_reg) {
    } else {
        EMLRTPUSHRTSTACK(&p_emlrtRSI);
        b_y = NULL;
        m0 = mxCreateString("Assertion failed.");
        emlrtAssign(&b_y, m0);
        error(b_y, &c_emlrtMCI);
        EMLRTPOPRTSTACK(&p_emlrtRSI);
    }
    /* x1 = load('ecg3.dat'); % load the ECG signal from the file */
    /*  Signal length */
    EMLRTPUSHRTSTACK(&o_emlrtRSI);
    EMLRTPUSHRTSTACK(&t_emlrtRSI);
    EMLRTPUSHRTSTACK(&u_emlrtRSI);
    EMLRTPOPRTSTACK(&u_emlrtRSI);
    EMLRTPOPRTSTACK(&t_emlrtRSI);
    EMLRTPOPRTSTACK(&o_emlrtRSI);
    /*  time index */
    /*  NFFT = 2 ^(ceil(log2(N))); %[GB] Next power of 2 from length of the signal */
    /*  Assures that the number of samples sent in aren't greater than the */
    /*  specified sample size */
    EMLRTPUSHRTSTACK(&n_emlrtRSI);
    EMLRTPUSHRTSTACK(&v_emlrtRSI);
    EMLRTPUSHRTSTACK(&w_emlrtRSI);
    EMLRTPOPRTSTACK(&w_emlrtRSI);
    EMLRTPOPRTSTACK(&v_emlrtRSI);
    EMLRTPOPRTSTACK(&n_emlrtRSI);
    if (div_repeat_u32_sat_near(2147483648U, fs, 1U) >= sample_time) {
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
    /*  cancel DC conponents */
    /*  x1 = x1/ max( abs(x1 )); % normalize to one */
    EMLRTPUSHRTSTACK(&l_emlrtRSI);
    x1 = div_u32_near(0U, 0U);
    EMLRTPOPRTSTACK(&l_emlrtRSI);
    /*  normalize to one */
    /*  UNCOMMENT TO SEE PLOT OF EKG AFTER NORMALIZATION AND REMOVAL OF DC DRIFT */
    /* figure(3) */
    /* sub%plot(2,1,1) */
    /* plot(t,x1) */
    /* xlabel('second');ylabel('Volts');title(' ECG Signal after cancellation DC drift and normalization') */
    /* sub%plot(2,1,2) */
    /* plot(t(200:600),x1(200:600)) */
    /* xlabel('second');ylabel('Volts');title(' ECG Signal 1-3 second') */
    /* xlim([1 3]); */
    /*  UNCOMMENT TO SEE FFT OF ORIGINAL EKG */
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
    /* transform=fft(x2,NFFT)/N;%[GB] Transform from discrete values to the frequency domain */
    /*  Plots the fft of the filtered signal */
    /*    transform=transform; */
    /* windows=[windows,abs(transform)]; */
    /* freq = fs/2*linspace(0,1,NFFT/2+1);%[GB]Frequency index */
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
    /* transform=fft(x3,NFFT)/N;%[GB] Transform from discrete values to the frequency domain */
    /*  Plots the fft of the filtered signal */
    /*   transform=transform; */
    /* windows=[windows,abs(transform)]; */
    /* freq = fs/2*linspace(0,1,NFFT/2+1);%[GB]Frequency index */
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
    d_y = mul_u32_u32_u32_sr16_sat_near(x1, x1);
    /*  x5 = mpower(x1, 2); */
    /*  x5 = x5/ max( abs(x5 )); */
    EMLRTPUSHRTSTACK(&k_emlrtRSI);
    d_y = div_repeat_u32_sat_near(d_y, d_y, 16U);
    EMLRTPOPRTSTACK(&k_emlrtRSI);
    /*  normalize to one */
    /*  UNCOMMENT TO SEE PLOT OF EKG AFTER SQUARING */
    /* figure(8) */
    /* subplot(2,1,1) */
    /* plot([0:length(x5)-1]/fs,x5) */
    /* xlabel('second');ylabel('Volts');title(' ECG Signal Squarting') */
    /* subplot(2,1,2) */
    /* plot(t(200:600),x5(200:600)) */
    /* xlabel('second');ylabel('Volts');title(' ECG Signal 1-3 second') */
    /* xlim([1 3]); */
    /* MOVING WINDOW INTEGRATION */
    /*  Make impulse response */
    /*  Delay = 15; % Delay in samples */
    /*  Apply filter */
    for (i = 0; i < 31; i++) {
        c[i] = mul_u32_u32_u32_sr36_near(d_y, 2216757314U);
    }
    /*  Normalizes the signal  */
    /*  x6 = x6 / max( abs(x6 )); */
    EMLRTPUSHRTSTACK(&j_emlrtRSI);
    d_y = c[15];
    x6 = div_repeat_u32_sat_near(c[15], d_y, 16U);
    EMLRTPOPRTSTACK(&j_emlrtRSI);
    /*  normalize to one */
    /*  UNCOMMENT TO SEE PLOT OF EKG AFTER A MWI IS APPLIED */
    /* figure(9) */
    /* subplot(2,1,1) */
    /* plot([0:length(x6)-1]/fs,x6) */
    /* xlabel('second');ylabel('Volts');title(' ECG Signal after Averaging') */
    /* subplot(2,1,2) */
    /* plot(t(200:600),x6(200:600)) */
    /* xlabel('second');ylabel('Volts');title(' ECG Signal 1-3 second') */
    /* xlim([1 3]); */
    /* FIND QRS POINTS. NOTE: THE PEAK FINDING IS DIFFERENT THAN PAN-TOMPKINS ALGORITHM */
    /* figure(7) */
    /* subplot(2,1,1) */
    /* [GB] Outputs an array with each value indicating whether the value at that */
    /*  index is greater than thresh * max_h */
    poss_reg = (x6 > mul_u32_u32_u32_sr16_sat_near(x6, x6));
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
    /*  [GB] Finds(the indices) all the heart beats which are preceded by a non-beat */
    if (poss_reg == 1) {
        ii_sizes_idx_0 = 1;
        ii_sizes_idx_1 = 1;
    } else {
        ii_sizes_idx_0 = 0;
        ii_sizes_idx_1 = 0;
    }
    left_sizes_idx_0 = ii_sizes_idx_0;
    left_sizes_idx_1 = ii_sizes_idx_1;
    /* [GB] Gets all the indices in the resultant diff vector for which X[n] - X[n-1] = 1 */
    /*  [GB] Finds all the heart beats where  the heart beats are proceeded by a */
    /*  non-beat */
    /* left(1:10); */
    b_poss_reg[0] = (real_T)poss_reg;
    b_poss_reg[1] = 0.0;
    if (diff(b_poss_reg) == -1.0) {
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
        last_R_index = -1;
    } else {
        last_R_index = 0;
    }
    i = 0;
    while (i <= last_R_index) {
        emlrtDynamicBoundsCheck(1, 1, left_sizes_idx_0 * left_sizes_idx_1, &y_emlrtBCI);
        emlrtDynamicBoundsCheck(1, 1, ii_sizes_idx_0 * ii_sizes_idx_1, &x_emlrtBCI);
        EMLRTPUSHRTSTACK(&i_emlrtRSI);
        tmp_sizes[0] = 1;
        tmp_sizes[1] = 1;
        x1_data[0] = x1;
        b_max(x1_data, tmp_sizes, &d_y, &d0);
        EMLRTPOPRTSTACK(&i_emlrtRSI);
        emlrtDynamicBoundsCheck(1, 1, R_value_sizes[1], &s_emlrtBCI);
        R_value_data[0] = d_y;
        emlrtDynamicBoundsCheck(1, 1, left_sizes_idx_1, &w_emlrtBCI);
        R_loc_data[0] = 1;
        emlrtDynamicBoundsCheck(1, 1, left_sizes_idx_1, &t_emlrtBCI);
        emlrtDynamicBoundsCheck(1, 1, left_sizes_idx_1, &v_emlrtBCI);
        emlrtDynamicBoundsCheck(1, 1, left_sizes_idx_0 * left_sizes_idx_1, &u_emlrtBCI);
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
        c_R_loc_data[i] = R_loc_data[emlrtDynamicBoundsCheck(tmp_data[tmp_sizes[0] * i], 1, left_sizes_idx_1, &ab_emlrtBCI) - 1];
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
        ii_sizes_idx_0 = -1;
    } else {
        ii_sizes_idx_0 = 0;
    }
    if (1 > tmp_sizes[1]) {
        left_sizes_idx_0 = -1;
    } else {
        left_sizes_idx_0 = 0;
    }
    loop_ub = left_sizes_idx_0;
    last_R_index = 0;
    while (last_R_index <= loop_ub) {
        R_peak_indices_channel_3_data[0] = R_loc_data[0];
        last_R_index = 1;
    }
    if (1 > tmp_sizes[1]) {
        ii_sizes_idx_1 = -1;
    } else {
        ii_sizes_idx_1 = 0;
    }
    /*  REPLACE THIS WITH A ZEROS ARRAY */
    /*  UNCOMMENT TO SEE THE NUMBER OF PEAKS BEFORE CHANNEL 1 PROCESSING */
    /* if (shouldPlot) */
    /*     fprintf('Channel 1 Original: There are %i non-zero values\n',length(find(R_peak_indices_channel_1 ~= 0))); */
    /* end */
    EMLRTPUSHRTSTACK(&g_emlrtRSI);
    R_peak_indices_channel_1_sizes[0] = 1;
    R_peak_indices_channel_1_sizes[1] = i + 1;
    loop_ub = i;
    i = 0;
    while (i <= loop_ub) {
        R_peak_indices_channel_1_data[0] = (real_T)R_loc_data[0];
        i = 1;
    }
    dualThreshold(R_value_data, R_value_sizes, threshold_1, R_peak_indices_channel_1_data, R_peak_indices_channel_1_sizes, x6, pos_deviance_threshold, neg_deviance_threshold, &noise_lvl_channel_1, &signal_lvl_channel_1);
    EMLRTPOPRTSTACK(&g_emlrtRSI);
    EMLRTPUSHRTSTACK(&f_emlrtRSI);
    R_peak_indices_channel_2_sizes[0] = 1;
    R_peak_indices_channel_2_sizes[1] = ii_sizes_idx_0 + 1;
    loop_ub = ii_sizes_idx_0;
    i = 0;
    while (i <= loop_ub) {
        R_peak_indices_channel_2_data[0] = (real_T)R_loc_data[0];
        i = 1;
    }
    dualThreshold(R_value_data, R_value_sizes, threshold_2, R_peak_indices_channel_2_data, R_peak_indices_channel_2_sizes, x6, pos_deviance_threshold, neg_deviance_threshold, &noise_lvl_channel_2, &signal_lvl_channel_2);
    EMLRTPOPRTSTACK(&f_emlrtRSI);
    /*  UNCOMMENT TO SEE THE NUMBER OF PEAKS AFTER CHANNEL 1 PROCESSING */
    /* if (shouldPlot) */
    /*     fprintf('Channel 1 Post: There are %i non-zero values\n',length(find(R_peak_indices_channel_1 ~= 0))); */
    /* end */
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
        emlrtDynamicBoundsCheck(1, 1, R_peak_indices_channel_1_sizes[1], &r_emlrtBCI);
        guard1 = FALSE;
        if (R_peak_indices_channel_1_data[0] == 0.0) {
            emlrtDynamicBoundsCheck(1, 1, R_peak_indices_channel_2_sizes[1], &q_emlrtBCI);
            if (R_peak_indices_channel_2_data[0] == 0.0) {
                emlrtDynamicBoundsCheck(1, 1, ii_sizes_idx_1 + 1, &p_emlrtBCI);
            } else {
                guard1 = TRUE;
            }
        } else {
            guard1 = TRUE;
        }
        if (guard1 == TRUE) {
            emlrtDynamicBoundsCheck(1, 1, R_peak_indices_channel_1_sizes[1], &o_emlrtBCI);
            if (R_peak_indices_channel_1_data[0] != 0.0) {
                emlrtDynamicBoundsCheck(1, 1, R_peak_indices_channel_2_sizes[1], &n_emlrtBCI);
                if (R_peak_indices_channel_2_data[0] == 0.0) {
                    /*  DELETE DEBUGGING */
                    /* if (shouldPlot) */
                    /*    fprintf('The peak val is: %f\n',R_peak_vals(i)); */
                    /* end */
                    /*  Uses the decision of the channel w/ the highest Detection. */
                    /*  Ensures that Ds is between 0 and 1 */
                    /*  strength(Ds) */
                    emlrtDynamicBoundsCheck(1, 1, R_value_sizes[1], &m_emlrtBCI);
                    EMLRTPUSHRTSTACK(&e_emlrtRSI);
                    d_y = R_value_data[0];
                    x1 = d_y - noise_lvl_channel_1;
                    if (x1 > d_y) {
                        x1 = 0U;
                    }
                    d_y = signal_lvl_channel_1 - noise_lvl_channel_1;
                    if (d_y > signal_lvl_channel_1) {
                        d_y = 0U;
                    }
                    d_y = mrdivide(x1, d_y);
                    if (1U > d_y) {
                        last_R_index = 0;
                    } else {
                        last_R_index = 1;
                    }
                    EMLRTPOPRTSTACK(&e_emlrtRSI);
                    emlrtDynamicBoundsCheck(1, 1, R_value_sizes[1], &l_emlrtBCI);
                    EMLRTPUSHRTSTACK(&d_emlrtRSI);
                    d_y = R_value_data[0];
                    x1 = d_y - noise_lvl_channel_2;
                    if (x1 > d_y) {
                        x1 = 0U;
                    }
                    d_y = signal_lvl_channel_2 - noise_lvl_channel_2;
                    if (d_y > signal_lvl_channel_2) {
                        d_y = 0U;
                    }
                    d_y = mrdivide(x1, d_y);
                    if (1U > d_y) {
                        ii_sizes_idx_0 = 0;
                    } else {
                        ii_sizes_idx_0 = 1;
                    }
                    EMLRTPOPRTSTACK(&d_emlrtRSI);
                    if ((uint32_T)last_R_index > (uint32_T)ii_sizes_idx_0) {
                        /* if(shouldPlot) */
                        /* fprintf('Ds1: %f Ds2: %f Ds1 wins\n', Ds_1, Ds_2); */
                        /* end */
                        emlrtDynamicBoundsCheck(1, 1, ii_sizes_idx_1 + 1, &j_emlrtBCI);
                        emlrtDynamicBoundsCheck(1, 1, R_peak_indices_channel_1_sizes[1], &k_emlrtBCI);
                    } else {
                        /* if(shouldPlot) */
                        /* fprintf('Ds1: %f Ds2: %f Ds2 wins\n', Ds_1, Ds_2); */
                        /* end */
                        emlrtDynamicBoundsCheck(1, 1, ii_sizes_idx_1 + 1, &h_emlrtBCI);
                        emlrtDynamicBoundsCheck(1, 1, R_peak_indices_channel_2_sizes[1], &i_emlrtBCI);
                    }
                }
            }
        }
        i = 1;
        emlrtBreakCheck();
    }
    /*  UNCOMMENT TO SEE THE NUMBER OF PEAKS AFTER LEVEL 3 PROCESSING */
    /* if (shouldPlot) */
    /* fprintf('Combined Post: There are %i non-zero values\n',length(find(R_peak_indices_combined ~= 0))); */
    /* end */
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
    last_R_index = 0;
    i = 0;
    while (i <= R_value_sizes[1] - 1) {
        emlrtDynamicBoundsCheck(1, 1, left_sizes_idx_0 + 1, &g_emlrtBCI);
        if (R_peak_indices_channel_3_data[0] == 0) {
            emlrtDynamicBoundsCheck(1, 1, R_value_sizes[1], &f_emlrtBCI);
            R_peak_vals_data[0] = 0U;
            /*  Level 5 Detection: Refines heart beat detection by considering a heart */
            /*  beat's refactory period  */
        } else {
            /*  Filters out any R_values which happen too soon after a previous */
            /*  beat detection */
            emlrtDynamicBoundsCheck(1, 1, left_sizes_idx_0 + 1, &e_emlrtBCI);
            if (last_R_index != 0) {
                emlrtBoundsCheck(1, &d_emlrtBCI);
                /* fprintf('Getting rid of a value\n'); */
                emlrtDynamicBoundsCheck(1, 1, R_value_sizes[1], &c_emlrtBCI);
                R_peak_vals_data[0] = 0U;
                emlrtDynamicBoundsCheck(1, 1, left_sizes_idx_0 + 1, &b_emlrtBCI);
                R_peak_indices_channel_3_data[0] = 0;
                /*  Updates the last index if the R_value is valid */
            } else {
                /*  Updates the last index */
                emlrtDynamicBoundsCheck(1, 1, left_sizes_idx_0 + 1, &emlrtBCI);
                last_R_index = 1;
            }
        }
        i = 1;
        emlrtBreakCheck();
    }
    /*  Removes all zero values from both the indice and value array */
    EMLRTPUSHRTSTACK(&c_emlrtRSI);
    R_peak_indices_channel_3_sizes[0] = 1;
    R_peak_indices_channel_3_sizes[1] = left_sizes_idx_0 + 1;
    loop_ub = left_sizes_idx_0;
    i = 0;
    while (i <= loop_ub) {
        b_R_loc_data[0] = (R_peak_indices_channel_3_data[0] != 0);
        i = 1;
    }
    eml_li_find(b_R_loc_data, R_peak_indices_channel_3_sizes, tmp_data, tmp_sizes);
    last_R_index = tmp_sizes[1];
    loop_ub = tmp_sizes[1] - 1;
    for (i = 0; i <= loop_ub; i++) {
        emlrtDynamicBoundsCheck(tmp_data[tmp_sizes[0] * i], 1, left_sizes_idx_0 + 1, &bb_emlrtBCI);
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
        emlrtDynamicBoundsCheck(tmp_data[i], 1, R_value_sizes[1], &cb_emlrtBCI);
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
    d_y = 0U;
    /*  Counts how many R peak counts are found in N seconds */
    i = 0;
    while (i <= last_R_index - 1) {
        /*  Counts how many R wave peaks are found in a  */
        x1 = d_y + 65536U;
        if (x1 < d_y) {
            x1 = MAX_uint32_T;
        }
        d_y = x1;
        i = 1;
        emlrtBreakCheck();
    }
    EMLRTPUSHRTSTACK(&emlrtRSI);
    d_y = mrdivide(d_y, sample_time);
    heart_rate = mul_u32_u32_u32_sr10_sat_near(d_y, 4026531840U);
    EMLRTPOPRTSTACK(&emlrtRSI);
    emlrtDisplayR2011a(emlrt_marshallOut(heart_rate), "heart_rate");
    /* heart_rate = R_peak_count; */
    return heart_rate;
}
/* End of code generation (heart_rate_official_cport.c) */
