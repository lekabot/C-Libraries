#ifndef CONVERT_H
#define CONVERT_H

#include <stdlib.h>

#include "../arithmetic/arithmetic.h"
#include "../helpers/helpers.h"
#include "../types.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

typedef enum conversion_result_code {
  CONVERSION_OK = 0,
  CONVERSION_ERROR = 1
} conversion_result_code;

#define MAX_FLOAT_TO_CONVERT 79228157791897854723898736640.0f
#define MIN_FLOAT_TO_CONVERT \
  0.00000000000000000000000000010000000031710768509710513471352647538147514756461109f

// Вспомогательные функции

s21_decimal decimal_get_from_char(char c);
int float_get_exp_from_string(char *str);
s21_decimal float_string_to_decimal(char *str);

#endif  // CONVERT_H