#include "arithmetic.h"

/// @brief Вычитает из value_1 значение value_2 и записывает результат в result
/// @param value_1
/// @param value_2
/// @param result
/// @return  * 0 - OK
/// 1 - число слишком велико или равно бесконечности
/// 2 - число слишком мало или равно отрицательной бесконечности
/// 3 - деление на 0
/// 4 - некорректные входные данные
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  arithmetic_error_codes code = OK;
  if (!result) {
    code = INCORRECT_INPUT_DATA;
  } else if (!decimal_is_correct(value_1) || !decimal_is_correct(value_2)) {
    code = INCORRECT_INPUT_DATA;
    *result = decimal_get_inf();
  } else {
    *result = decimal_get_zero();
    s21_decimal tmp_res = decimal_get_zero();
    int sign_1 = decimal_get_sign(value_1);
    int sign_2 = decimal_get_sign(value_2);
    if (sign_1 == POSITIVE && sign_2 == POSITIVE) {
      if (s21_is_greater_or_equal(value_1, value_2)) {
        code = subtraction_core(value_1, value_2, &tmp_res);
      } else {
        code = subtraction_core(value_2, value_1, &tmp_res);
        s21_negate(tmp_res, &tmp_res);
      }
    } else if (sign_1 == POSITIVE && sign_2 == NEGATIVE) {
      code = s21_add(value_1, s21_abs(value_2), &tmp_res);
    } else if (sign_1 == NEGATIVE && sign_2 == POSITIVE) {
      code = s21_add(s21_abs(value_1), value_2, &tmp_res);
      s21_negate(tmp_res, &tmp_res);
    } else if (sign_1 == NEGATIVE && sign_2 == NEGATIVE) {
      if (s21_is_greater_or_equal(value_1, value_2)) {
        code = subtraction_core(s21_abs(value_2), s21_abs(value_1), &tmp_res);
      } else {
        code = subtraction_core(s21_abs(value_1), s21_abs(value_2), &tmp_res);
        s21_negate(tmp_res, &tmp_res);
      }
    }
    if (decimal_get_sign(tmp_res) == NEGATIVE && code == TOO_BIG) {
      code = TOO_SMALL;
    }
    *result = tmp_res;
  }
  return code;
}

/// @brief Вспомогательная функция, которая осуществляет вычитание двух
/// положительных чисел decimal
/// @param value_1
/// @param value_2
/// @param result
/// @return int код ошибки, для передачи в родительскую функцию
int subtraction_core(s21_decimal value_1, s21_decimal value_2,
                     s21_decimal *result) {
  arithmetic_error_codes code = OK;
  s21_int256 long_value_1;
  s21_int256 long_value_2;
  const int power_1 = decimal_get_power(value_1);
  const int power_2 = decimal_get_power(value_2);
  int max_power = max(power_1, power_2);
  decimal_align_exponents(value_1, value_2, &long_value_1, &long_value_2);
  s21_int256 tmp_res = int256_binary_subtraction(long_value_1, long_value_2);
  int shift = int256_get_shift_to_decimal(tmp_res);
  int res_power = max_power - shift;
  if (res_power < 0) {
    code = TOO_BIG;
    *result = decimal_get_inf();
  } else {
    s21_int256 remainder = int256_create_from_decimal(decimal_get_zero());
    const s21_int256 powerten =
        int256_create_from_decimal(int128_get_ten_pow(shift));
    tmp_res = int256_binary_division(tmp_res, powerten, &remainder);
    decimal_set_power(&remainder.decimals[0], shift);
    tmp_res.decimals[0] =
        decimal_round_banking(tmp_res.decimals[0], remainder.decimals[0]);
    decimal_set_power(&tmp_res.decimals[0], res_power);
    *result = tmp_res.decimals[0];
  }
  return code;
}