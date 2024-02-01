#include "convert.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  conversion_result_code code = CONVERSION_OK;
  if (!dst) {
    code = CONVERSION_ERROR;
  } else if (!decimal_is_correct(src)) {
    code = CONVERSION_ERROR;
    *dst = 0.0;
  } else if (s21_is_equal(src, decimal_get_zero())) {
    int sign = decimal_get_sign(src);
    if (sign == NEGATIVE) {
      *dst = -0.0;
    } else {
      *dst = 0.0;
    }
    code = CONVERSION_OK;
  } else {
    *dst = 0.0;
    double another_tmp = 0.0;
    int sign = decimal_get_sign(src);
    int power = decimal_get_power(src);

    for (int i = 0; i < MAX_BLOCK_NUMBER; i++) {
      if (decimal_bit_is_set(src, i)) {
        another_tmp += pow(2.0, i);
      }
    }

    double power_ten = pow(10, power);
    another_tmp /= power_ten;

    if (sign) {
      another_tmp *= -1.0;
    }
    *dst = (float)another_tmp;
  }
  return code;
}