#include "binary.h"

/**
 * @brief Функция бинарного деления двоичных положительных целых чисел размера
 * @param decimal_1 Делимое
 * @param decimal_2 Делитель
 * @param remainder Остаток. Если нам не требуется получать остаток, то можно
 * передать NULL
 * @return s21_decimal Частное чисел decimal1 и decimal2
 */
s21_decimal int128_binary_division(s21_decimal decimal_1, s21_decimal decimal_2,
                                   s21_decimal *remainder) {
  s21_decimal result;
  // Рассчитываемый в алгоритме частичный остаток при расчетах
  s21_decimal partial_remainder = decimal_get_zero();
  // Рассчитываемое в алгоритме частное
  s21_decimal quotient = decimal_get_zero();

  if (int128_binary_equal_zero(decimal_1)) {
    quotient = decimal_get_zero();
    partial_remainder = decimal_get_zero();
  } else if (int128_binary_compare(decimal_1, decimal_2) == -1) {
    quotient = decimal_get_zero();
    partial_remainder = decimal_1;
  } else {
    int left_1 = decimal_get_not_zero_bit(decimal_1);
    int left_2 = decimal_get_not_zero_bit(decimal_2);
    int shift = left_1 - left_2;

    s21_decimal shift_divisor = int128_binary_shift_left(decimal_2, shift);
    s21_decimal dividend = decimal_1;

    // Флаг необходимости проводить вычитание (Шаг 5 алгоритма).
    // На первой итерации всегда требуется вычитать
    int flag_need_for_division = 1;

    while (shift >= 0) {
      if (flag_need_for_division == 1) {
        partial_remainder = int128_binary_subtraction(dividend, shift_divisor);
      } else {
        partial_remainder = int128_binary_addition(dividend, shift_divisor);
      }
      // Сдвигаем влево на 1 частное и записываем в младший бит результата 1,
      // если старший бит частичного остатка равен 1
      quotient = int128_binary_shift_left(quotient, 1);
      if (decimal_bit_is_set(partial_remainder, MAX_BITS - 1) == 0) {
        quotient = decimal_set_bit(quotient, 0);
      }

      dividend = int128_binary_shift_left(partial_remainder, 1);

      if (decimal_bit_is_set(partial_remainder, MAX_BITS - 1) == 0) {
        flag_need_for_division = 1;
      } else {
        flag_need_for_division = 0;
      }
      --shift;
    }
    // Определяем, требуется ли коррекция остатка
    if (decimal_bit_is_set(partial_remainder, MAX_BITS - 1)) {
      partial_remainder =
          int128_binary_addition(partial_remainder, shift_divisor);
    }
    partial_remainder =
        int128_binary_shift_right(partial_remainder, left_1 - left_2);
  }
  result = quotient;
  if (remainder != NULL) {
    *remainder = partial_remainder;
  }
  return result;
}

/// @brief Функция бинарного деления для двоичных положительных целых чисел
/// размера 256бит
/// @param decimal_1 Делимое
/// @param decimal_2 Делитель
/// @param remainder Остаток. Если нам не требуется получать остаток, то можно
/// передать NULL
/// @return s21_decimal Частное чисел decimal1 и decimal2
s21_int256 int256_binary_division(s21_int256 decimal_1, s21_int256 decimal_2,
                                  s21_int256 *remainder) {
  s21_int256 result;

  s21_int256 partial_remainder = int256_create_from_decimal(decimal_get_zero());
  s21_int256 quotient = int256_create_from_decimal(decimal_get_zero());

  if (int128_binary_equal_zero(decimal_1.decimals[0]) &&
      int128_binary_equal_zero(decimal_1.decimals[1])) {
    quotient = int256_create_from_decimal(decimal_get_zero());
    partial_remainder = int256_create_from_decimal(decimal_get_zero());
  } else if (int256_binary_compare(decimal_1, decimal_2) == -1) {
    quotient = int256_create_from_decimal(decimal_get_zero());
    partial_remainder = decimal_1;
  } else {
    int left_1 = decimal_get_not_zero_bit(decimal_1.decimals[1]);
    if (left_1 == -1) {
      left_1 = decimal_get_not_zero_bit(decimal_1.decimals[0]);
    } else {
      left_1 = MAX_BITS + left_1;
    }

    int left_2 = decimal_get_not_zero_bit(decimal_2.decimals[1]);
    if (left_2 == -1) {
      left_2 = decimal_get_not_zero_bit(decimal_2.decimals[0]);
    } else {
      left_2 = MAX_BITS + left_2;
    }
    int shift = left_1 - left_2;

    s21_int256 shifted_divisor = int256_binary_shift_left(decimal_2, shift);
    s21_int256 dividend = decimal_1;

    int flag_need_for_division = 1;

    while (shift >= 0) {
      if (flag_need_for_division == 1) {
        partial_remainder =
            int256_binary_subtraction(dividend, shifted_divisor);
      } else {
        partial_remainder = int256_binary_addition(dividend, shifted_divisor);
      }
      quotient = int256_binary_shift_left(quotient, 1);
      if (decimal_bit_is_set(partial_remainder.decimals[1], MAX_BITS - 1) ==
          0) {
        quotient.decimals[0] = decimal_set_bit(quotient.decimals[0], 0);
      }

      dividend = int256_binary_shift_left(partial_remainder, 1);

      if (decimal_bit_is_set(partial_remainder.decimals[1], MAX_BITS - 1) ==
          0) {
        flag_need_for_division = 1;
      } else {
        flag_need_for_division = 0;
      }
      --shift;
    }
    // Определяем, требуется ли коррекция остатка
    if (decimal_bit_is_set(partial_remainder.decimals[1], MAX_BITS - 1)) {
      partial_remainder =
          int256_binary_addition(partial_remainder, shifted_divisor);
    }
    partial_remainder =
        int256_binary_shift_right(partial_remainder, left_1 - left_2);
  }
  result = quotient;
  if (remainder != NULL) {
    *remainder = partial_remainder;
  }
  return result;
}