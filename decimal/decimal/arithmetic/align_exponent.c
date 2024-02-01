#include "arithmetic.h"

/// @brief Выравнивание порядков степеней чисел value_1 и value_2.
/// Степень и знак чисел зануляются при выравнивании. Выравненные числа - это
/// только целая часть чисел
///
/// Например:
/// 123 (степень 0) и 7.898 (степень 3)
/// 123      -> 123.000 (степень 3)
/// 7.898    ->   7.898 (степень 3)
///
/// Результат: 123000 и 7898
/// @param value_1 первое число
/// @param value_2 второе число
/// @param long_value_1 число с выравненной экспонентой
/// @param long_value_1 число с выравненной экспонентой
void decimal_align_exponents(s21_decimal value_1, s21_decimal value_2,
                             s21_int256 *long_value_1,
                             s21_int256 *long_value_2) {
  const int power_1 = decimal_get_power(value_1);
  const int power_2 = decimal_get_power(value_2);
  s21_decimal tmp1 = value_1;
  s21_decimal tmp2 = value_2;
  decimal_clear_service_bits(&tmp1);
  decimal_clear_service_bits(&tmp2);
  if (power_1 > power_2) {
    *long_value_1 = int256_create_from_decimal(tmp1);
    *long_value_2 = int128_binary_multiplication(
        tmp2, int128_get_ten_pow(power_1 - power_2));
  } else if (power_1 < power_2) {
    *long_value_1 = int128_binary_multiplication(
        tmp1, int128_get_ten_pow(power_2 - power_1));
    *long_value_2 = int256_create_from_decimal(tmp2);
  } else {
    *long_value_1 = int256_create_from_decimal(tmp1);
    *long_value_2 = int256_create_from_decimal(tmp2);
  }
}