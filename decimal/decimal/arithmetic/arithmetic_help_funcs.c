#include "arithmetic.h"

/// @brief рассчитывает сколько раз необходимо разделить 256-битный int на 10,
/// чтобы результат поместился в 96битный int (в decimal)
/// @param value
/// @return int искомая степень десятки
int int256_get_shift_to_decimal(s21_int256 value) {
  int cnt = 0;
  if (!(int128_binary_equal_zero(value.decimals[0]) &&
        int128_binary_equal_zero(value.decimals[1]))) {
    s21_int256 max = int256_create_from_decimal(decimal_get_max());
    // Находим число, во сколько раз value больше максимального 96битного числа
    s21_int256 quotient = int256_binary_division(value, max, NULL);
    while (1) {
      int compare =
          int128_binary_compare(quotient.decimals[0], int128_get_ten_pow(cnt));
      if (compare == -1 || compare == 0) {
        break;
      }
      ++cnt;
    }
    // Проверяем, что value впишется в 96 бит, если поделить на 10 в найденной
    // степени
    s21_int256 tmp = int256_binary_division(
        value, int256_create_from_decimal(int128_get_ten_pow(cnt)), NULL);
    if (!int128_binary_equal_zero(tmp.decimals[1]) ||
        tmp.decimals[0].bits[3] != 0) {
      ++cnt;
    }
  }
  return cnt;
}

/// @brief Модуль decimal
/// @param value_1
/// @return
s21_decimal s21_abs(s21_decimal value_1) {
  s21_decimal result = value_1;
  decimal_set_sign(&result, POSITIVE);
  return result;
}

int max(int value_1, int value_2) {
  return (value_1 > value_2) ? value_1 : value_2;
}