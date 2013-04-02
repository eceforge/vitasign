/*
 * heart_rate_official_cport.c
 *
 * Code generation for function 'heart_rate_official_cport'
 *
 * C source code generated on: Mon Mar 11 20:10:04 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "abs.h"
#include "plus.h"
#include "minus.h"
#include "sqrt.h"
#include "mean.h"
#include "max.h"
#include "conv.h"
#include "heart_rate_official_cport_rtwutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern int32_T div_repeat_s32_sat_near(int32_T numerator, int32_T denominator,
  uint16_T nRepeatSub);
static int32_T div_s32_SR_near(int32_T numerator, int32_T denominator, uint16_T
  nShiftRight);
static void dualThreshold(const int32_T R_peak_vals[500], int32_T threshold,
  uint32_T indices[500], int32_T max_voltage, int32_T pos_deviance_threshold,
  int32_T neg_deviance_threshold, uint32_T num_cols_indices, int32_T *noise_lvl,
  int32_T *signal_lvl);
static int32_T mul_s32_s32_s32_sr14_sat_near(int32_T a, int32_T b);
static int32_T mul_s32_s32_s32_sr15_sat_near(int32_T a, int32_T b);
static int32_T mul_s32_s32_s32_sr27_sat_near(int32_T a, int32_T b);
static boolean_T sMultiWordGt(const uint32_T u1[], const uint32_T u2[], int16_T
  n);
static boolean_T sMultiWordLt(const uint32_T u1[], const uint32_T u2[], int16_T
  n);

/* Function Definitions */
extern int32_T div_repeat_s32_sat_near(int32_T numerator, int32_T denominator,
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

static int32_T div_s32_SR_near(int32_T numerator, int32_T denominator, uint16_T
  nShiftRight)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  int16_T quotientNeedsNegation;
  uint32_T tempAbsQuotient;
  uint32_T tempAbsQuotReduced;
  uint32_T maskMSdropoffBit;
  if (denominator == (int32_T)0) {
    quotient = numerator >= (int32_T)0 ? MAX_int32_T : MIN_int32_T;
  } else {
    absNumerator = (uint32_T)(numerator >= (int32_T)0 ? numerator : -numerator);
    absDenominator = (uint32_T)(denominator >= (int32_T)0 ? denominator :
      -denominator);
    quotientNeedsNegation = ((numerator < (int32_T)0) != (denominator < (int32_T)
      0));
    tempAbsQuotient = absNumerator / absDenominator;
    tempAbsQuotReduced = nShiftRight >= 32U ? (uint32_T)0 : tempAbsQuotient >>
      nShiftRight;
    if (nShiftRight <= 32U) {
      tempAbsQuotient &= MAX_uint32_T >> (32 - (int16_T)nShiftRight);
      maskMSdropoffBit = 1UL << ((int16_T)nShiftRight - 1);
      if ((tempAbsQuotient >= maskMSdropoffBit) && ((!(uint16_T)
            quotientNeedsNegation) || (tempAbsQuotient > maskMSdropoffBit) ||
           (absNumerator % absDenominator))) {
        tempAbsQuotReduced++;
      }
    }

    quotient = (uint16_T)quotientNeedsNegation ? -(int32_T)tempAbsQuotReduced :
      (int32_T)tempAbsQuotReduced;
  }

  return quotient;
}

