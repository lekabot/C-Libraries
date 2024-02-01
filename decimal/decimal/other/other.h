#ifndef _OTHER_OTHER_H_
#define _OTHER_OTHER_H_

#include "../../s21_decimal.h"

// floor.c

int s21_floor(s21_decimal value, s21_decimal *result);

// negative.c

int s21_negate(s21_decimal value, s21_decimal *result);

// remove_trailing_zeros.c

s21_decimal decimal_remove_trailing_zeros(s21_decimal value);

// round.c
int s21_round(s21_decimal value, s21_decimal *result);

// rounder_banking.c

s21_decimal decimal_round_banking(s21_decimal integral, s21_decimal fractional);

// truncate.c

int s21_truncate(s21_decimal value, s21_decimal *result);

/// @brief Результирующие функции для других функций
typedef enum other_result_codes {
  OTHER_OK = 0,
  OTHER_ERROR = 1
} other_result_codes;

#endif  //  _OTHER_OTHER_H_
