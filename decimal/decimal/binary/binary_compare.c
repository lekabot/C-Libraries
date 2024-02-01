#include "binary.h"

/// @brief Сравниваем каждую переменную всего decimala с 0
/// @param decimal
/// @return 1 - все биты нули, 0 - не все биты нули
int int128_binary_equal_zero(s21_decimal decimal) {
  return decimal.bits[0] == 0 && decimal.bits[1] == 0 && decimal.bits[2] == 0 &&
         decimal.bits[3] == 0;
}

/// @brief Сравнивает побиотов 2 decimal
/// @param decimal_1 1 число
/// @param decimal_2 2 число
/// @return -1 - Значение d1 меньше d2.
///         0 - Значения d1 и d2 равны.
///         1 - Значение d1 больше значения d2.
int int128_binary_compare(s21_decimal decimal_1, s21_decimal decimal_2) {
  int result = 0;
  for (int i = MAX_BITS - 1; i >= 0; i--) {
    int bit_1 = decimal_bit_is_set(decimal_1, i);
    int bit_2 = decimal_bit_is_set(decimal_2, i);
    if (bit_1 == 0 && bit_2 != 0) {
      result = -1;
    }
    if (bit_1 != 0 && bit_2 == 0) {
      result = 1;
    }
    if (result != 0) {
      break;
    }
  }
  return result;
}

/// @brief Функция сравнивает побитово 2 больших decimal
/// @param decimal_1
/// @param decimal_2
/// @return -1 - Значение d1 меньше d2.
///         0 - Значения d1 и d2 равны.
///         1 - Значение d1 больше значения d2.
int int256_binary_compare(s21_int256 decimal_1, s21_int256 decimal_2) {
  int compare_error_code =
      int128_binary_compare(decimal_1.decimals[1], decimal_2.decimals[1]);
  if (compare_error_code == 0) {
    compare_error_code =
        int128_binary_compare(decimal_1.decimals[0], decimal_2.decimals[0]);
  }
  return compare_error_code;
}