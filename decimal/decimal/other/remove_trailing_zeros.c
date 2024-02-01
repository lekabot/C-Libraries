#include "other.h"

/// @brief Убирает конечные нули числа
/// @param value
/// @return
s21_decimal decimal_remove_trailing_zeros(s21_decimal value) {
  s21_decimal result = value;
  int power = decimal_get_power(value);
  int sign = decimal_get_sign(value);

  if (power > 0 && decimal_is_correct(value)) {
    s21_decimal remainder = decimal_get_zero();
    s21_decimal tmp = value;
    decimal_clear_service_bits(&tmp);
    // Делим число на 10, уменьшая степень decimal, до тех пор, пока остаток от
    // деления равен нулю
    while (power > 0) {
      tmp = int128_binary_division(tmp, int128_get_ten_pow(1), &remainder);
      if (int128_binary_equal_zero(remainder)) {
        --power;
        result = tmp;
      } else {
        break;
      }
    }
    decimal_set_power(&result, power);
    decimal_set_sign(&result, sign);
  }
  return result;
}