#ifndef _ARITHMETIC_H
#define _ARITHMETIC_H

#include "../binary/binary.h"
#include "../helpers/helpers.h"
#include "../types.h"

/// @brief
/// 0 - OK
/// 1 - число слишком велико или равно бесконечности
/// 2 - число слишком мало или равно отрицательной бесконечности
/// 3 - деление на 0
/// 4 - некорректные входные данные
typedef enum {
  OK = 0,
  TOO_BIG = 1,
  TOO_SMALL = 2,
  ZERO_DIV = 3,
  INCORRECT_INPUT_DATA = 4
} arithmetic_error_codes;

// arithmetic_help_funcs.c

s21_decimal s21_abs(s21_decimal value_1);
int max(int value_1, int value_2);
int int256_get_shift_to_decimal(s21_int256 value);

// add.c

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int additional_core(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result);
void decimal_align_exponents(s21_decimal value_1, s21_decimal value_2,
                             s21_int256 *long_value_1,
                             s21_int256 *long_value_2);

// sub.c

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int subtraction_core(s21_decimal value_1, s21_decimal value_2,
                     s21_decimal *result);

// mul.c

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int multiplication_core(s21_decimal value_1, s21_decimal value_2,
                        s21_decimal *result);

// div.c

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int division_core(s21_int256 value_2l, s21_int256 res, s21_int256 remainder,
                  s21_decimal *result);
int s21_div_calc_fractional(s21_int256 *res, s21_int256 value_2l,
                            s21_int256 *remainder);

#endif  // _ARITHMETIC_H