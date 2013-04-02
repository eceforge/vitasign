/*
 * heart_rate_official_cport.c
 *
 * Code generation for function 'heart_rate_official_cport'
 *
 * C source code generated on: Wed Feb 13 13:34:56 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "max.h"
#include "diff.h"
#include "mean.h"
#include "abs.h"
#include "conv.h"
#include "power.h"
#include "heart_rate_official_cport_rtwutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void MultiWordUnsignedWrap(const uint32_T u1[], int16_T n1, uint16_T n2,
  uint32_T y[]);
static int32_T compute_nones(const boolean_T x_data[1000], const int16_T
  x_sizes[2], int32_T n);
static int32_T div_repeat_s32_sat_near(int32_T numerator, int32_T denominator,
  uint16_T nRepeatSub);
uint32_T div_repeat_u32_sat_near(uint32_T numerator, uint32_T denominator,
  uint16_T nRepeatSub);
static uint32_T div_u32_SR_near(uint32_T numerator, uint32_T denominator,
  uint16_T nShiftRight);
static void dualThreshold(const uint32_T R_peak_vals_data[1000], const int16_T
  R_peak_vals_sizes[2], uint32_T threshold, uint32_T indices_data[1000], int16_T
  indices_sizes[2], uint32_T max_voltage, uint32_T pos_deviance_threshold,
  uint32_T neg_deviance_threshold, uint32_T *noise_lvl, uint32_T *signal_lvl);
static void eml_li_find(const boolean_T x_data[1000], const int16_T x_sizes[2],
  int32_T y_data[1000], int16_T y_sizes[2]);
static uint32_T mul_u32_u32_u32_sr15_sat_near(uint32_T a, uint32_T b);
static uint32_T mul_u32_u32_u32_sr16_sat_near(uint32_T a, uint32_T b);
static uint32_T mul_u32_u32_u32_sr28_sat_near(uint32_T a, uint32_T b);
static void uLong2MultiWord(uint32_T u, uint32_T y[], int16_T n);
static int16_T uMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int16_T n);
static boolean_T uMultiWordGt(const uint32_T u1[], const uint32_T u2[], int16_T
  n);
static boolean_T uMultiWordLt(const uint32_T u1[], const uint32_T u2[], int16_T
  n);
static void uMultiWordShl(const uint32_T u1[], int16_T n1, uint16_T n2, uint32_T
  y[], int16_T n);

/* Function Definitions */
static void MultiWordUnsignedWrap(const uint32_T u1[], int16_T n1, uint16_T n2,
  uint32_T y[])
{
  int16_T n1m1;
  int16_T i;
  uint16_T ns;
  uint32_T mask;
  n1m1 = n1 - 1;
  for (i = 0; i <= n1m1 - 1; i++) {
    y[i] = u1[i];
  }

  ns = 32U - n2;
  mask = (1UL << ns) - 1UL;
  y[n1m1] = u1[n1m1] & mask;
}

static int32_T compute_nones(const boolean_T x_data[1000], const int16_T
  x_sizes[2], int32_T n)
{
  int32_T k;
  int16_T i;
  k = 0L;
  for (i = 0; (int32_T)(i + 1) <= n; i++) {
    if (x_data[i]) {
      k++;
    }
  }

  return k;
}

static int32_T div_repeat_s32_sat_near(int32_T numerator, int32_T denominator,
  uint16_T nRepeatSub)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  int16_T quotientNeedsNegation;
  uint8_T overflow;
  uint32_T tempQuotient;
  uint16_T iRepeatSub;
  uint8_T numeratorExtraBit;
  if (denominator == (int32_T)0) {
    quotient = numerator >= (int32_T)0 ? MAX_int32_T : MIN_int32_T;
  } else {
    absNumerator = (uint32_T)(numerator >= (int32_T)0 ? numerator : -numerator);
    absDenominator = (uint32_T)(denominator >= (int32_T)0 ? denominator :
      -denominator);
    quotientNeedsNegation = ((numerator < (int32_T)0) != (denominator < (int32_T)
      0));
    overflow = (uint8_T)0U;
    tempQuotient = absNumerator / absDenominator;
    absNumerator %= absDenominator;
    for (iRepeatSub = (uint16_T)0; iRepeatSub < nRepeatSub; iRepeatSub++) {
      numeratorExtraBit = (uint8_T)(absNumerator >= 2147483648UL);
      absNumerator <<= 1;
      overflow = (uint8_T)(overflow || (tempQuotient >= 2147483648UL));
      tempQuotient <<= 1;
      if (numeratorExtraBit || (absNumerator >= absDenominator)) {
        tempQuotient++;
        absNumerator -= absDenominator;
      }
    }

    if (overflow || (tempQuotient >= MAX_uint32_T)) {
      tempQuotient = MAX_uint32_T;
    } else {
      numeratorExtraBit = (uint8_T)(absNumerator >= 2147483648UL);
      absNumerator <<= 1;
      if (numeratorExtraBit || ((uint16_T)quotientNeedsNegation ? absNumerator >
           absDenominator : absNumerator >= absDenominator)) {
        tempQuotient++;
      }
    }

    if ((uint16_T)quotientNeedsNegation) {
      quotient = tempQuotient <= 2147483647UL ? -(int32_T)tempQuotient :
        MIN_int32_T;
    } else {
      quotient = tempQuotient <= 2147483647UL ? (int32_T)tempQuotient :
        MAX_int32_T;
    }
  }

  return quotient;
}

uint32_T div_repeat_u32_sat_near(uint32_T numerator, uint32_T denominator,
  uint16_T nRepeatSub)
{
  uint32_T quotient;
  uint8_T overflow;
  uint16_T iRepeatSub;
  uint8_T numeratorExtraBit;
  if (denominator == (uint32_T)0) {
    quotient = MAX_uint32_T;
  } else {
    overflow = (uint8_T)0U;
    quotient = numerator / denominator;
    numerator %= denominator;
    for (iRepeatSub = (uint16_T)0; iRepeatSub < nRepeatSub; iRepeatSub++) {
      numeratorExtraBit = (uint8_T)(numerator >= 2147483648UL);
      numerator <<= 1;
      overflow = (uint8_T)(overflow || (quotient >= 2147483648UL));
      quotient <<= 1;
      if (numeratorExtraBit || (numerator >= denominator)) {
        quotient++;
        numerator -= denominator;
      }
    }

    if (overflow || (quotient >= MAX_uint32_T)) {
      quotient = MAX_uint32_T;
    } else {
      numeratorExtraBit = (uint8_T)(numerator >= 2147483648UL);
      numerator <<= 1;
      if (numeratorExtraBit || (numerator >= denominator)) {
        quotient++;
      }
    }
  }

  return quotient;
}

