#ifndef _COMPARISON_H_
#define _COMPARISON_H_

#include "../arithmetic/arithmetic.h"
#include "../types.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

int is_less_core(s21_decimal value_1, s21_decimal value_2);

typedef enum comparison_result_code {
  COMPARISON_FALSE = 0,
  COMPARISON_TRUE = 1,
} comparison_result_code;

#endif  // _COMPARISON_H_