#include "arithmetic.h"

/// @brief Умножает value_1 на value_2 и записывает результат в result
/// @param value_1
/// @param value_2
/// @param result
/// @return
/// 0 - OK
/// 1 - число слишком велико или равно бесконечности
/// 2 - число слишком мало или равно отрицательной бесконечности
/// 3 - деление на 0
/// 4 - некорректные входные данные
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  arithmetic_error_codes code = OK;
  if (!result) {
    code = INCORRECT_INPUT_DATA;
  } else if (decimal_is_correct(value_1) == 0 ||
             decimal_is_correct(value_2) == 0) {
    code = INCORRECT_INPUT_DATA;
    *result = decimal_get_inf();
  } else {
    *result = decimal_get_zero();
    s21_decimal tmp_res = decimal_get_zero();
    int sign_1 = decimal_get_sign(value_1);
    int sign_2 = decimal_get_sign(value_2);
    if (sign_1 == POSITIVE && sign_2 == POSITIVE) {
      code = multiplication_core(value_1, value_2, &tmp_res);
    } else if (sign_1 == POSITIVE && sign_2 == NEGATIVE) {
      code = multiplication_core(value_1, s21_abs(value_2), &tmp_res);
      s21_negate(tmp_res, &tmp_res);
    } else if (sign_1 == NEGATIVE && sign_2 == POSITIVE) {
      code = multiplication_core(s21_abs(value_1), value_2, &tmp_res);
      s21_negate(tmp_res, &tmp_res);
    } else if (sign_1 == NEGATIVE && sign_2 == NEGATIVE) {
      code = multiplication_core(s21_abs(value_1), s21_abs(value_2), &tmp_res);
    }
    if (code == TOO_BIG) {
      if (decimal_get_sign(tmp_res) == NEGATIVE) {
        code = TOO_SMALL;
      }
    }
    if (code == OK && s21_is_not_equal(value_1, decimal_get_zero()) &&
        s21_is_not_equal(value_2, decimal_get_zero()) &&
        s21_is_equal(tmp_res, decimal_get_zero())) {
      code = TOO_SMALL;
    }
    *result = tmp_res;
  }
  return code;
}

/// @brief Вспомогательная функция, которая осуществляет умножение двух
/// положительных чисел decimal
/// @param value_1
/// @param value_2
/// @param result
/// @return код ошибки
int multiplication_core(s21_decimal value_1, s21_decimal value_2,
                        s21_decimal *result) {
  arithmetic_error_codes code = OK;
  int power_1 = decimal_get_power(value_1);
  int power_2 = decimal_get_power(value_2);
  decimal_clear_service_bits(&value_1);
  decimal_clear_service_bits(&value_2);
  s21_int256 tmp_res = int128_binary_multiplication(value_1, value_2);
  int shift = int256_get_shift_to_decimal(tmp_res);
  int res_power = power_1 + power_2 - shift;
  if (res_power < 0) {
    code = TOO_BIG;
    *result = decimal_get_inf();
  } else {
    while (shift > 28) {
      tmp_res = int256_binary_division(
          tmp_res, int256_create_from_decimal(decimal_get_ten()), NULL);
      --shift;
    }
    if (res_power > 28) {
      s21_int256 tmp = tmp_res;
      int tmp_power = res_power;
      while (tmp_power > 28) {
        tmp = int256_binary_division(
            tmp, int256_create_from_decimal(decimal_get_ten()), NULL);
        --tmp_power;
      }
      shift = res_power - tmp_power + shift;
      res_power = tmp_power;
    }
    s21_int256 remainder = int256_create_from_decimal(decimal_get_zero());
    const s21_int256 powerten =
        int256_create_from_decimal(int128_get_ten_pow(shift));
    tmp_res = int256_binary_division(tmp_res, powerten, &remainder);
    decimal_set_power(&remainder.decimals[0], shift);
    tmp_res.decimals[0] =
        decimal_round_banking(tmp_res.decimals[0], remainder.decimals[0]);
    decimal_set_power(&tmp_res.decimals[0], res_power);
    if (!int128_binary_equal_zero(tmp_res.decimals[1]) &&
        !decimal_is_correct(tmp_res.decimals[0])) {
      code = TOO_BIG;
      *result = decimal_get_inf();
    } else {
      *result = tmp_res.decimals[0];
    }
  }
  return code;
}