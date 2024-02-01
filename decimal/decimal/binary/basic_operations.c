#include "binary.h"

/// @brief Проверяет включён ли бит на назанном индексе
/// @param number число
/// @param index индекс по которому смотрим
/// @return 1 если включён и 0, если выключен
int bit_is_set(int number, int index) { return !!(number & (1U << index)); }

/// @brief Выставляет значение бита в заданной позиции в 1
/// @param number
/// @param index
/// @return
int bit_set_to_one(int number, int index) { return number | (1U << index); }

/// @brief Выставляет бит в заданной позиции в 0
/// @param number
/// @param index
/// @return
int bit_set_to_zero(int number, int index) { return number & ~(1U << index); }

/// @brief Проверяет, установлен ли бит (имеет значение 1) номер index в числе
/// decimal
/// @param decimal проверяемое число
/// @param index номер проверяемого бита
/// @return 0 не установлен или 1 установлен
int decimal_bit_is_set(s21_decimal decimal, int index) {
  return bit_is_set(decimal.bits[index / MAX_BLOCK_BITS],
                    index % MAX_BLOCK_BITS);
}

/// @brief Устанавливает значение 1 для бита номер index в числе decimal
/// @param decimal проверяемое число
/// @param index номер проверяемого бита
/// @return
s21_decimal decimal_set_bit(s21_decimal decimal, int index) {
  decimal.bits[index / MAX_BLOCK_BITS] = bit_set_to_one(
      decimal.bits[index / MAX_BLOCK_BITS], index % MAX_BLOCK_BITS);
  return decimal;
}

/// @brief Находит ближайший к старшему биту установленный бит (который имеет
/// значение 1) числа decimal
/// @param decimal число
/// @return индекс
int decimal_get_not_zero_bit(s21_decimal decimal) {
  int result = -1;
  for (int i = MAX_BITS - 1; i >= 0; i--) {
    if (decimal_bit_is_set(decimal, i)) {
      result = i;
      break;
    }
  }
  return result;
}