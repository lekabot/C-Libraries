#ifndef S21_DECIMAL_TESTS_H
#define S21_DECIMAL_TESTS_H

#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "../s21_decimal.h"

Suite *s21_int_to_decimal_tests(void);
Suite *s21_decimal_to_int_tests(void);
Suite *s21_from_float_to_decimal_tests(void);
Suite *s21_from_decimal_to_float_tests(void);
Suite *s21_less_tests(void);
Suite *s21_is_less_or_equal_tests(void);
Suite *s21_is_equal_tests(void);
Suite *s21_is_greater_tests(void);
Suite *s21_is_greater_or_equal_tests(void);
Suite *s21_not_equal_tests(void);
Suite *s21_div_tests(void);
Suite *s21_add_tests(void);
Suite *s21_mul_tests(void);
Suite *s21_sub_tests(void);
Suite *s21_help_tests(void);
Suite *s21_floor_tests(void);
Suite *s21_negate_tests(void);
Suite *s21_round_tests(void);
Suite *s21_truncate_tests(void);

void run_testcase(Suite *testcase);
void run_tests(void);

#endif  // S21_DECIMAL_TESTS_H