static void dualThreshold(const int32_T R_peak_vals[500], int32_T threshold,
  uint32_T indices[500], int32_T max_voltage, int32_T pos_deviance_threshold,
  int32_T neg_deviance_threshold, uint32_T num_cols_indices, int32_T *noise_lvl,
  int32_T *signal_lvl)
{
  int32_T noise_sum;
  int32_T signal_sum;
  int32_T noise_count;
  int32_T signal_count;
  int16_T b_index;
  int64m_T r11;
  int64m_T r12;
  int64m_T r13;
  int64m_T r14;
  int16_T is_neg;
  int32_T deviance;
  int32_T q0;
  int32_T qY;
  int64m_T r15;
  int64m_T r16;
  int64m_T r17;

  /* DUAL THRESHOLD PROCESSSING */
  /*  Filters out R_peaks which don't meet the threshold reqs */
  /*  asserts that the input parameters are of fixed point */
  /*  asserts that input parameters are of specific fixed point parameters */
  noise_sum = 0L;
  signal_sum = 0L;
  noise_count = 0L;
  signal_count = 0L;

  /*  Setting signal count to 1 ensures that the first value doesn't dominate the avg signal level */
  *noise_lvl = 0L;
  *signal_lvl = 0L;
  for (b_index = 0; (uint32_T)(b_index + 1) <= num_cols_indices; b_index++) {
    sLong2MultiWord(mul_s32_s32_s32_sat(R_peak_vals[b_index], max_voltage),
                    &r11.chunks[0U], 2);
    MultiWordSignedWrap(&r11.chunks[0U], 2, 22U, &r12.chunks[0U]);
    sLong2MultiWord(threshold, &r13.chunks[0U], 2);
    sMultiWordShl(&r13.chunks[0U], 2, 10U, &r14.chunks[0U], 2);
    MultiWordSignedWrap(&r14.chunks[0U], 2, 22U, &r11.chunks[0U]);
    if (sMultiWordGt(&r12.chunks[0U], &r11.chunks[0U], 2)) {
      /*  Filters out any signal value which exceeds the allowed deviance from */
      /*  the average signal value  */
      /*  RETURNS TRUE IF THE INPUT SIGNAL VALUE MEETS THE DEVIANCE REQS. NOTE */
      /*  THE THRESHOLD VALUE CHANGES BASED ON WHETHER DEVIANCE IS NEG OR POS */
      /*  asserts that the input parameters are of fixed point */
      /*  asserts that input parameters are of specific fixed point parameters */
      /* Accounts for the first signal value */
      if (*signal_lvl == 0L) {
        is_neg = 1;
      } else {
        if (R_peak_vals[b_index] < *signal_lvl) {
          deviance = mul_s32_s32_s32_sr14_sat_near(*signal_lvl, 1677721600L);
          q0 = (deviance >> 10) + ((deviance & 512L) != 0L);
          deviance = mul_s32_s32_s32_sr14_sat_near(R_peak_vals[b_index],
            1677721600L);
          deviance = (deviance >> 10) + ((deviance & 512L) != 0L);
          qY = q0 - deviance;
          if ((q0 < 0L) && ((deviance >= 0L) && (qY >= 0L))) {
            qY = MIN_int32_T;
          } else {
            if ((q0 >= 0L) && ((deviance < 0L) && (qY < 0L))) {
              qY = MAX_int32_T;
            }
          }

          deviance = div_repeat_s32_sat_near(qY, *signal_lvl, 10U);
          is_neg = 1;
        } else {
          deviance = mul_s32_s32_s32_sr14_sat_near(R_peak_vals[b_index],
            1677721600L);
          q0 = (deviance >> 10) + ((deviance & 512L) != 0L);
          deviance = mul_s32_s32_s32_sr14_sat_near(*signal_lvl, 1677721600L);
          deviance = (deviance >> 10) + ((deviance & 512L) != 0L);
          qY = q0 - deviance;
          if ((q0 < 0L) && ((deviance >= 0L) && (qY >= 0L))) {
            qY = MIN_int32_T;
          } else {
            if ((q0 >= 0L) && ((deviance < 0L) && (qY < 0L))) {
              qY = MAX_int32_T;
            }
          }

          deviance = div_repeat_s32_sat_near(qY, *signal_lvl, 10U);
          is_neg = 0;
        }

        /*  Checks value against NEG and POS deviance threshold */
        if (is_neg != 0) {
          sLong2MultiWord(deviance, &r15.chunks[0U], 2);
          sMultiWordShl(&r15.chunks[0U], 2, 10U, &r16.chunks[0U], 2);
          MultiWordSignedWrap(&r16.chunks[0U], 2, 22U, &r17.chunks[0U]);
          sLong2MultiWord(mul_s32_s32_s32_sr14_sat_near(neg_deviance_threshold,
            1677721600L), &r15.chunks[0U], 2);
          MultiWordSignedWrap(&r15.chunks[0U], 2, 22U, &r16.chunks[0U]);
          if (sMultiWordLt(&r17.chunks[0U], &r16.chunks[0U], 2)) {
            is_neg = 1;
          } else {
            /*              fprintf('Does not meet neg deviance threshold %d\n', double(deviance)); */
            is_neg = 0;
          }
        } else {
          sLong2MultiWord(deviance, &r17.chunks[0U], 2);
          sMultiWordShl(&r17.chunks[0U], 2, 10U, &r13.chunks[0U], 2);
          MultiWordSignedWrap(&r13.chunks[0U], 2, 22U, &r14.chunks[0U]);
          sLong2MultiWord(mul_s32_s32_s32_sr14_sat_near(pos_deviance_threshold,
            1677721600L), &r17.chunks[0U], 2);
          MultiWordSignedWrap(&r17.chunks[0U], 2, 22U, &r13.chunks[0U]);
          if (sMultiWordLt(&r14.chunks[0U], &r13.chunks[0U], 2)) {
            is_neg = 1;
          } else {
            /*              fprintf('Does not meet pos deviance threshold %d\n', double(deviance)); */
            is_neg = 0;
          }
        }
      }

      if ((!(is_neg != 0)) && (b_index + 1 > 4)) {
        /*  Sets all the indices which R_vals don't meet the threshold to 0 */
        indices[b_index] = 0UL;

        /*  Updates the average noise signal lvl */
        deviance = R_peak_vals[b_index];
        qY = noise_sum + deviance;
        if ((noise_sum < 0L) && ((deviance < 0L) && (qY >= 0L))) {
          qY = MIN_int32_T;
        } else {
          if ((noise_sum > 0L) && ((deviance > 0L) && (qY <= 0L))) {
            qY = MAX_int32_T;
          }
        }

        noise_sum = qY;
        qY = noise_count + 1024L;
        if ((noise_count > 0L) && (qY <= 0L)) {
          qY = MAX_int32_T;
        }

        noise_count = qY;

        /*  Calculates the noise level */
        *noise_lvl = div_repeat_s32_sat_near(noise_sum, noise_count, 10U);
      } else {
        /*  Updates the average signal lvl */
        deviance = R_peak_vals[b_index];
        qY = signal_sum + deviance;
        if ((signal_sum < 0L) && ((deviance < 0L) && (qY >= 0L))) {
          qY = MIN_int32_T;
        } else {
          if ((signal_sum > 0L) && ((deviance > 0L) && (qY <= 0L))) {
            qY = MAX_int32_T;
          }
        }

        signal_sum = qY;
        qY = signal_count + 1024L;
        if ((signal_count > 0L) && (qY <= 0L)) {
          qY = MAX_int32_T;
        }

        signal_count = qY;

        /*  Calculates the signal level */
        *signal_lvl = div_repeat_s32_sat_near(signal_sum, signal_count, 10U);
      }
    } else {
      /*  Sets all the indices which R_vals don't meet the threshold to 0 */
      indices[b_index] = 0UL;

      /*  Updates the average noise signal lvl */
      deviance = R_peak_vals[b_index];
      qY = noise_sum + deviance;
      if ((noise_sum < 0L) && ((deviance < 0L) && (qY >= 0L))) {
        qY = MIN_int32_T;
      } else {
        if ((noise_sum > 0L) && ((deviance > 0L) && (qY <= 0L))) {
          qY = MAX_int32_T;
        }
      }

      noise_sum = qY;
      qY = noise_count + 1024L;
      if ((noise_count > 0L) && (qY <= 0L)) {
        qY = MAX_int32_T;
      }

      noise_count = qY;

      /*  Calculates the noise level */
      *noise_lvl = div_repeat_s32_sat_near(noise_sum, noise_count, 10U);
    }
  }
}

