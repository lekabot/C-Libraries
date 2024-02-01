#include "other.h"

int s21_round(s21_decimal value, s21_decimal *result) {
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
    s21_decimal value_unsigned_truncated;
    s21_decimal value_unsigned = s21_abs(value);
    s21_truncate(value_unsigned, &value_unsigned_truncated);
    s21_sub(value_unsigned, value_unsigned_truncated, &fractional);

    value_unsigned_truncated =
        decimal_round_banking(value_unsigned_truncated, fractional);

    *result = value_unsigned_truncated;
    decimal_set_sign(result, sign);
  }
  return code;
}