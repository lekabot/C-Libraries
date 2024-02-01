#include "other.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  other_result_codes code = OTHER_OK;
  if (!result) {
    code = OTHER_ERROR;
  } else if (!decimal_is_correct(value)) {
    code = OTHER_ERROR;
    *result = decimal_get_inf();
  } else {
    *result = decimal_get_zero();
    int sign = decimal_get_sign(value);
    s21_decimal fractional;
    s21_decimal value_unsign_truncated;
    s21_decimal value_unsign = s21_abs(value);
    s21_truncate(value_unsign, &value_unsign_truncated);
    s21_sub(value_unsign, value_unsign_truncated, &fractional);

    if (sign == NEGATIVE && s21_is_greater(fractional, decimal_get_zero())) {
      s21_add(value_unsign_truncated, decimal_get_one(),
              &value_unsign_truncated);
    }
    *result = value_unsign_truncated;
    decimal_set_sign(result, sign);
  }
  return code;
}