static int32_T mul_s32_s32_s32_sr14_sat_near(int32_T a, int32_T b)
{
  int32_T result;
  uint32_T u32_clo;
  uint32_T u32_chi;
  boolean_T roundup;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  roundup = ((uint16_T)((int16_T)u32_clo & 8192) != 0U);
  u32_clo = (u32_chi << 18UL | u32_clo >> 14) + (uint32_T)roundup;
  u32_chi = (uint32_T)((int32_T)u32_chi >> 14) + (uint32_T)(roundup && (u32_clo ==
    0UL));
  if (((int32_T)u32_chi > 0L) || ((u32_chi == 0UL) && (u32_clo >= 2147483648UL)))
  {
    result = MAX_int32_T;
  } else if (((int32_T)u32_chi < -1L) || (((int32_T)u32_chi == -1L) && (u32_clo <
    2147483648UL))) {
    result = MIN_int32_T;
  } else {
    result = (int32_T)u32_clo;
  }

  return result;
}

static int32_T mul_s32_s32_s32_sr15_sat_near(int32_T a, int32_T b)
{
  int32_T result;
  uint32_T u32_clo;
  uint32_T u32_chi;
  boolean_T roundup;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  roundup = ((uint16_T)((int16_T)u32_clo & 16384) != 0U);
  u32_clo = (u32_chi << 17UL | u32_clo >> 15) + (uint32_T)roundup;
  u32_chi = (uint32_T)((int32_T)u32_chi >> 15) + (uint32_T)(roundup && (u32_clo ==
    0UL));
  if (((int32_T)u32_chi > 0L) || ((u32_chi == 0UL) && (u32_clo >= 2147483648UL)))
  {
    result = MAX_int32_T;
  } else if (((int32_T)u32_chi < -1L) || (((int32_T)u32_chi == -1L) && (u32_clo <
    2147483648UL))) {
    result = MIN_int32_T;
  } else {
    result = (int32_T)u32_clo;
  }

  return result;
}

static int32_T mul_s32_s32_s32_sr27_sat_near(int32_T a, int32_T b)
{
  int32_T result;
  uint32_T u32_clo;
  uint32_T u32_chi;
  boolean_T roundup;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  roundup = ((int32_T)(u32_clo & 67108864UL) != 0L);
  u32_clo = (u32_chi << 5UL | u32_clo >> 27) + (uint32_T)roundup;
  u32_chi = (uint32_T)((int32_T)u32_chi >> 27) + (uint32_T)(roundup && (u32_clo ==
    0UL));
  if (((int32_T)u32_chi > 0L) || ((u32_chi == 0UL) && (u32_clo >= 2147483648UL)))
  {
    result = MAX_int32_T;
  } else if (((int32_T)u32_chi < -1L) || (((int32_T)u32_chi == -1L) && (u32_clo <
    2147483648UL))) {
    result = MIN_int32_T;
  } else {
    result = (int32_T)u32_clo;
  }

  return result;
}

static boolean_T sMultiWordGt(const uint32_T u1[], const uint32_T u2[], int16_T
  n)
{
  return sMultiWordCmp(u1, u2, n) > 0 ? TRUE : FALSE;
}

static boolean_T sMultiWordLt(const uint32_T u1[], const uint32_T u2[], int16_T
  n)
{
  return sMultiWordCmp(u1, u2, n) < 0 ? TRUE : FALSE;
}

