#include "convert.h"

/// @brief Эта функция находит экспонентку у числа типа float записанного в виде
/// строки
/// @param str
/// @return exp
int float_get_exp_from_string(char* str) {
  int exp = 0;
  char* tmp = str;
  while (*tmp) {
    if (*tmp == 'E') {
      ++tmp;
      exp = strtol(tmp, NULL, 10);
      break;
    }
    ++tmp;
  }
  return exp;
}

s21_decimal float_string_to_decimal(char* str) {
  int digits_counter = 6;
  s21_decimal result = decimal_get_zero();
  char* tmp_str = str;
  int exp = float_get_exp_from_string(str);
  while (*tmp_str) {
    if (*tmp_str == '.') {
      ++tmp_str;
      continue;
    } else if (*tmp_str >= '0' && *tmp_str <= '9') {
      s21_decimal tmp_decimal = decimal_get_zero();
      s21_mul(decimal_get_from_char(*tmp_str),
              int128_get_ten_pow(digits_counter), &tmp_decimal);
      s21_add(result, tmp_decimal, &result);
      --digits_counter;
      ++tmp_str;
    } else {
      break;
    }
  }
  exp = exp - 6;

  if (exp > 0) {
    // Для положительной степени производим умножение на 10^exp
    s21_mul(result, int128_get_ten_pow(exp), &result);
  } else if (exp < 0) {
    // Для отрицательной степени производим деление на 10^exp
    if (exp < -28) {
      // Для очень маленьких степеней
      s21_div(result, int128_get_ten_pow(28), &result);
      exp += 28;
    }
    s21_div(result, int128_get_ten_pow(-exp), &result);
  }
  // Плачем попой >=|
  return result;
}

/// @brief возвращает число в виде decimal
/// @param c
/// @return s21_decimal число в виде decimal
s21_decimal decimal_get_from_char(char c) {
  s21_decimal result;
  switch (c) {
    case '0':
      result = decimal_get_zero();
      break;
    case '1':
      result = decimal_get_one();
      break;
    case '2':
      s21_from_int_to_decimal(2, &result);
      break;
    case '3':
      s21_from_int_to_decimal(3, &result);
      break;
    case '4':
      s21_from_int_to_decimal(4, &result);
      break;
    case '5':
      s21_from_int_to_decimal(5, &result);
      break;
    case '6':
      s21_from_int_to_decimal(6, &result);
      break;
    case '7':
      s21_from_int_to_decimal(7, &result);
      break;
    case '8':
      s21_from_int_to_decimal(8, &result);
      break;
    case '9':
      s21_from_int_to_decimal(9, &result);
      break;
  }
  return result;
}