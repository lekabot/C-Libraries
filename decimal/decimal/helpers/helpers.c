#include "helpers.h"

/// @brief Проверяет корректный ли decimal
/// @param decimal
/// @return 1 - ок, 0 - некорректные данные
int decimal_is_correct(s21_decimal decimal) {
  int code = 1;

  if (decimal_get_empty1_in_service_bits(decimal) != 0 ||
      decimal_get_empty2_in_service_bits(decimal) != 0) {
    code = 0;
  } else {
    int power = decimal_get_power(decimal);
    if (power < 0 || power > 28) {
      code = 0;
    }
  }

  return code;
}

/// @brief Выставляет переданный знак decimal
/// @param decimal
/// @param sign
void decimal_set_sign(s21_decimal *decimal, int sign) {
  decimal_bit3 bit3;
  bit3.i = decimal->bits[3];
  if (sign == POSITIVE) {
    bit3.parts.sign = POSITIVE;
  } else {
    bit3.parts.sign = NEGATIVE;
  }
  decimal->bits[3] = bit3.i;
}

/// @brief Выставляет степень для decimal
/// @param decimal
/// @param power
void decimal_set_power(s21_decimal *decimal, int power) {
  decimal_bit3 bit3;
  bit3.i = decimal->bits[3];
  bit3.parts.power = power;
  decimal->bits[3] = bit3.i;
}

/// @brief Возвращает пустое пространство из service bit
/// @param decimal
/// @return
int decimal_get_empty1_in_service_bits(s21_decimal decimal) {
  decimal_bit3 bits3;
  bits3.i = decimal.bits[3];
  return bits3.parts.empty_part_1;
}

/// @brief Возвращает пустое пространство из service bit
/// @param decimal
/// @return
int decimal_get_empty2_in_service_bits(s21_decimal decimal) {
  decimal_bit3 bits;
  bits.i = decimal.bits[3];
  return bits.parts.empty_part_2;
}

/// @brief Возвращает степень decimal
/// @param decimal
/// @return
int decimal_get_power(s21_decimal decimal) {
  decimal_bit3 bits;
  bits.i = decimal.bits[3];
  return bits.parts.power;
}

/// @brief Возвращает знак decimal
/// @param decimal
/// @return знак
int decimal_get_sign(s21_decimal decimal) {
  decimal_bit3 bits;
  bits.i = decimal.bits[3];
  return bits.parts.sign;
}

/// @brief Проверяет число на чётность
/// @param decimal
/// @return 1 - чётное, 0 не чётное
int decimal_is_even(s21_decimal decimal) { return (decimal.bits[0] & 1) != 1; }