#include <limits.h>

#include "convert.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  conversion_result_code code = CONVERSION_OK;
  if (!dst) {
    code = CONVERSION_ERROR;
  } else {
    *dst = decimal_get_zero();
    int sign;
    if (src < 0) {
      sign = NEGATIVE;
      if (src != INT_MIN) {
        src *= -1;
      }
    } else {
      sign = POSITIVE;
    }
    dst->bits[0] = src;
    decimal_set_sign(dst, sign);
  }
  return code;
}