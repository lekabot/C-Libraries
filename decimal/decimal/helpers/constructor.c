#include "helpers.h"

/// @brief Отчищает decimal
/// @param decimal
void decimal_clear(s21_decimal *decimal) {
  decimal->bits[0] = 0;
  decimal->bits[1] = 0;
  decimal->bits[2] = 0;
  decimal->bits[3] = 0;
}

/// @brief Формирует и возвращает decimal = 0
/// @return 0
s21_decimal decimal_get_zero(void) {
  s21_decimal result;
  decimal_clear(&result);
  return result;
}

/// @brief Заполнает децимал из переданных аргументов
/// @param data_1
/// @param data_2
/// @param data_3
/// @param data_4
/// @return заполненный decimal
s21_decimal decimal_create_from_array(int data_1, int data_2, int data_3,
                                      int data_4) {
  s21_decimal decimal;
  decimal.bits[0] = data_1;
  decimal.bits[1] = data_2;
  decimal.bits[2] = data_3;
  decimal.bits[3] = data_4;
  return decimal;
}

/// @brief Возвращет бесконечность
/// @return inf
s21_decimal decimal_get_inf(void) {
  s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF}};

  return result;
}

/// @brief Отчищает знаковые и степенные биты
/// @param decimal
void decimal_clear_service_bits(s21_decimal *decimal) { decimal->bits[3] = 0; }

/// @brief Формирует и возвращает 1
/// @return
s21_decimal decimal_get_one(void) {
  s21_decimal decimal;
  decimal_clear(&decimal);
  decimal.bits[0] = 1;
  return decimal;
}

/// @brief Формирует и возвращает 10
/// @return
s21_decimal decimal_get_ten(void) {
  s21_decimal decimal;
  decimal_clear(&decimal);
  decimal.bits[0] = 10;
  return decimal;
}

/// @brief Возвращает 0.5
/// @return
s21_decimal decimal_get_point_five(void) {
  s21_decimal decimal = {{0x5, 0x0, 0x0, 0x10000}};

  return decimal;
}

/// @brief Возвращает 10 в степени pow pow - [0, 38]
/// @param pow
/// @return
s21_decimal int128_get_ten_pow(int pow) { return all_ten_pows[pow]; }

/// @brief Возвращает минимальный decimal
/// @return 0.0000000000000000000000000001
s21_decimal decimal_get_min(void) {
  s21_decimal result = {{0x1, 0x0, 0x0, 0x1C0000}};
  return result;
}

/// @brief Возвращает максимальный decimal 79228162514264337593543950335
/// @return
s21_decimal decimal_get_max(void) {
  s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  return result;
}

/// @brief Возвращает максимальный int 2147483647 в всиде decimal
/// @return
s21_decimal decimal_get_int_max(void) {
  s21_decimal result = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};
  return result;
}

/// @brief Возвращает минимальный int -2147483648 в всиде decimal
/// @return
s21_decimal decimal_get_int_min(void) {
  s21_decimal result = {{0x80000000, 0x0, 0x0, 0x80000000}};
  return result;
}

/// @brief Создаёт из decimal big decimal
/// @param value_1 decimal
/// @return
s21_int256 int256_create_from_decimal(s21_decimal value_1) {
  s21_int256 result;
  result.decimals[0] = value_1;
  result.decimals[1] = decimal_get_zero();
  return result;
}