#ifndef SRC_S21_HELPERS_H_
#define SRC_S21_HELPERS_H_

#include "s21_decimal.h"


int get_bit(int number, int position);
int set_bit_to_zero(int* number, int position);
int set_bit_to_one(int* number, int position);
void set_bit_to_zero_in_decimal(s21_decimal* decimal, int position, int index);
int set_bit_to_one_in_decimal(s21_decimal* decimal, int position, int index);

#endif  //  SRC_S21_DECIMAL_H_