static uint32_T div_u32_SR_near(uint32_T numerator, uint32_T denominator,
  uint16_T nShiftRight)
{
  uint32_T quotient;
  uint32_T tempAbsQuotient;
  uint32_T maskMSdropoffBit;
  if (denominator == (uint32_T)0) {
    quotient = MAX_uint32_T;
  } else {
    tempAbsQuotient = numerator / denominator;
    quotient = nShiftRight >= 32U ? (uint32_T)0 : tempAbsQuotient >> nShiftRight;
    if (nShiftRight <= 32U) {
      tempAbsQuotient &= MAX_uint32_T >> (32 - (int16_T)nShiftRight);
      maskMSdropoffBit = 1UL << ((int16_T)nShiftRight - 1);
      if (tempAbsQuotient >= maskMSdropoffBit) {
        quotient++;
      }
    }
  }

  return quotient;
}

static void dualThreshold(const uint32_T R_peak_vals_data[1000], const int16_T
  R_peak_vals_sizes[2], uint32_T threshold, uint32_T indices_data[1000], int16_T
  indices_sizes[2], uint32_T max_voltage, uint32_T pos_deviance_threshold,
  uint32_T neg_deviance_threshold, uint32_T *noise_lvl, uint32_T *signal_lvl)
{
  uint32_T noise_sum;
  uint32_T signal_sum;
  uint32_T noise_count;
  uint32_T signal_count;
  int16_T b_index;
  uint64m_T r3;
  uint64m_T r4;
  uint64m_T r5;
  uint64m_T r6;
  int16_T is_neg;
  uint32_T deviance;
  uint32_T q0;
  uint64m_T r7;
  uint64m_T r8;
  uint64m_T r9;

  /* DUAL THRESHOLD PROCESSSING */
  /*  Filters out R_peaks which don't meet the threshold reqs */
  /*  asserts that the input parameters are of fixed point */
  /*  asserts that input parameters are of specific fixed point parameters */
  noise_sum = 0UL;
  signal_sum = 0UL;
  noise_count = 0UL;
  signal_count = 0UL;

  /*  Setting signal count to 1 ensures that the first value doesn't dominate the avg signal level */
  *noise_lvl = 0UL;
  *signal_lvl = 0UL;
  for (b_index = 0; b_index <= R_peak_vals_sizes[1] - 1; b_index++) {
    /*  DELETE AFTER DEBUGGING */
    /* if (shouldOutput && channel == 2) */
    /*     fprintf('The peak val is: %f\n',R_peak_vals(index)); */
    /* end */
    uLong2MultiWord(mul_u32_u32_u32_sat(R_peak_vals_data[b_index], max_voltage),
                    &r3.chunks[0U], 2);
    MultiWordUnsignedWrap(&r3.chunks[0U], 2, 22U, &r4.chunks[0U]);
    uLong2MultiWord(threshold, &r5.chunks[0U], 2);
    uMultiWordShl(&r5.chunks[0U], 2, 10U, &r6.chunks[0U], 2);
    MultiWordUnsignedWrap(&r6.chunks[0U], 2, 22U, &r3.chunks[0U]);
    if (uMultiWordGt(&r4.chunks[0U], &r3.chunks[0U], 2)) {
      /* fprintf('mv: %f. Threshold is: %f\n', R_peak_vals(index) * max_voltage, threshold); */
      /* R_peak_vals(index) */
      /*  Filters out any signal value which exceeds the allowed deviance from */
      /*  the average signal value  */
      /*  RETURNS TRUE IF THE INPUT SIGNAL VALUE MEETS THE DEVIANCE REQS. NOTE */
      /*  THE THRESHOLD VALUE CHANGES BASED ON WHETHER DEVIANCE IS NEG OR POS */
      /*  asserts that the input parameters are of fixed point */
      /*  asserts that input parameters are of specific fixed point parameters */
      /* Accounts for the first signal value */
      if (*signal_lvl == 0UL) {
        is_neg = 1;
      } else {
        if (R_peak_vals_data[b_index] < *signal_lvl) {
          deviance = mul_u32_u32_u32_sr15_sat_near(*signal_lvl, 3355443200UL);
          q0 = (deviance >> 10) + ((uint16_T)((int16_T)deviance & 512) != 0U);
          deviance = mul_u32_u32_u32_sr15_sat_near(R_peak_vals_data[b_index],
            3355443200UL);
          deviance = (q0 - (deviance >> 10)) - ((uint16_T)((int16_T)deviance &
            512) != 0U);
          if (deviance > q0) {
            deviance = 0UL;
          }

          deviance = div_repeat_u32_sat_near(deviance, *signal_lvl, 10U);
          is_neg = 1;
        } else {
          deviance = mul_u32_u32_u32_sr15_sat_near(R_peak_vals_data[b_index],
            3355443200UL);
          q0 = (deviance >> 10) + ((uint16_T)((int16_T)deviance & 512) != 0U);
          deviance = mul_u32_u32_u32_sr15_sat_near(*signal_lvl, 3355443200UL);
          deviance = (q0 - (deviance >> 10)) - ((uint16_T)((int16_T)deviance &
            512) != 0U);
          if (deviance > q0) {
            deviance = 0UL;
          }

          deviance = div_repeat_u32_sat_near(deviance, *signal_lvl, 10U);
          is_neg = 0;
        }

        /*  Checks value against NEG and POS deviance threshold */
        if (is_neg != 0) {
          uLong2MultiWord(deviance, &r7.chunks[0U], 2);
          uMultiWordShl(&r7.chunks[0U], 2, 10U, &r8.chunks[0U], 2);
          MultiWordUnsignedWrap(&r8.chunks[0U], 2, 22U, &r9.chunks[0U]);
          uLong2MultiWord(mul_u32_u32_u32_sr15_sat_near(neg_deviance_threshold,
            3355443200UL), &r7.chunks[0U], 2);
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
          uLong2MultiWord(mul_u32_u32_u32_sr15_sat_near(pos_deviance_threshold,
            3355443200UL), &r9.chunks[0U], 2);
          MultiWordUnsignedWrap(&r9.chunks[0U], 2, 22U, &r5.chunks[0U]);
          if (uMultiWordLt(&r6.chunks[0U], &r5.chunks[0U], 2)) {
            is_neg = 1;
          } else {
            is_neg = 0;
          }
        }
      }

      if ((!(is_neg != 0)) && (1 + b_index > 4)) {
        /*                      if(shouldOutput) */
        /*                            fprintf('Does not meet the deviance threshold\n'); */
        /*                            R_peak_vals(index) */
        /*                            signal_lvl */
        /*                      end */
        /*  Sets all the indices which R_vals don't meet the threshold to 0 */
        indices_data[b_index] = 0UL;

        /*  Updates the average noise signal lvl */
        deviance = noise_sum + R_peak_vals_data[b_index];
        if (deviance < noise_sum) {
          deviance = MAX_uint32_T;
        }

        noise_sum = deviance;
        deviance = noise_count + 1024UL;
        if (deviance < noise_count) {
          deviance = MAX_uint32_T;
        }

        noise_count = deviance;

        /*  Calculates the noise level */
        /*                     noise_lvl = noise_sum / noise_count; */
        *noise_lvl = div_repeat_u32_sat_near(noise_sum, noise_count, 10U);
      } else {
        /*  DELETE AFTER DEBUGGING */
        /* if (shouldOutput && channel == 2) */
        /*    fprintf('The peak val is: %f\n',R_peak_vals(index)); */
        /* end */
        /*  Updates the average signal lvl */
        deviance = signal_sum + R_peak_vals_data[b_index];
        if (deviance < signal_sum) {
          deviance = MAX_uint32_T;
        }

        signal_sum = deviance;
        deviance = signal_count + 1024UL;
        if (deviance < signal_count) {
          deviance = MAX_uint32_T;
        }

        signal_count = deviance;

        /*  Calculates the signal level */
        *signal_lvl = div_repeat_u32_sat_near(signal_sum, signal_count, 10U);
      }
    } else {
      /*  Sets all the indices which R_vals don't meet the threshold to 0 */
      indices_data[b_index] = 0UL;

      /*  Updates the average noise signal lvl */
      deviance = noise_sum + R_peak_vals_data[b_index];
      if (deviance < noise_sum) {
        deviance = MAX_uint32_T;
      }

      noise_sum = deviance;
      deviance = noise_count + 1024UL;
      if (deviance < noise_count) {
        deviance = MAX_uint32_T;
      }

      noise_count = deviance;

      /*  Calculates the noise level */
      /*                 noise_lvl = noise_sum / noise_count; */
      *noise_lvl = div_repeat_u32_sat_near(noise_sum, noise_count, 10U);
    }
  }
}

