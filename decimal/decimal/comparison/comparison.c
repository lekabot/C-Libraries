#include "comparison.h"

/// @brief Проверяет, что число value_1 равно value_2
/// @param value_1
/// @param value_2
/// @return 1 - true 0 - false
int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  comparison_result_code code = COMPARISON_TRUE;
  const s21_decimal tmp_1 = decimal_remove_trailing_zeros(value_1);
  const s21_decimal tmp_2 = decimal_remove_trailing_zeros(value_2);

  if (tmp_1.bits[0] == 0 && tmp_1.bits[1] == 0 && tmp_1.bits[2] == 0 &&
      tmp_2.bits[0] == 0 && tmp_2.bits[1] == 0 && tmp_2.bits[2] == 0) {
    code = COMPARISON_TRUE;
  } else {
    code = tmp_1.bits[0] == tmp_2.bits[0] && tmp_1.bits[1] == tmp_2.bits[1] &&
           tmp_1.bits[2] == tmp_2.bits[2] && tmp_1.bits[3] == tmp_2.bits[3];
  }
  return code;
}

/// @brief Проверяет, что число value_1 меньше value_2
/// @param value_1
/// @param value_2
/// @return 1 - true, 0 - false
int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  comparison_result_code code = COMPARISON_FALSE;
  int sign_1 = decimal_get_sign(value_1);
  int sign_2 = decimal_get_sign(value_2);

  if (s21_is_equal(value_1, value_2)) {
    code = COMPARISON_FALSE;
  } else {
    if (s21_is_equal(value_1, decimal_get_zero()) &&
        s21_is_equal(value_2, decimal_get_zero())) {
      code = COMPARISON_FALSE;
    } else if (sign_1 == NEGATIVE && sign_2 == POSITIVE) {
      code = COMPARISON_TRUE;
    } else if (sign_1 == POSITIVE && sign_2 == NEGATIVE) {
      code = COMPARISON_FALSE;
    } else if (sign_1 == NEGATIVE && sign_2 == NEGATIVE) {
      code = is_less_core(s21_abs(value_1), s21_abs(value_2));
      if (code == 0) {
        code = 1;
      } else {
        code = 0;
      }
    } else {
      code = is_less_core(value_1, value_2);
    }
  }
  return code;
}

/// @brief Вспомогательная функция для сравнения
/// @param value_1
/// @param value_2
/// @return 1 - true, 0 - false
int is_less_core(s21_decimal value_1, s21_decimal value_2) {
  comparison_result_code code = COMPARISON_FALSE;
  s21_decimal tmp_1 = value_1;
  s21_decimal tmp_2 = value_2;
  s21_int256 long_tmp_1;
  s21_int256 long_tmp_2;

  decimal_align_exponents(tmp_1, tmp_2, &long_tmp_1, &long_tmp_2);
  const int compare = int256_binary_compare(long_tmp_1, long_tmp_2);
  if (compare == -1) {
    code = COMPARISON_TRUE;
  } else {
    code = COMPARISON_FALSE;
  }
  return code;
}

/// @brief Проверяет, что число value_1 меньше или равно value_2
/// @param value_1
/// @param value_2
/// @return
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return s21_is_less(value_1, value_2) || s21_is_equal(value_1, value_2);
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  return s21_is_less(value_2, value_1);
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return s21_is_less_or_equal(value_2, value_1);
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_equal(value_1, value_2);
}