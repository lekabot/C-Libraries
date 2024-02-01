#ifndef _BINARY_H_
#define _BINARY_H_

#include "../../s21_decimal.h"
#include "../types.h"
// basic_operations.c

int bit_is_set(int number, int index);
int bit_set_to_one(int number, int index);
int bit_set_to_zero(int number, int index);
int decimal_bit_is_set(s21_decimal decimal, int index);
s21_decimal decimal_set_bit(s21_decimal decimal, int index);
int decimal_get_not_zero_bit(s21_decimal decimal);

// binary_multiplication.c

s21_int256 int128_binary_multiplication(s21_decimal decimal_1,
                                        s21_decimal decimal_2);
s21_int256 int256_binary_multiplication(s21_int256 decimal_1,
                                        s21_decimal decimal_2);

// binary_addition.c

s21_decimal int128_binary_addition(s21_decimal decimal_1,
                                   s21_decimal decimal_2);
s21_int256 int256_binary_addition(s21_int256 decimal_1, s21_int256 decimal_2);

// binary_compare.c

int int128_binary_equal_zero(s21_decimal decimal);
int int128_binary_compare(s21_decimal decimal_1, s21_decimal decimal_2);
int int256_binary_compare(s21_int256 decimal_1, s21_int256 decimal_2);

// binary_logic_operations.c

s21_decimal int128_binary_and(s21_decimal decimal1, s21_decimal decimal2);
s21_decimal int128_binary_xor(s21_decimal decimal1, s21_decimal decimal2);
s21_decimal int128_binary_not(s21_decimal decimal);

// binary_shitfs.c

s21_decimal int128_binary_shift_left_one(s21_decimal decimal);
s21_decimal int128_binary_shift_left(s21_decimal decimal, int shift);
s21_decimal int128_binary_shift_right_one(s21_decimal decimal);
s21_decimal int128_binary_shift_right(s21_decimal decimal, int shift);
s21_int256 int256_binary_shift_left(s21_int256 decimal, int shift);
s21_int256 int256_binary_shift_right(s21_int256 decimal, int shift);

// binary_subtraction.c

s21_decimal int128_binary_subtraction(s21_decimal decimal_1,
                                      s21_decimal decimal_2);
s21_int256 int256_binary_subtraction(s21_int256 decimal_1,
                                     s21_int256 decimal_2);

// binary_division.c

s21_decimal int128_binary_division(s21_decimal decimal_1, s21_decimal decimal_2,
                                   s21_decimal *remainder);
s21_int256 int256_binary_division(s21_int256 decimal_1, s21_int256 decimal_2,
                                  s21_int256 *remainder);

#endif  // _BINARY_H_