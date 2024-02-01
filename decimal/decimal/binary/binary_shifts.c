#include "binary.h"

/// @brief Функция сдвигает все биты в decimal на 1
/// @param decimal
/// @return s21_decimal результат применения decimal << 1
s21_decimal int128_binary_shift_left_one(s21_decimal decimal) {
  s21_decimal result = decimal_get_zero();

  int bit_0 = bit_is_set(decimal.bits[0], MAX_BLOCK_BITS - 1);
  unsigned int result_0 = decimal.bits[0];
  result_0 = result_0 << 1;
  result.bits[0] = result_0;

  int bit_1 = bit_is_set(decimal.bits[1], MAX_BLOCK_BITS - 1);
  unsigned int result_1 = decimal.bits[1];
  result_1 = result_1 << 1;
  result.bits[1] = result_1;

  int bit_2 = bit_is_set(decimal.bits[2], MAX_BLOCK_BITS - 1);
  unsigned int result_2 = decimal.bits[2];
  result_2 = result_2 << 1;
  result.bits[2] = result_2;

  unsigned int result_3 = decimal.bits[3];
  result_3 = result_3 << 1;
  result.bits[3] = result_3;

  if (bit_0) {
    result.bits[1] = bit_set_to_one(result.bits[1], 0);
  }
  if (bit_1) {
    result.bits[2] = bit_set_to_one(result.bits[2], 0);
  }
  if (bit_2) {
    result.bits[3] = bit_set_to_one(result.bits[3], 0);
  }
  return result;
}

/// @brief Функция сдвигает биты влево на указанное количество ячеек
/// @param decimal
/// @param shift
/// @return
s21_decimal int128_binary_shift_left(s21_decimal decimal, int shift) {
  s21_decimal result = decimal;
  while (shift > 0) {
    result = int128_binary_shift_left_one(result);
    --shift;
  }
  return result;
}

/// @brief Сдвигает один бит во всём decimal на 1 вправо
/// @param decimal
/// @return s21_decimal результат применения decimal >> 1
s21_decimal int128_binary_shift_right_one(s21_decimal decimal) {
  s21_decimal result = decimal_get_zero();

  int bit_3 = bit_is_set(decimal.bits[3], 0);
  unsigned int result_3 = decimal.bits[3];
  result_3 = result_3 >> 1;
  result.bits[3] = result_3;

  int bit_2 = bit_is_set(decimal.bits[2], 0);
  unsigned int result_2 = decimal.bits[2];
  result_2 = result_2 >> 1;
  result.bits[2] = result_2;

  int bit_1 = bit_is_set(decimal.bits[1], 0);
  unsigned int result_1 = decimal.bits[1];
  result_1 = result_1 >> 1;
  result.bits[1] = result_1;

  unsigned int result_0 = decimal.bits[0];
  result_0 = result_0 >> 1;
  result.bits[0] = result_0;

  if (bit_3) {
    result.bits[2] = bit_set_to_one(result.bits[2], MAX_BLOCK_BITS - 1);
  }
  if (bit_2) {
    result.bits[1] = bit_set_to_one(result.bits[1], MAX_BLOCK_BITS - 1);
  }
  if (bit_1) {
    result.bits[0] = bit_set_to_one(result.bits[0], MAX_BLOCK_BITS - 1);
  }
  return result;
}

/// @brief Функция сдвигает биты влево на указанное количество ячеек
/// @param decimal
/// @param shift
/// @return
s21_decimal int128_binary_shift_right(s21_decimal decimal, int shift) {
  s21_decimal result = decimal;
  while (shift > 0) {
    result = int128_binary_shift_right_one(result);
    --shift;
  }
  return result;
}

/// @brief Битовый сдвиг влево на указанное количество ячеек
/// @param decimal
/// @param shift
/// @return int256 результат применения decimal << shift
s21_int256 int256_binary_shift_left(s21_int256 decimal, int shift) {
  s21_int256 result = decimal;
  while (shift > 0) {
    int bit_0 = decimal_bit_is_set(result.decimals[0], MAX_BITS - 1);
    result.decimals[0] = int128_binary_shift_left_one(result.decimals[0]);
    result.decimals[1] = int128_binary_shift_left_one(result.decimals[1]);
    if (bit_0) {
      result.decimals[1] = decimal_set_bit(result.decimals[1], 0);
    }
    --shift;
  }
  return result;
}

/// @brief Битовый сдвиг вправо на указанное количество ячеек
/// @param decimal
/// @param shift
/// @return int256 результат применения decimal >> shift
s21_int256 int256_binary_shift_right(s21_int256 decimal, int shift) {
  s21_int256 result = decimal;
  while (shift > 0) {
    int bit_1 = decimal_bit_is_set(result.decimals[1], 0);
    result.decimals[0] = int128_binary_shift_right_one(result.decimals[0]);
    result.decimals[1] = int128_binary_shift_right_one(result.decimals[1]);
    if (bit_1) {
      result.decimals[0] = decimal_set_bit(result.decimals[0], MAX_BITS - 1);
    }
    --shift;
  }
  return result;
}