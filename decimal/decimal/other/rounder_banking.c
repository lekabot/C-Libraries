#include "other.h"

/// @brief Производит банковское округление числа
/// @param integral цела часть числа
/// @param fractional дробная часть числа
/// @return s21_decimal округлённый
s21_decimal decimal_round_banking(s21_decimal integral,
                                  s21_decimal fractional) {
  s21_decimal point_five = decimal_get_point_five();
  s21_decimal result;
  if (s21_is_equal(fractional, point_five)) {
    if (decimal_is_even(integral)) {
      result = integral;
    } else {
      result = int128_binary_addition(integral, decimal_get_one());
    }
  } else if (s21_is_greater(fractional, point_five)) {
    result = int128_binary_addition(integral, decimal_get_one());
  } else {
    result = integral;
  }
  return result;
}