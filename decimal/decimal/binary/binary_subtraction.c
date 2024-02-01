#include "binary.h"

/**
 * @brief Функция бинарного вычитания двоичных положительных целых чисел размера
 128бит.
 * @param decimal_1 Уменьшаемое
 * @param decimal_2 Вычитаемое
 * @return s21_decimal Разность чисел decimal1 и decimal2
 */

s21_decimal int128_binary_subtraction(s21_decimal decimal_1,
                                      s21_decimal decimal_2) {
  s21_decimal result;
  decimal_2 = int128_binary_not(decimal_2);
  decimal_2 = int128_binary_addition(decimal_2, decimal_get_one());
  result = int128_binary_addition(decimal_1, decimal_2);
  return result;
}

/// @brief Функция бинарного вычитания двоичных положительных целых чисел
/// размера 256бит
/// @param decimal_1
/// @param decimal_2
/// @return s21_decimal Разность чисел decimal1 и decimal2
s21_int256 int256_binary_subtraction(s21_int256 decimal_1,
                                     s21_int256 decimal_2) {
  s21_int256 result;
  decimal_2.decimals[0] = int128_binary_not(decimal_2.decimals[0]);
  decimal_2.decimals[1] = int128_binary_not(decimal_2.decimals[1]);

  s21_int256 one = int256_create_from_decimal(decimal_get_one());

  decimal_2 = int256_binary_addition(decimal_2, one);
  result = int256_binary_addition(decimal_1, decimal_2);

  return result;
}