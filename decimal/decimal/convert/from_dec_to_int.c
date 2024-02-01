#include <limits.h>

#include "convert.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  conversion_result_code code = CONVERSION_OK;

  if (!dst) {
    code = CONVERSION_ERROR;
  } else if (!decimal_is_correct(src)) {
    code = CONVERSION_ERROR;
    *dst = 0;
  } else {
    *dst = 0;
    s21_decimal truncated_decimal = decimal_get_zero();
    s21_truncate(src, &truncated_decimal);

    if (s21_is_less(truncated_decimal, decimal_get_int_min()) ==
        COMPARISON_TRUE) {
      code = CONVERSION_ERROR;
    } else if (s21_is_greater(truncated_decimal, decimal_get_int_max()) ==
               COMPARISON_TRUE) {
      code = CONVERSION_ERROR;
    } else {
      for (int i = 0; i < MAX_BLOCK_NUMBER; i++) {
        if (decimal_bit_is_set(truncated_decimal, i) != 0) {
          *dst += pow(2, i);
        }
      }
      if (decimal_get_sign(src) == NEGATIVE && *dst != -2147483648) {
        *dst = -*dst;
      }
    }
  }

  return code;
}