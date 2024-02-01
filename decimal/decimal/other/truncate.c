#include "other.h"

/// @brief Возвращает целую часть числа
/// @param value
/// @param result
/// @return
int s21_truncate(s21_decimal value, s21_decimal *result) {
  other_result_codes code = OTHER_OK;
  if (!result) {
    code = OTHER_ERROR;
  } else if (!decimal_is_correct(value)) {
    code = OTHER_ERROR;
    *result = decimal_get_inf();
  } else {
    *result = decimal_get_zero();
    int power = decimal_get_power(value);
    s21_decimal tmp = value;
    decimal_clear_service_bits(&tmp);
    tmp = int128_binary_division(tmp, int128_get_ten_pow(power), NULL);
    *result = tmp;
    if (decimal_get_sign(value) == NEGATIVE) {
      decimal_set_sign(result, NEGATIVE);
    }
  }
  return code;
}