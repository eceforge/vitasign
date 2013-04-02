/*
 * find.c
 *
 * Code generation for function 'find'
 *
 * C source code generated on: Wed Feb 13 13:34:29 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "heart_rate_official_cport.h"
#include "find.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

void eml_find(const boolean_T x[1000], int32_T i_data[1000], int32_T i_sizes[2])
{
    int32_T idx;
    int32_T ii;
    boolean_T exitg1;
    boolean_T guard1 = FALSE;
    int32_T tmp_data[1000];
    int32_T loop_ub;
    int16_T b_i_data[1000];
    int32_T i1;
    idx = 0;
    for (ii = 0; ii < 2; ii++) {
        i_sizes[ii] = 1 + 999 * ii;
    }
    ii = 1;
    exitg1 = 0U;
    while ((exitg1 == 0U) && (ii < 1001)) {
        guard1 = FALSE;
        if (x[ii - 1]) {
            idx++;
            i_data[idx - 1] = ii;
            if (idx >= 1000) {
                exitg1 = 1U;
            } else {
                guard1 = TRUE;
            }
        } else {
            guard1 = TRUE;
        }
        if (guard1 == TRUE) {
            ii++;
        }
    }
    if (1 > idx) {
        idx = 0;
    }
    loop_ub = idx - 1;
    for (ii = 0; ii <= loop_ub; ii++) {
        tmp_data[ii] = 1 + ii;
    }
    loop_ub = idx - 1;
    for (ii = 0; ii <= loop_ub; ii++) {
        i1 = 0;
        while (i1 <= 0) {
            b_i_data[ii] = (int16_T)i_data[tmp_data[ii] - 1];
            i1 = 1;
        }
    }
    i_sizes[0] = 1;
    i_sizes[1] = idx;
    loop_ub = idx - 1;
    for (ii = 0; ii <= loop_ub; ii++) {
        i_data[ii] = b_i_data[ii];
    }
}
/* End of code generation (find.c) */
