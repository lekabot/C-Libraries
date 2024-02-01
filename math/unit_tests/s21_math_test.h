#ifndef s21_s21_math_test_h
#define s21_s21_math_test_h

#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define S21_ASIN_EPS 1e-6l;
#define S21_NEGZERO -0.0
#define TEST_EPS 1e-6l

#include "../s21_math.h"

Suite *suite_abs(void);
Suite *suite_acos(void);
Suite *suite_asin(void);
Suite *suite_atan(void);
Suite *suite_ceil(void);
Suite *suite_cos(void);
Suite *suite_exp(void);
Suite *suite_fabs(void);
Suite *suite_floor(void);
Suite *suite_fmod(void);
Suite *suite_log(void);
Suite *suite_pow(void);
Suite *suite_sin(void);
Suite *suite_sqrt(void);
Suite *suite_tan(void);

void run_tests(void);
void run_testcase(Suite* testcase);

#endif /*s21_s21_math_test_h*/