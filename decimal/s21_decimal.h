#ifndef _S21_DECIMAL_H_
#define _S21_DECIMAL_H_

// typedef struct {
//     unsigned int bits[4];
// } s21_decimal;

#include <math.h>
#include <string.h>

#include "decimal/arithmetic/arithmetic.h"
#include "decimal/binary/binary.h"
#include "decimal/comparison/comparison.h"
#include "decimal/convert/convert.h"
#include "decimal/helpers/helpers.h"
#include "decimal/other/other.h"
#include "decimal/types.h"

// & - AND если один из пары равен 0, то 0. Иначе 1
// | - OR если один из пары равен 1, то 1. Иначе 0
// << - равносильно * 2
// >> - равносильно / 2
// ~ - NO где было 0 станет 1

// 0 - OK
// 1 - the number is too large or equal to infinity
// 2 - the number is too small or equal to negative infinity
// 3 - division by 0

// int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
// int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
// int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
// int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// 0 - FALSE
// 1 - TRUE

// int s21_is_less(s21_decimal value_1, s21_decimal value_2);
// int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
// int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
// int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
// int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
// int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

// 0 - OK
// 1 - convertation error

// int s21_from_int_to_decimal(int src, s21_decimal *dst);
// int s21_from_float_to_decimal(float src, s21_decimal *dst);
// int s21_from_decimal_to_int(s21_decimal src, int *dst);
// int s21_from_decimal_to_float(s21_decimal src, float *dst);

#endif  //  SRC_S21_DECIMAL_H_