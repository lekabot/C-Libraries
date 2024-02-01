#include "binary.h"

/**
 * @brief Функция бинарного умножения двоичных положительных чисел размера
 * 128бит.
 * @param decimal_1 первый множитель
 * @param decimal_2 второй множитель
 * @return s21_decimal
 */
s21_int256 int128_binary_multiplication(s21_decimal decimal_1,
                                        s21_decimal decimal_2) {
  s21_int256 int256_result = int256_create_from_decimal(decimal_get_zero());
  s21_int256 int256_tmp1 = int256_create_from_decimal(decimal_1);

  int max_bit = decimal_get_not_zero_bit(decimal_2);

  for (int i = 0; i <= max_bit; i++) {
    if (decimal_bit_is_set(decimal_2, i) != 0) {
      int256_result = int256_binary_addition(int256_result, int256_tmp1);
    }
    int256_tmp1 = int256_binary_shift_left(int256_tmp1, 1);
  }
  return int256_result;
}

/// @brief Вспомогательная функция для бинарного умножения двоичных
/// положительных чисел 256бит на 128бит
/// @param decimal_1
/// @param decimal_2
/// @return s21_decimal
s21_int256 int256_binary_multiplication(s21_int256 decimal_1,
                                        s21_decimal decimal_2) {
  s21_int256 int256_result = int256_create_from_decimal(decimal_get_zero());
  s21_int256 int256_tmp = decimal_1;

  int max_bit = decimal_get_not_zero_bit(decimal_2);

  for (int i = 0; i <= max_bit; i++) {
    if (decimal_bit_is_set(decimal_2, i) != 0) {
      int256_result = int256_binary_addition(int256_result, int256_tmp);
    }
    int256_tmp = int256_binary_shift_left(int256_tmp, 1);
  }
  return int256_result;
}
