#include "binary.h"

/// @brief Функция бинарного сложения для int128
/// @param decimal_1
/// @param decimal_2
/// @return s21_int128 сумма decimal_1 и decimal_2
s21_decimal int128_binary_addition(s21_decimal decimal_1,
                                   s21_decimal decimal_2) {
  s21_decimal result = decimal_1;
  s21_decimal tmp = decimal_2;
  while (!int128_binary_equal_zero(tmp)) {
    s21_decimal overflow_bit = int128_binary_and(result, tmp);
    overflow_bit = int128_binary_shift_left(overflow_bit, 1);
    result = int128_binary_xor(result, tmp);
    tmp = overflow_bit;
  }
  return result;
}

/// @brief Функция бинарного сложения для int256
/// @param decimal_1
/// @param decimal_2
/// @return s21_int256 сумма decimal_1 и decimal_2
s21_int256 int256_binary_addition(s21_int256 decimal_1, s21_int256 decimal_2) {
  s21_int256 result = decimal_1;
  s21_int256 tmp = decimal_2;

  while (!int128_binary_equal_zero(tmp.decimals[0]) ||
         !int128_binary_equal_zero(tmp.decimals[1])) {
    s21_int256 overflow_bits;
    overflow_bits.decimals[0] =
        int128_binary_and(result.decimals[0], tmp.decimals[0]);
    overflow_bits.decimals[1] =
        int128_binary_and(result.decimals[1], tmp.decimals[1]);

    overflow_bits = int256_binary_shift_left(overflow_bits, 1);
    result.decimals[0] = int128_binary_xor(result.decimals[0], tmp.decimals[0]);
    result.decimals[1] = int128_binary_xor(result.decimals[1], tmp.decimals[1]);

    tmp = overflow_bits;
  }
  return result;
}