static void eml_li_find(const boolean_T x_data[1000], const int16_T x_sizes[2],
  int32_T y_data[1000], int16_T y_sizes[2])
{
  int16_T j;
  int16_T i;
  y_sizes[0L] = 1;
  y_sizes[1L] = (int16_T)compute_nones(x_data, x_sizes, (int32_T)x_sizes[1]);
  j = 0;
  for (i = 1; i <= x_sizes[1]; i++) {
    if (x_data[i - 1]) {
      y_data[j] = (int32_T)i;
      j++;
    }
  }
}

static uint32_T mul_u32_u32_u32_sr15_sat_near(uint32_T a, uint32_T b)
{
  uint32_T result;
  uint32_T u32_chi;
  boolean_T roundup;
  mul_wide_u32(a, b, &u32_chi, &result);
  roundup = ((uint16_T)((int16_T)result & 16384) != 0U);
  result = (u32_chi << 17UL | result >> 15) + (uint32_T)roundup;
  u32_chi = (u32_chi >> 15) + (uint32_T)(roundup && (result == 0UL));
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
  roundup = (((uint16_T)result & 32768U) != 0U);
  result = (u32_chi << 16UL | result >> 16) + (uint32_T)roundup;
  u32_chi = (u32_chi >> 16) + (uint32_T)(roundup && (result == 0UL));
  if (u32_chi) {
    result = MAX_uint32_T;
  }

  return result;
}

static uint32_T mul_u32_u32_u32_sr28_sat_near(uint32_T a, uint32_T b)
{
  uint32_T result;
  uint32_T u32_chi;
  boolean_T roundup;
  mul_wide_u32(a, b, &u32_chi, &result);
  roundup = ((int32_T)(result & 134217728UL) != 0L);
  result = (u32_chi << 4UL | result >> 28) + (uint32_T)roundup;
  u32_chi = (uint32_T)((int16_T)(u32_chi >> 28) + (roundup && (result == 0UL)));
  if (u32_chi) {
    result = MAX_uint32_T;
  }

  return result;
}

static void uLong2MultiWord(uint32_T u, uint32_T y[], int16_T n)
{
  int16_T i;
  y[0] = u;
  for (i = 1; i <= n - 1; i++) {
    y[i] = 0UL;
  }
}