void heart_rate_official_cport(int32_T data[500], uint32_T fs, int32_T
  threshold_1, int32_T threshold_2, int32_T threshold_3, int32_T
  pos_deviance_threshold, int32_T neg_deviance_threshold, uint32_T sample_time,
  uint32_T shouldOutput, int32_T prev_hr_delta, int32_T *heart_rate, int32_T
  *last_hr_delta)
{
  int32_T thresh;
  int16_T left_index;
  int32_T q0;
  int32_T qY;
  int32_T max_val;
  int16_T i;
  static const int32_T iv0[5] = { -128L, -256L, 0L, 256L, 128L };
#pragma SET_DATA_SECTION (".big_stuff")
  static int32_T b_data[504];
  static int32_T c_data[506];
  static uint32_T left[500];
#pragma SET_DATA_SECTION()

#pragma SET_DATA_SECTION(".big_stuff")
  static int16_T right[500];
#pragma SET_DATA_SECTION()

#pragma SET_DATA_SECTION(".big_stuff")
  static uint32_T R_peak_indices_channel_1[500];
#pragma SET_DATA_SECTION()
  int32_T q1;
  int32_T iv1[7];
  int32_T max_voltage;
  int16_T right_index;
  int64m_T r4;
  int64m_T r5;
  int64m_T r6;
  int64m_T r7;
  int64m_T r8;
  int64m_T r9;
  int64m_T r10;
  uint32_T num_cols_indices;
  uint32_T j;
  int32_T heart_beat_count;
  int32_T heart_beat_last_sum;
  int32_T signal_lvl_channel_2;
  int32_T noise_lvl_channel_2;
  boolean_T guard1 = FALSE;

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
  /*  assert(isequal(numerictype(data), Fixed_Point_Properties) && isequal(fimath(data), F)); */
  /*  Ensures that the prev time delta is unsigned and has fractional bits */
  /*  specified by Fixed_Point_Properties */
  /*  assert(isequal(numerictype(sample_time),Fixed_Point_Properties) && isequal(fimath(sample_time), F)); */
  /*   Assures that the first threshold is less than the second threshold */
  /*   Assures that the third threshold is in between the first and the second */
  /*  threshold */
  /* x1 = load('ecg3.dat'); % load the ECG signal from the file */
  /*  x1 = data; */
  /*  Signal length */
  /*  Assures that the number of samples sent in aren't greater than the */
  /*  specified sample size */
  /*  x1 = x1/ max( abs(x1 )); % normalize to one */
  /*  max_x = fi(max(abs(data)), Fixed_Point_Properties_signed, F_signed); */
  /* CANCELLATION DC DRIFT AND NORMALIZATION */
  thresh = mean(data);
  for (left_index = 0; left_index < 500; left_index++) {
    q0 = data[left_index];
    qY = q0 - thresh;
    if ((q0 < 0L) && ((thresh >= 0L) && (qY >= 0L))) {
      qY = MIN_int32_T;
    } else {
      if ((q0 >= 0L) && ((thresh < 0L) && (qY < 0L))) {
        qY = MAX_int32_T;
      }
    }

    data[left_index] = qY;
  }

  /*  cancel DC conponents */
  max_val = 0L;

  /*  Finds the maximum of the absolute value of the array */
  for (i = 0; i < 500; i++) {
    thresh = b_abs(data[i]);
    if (thresh > max_val) {
      max_val = thresh;
    }
  }

  /*  % for i=1:length(x1) */
  /*  %     divide(Fixed_Point_Properties_signed, x1(i), max_x) % normalize to one */
  /*  % end */
  for (left_index = 0; left_index < 500; left_index++) {
    data[left_index] = div_repeat_s32_sat_near(data[left_index], max_val, 10U);
  }

  /*  normalize to one */
  /*  assert(isequal(numerictype(data),Fixed_Point_Properties_signed) && isequal(fimath(data), F_signed)); */
  /* ------ MOST FILTERING NOW OCCURS IN ANALOG SEE 'front_end_filters.m' FOR EMULATED FRONT END FILTERS */
  /* DERIVATIVE FILTER */
  /*  Make impulse response */
  /*  Apply filter */
  conv(data, iv0, b_data);

  /*  max_val = fi(max(abs(data)), Fixed_Point_Properties_signed, F_signed); */
  max_val = 0L;

  /*  Finds the absolute value of the array */
  for (i = 0; i < 500; i++) {
    thresh = c_abs(b_data[2 + i]);
    if (thresh > max_val) {
      max_val = thresh;
    }
  }

  for (i = 0; i < 500; i++) {
    data[i] = div_repeat_s32_sat_near(b_data[i + 2], max_val, 10U);
  }

  /*  UPDATES FIXED POINT DEFINITION TO BE UNSIGNED(CURRENTLY REVERESED TO BE */
  /*  SIGNED B/C OF SPACE CONSTRAINTS */
  /* SQUARING */
  for (i = 0; i < 500; i++) {
    q1 = mul_s32_s32_s32_sat(data[i], data[i]);
    data[i] = (q1 >> 10) + ((q1 & 512L) != 0L);
  }

  /*  data = fi(data.^2, Fixed_Point_Properties, F); */
  /*  squared_data = data; */
  /*  Changes the fixed point properties of the data to be unsigned after */
  /*  squaring */
  /*  data_unsigned = fi(data, Fixed_Point_Properties, F); */
  /*  Normalizes the result of the squaring */
  /*  data_unsigned = divide(Fixed_Point_Properties, data_unsigned, max( data_unsigned )); % normalize to one */
  /*  assert(isequal(numerictype(data_unsigned),Fixed_Point_Properties) && isequal(fimath(data_unsigned), F)); */
  /* MOVING WINDOW INTEGRATION */
  /*  Make impulse response */
  /*  Delay = 15; % Delay in samples */
  /*  Apply filter */
  for (left_index = 0; left_index < 7; left_index++) {
    iv1[left_index] = 146L;
  }

  b_conv(data, iv1, c_data);

  /*  Normalizes the signal  */
  thresh = b_max(*(int32_T (*)[500])&c_data[3]);
  for (i = 0; i < 500; i++) {
    data[i] = div_repeat_s32_sat_near(c_data[i + 3], thresh, 10U);
  }

  /*  normalize to one */
  /* FIND QRS POINTS. NOTE: THE PEAK FINDING IS DIFFERENT THAN PAN-TOMPKINS ALGORITHM */
  max_voltage = b_max(data);
  thresh = mean(data);
  thresh = mul_s32_s32_s32_sat(thresh, max_voltage);

  /*  Outputs an array with each value indicating whether the value at that */
  /*  index is greater than thresh * max_h */
  /*  poss_reg = int32((data_unsigned > thresh*max_voltage)'); */
  /*  poss_reg =(data_unsigned > thresh*max_voltage)'; */
  for (left_index = 0; left_index < 500; left_index++) {
    left[left_index] = 0UL;
    right[left_index] = 0;
  }

  /*   Finds(the indices) all the heart beats which are preceded by a */
  /*   non-beat(left) */
  /*  Finds all the heart beats where  the heart beats are proceeded by a */
  /*  non-beat(right) */
  left_index = 0;
  right_index = 0;
  for (i = 0; i < 500; i++) {
    sLong2MultiWord(data[i], &r4.chunks[0U], 2);
    sMultiWordShl(&r4.chunks[0U], 2, 10U, &r5.chunks[0U], 2);
    MultiWordSignedWrap(&r5.chunks[0U], 2, 22U, &r6.chunks[0U]);
    sLong2MultiWord(thresh, &r4.chunks[0U], 2);
    MultiWordSignedWrap(&r4.chunks[0U], 2, 22U, &r5.chunks[0U]);
    if (sMultiWordGt(&r6.chunks[0U], &r5.chunks[0U], 2)) {
      /*  Checks for the edge cases */
      if (i + 1 == 1) {
        left[left_index] = 1UL;
        left_index++;
      } else if ((uint16_T)(i + 1) == 500U) {
        right[right_index] = 500;
        right_index++;
      } else {
        /*  Checks if a beat is proceeded or preceeded by a beat */
        sLong2MultiWord(data[i - 1], &r7.chunks[0U], 2);
        sMultiWordShl(&r7.chunks[0U], 2, 10U, &r8.chunks[0U], 2);
        MultiWordSignedWrap(&r8.chunks[0U], 2, 22U, &r4.chunks[0U]);
        sLong2MultiWord(thresh, &r7.chunks[0U], 2);
        MultiWordSignedWrap(&r7.chunks[0U], 2, 22U, &r8.chunks[0U]);
        if (sMultiWordLe(&r4.chunks[0U], &r8.chunks[0U], 2)) {
          left[left_index] = (uint32_T)(i + 1);
          left_index++;
        } else {
          sLong2MultiWord(data[i + 1], &r9.chunks[0U], 2);
          sMultiWordShl(&r9.chunks[0U], 2, 10U, &r10.chunks[0U], 2);
          MultiWordSignedWrap(&r10.chunks[0U], 2, 22U, &r7.chunks[0U]);
          sLong2MultiWord(thresh, &r9.chunks[0U], 2);
          MultiWordSignedWrap(&r9.chunks[0U], 2, 22U, &r10.chunks[0U]);
          if (sMultiWordLe(&r7.chunks[0U], &r10.chunks[0U], 2)) {
            right[right_index] = i + 1;
            right_index++;
          }
        }
      }
    } else {
      /*          left(i) = uint32(0); */
      /*          right(i) = uint32(0); */
    }
  }

  /*   Finds(the indices) all the heart beats which are preceded by a non-beat */
  /*  left = uint32(find(diff([int32(0) poss_reg]) == int32(1))) % Gets all the indices in the resultant diff vector for which X[n] - X[n-1] = 1 */
  /*  Finds all the heart beats where  the heart beats are proceeded by a */
  /*  non-beat */
  /*  right = uint32(find(diff([poss_reg 0]) == int32(-1))) */
  /*  Don't need poss_reg after this call */
  /*   Finds(the indices) all the heart beats which are preceded by a non-beat */
  /*  left = find(diff([0 poss_reg])==1); % Gets all the indices in the resultant diff vector for which X[n] - X[n-1] = 1 */
  /*  Finds all the heart beats where  the heart beats are proceeded by a */
  /*  non-beat */
  /*  right = find(diff([poss_reg 0])==-1); */
  /* left=left-(6+16);  % cancel delay because of LP and HP */
  /* right=right-(6+16);% cancel delay because of LP and HP */
  /*  [~, left_num_cols] = size(left); */
  /*  R_peak_vals = fi(zeros(uint32(1), left_num_cols), Fixed_Point_Properties, F); */
  memset((void *)&R_peak_indices_channel_1[0L], 0, 500U * sizeof(uint32_T));
  max_val = 0L;
  left_index = 0;
  num_cols_indices = 0UL;
  i = 0;
  while (((uint16_T)(i + 1) < 501U) && (!(left[i] == 0UL))) {
    /*       [R_peak_vals(i) R_peak_indices(i)] = max(data(left(i):right(i)) ); */
    /*       [data_unsigned(i) R_peak_indices_channel_1(i)] = max(data_unsigned(left(i):right(i)) ); */
    /*       Finds the max value from left(i) to right(i) */
    for (j = left[i]; j <= (uint32_T)right[i]; j = (uint32_T)((int16_T)j + 1)) {
      /*  Compares to find the maximum */
      thresh = (int32_T)b_sqrt(data[(int16_T)j - 1]) << 5;
      if (thresh > max_val) {
        max_val = (int32_T)b_sqrt(data[(int16_T)j - 1]) << 5;
        left_index = (int16_T)j;
      }
    }

    /*  Saves the peak's index and value */
    data[i] = max_val;
    R_peak_indices_channel_1[i] = (uint32_T)left_index;
    j = num_cols_indices + 1UL;
    if (j < num_cols_indices) {
      j = MAX_uint32_T;
    }

    num_cols_indices = j;

    /*  Resets max for next iteration */
    max_val = 0L;
    i++;
  }

  /*  there is no selective wave */
  /*  R_peak_indices_channel_1=R_peak_indices_channel_1(R_peak_indices_channel_1~=uint32(0)); */
  /*  VITASIGN'S CODE BELOW */
  /*  Level 1 Detection: Detects all peaks  */
  /*  R_peak_vals = R_peak_vals; */
  /*  R_peak_indices = R_peak_indices; */
  /*  Level 2 Detection: Uses two channels to detect heart beats based on two threshold */
  /*  [num_rows_vals, num_cols_vals] = size(R_peak_vals); */
  /*  [~, num_cols_indices] = size(R_peak_indices); */
  /*  num_cols_indices = uint32(length(R_peak_indices_channel_1)); */
  /*  Creates a copy of the indices which store the indices where the 'R' peaks */
  /*  lie */
  /*  if(shouldOutput) */
  /*       num_cols_indices; */
  /*  end */
  /*  R_peak_indices_channel_1 = R_peak_indices(1:num_cols_indices);  */
  /*  R_peak_indices_combined = zeros(1, length(R_peak_indices_channel_2)); % REPLACE THIS WITH A ZEROS ARRAY */
  memcpy((void *)&left[0L], (void *)&R_peak_indices_channel_1[0L], 500U * sizeof
         (uint32_T));
  dualThreshold(data, threshold_1, left, max_voltage, pos_deviance_threshold,
                neg_deviance_threshold, num_cols_indices, &heart_beat_last_sum,
                &heart_beat_count);
  dualThreshold(data, threshold_2, R_peak_indices_channel_1, max_voltage,
                pos_deviance_threshold, neg_deviance_threshold, num_cols_indices,
                &noise_lvl_channel_2, &signal_lvl_channel_2);

  /*  CAN RELEASE DATA HERE  */
  /*  if(shouldOutput) */
  /*      chan1 = length(find(R_peak_indices_channel_1)) */
  /*      chan2 = length(find(R_peak_indices_channel_2)) */
  /*  end */
  /*  Ensures that noise and signal levels are fixed point */
  /*  Level 3 DETECTION: REFINES HEART BEAT DETECTION ACCURACY BY CHANNEL */
  /*  COMPARISON */
  /*  Combines both channels to refine beat detection */
  for (i = 0; (uint32_T)(i + 1) <= num_cols_indices; i++) {
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
    if ((left[i] == 0UL) && (R_peak_indices_channel_1[i] == 0UL)) {
      R_peak_indices_channel_1[i] = 0UL;
    } else {
      if ((left[i] != 0UL) && (R_peak_indices_channel_1[i] == 0UL)) {
        /*  Uses the decision of the channel w/ the highest Detection. */
        /*  Ensures that Ds is between 0 and 1 */
        /*  strength(Ds) */
        /*  If the delta between the peak value and the noise level is < 0 */
        /*  then due to unsigned fixed point rules this value is 0 which is what we */
        /*  want anyways so this proves to be a useful overflow case. */
        if (heart_beat_count < heart_beat_last_sum) {
          max_val = 0L;
        } else {
          q1 = mul_s32_s32_s32_sr14_sat_near(data[i], 1677721600L);
          q0 = (q1 >> 10) + ((q1 & 512L) != 0L);
          q1 = mul_s32_s32_s32_sr14_sat_near(heart_beat_last_sum, 1677721600L);
          q1 = (q1 >> 10) + ((q1 & 512L) != 0L);
          qY = q0 - q1;
          if ((q0 < 0L) && ((q1 >= 0L) && (qY >= 0L))) {
            qY = MIN_int32_T;
          } else {
            if ((q0 >= 0L) && ((q1 < 0L) && (qY < 0L))) {
              qY = MAX_int32_T;
            }
          }

          q1 = mul_s32_s32_s32_sr14_sat_near(heart_beat_count, 1677721600L);
          q0 = (q1 >> 10) + ((q1 & 512L) != 0L);
          q1 = mul_s32_s32_s32_sr14_sat_near(heart_beat_last_sum, 1677721600L);
          q1 = (q1 >> 10) + ((q1 & 512L) != 0L);
          thresh = q0 - q1;
          if ((q0 < 0L) && ((q1 >= 0L) && (thresh >= 0L))) {
            thresh = MIN_int32_T;
          } else {
            if ((q0 >= 0L) && ((q1 < 0L) && (thresh < 0L))) {
              thresh = MAX_int32_T;
            }
          }

          max_val = div_repeat_s32_sat_near(qY, thresh, 10U);
          if (1024L > max_val) {
          } else {
            max_val = 1024L;
          }
        }

        /*          Ds_1 = max(0, Ds_1); */
        if (signal_lvl_channel_2 < noise_lvl_channel_2) {
          thresh = 0L;
        } else {
          q1 = mul_s32_s32_s32_sr14_sat_near(data[i], 1677721600L);
          q0 = (q1 >> 10) + ((q1 & 512L) != 0L);
          q1 = mul_s32_s32_s32_sr14_sat_near(noise_lvl_channel_2, 1677721600L);
          q1 = (q1 >> 10) + ((q1 & 512L) != 0L);
          qY = q0 - q1;
          if ((q0 < 0L) && ((q1 >= 0L) && (qY >= 0L))) {
            qY = MIN_int32_T;
          } else {
            if ((q0 >= 0L) && ((q1 < 0L) && (qY < 0L))) {
              qY = MAX_int32_T;
            }
          }

          q1 = mul_s32_s32_s32_sr14_sat_near(signal_lvl_channel_2, 1677721600L);
          q0 = (q1 >> 10) + ((q1 & 512L) != 0L);
          q1 = mul_s32_s32_s32_sr14_sat_near(noise_lvl_channel_2, 1677721600L);
          q1 = (q1 >> 10) + ((q1 & 512L) != 0L);
          thresh = q0 - q1;
          if ((q0 < 0L) && ((q1 >= 0L) && (thresh >= 0L))) {
            thresh = MIN_int32_T;
          } else {
            if ((q0 >= 0L) && ((q1 < 0L) && (thresh < 0L))) {
              thresh = MAX_int32_T;
            }
          }

          thresh = div_repeat_s32_sat_near(qY, thresh, 10U);
          if (1024L > thresh) {
          } else {
            thresh = 1024L;
          }
        }

        /*          Ds_2 = max(0, Ds_2); */
        if (max_val > thresh) {
          R_peak_indices_channel_1[i] = left[i];
        }
      }
    }
  }

  /*  if(shouldOutput) */
  /*      final = length(find(R_peak_indices_channel_2)) */
  /*  end */
  /*  LEVEL 5 DETECTION:  */
  /* Refines heart beat detection by considering a heart beat's refactory period     */
  /*  Sets R values to zero which failed any of the previous phases */
  thresh = 0L;

  /*  Sample time delta is based off the Fs passed in */
  /*  time_delta = divide(Fixed_Point_Properties, fi(1, Fixed_Point_Properties, F), fi(100, Fixed_Point_Properties, F)); */
  /*  Heart beat delta sum is the summation of the time between heart beats. It's used for */
  /*  HR calculation */
  max_voltage = 0L;
  heart_beat_last_sum = 0L;

  /*  Heart beat count is the amount of heart beats detected */
  heart_beat_count = 0L;
  for (i = 0; (uint16_T)(i + 1) <= (uint16_T)num_cols_indices; i++) {
    if (R_peak_indices_channel_1[i] == 0UL) {
      data[i] = 0L;

      /*  Filters out any R_values which happen too soon after a previous */
      /*  beat detection. Updates the average HR delta which will be used to */
      /*  calculate HR */
    } else {
      /*  Updates the index */
      j = R_peak_indices_channel_1[i];
      if (j > 2097151UL) {
        max_val = MAX_int32_T;
      } else {
        max_val = (int32_T)j << 10;
      }

      /* Filters out any R_values which happen too soon after a previous */
      /*  beat detection. */
      guard1 = FALSE;
      if ((uint32_T)thresh != 0UL) {
        q1 = mul_s32_s32_s32_sr27_sat_near(minus(max_val), 1374389535L);
        q0 = (q1 >> 10) + ((q1 & 512L) != 0L);
        q1 = mul_s32_s32_s32_sr27_sat_near(minus(thresh), 1374389535L);
        q1 = (q1 >> 10) + ((q1 & 512L) != 0L);
        qY = q0 - q1;
        if ((q0 < 0L) && ((q1 >= 0L) && (qY >= 0L))) {
          qY = MIN_int32_T;
        } else {
          if ((q0 >= 0L) && ((q1 < 0L) && (qY < 0L))) {
            qY = MAX_int32_T;
          }
        }

        if (qY < 205L) {
          data[i] = 0L;
          R_peak_indices_channel_1[i] = 0UL;

          /*  Initializes the first delta which is when the first heart */
          /*  beat occurs */
        } else {
          guard1 = TRUE;
        }
      } else {
        guard1 = TRUE;
      }

      if (guard1 == TRUE) {
        if ((uint32_T)thresh == 0UL) {
          /*              assert(isequal(numerictype(prev_hr_delta),Fixed_Point_Properties) && isequal(fimath(prev_hr_delta), F)); */
          /*              heart_beat_delta = (current_R_index - 1) * time_delta + prev_hr_delta; */
          /*              heart_beat_current_sum = heart_beat_delta + 0; % For future iterations: Add the previous delta from the previous data window. i.e. the amount of secs between the last peak in the sample and the next one in the next sample */
          /*  Updates the last index */
          j = R_peak_indices_channel_1[i];
          if (j > 2097151UL) {
            thresh = MAX_int32_T;
          } else {
            thresh = (int32_T)j << 10;
          }

          /*  Updates the heart beat count */
          /*              heart_beat_count = heart_beat_count + 1; */
          /*  Updates the last index if the R_value is valid */
        } else {
          q1 = mul_s32_s32_s32_sr27_sat_near(minus(max_val), 1374389535L);
          q1 = (q1 >> 10) + ((q1 & 512L) != 0L);
          qY = max_voltage + q1;
          if ((max_voltage < 0L) && ((q1 < 0L) && (qY >= 0L))) {
            qY = MIN_int32_T;
          } else {
            if ((max_voltage > 0L) && ((q1 > 0L) && (qY <= 0L))) {
              qY = MAX_int32_T;
            }
          }

          max_voltage = qY;
          q1 = mul_s32_s32_s32_sr27_sat_near(minus(thresh), 1374389535L);
          q1 = (q1 >> 10) + ((q1 & 512L) != 0L);
          qY = heart_beat_last_sum + q1;
          if ((heart_beat_last_sum < 0L) && ((q1 < 0L) && (qY >= 0L))) {
            qY = MIN_int32_T;
          } else {
            if ((heart_beat_last_sum > 0L) && ((q1 > 0L) && (qY <= 0L))) {
              qY = MAX_int32_T;
            }
          }

          heart_beat_last_sum = qY;

          /*              heart_beat_delta = (current_R_index - 1) * time_delta - (last_R_index - 1) * time_delta; */
          /*              heart_beat_current_sum = heart_beat_current_sum + heart_beat_delta; */
          /*  Updates the heart beat count */
          heart_beat_count = plus(heart_beat_count);

          /*  Updates the last index */
          j = R_peak_indices_channel_1[i];
          if (j > 2097151UL) {
            thresh = MAX_int32_T;
          } else {
            thresh = (int32_T)j << 10;
          }
        }
      }
    }
  }

  *last_hr_delta = 0L;

  /*  CALCULATES HEART RATE USING AVERAGE TIME TIME DELTAS BETWEEN BEATS */
  /*    Provides less quantized HR values */
  /*  Produces a result which is avg heart beat delta(s) */
  thresh = max_voltage - heart_beat_last_sum;
  if ((max_voltage < 0L) && ((heart_beat_last_sum >= 0L) && (thresh >= 0L))) {
    thresh = MIN_int32_T;
  } else {
    if ((max_voltage >= 0L) && ((heart_beat_last_sum < 0L) && (thresh < 0L))) {
      thresh = MAX_int32_T;
    }
  }

  /*  Avoids dividing by zero */
  if (thresh == 0L) {
    *heart_rate = mul_s32_s32_s32_sat(0L, 0L);

    /*  This is to ensure the Q value of HR is 20 */
  } else {
    /*  heart_rate = heart_beat_delta_sum * heart_beat_delta_sum; % This is to ensure the Q value of HR is 20 */
    /*  heart_beat_delta_sum = fi(heart_rate, Fixed_Point_Properties, F); */
    /*  heart_beat_delta_sum = heart_beat_delta_sum + heart_beat_delta_sum; */
    /*  Inverses it to produce HBPM */
    *heart_rate = mul_s32_s32_s32_sr15_sat_near(div_s32_SR_near(1073741824L,
      div_repeat_s32_sat_near(thresh, heart_beat_count, 10U), 10U), 2013265920L);
  }
}

/* End of code generation (heart_rate_official_cport.c) */