static int16_T uMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int16_T n)
{
  int16_T y;
  int16_T i;
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

static boolean_T uMultiWordGt(const uint32_T u1[], const uint32_T u2[], int16_T
  n)
{
  return uMultiWordCmp(u1, u2, n) > 0 ? TRUE : FALSE;
}

static boolean_T uMultiWordLt(const uint32_T u1[], const uint32_T u2[], int16_T
  n)
{
  return uMultiWordCmp(u1, u2, n) < 0 ? TRUE : FALSE;
}

static void uMultiWordShl(const uint32_T u1[], int16_T n1, uint16_T n2, uint32_T
  y[], int16_T n)
{
  int16_T nb;
  uint32_T ys;
  int16_T nc;
  uint32_T u1i;
  int16_T i;
  uint16_T nl;
  uint16_T nr;
  uint32_T yi;
  nb = (int16_T)n2 / 32;
  ys = (u1[n1 - 1] & 2147483648UL) != 0UL ? MAX_uint32_T : 0UL;
  nc = nb > n ? n : nb;
  u1i = 0UL;
  for (i = 0; i <= nc - 1; i++) {
    y[i] = 0UL;
  }

  if (nb < n) {
    nl = n2 - (uint16_T)nb * 32U;
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

void heart_rate_official_cport(const int32_T data[1000], uint32_T fs, uint32_T
  threshold_1, uint32_T threshold_2, uint32_T threshold_3, uint32_T
  pos_deviance_threshold, uint32_T neg_deviance_threshold, uint32_T sample_time,
  uint32_T shouldOutput, uint32_T prev_hr_delta, uint32_T *heart_rate, uint32_T *
  last_hr_delta)
{
  int32_T iv0[1000];
  int32_T max_x;
  int32_T x1[1000];
  int16_T i;
  int32_T ii_data[1000];
  uint32_T x5[1000];
  uint32_T uv0[1000];
  uint32_T thresh;
  int16_T i0;
  uint32_T uv1[31];
  uint32_T x6[1030];
  uint32_T max_h;
  real_T c[1001];
  uint64m_T r0;
  uint64m_T r1;
  uint64m_T r2;
  boolean_T b_c;
  boolean_T c_c[1000];
  real_T R_loc_data[1000];
  boolean_T x[1000];
  int16_T ii_sizes[2];
  int16_T Ds_1;
  boolean_T exitg2;
  boolean_T guard2 = FALSE;
  int16_T Ds_2;
  int16_T tmp_data[1000];
  int16_T loop_ub;
  int16_T b_ii_data[1000];
  int16_T tmp_sizes;
  int16_T left_sizes_idx_1;
  real_T left_data[1000];
  boolean_T exitg1;
  boolean_T guard1 = FALSE;
  int16_T right_data[1000];
  int16_T R_value_sizes[2];
  uint32_T R_value_data[1000];
  real_T b_R_loc_data[1000];
  real_T d0;
  int16_T R_loc_sizes[2];
  int16_T R_peak_indices_channel_1_sizes[2];
  uint32_T u0;
  uint32_T R_peak_indices_channel_1_data[1000];
  uint32_T heart_beat_last_sum;
  uint32_T heart_beat_current_sum;
  int16_T R_peak_indices_channel_2_sizes[2];
  uint32_T R_peak_indices_channel_2_data[1000];
  uint32_T signal_lvl_channel_2;
  uint32_T heart_beat_count;
  uint32_T q0;
  uint32_T qY;
  boolean_T b_guard1 = FALSE;

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
  /*  Ensures that the prev time delta is unsigned and has fractional bits */
  /*  specified by Fixed_Point_Properties */
  /*  assert(isequal(numerictype(sample_time),Fixed_Point_Properties) && isequal(fimath(sample_time), F)); */
  /*   Assures that the first threshold is less than the second threshold */
  /*   Assures that the third threshold is in between the first and the second */
  /*  threshold */
  /* x1 = load('ecg3.dat'); % load the ECG signal from the file */
  /*  assert (~isscalar(data)); */
  /*  figure(30) */
  /*  plot(data); */
  /*  Signal length */
  /*  t = (0:N-1)/fs;        % time index */
  /*  NFFT = 2 ^(ceil(log2(N))); % Next power of 2 from length of the signal */
  /*  Assures that the number of samples sent in aren't greater than the */
  /*  specified sample size */
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
  b_abs(data, iv0);
  max_x = b_max(iv0);

  /*  for i=1:length(x1) */
  /*      divide(Fixed_Point_Properties_signed, x1(i), max_x) % normalize to one */
  /*  end */
  for (i = 0; i < 1000; i++) {
    x1[i] = div_repeat_s32_sat_near(data[i], max_x, 10U);
  }

  /*  normalize to one */
  /*  UNCOMMENT TO SEE PLOT OF EKG AFTER NORMALIZATION AND REMOVAL OF DC DRIFT */
  /*  UNCOMMENT TO SEE FFT OF ORIGINAL EKG */
  /*      if (shouldOutput) */
  /* Plots the fft of the original signal */
  /* transform=fft(x1,NFFT)/N;% Transform from discrete values to the frequency domain */
  /* transform=transform; */
  /* windows=[windows,abs(transform)]; */
  /* freq = fs/2*linspace(0,1,NFFT/2+1);%Frequency index */
  /*    fprintf('Plotting\n'); */
  /* figure(2)  */
  /* plot(freq,2*abs(transform(1:NFFT/2+1))); */
  /* title('FFT EKG Signal'); */
  /* xlabel('Frequency (Hz)'); */
  /* ylabel('|X(f)|'); */
  /*      end */
  /* ------ MOST FILTERING NOW OCCURS IN ANALOG SEE 'front_end_filters.m' FOR EMULATED FRONT END FILTERS */
  /* LOW PASS FILTERING */
  /*  LPF (1-z^-6)^2/(1-z^-1)^2 */
  /* b=[1 0 0 0 0 0 -2 0 0 0 0 0 1]; */
  /* a=[1 -2 1]; */
  /* h_LP=filter(b,a,[1 zeros(1,12)]); % transfer function of LPF */
  /* if(shouldOutput) */
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
  /* if(shouldOutput) */
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
  /* if(shouldOutput) */
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
  /* if(shouldOutput) */
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
  /*  assert(isequal(numerictype(x5),Fixed_Point_Properties) && isequal(fimath(x5), F)); */
  /* x5 = mpower(x1, 2); */
  /* x5 = x5/ max( abs(x5 )); */
  /*  figure(24) */
  /*  plot(x5); */
  /*  UPDATES FIXED POINT DEFINITION TO BE UNSIGNED */
  /*  assert(isequal(numerictype(x5),Fixed_Point_Properties) && isequal(fimath(x5), F)); */
  /*  Changes the fixed point properties of the data to be unsigned after */
  /*  squaring */
  power(x1, ii_data);
  for (i = 0; i < 1000; i++) {
    max_x = ii_data[i];
    max_x = (max_x >> 10) + ((max_x & 512L) != 0L);
    if (max_x < 0L) {
      max_x = 0L;
    }

    x5[i] = (uint32_T)max_x;
  }

  /*  Normalizes the result of the squaring */
  c_abs(x5, uv0);
  thresh = c_max(uv0);
  for (i0 = 0; i0 < 1000; i0++) {
    x5[i0] = div_repeat_u32_sat_near(x5[i0], thresh, 10U);
  }

  /*  normalize to one */
  /*  UNCOMMENT TO SEE PLOT OF EKG AFTER SQUARING */
  /*      if(shouldOutput) */
  /* figure(8) */
  /* subplot(2,1,1) */
  /* plot([0:length(x5)-1]/fs,x5) */
  /* xlabel('second');ylabel('Volts');title(' ECG Signal Squaring') */
  /* subplot(2,1,2) */
  /* plot(t(200:600),x5(200:600)) */
  /* xlabel('second');ylabel('Volts');title(' ECG Signal 1-3 second') */
  /* xlim([1 3]); */
  /*      end */
  /* MOVING WINDOW INTEGRATION */
  /*  Make impulse response */
  /*  Delay = 15; % Delay in samples */
  /*  Apply filter */
  for (i0 = 0; i0 < 31; i0++) {
    uv1[i0] = 33UL;
  }

  conv(x5, uv1, x6);

  /*  Normalizes the signal  */
  /*  x6 = x6 / max( abs(x6 )); */
  c_abs(*(uint32_T (*)[1000])&x6[15], x5);
  thresh = c_max(x5);
  for (i = 0; i < 1000; i++) {
    x5[i] = div_repeat_u32_sat_near(x6[i + 15], thresh, 10U);
  }

  /*  normalize to one */
  /*  figure(25) */
  /*  plot(x6); */
  /*  UNCOMMENT TO SEE PLOT OF EKG AFTER A MWI IS APPLIED */
  /*      if(shouldOutput) */
  /* figure(9) */
  /* subplot(2,1,1) */
  /* plot([0:length(x6)-1]/fs,x6) */
  /* xlabel('second');ylabel('Volts');title(' ECG Signal after Averaging') */
  /* subplot(2,1,2) */
  /* plot(t(200:600),x6(200:600)) */
  /* xlabel('second');ylabel('Volts');title(' ECG Signal 1-3 second') */
  /* xlim([1 3]); */
  /*      end */
  /* FIND QRS POINTS. NOTE: THE PEAK FINDING IS DIFFERENT THAN PAN-TOMPKINS ALGORITHM */
  /* figure(7) */
  /* subplot(2,1,1) */
  max_h = c_max(x5);
  thresh = mean(x5);

  /*  Outputs an array with each value indicating whether the value at that */
  /*  index is greater than thresh * max_h */
  thresh = mul_u32_u32_u32_sat(thresh, max_h);

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
  c[0] = 0.0;
  for (i = 0; i < 1000; i++) {
    uLong2MultiWord(x5[i], &r0.chunks[0U], 2);
    uMultiWordShl(&r0.chunks[0U], 2, 10U, &r1.chunks[0U], 2);
    MultiWordUnsignedWrap(&r1.chunks[0U], 2, 22U, &r2.chunks[0U]);
    uLong2MultiWord(thresh, &r0.chunks[0U], 2);
    MultiWordUnsignedWrap(&r0.chunks[0U], 2, 22U, &r1.chunks[0U]);
    b_c = uMultiWordGt(&r2.chunks[0U], &r1.chunks[0U], 2);
    c[i + 1] = (real_T)b_c;
    c_c[i] = b_c;
  }

  diff(c, R_loc_data);
  for (i0 = 0; i0 < 1000; i0++) {
    x[i0] = (R_loc_data[i0] == 1.0);
  }

  max_x = 0L;
  for (i0 = 0; i0 < 2; i0++) {
    ii_sizes[i0] = 1 + 999 * i0;
  }

  Ds_1 = 1;
  exitg2 = 0UL;
  while ((exitg2 == 0UL) && (Ds_1 < 1001)) {
    guard2 = FALSE;
    if (x[Ds_1 - 1]) {
      max_x++;
      ii_data[(int16_T)max_x - 1] = (int32_T)Ds_1;
      if (max_x >= 1000L) {
        exitg2 = 1UL;
      } else {
        guard2 = TRUE;
      }
    } else {
      guard2 = TRUE;
    }

    if (guard2 == TRUE) {
      Ds_1++;
    }
  }

  if (1L > max_x) {
    Ds_2 = 0;
  } else {
    Ds_2 = (int16_T)max_x;
  }

  loop_ub = Ds_2 - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    tmp_data[i0] = 1 + i0;
  }

  loop_ub = Ds_2 - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    tmp_sizes = 0;
    while (tmp_sizes <= 0) {
      b_ii_data[i0] = (int16_T)ii_data[tmp_data[i0] - 1];
      tmp_sizes = 1;
    }
  }

  ii_sizes[0L] = 1;
  ii_sizes[1L] = Ds_2;
  loop_ub = Ds_2 - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    ii_data[i0] = (int32_T)b_ii_data[i0];
  }

  left_sizes_idx_1 = ii_sizes[1];
  loop_ub = ii_sizes[1] - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    left_data[i0] = (real_T)ii_data[i0];
  }

  /*  Gets all the indices in the resultant diff vector for which X[n] - X[n-1] = 1 */
  /*  Finds all the heart beats where  the heart beats are proceeded by a */
  /*  non-beat */
  for (i0 = 0; i0 < 1000; i0++) {
    c[i0] = (real_T)c_c[i0];
  }

  c[1000] = 0.0;
  diff(c, R_loc_data);
  for (i0 = 0; i0 < 1000; i0++) {
    x[i0] = (R_loc_data[i0] == -1.0);
  }

  max_x = 0L;
  for (i0 = 0; i0 < 2; i0++) {
    ii_sizes[i0] = 1 + 999 * i0;
  }

  Ds_1 = 1;
  exitg1 = 0UL;
  while ((exitg1 == 0UL) && (Ds_1 < 1001)) {
    guard1 = FALSE;
    if (x[Ds_1 - 1]) {
      max_x++;
      ii_data[(int16_T)max_x - 1] = (int32_T)Ds_1;
      if (max_x >= 1000L) {
        exitg1 = 1UL;
      } else {
        guard1 = TRUE;
      }
    } else {
      guard1 = TRUE;
    }

    if (guard1 == TRUE) {
      Ds_1++;
    }
  }

  if (1L > max_x) {
    Ds_2 = 0;
  } else {
    Ds_2 = (int16_T)max_x;
  }

  loop_ub = Ds_2 - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    tmp_data[i0] = 1 + i0;
  }

  loop_ub = Ds_2 - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    tmp_sizes = 0;
    while (tmp_sizes <= 0) {
      b_ii_data[i0] = (int16_T)ii_data[tmp_data[i0] - 1];
      tmp_sizes = 1;
    }
  }

  ii_sizes[0L] = 1;
  ii_sizes[1L] = Ds_2;
  loop_ub = Ds_2 - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    ii_data[i0] = (int32_T)b_ii_data[i0];
  }

  loop_ub = ii_sizes[1] - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    right_data[i0] = (int16_T)ii_data[i0];
  }

  /* left=left-(6+16);  % cancel delay because of LP and HP */
  /* right=right-(6+16);% cancel delay because of LP and HP */
  R_value_sizes[0] = 1;
  R_value_sizes[1] = left_sizes_idx_1;
  loop_ub = left_sizes_idx_1 - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    R_value_data[i0] = 0UL;
  }

  loop_ub = left_sizes_idx_1 - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    b_R_loc_data[i0] = 0.0;
  }

  for (i = 0; i <= left_sizes_idx_1 - 1; i++) {
    if ((int16_T)left_data[i] > right_data[i]) {
      i0 = 1;
      tmp_sizes = 1;
    } else {
      i0 = (int16_T)left_data[i];
      tmp_sizes = right_data[i] + 1;
    }

    Ds_1 = tmp_sizes - i0;
    loop_ub = (tmp_sizes - i0) - 1;
    for (tmp_sizes = 0; tmp_sizes <= loop_ub; tmp_sizes++) {
      ii_data[tmp_sizes] = x1[(i0 + tmp_sizes) - 1];
    }

    d_max(ii_data, *(int16_T (*)[1])&Ds_1, &max_x, &d0);
    if (max_x < 0L) {
      max_x = 0L;
    }

    R_value_data[i] = (uint32_T)max_x;
    b_R_loc_data[i] = d0;
    b_R_loc_data[i] = (b_R_loc_data[i] - 1.0) + left_data[i];

    /*  add offset */
    /*      [Q_value(i) Q_loc(i)] = min( x1(left(i):R_loc(i)) ); */
    /*      Q_loc(i) = Q_loc(i)-1+left(i); % add offset */
    /*      [S_value(i) S_loc(i)] = min( x1(left(i):right(i)) ); */
    /*      S_loc(i) = S_loc(i)-1+left(i); % add offset */
  }

  /*  there is no selective wave */
  R_loc_sizes[0] = 1;
  R_loc_sizes[1] = left_sizes_idx_1;
  loop_ub = left_sizes_idx_1 - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    x[i0] = (b_R_loc_data[i0] != 0.0);
  }

  eml_li_find(x, R_loc_sizes, ii_data, ii_sizes);
  max_x = (int32_T)ii_sizes[1L] - 1L;
  for (i0 = 0; (int32_T)i0 <= max_x; i0++) {
    R_loc_data[i0] = b_R_loc_data[(int16_T)ii_data[ii_sizes[0] * i0] - 1];
  }

  max_x = (int32_T)ii_sizes[1L] - 1L;
  for (i0 = 0; (int32_T)i0 <= max_x; i0++) {
    b_R_loc_data[i0] = R_loc_data[i0];
  }

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
  /*  Level 2 Detection: Uses two channels to detect heart beats based on two threshold */
  /*  [num_rows_vals, num_cols_vals] = size(R_peak_vals); */
  /*  Creates a copy of the indices which store the indices where the 'R' peaks */
  /*  lie */
  /*  NEEDS OPTIMIZATION. NEED TO AVOID COPYING LARGE ARRAYS  */
  if (1 > ii_sizes[1L]) {
    Ds_2 = 0;
  } else {
    Ds_2 = ii_sizes[1L];
  }

  if (1 > ii_sizes[1L]) {
    Ds_1 = 0;
  } else {
    Ds_1 = ii_sizes[1L];
  }

  /*  R_peak_indices_channel_3 = R_peak_indices(1:num_cols_indices); */
  if (1 > ii_sizes[1L]) {
    tmp_sizes = 0;
  } else {
    tmp_sizes = ii_sizes[1L];
  }

  loop_ub = tmp_sizes - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    tmp_data[i0] = 1 + i0;
  }

  loop_ub = tmp_sizes - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    left_data[i0] = b_R_loc_data[tmp_data[i0] - 1];
  }

  /*  REPLACE THIS WITH A ZEROS ARRAY */
  /*  UNCOMMENT TO SEE THE NUMBER OF PEAKS BEFORE CHANNEL 1 PROCESSING */
  /*      if (shouldOutput) */
  /*          fprintf('Channel 1 Original: There are %i non-zero values\n',length(find(R_peak_indices_channel_1 ~= 0))); */
  /*      end */
  loop_ub = Ds_2 - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    tmp_data[i0] = 1 + i0;
  }

  R_peak_indices_channel_1_sizes[0] = 1;
  R_peak_indices_channel_1_sizes[1] = Ds_2;
  loop_ub = Ds_2 - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    d0 = b_R_loc_data[tmp_data[i0] - 1];
    d0 = d0 < 0.0 ? ceil(d0 - 0.5) : floor(d0 + 0.5);
    if (d0 < 4.294967296E+9) {
      if (d0 >= 0.0) {
        u0 = (uint32_T)d0;
      } else {
        u0 = 0UL;
      }
    } else if (d0 >= 4.294967296E+9) {
      u0 = MAX_uint32_T;
    } else {
      u0 = 0UL;
    }

    R_peak_indices_channel_1_data[i0] = u0;
  }

  dualThreshold(R_value_data, R_value_sizes, threshold_1,
                R_peak_indices_channel_1_data, R_peak_indices_channel_1_sizes,
                max_h, pos_deviance_threshold, neg_deviance_threshold,
                &heart_beat_current_sum, &heart_beat_last_sum);
  loop_ub = Ds_1 - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    tmp_data[i0] = 1 + i0;
  }

  R_peak_indices_channel_2_sizes[0] = 1;
  R_peak_indices_channel_2_sizes[1] = Ds_1;
  loop_ub = Ds_1 - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    d0 = b_R_loc_data[tmp_data[i0] - 1];
    d0 = d0 < 0.0 ? ceil(d0 - 0.5) : floor(d0 + 0.5);
    if (d0 < 4.294967296E+9) {
      if (d0 >= 0.0) {
        u0 = (uint32_T)d0;
      } else {
        u0 = 0UL;
      }
    } else if (d0 >= 4.294967296E+9) {
      u0 = MAX_uint32_T;
    } else {
      u0 = 0UL;
    }

    R_peak_indices_channel_2_data[i0] = u0;
  }

  dualThreshold(R_value_data, R_value_sizes, threshold_2,
                R_peak_indices_channel_2_data, R_peak_indices_channel_2_sizes,
                max_h, pos_deviance_threshold, neg_deviance_threshold,
                &heart_beat_count, &signal_lvl_channel_2);

  /*  Ensures that noise and signal levels are fixed point */
  /*  UNCOMMENT TO SEE THE NUMBER OF PEAKS AFTER CHANNEL 1 PROCESSING */
  /*      if (shouldOutput) */
  /*          fprintf('Channel 1 Post: There are %i non-zero values\n',length(find(R_peak_indices_channel_1 ~= 0))); */
  /*      end */
  /*  UNCOMMENT TO SEE PLOT OF EKG AFTER BEING PASSED THROUGH THE FIRST CHANNEL */
  /*  if (shouldOutput) */
  /*  Sets R values to zero which failed any of the previous phases  */
  /* R_valuea = R_value; */
  /* for i=1:length(R_valuea) */
  /*     if (R_peak_indices_channel_1(i) == 0) */
  /*         R_valuea(i) = 0; */
  /*     end */
  /* end */
  /* R_valuea = R_valuea(R_valuea ~= 0);    */
  /* R_peak_indices_channel_1a = R_peak_indices_channel_1((R_peak_indices_channel_1 ~= 0)); */
  /* fprintf('The length of R after is: %i\n',length(R_valuea)); */
  /* fprintf('The length of R_indices after is: %i\n',length(R_peak_indices_channel_1a));    */
  /*      t(R_peak_indices_channel_1a); */
  /* clf(figure(13)); */
  /* figure(13) */
  /* subplot(2,1,1) */
  /* plot (t, x1/max(x1), t(R_peak_indices_channel_1a), R_valuea, 'r^'); */
  /* title('ECG Signal Post Channel 1 Processing'); */
  /* xlabel('Time(s)'); */
  /* ylabel('mV'); */
  /* legend('ECG','R'); */
  /* subplot(2,1,2) */
  /* plot (t, x1/max(x1), t(R_peak_indices), R_value, 'r^'); */
  /* title('ECG All Detected Peaks'); */
  /* xlabel('Time(s)'); */
  /* ylabel('mV') */
  /* plot (t, x1/max(x1) , t(R_peak_indices_channel_3) ,R_peak_vals , 'r^', t(S_loc) ,S_value, '*',t(Q_loc) , Q_value, 'o'); */
  /*  end */
  /*  UNCOMMENT TO SEE PLOT OF EKG AFTER BEING PASSED THROUGH THE SECOND CHANNEL */
  /*  if (shouldOutput) */
  /*  Sets R values to zero which failed any of the previous phases  */
  /* R_valuea = R_value; */
  /* for i=1:length(R_valuea) */
  /*     if (R_peak_indices_channel_2(i) == 0) */
  /*         R_valuea(i) = 0; */
  /*     end */
  /* end */
  /* R_valuea = R_valuea(R_valuea ~= 0);    */
  /* R_peak_indices_channel_2a = R_peak_indices_channel_2((R_peak_indices_channel_2 ~= 0)); */
  /* fprintf('The length of R after is: %i\n',length(R_valuea)); */
  /* fprintf('The length of R_indices after is: %i\n',length(R_peak_indices_channel_2a));    */
  /*      t(R_peak_indices_channel_2a); */
  /* clf(figure(13)); */
  /* figure(14) */
  /* subplot(2,1,1) */
  /* plot (t, x1/max(x1), t(R_peak_indices_channel_2a), R_valuea, 'r^'); */
  /* title('ECG Signal Post Channel 2 Processing'); */
  /* xlabel('Time(s)'); */
  /* ylabel('mV'); */
  /* legend('ECG','R'); */
  /* subplot(2,1,2) */
  /* plot (t, x1/max(x1), t(R_peak_indices), R_value, 'r^'); */
  /* title('ECG All Detected Peaks'); */
  /* xlabel('Time(s)'); */
  /* ylabel('mV'); */
  /* legend('ECG','R'); */
  /* plot (t, x1/max(x1) , t(R_peak_indices_channel_3) ,R_peak_vals , 'r^', t(S_loc) ,S_value, '*',t(Q_loc) , Q_value, 'o'); */
  /*  end */
  /*  Level 3 DETECTION: REFINES HEART BEAT DETECTION ACCURACY BY CHANNEL */
  /*  COMPARISON */
  /*  UNCOMMENT TO SEE THE NUMBER OF PEAKS BEFORE LEVEL 3 PROCESSING */
  /* if (shouldOutput) */
  /*     fprintf('\nCombined Original: There are %i non-zero values\n',length(find(R_peak_indices_combined ~= 0))); */
  /* end */
  /*  Combines both channels to refine beat detection */
  for (i = 0; i <= tmp_sizes - 1; i++) {
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
    if ((R_peak_indices_channel_1_data[i] == 0UL) &&
        (R_peak_indices_channel_2_data[i] == 0UL)) {
      left_data[i] = 0.0;
    } else {
      if ((R_peak_indices_channel_1_data[i] != 0UL) &&
          (R_peak_indices_channel_2_data[i] == 0UL)) {
        /*  DELETE DEBUGGING */
        /* if (shouldOutput) */
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
        /*  If the delta between the peak value and the noise level is < 0 */
        /*  then due to unsigned fixed point rules this value is 0 which is what we */
        /*  want anyways so this proves to be a useful overflow case. */
        u0 = mul_u32_u32_u32_sr15_sat_near(R_value_data[i], 3355443200UL);
        q0 = (u0 >> 10) + ((uint16_T)((int16_T)u0 & 512) != 0U);
        u0 = mul_u32_u32_u32_sr15_sat_near(heart_beat_current_sum, 3355443200UL);
        qY = (q0 - (u0 >> 10)) - ((uint16_T)((int16_T)u0 & 512) != 0U);
        if (qY > q0) {
          qY = 0UL;
        }

        u0 = mul_u32_u32_u32_sr15_sat_near(heart_beat_last_sum, 3355443200UL);
        q0 = (u0 >> 10) + ((uint16_T)((int16_T)u0 & 512) != 0U);
        u0 = mul_u32_u32_u32_sr15_sat_near(heart_beat_current_sum, 3355443200UL);
        thresh = (q0 - (u0 >> 10)) - ((uint16_T)((int16_T)u0 & 512) != 0U);
        if (thresh > q0) {
          thresh = 0UL;
        }

        thresh = div_repeat_u32_sat_near(qY, thresh, 10U);
        if (1024UL > thresh) {
          Ds_1 = (int16_T)thresh;
        } else {
          Ds_1 = 1024;
        }

        u0 = mul_u32_u32_u32_sr15_sat_near(R_value_data[i], 3355443200UL);
        q0 = (u0 >> 10) + ((uint16_T)((int16_T)u0 & 512) != 0U);
        u0 = mul_u32_u32_u32_sr15_sat_near(heart_beat_count, 3355443200UL);
        qY = (q0 - (u0 >> 10)) - ((uint16_T)((int16_T)u0 & 512) != 0U);
        if (qY > q0) {
          qY = 0UL;
        }

        u0 = mul_u32_u32_u32_sr15_sat_near(signal_lvl_channel_2, 3355443200UL);
        q0 = (u0 >> 10) + ((uint16_T)((int16_T)u0 & 512) != 0U);
        u0 = mul_u32_u32_u32_sr15_sat_near(heart_beat_count, 3355443200UL);
        thresh = (q0 - (u0 >> 10)) - ((uint16_T)((int16_T)u0 & 512) != 0U);
        if (thresh > q0) {
          thresh = 0UL;
        }

        thresh = div_repeat_u32_sat_near(qY, thresh, 10U);
        if (1024UL > thresh) {
          Ds_2 = (int16_T)thresh;
        } else {
          Ds_2 = 1024;
        }

        if ((uint16_T)Ds_1 > (uint16_T)Ds_2) {
          /* if(shouldOutput) */
          /* fprintf('Ds1: %f Ds2: %f Ds1 wins\n', Ds_1, Ds_2); */
          /* end */
          left_data[i] = (real_T)R_peak_indices_channel_1_data[i];
        } else {
          /* if(shouldOutput) */
          /* fprintf('Ds1: %f Ds2: %f Ds2 wins\n', Ds_1, Ds_2); */
          /* end */
          left_data[i] = (real_T)R_peak_indices_channel_2_data[i];
        }
      }
    }
  }

  /*  UNCOMMENT TO SEE THE NUMBER OF PEAKS AFTER LEVEL 3 PROCESSING */
  /*      if (shouldOutput) */
  /*          fprintf('Combined Post: There are %i non-zero values\n',length(find(R_peak_indices_combined ~= 0))); */
  /*      end */
  /*  Grabs the result of both channels     */
  /*  UNCOMMENT TO SEE THE NUMBER OF PEAKS AFTER LEVEL 4 PROCESSING */
  /* if (shouldOutput) */
  /*     fprintf('\n4th level Original: There are %i non-zero values\n',length(find(R_peak_indices_channel_3 ~= 0))); */
  /* end */
  /*  UNCOMMENT TO USE LEVEL 4 PROCESSING  */
  /* [R_peak_indices_channel_3, noise_lvl_channel_3, signal_lvl_channel_3] = fourth_level_process(threshold_3, R_peak_indices_channel_3); */
  /* if (shouldOutput) */
  /*     fprintf('4th level Post: There are %i non-zero values\n',length(find(R_peak_indices_channel_3 ~= 0))); */
  /* end */
  /*  LEVEL 5 DETECTION:  */
  /* Refines heart beat detection by considering a heart beat's refactory period     */
  /*  Sets R values to zero which failed any of the previous phases */
  thresh = 0UL;

  /*  Sample time delta is based off the Fs passed in */
  /*  Heart beat delta sum is the summation of the time between heart beats. It's used for */
  /*  HR calculation */
  heart_beat_current_sum = 0UL;
  heart_beat_last_sum = 0UL;

  /*  Heart beat count is the amount of heart beats detected */
  heart_beat_count = 0UL;
  for (i = 0; i <= R_value_sizes[1] - 1; i++) {
    if (left_data[i] == 0.0) {
      /*  Filters out any R_values which happen too soon after a previous */
      /*  beat detection. Updates the average HR delta which will be used to */
      /*  calculate HR */
    } else {
      /*  Updates the index */
      d0 = left_data[i] * 1024.0;
      d0 = floor(d0 + 0.5);
      if (d0 < 4.294967296E+9) {
        if (d0 >= 0.0) {
          max_h = (uint32_T)d0;
        } else {
          max_h = 0UL;
        }
      } else if (d0 >= 4.294967296E+9) {
        max_h = MAX_uint32_T;
      } else {
        max_h = 0UL;
      }

      /* Filters out any R_values which happen too soon after a previous */
      /*  beat detection. */
      b_guard1 = FALSE;
      if (thresh != 0UL) {
        qY = max_h - 1024UL;
        if (qY > max_h) {
          qY = 0UL;
        }

        u0 = mul_u32_u32_u32_sr28_sat_near(qY, 2748779069UL);
        q0 = (u0 >> 10) + ((uint16_T)((int16_T)u0 & 512) != 0U);
        qY = thresh - 1024UL;
        if (qY > thresh) {
          qY = 0UL;
        }

        u0 = mul_u32_u32_u32_sr28_sat_near(qY, 2748779069UL);
        qY = (q0 - (u0 >> 10)) - ((uint16_T)((int16_T)u0 & 512) != 0U);
        if (qY > q0) {
          qY = 0UL;
        }

        if ((int32_T)qY < 205L) {
          left_data[i] = 0.0;

          /*  Initializes the first delta which is when the first heart */
          /*  beat occurs */
        } else {
          b_guard1 = TRUE;
        }
      } else {
        b_guard1 = TRUE;
      }

      if (b_guard1 == TRUE) {
        if (thresh == 0UL) {
          qY = max_h - 1024UL;
          if (qY > max_h) {
            qY = 0UL;
          }

          u0 = mul_u32_u32_u32_sr28_sat_near(qY, 2748779069UL);
          q0 = (u0 >> 10) + ((uint16_T)((int16_T)u0 & 512) != 0U);
          heart_beat_current_sum = q0 + prev_hr_delta;
          if (heart_beat_current_sum < q0) {
            heart_beat_current_sum = MAX_uint32_T;
          }

          /*  Updates the last index */
          d0 = left_data[i] * 1024.0;
          d0 = floor(d0 + 0.5);
          if (d0 < 4.294967296E+9) {
            if (d0 >= 0.0) {
              thresh = (uint32_T)d0;
            } else {
              thresh = 0UL;
            }
          } else if (d0 >= 4.294967296E+9) {
            thresh = MAX_uint32_T;
          } else {
            thresh = 0UL;
          }

          /*  Updates the heart beat count */
          qY = heart_beat_count + 1024UL;
          if (qY < heart_beat_count) {
            qY = MAX_uint32_T;
          }

          heart_beat_count = qY;

          /*  Updates the last index if the R_value is valid */
        } else {
          qY = max_h - 1024UL;
          if (qY > max_h) {
            qY = 0UL;
          }

          u0 = mul_u32_u32_u32_sr28_sat_near(qY, 2748779069UL);
          qY = (heart_beat_current_sum + (u0 >> 10)) + ((uint16_T)((int16_T)u0 &
            512) != 0U);
          if (qY < heart_beat_current_sum) {
            qY = MAX_uint32_T;
          }

          heart_beat_current_sum = qY;
          qY = thresh - 1024UL;
          if (qY > thresh) {
            qY = 0UL;
          }

          u0 = mul_u32_u32_u32_sr28_sat_near(qY, 2748779069UL);
          qY = (heart_beat_last_sum + (u0 >> 10)) + ((uint16_T)((int16_T)u0 &
            512) != 0U);
          if (qY < heart_beat_last_sum) {
            qY = MAX_uint32_T;
          }

          heart_beat_last_sum = qY;

          /*              heart_beat_delta = (current_R_index - 1) * time_delta - (last_R_index - 1) * time_delta; */
          /*              heart_beat_current_sum = heart_beat_current_sum + heart_beat_delta; */
          /*  Updates the heart beat count */
          qY = heart_beat_count + 1024UL;
          if (qY < heart_beat_count) {
            qY = MAX_uint32_T;
          }

          heart_beat_count = qY;

          /*  Updates the last index */
          d0 = left_data[i] * 1024.0;
          d0 = floor(d0 + 0.5);
          if (d0 < 4.294967296E+9) {
            if (d0 >= 0.0) {
              thresh = (uint32_T)d0;
            } else {
              thresh = 0UL;
            }
          } else if (d0 >= 4.294967296E+9) {
            thresh = MAX_uint32_T;
          } else {
            thresh = 0UL;
          }
        }
      }
    }
  }

  if (sample_time > 4194303UL) {
    q0 = MAX_uint32_T;
  } else {
    q0 = sample_time << 10;
  }

  u0 = mul_u32_u32_u32_sr28_sat_near(thresh, 2748779069UL);
  *last_hr_delta = (q0 - (u0 >> 10)) - ((uint16_T)((int16_T)u0 & 512) != 0U);
  if (*last_hr_delta > q0) {
    *last_hr_delta = 0UL;
  }

  /*  Removes all zero values from both the indice and value array */
  /*  R_peak_vals = R_peak_vals(R_peak_vals ~= 0); */
  /* plots R peaks after all level processing */
  /*  if (shouldOutput) */
  /* clf(figure(14)); */
  /* figure(15) */
  /* subplot(2,1,1) */
  /* plot (t, x1/max(x1), t(R_peak_indices_channel_3), R_peak_vals, 'r^'); */
  /* title('Final ECG Signal with R points'); */
  /* xlabel('Time(s)'); */
  /* ylabel('mV'); */
  /* legend('ECG','R'); */
  /* subplot(2,1,2) */
  /* plot (t, x1/max(x1), t(R_peak_indices), R_value, 'r^'); */
  /* title('ECG All Detected Peaks'); */
  /* xlabel('Time(s)'); */
  /* ylabel('mV'); */
  /* legend('ECG','R'); */
  /* plot (t, x1/max(x1) , t(R_peak_indices_channel_3) ,R_peak_vals , 'r^', t(S_loc) ,S_value, '*',t(Q_loc) , Q_value, 'o'); */
  /*  end */
  /* xlim([1 3]); */
  /* plot (t(R_peak_indices_channel_3) ,R_peak_vals, 'r^'); */
  /* plot (t,x1/max(x1) , t(R_loc) ,R_value , 'r^', t(S_loc) ,S_value, '*',t(Q_loc) , Q_value, 'o'); */
  /* xlabel('Seconds'); ylabel('Normalized Magnitude');title('R peaks'); */
  /* %plot(R_peak_vals, 'r+'); */
  /*  CALCULATES HEART RATE */
  /*  NOTE: This will assume that only 1-min windows of the EKG are sent in as */
  /*  the data type */
  /*  Counts how many R peak counts are found in N seconds */
  /*  R_peak_count */
  /*  heart_rate = divide(Fixed_Point_Properties, R_peak_count, sample_time) * 60; */
  /*  CALCULATES HEART RATE USING AVERAGE TIME TIME DELTAS BETWEEN BEATS */
  /*    Provides less quantized HR values */
  /*  Produces a result which is avg heart beat delta(s) */
  /*  heart_beat_delta_sum = heart_beat_current_sum; */
  /*  Inverses it to produce HBPM */
  qY = heart_beat_current_sum - heart_beat_last_sum;
  if (qY > heart_beat_current_sum) {
    qY = 0UL;
  }

  *heart_rate = mul_u32_u32_u32_sr16_sat_near(div_u32_SR_near(2147483648UL,
    div_repeat_u32_sat_near(qY, heart_beat_count, 10U), 11U), 4026531840UL);
}

/* End of code generation (heart_rate_official_cport.c) */
