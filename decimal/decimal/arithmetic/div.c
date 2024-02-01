#include "./../binary/binary.h"
#include "./../comparison/comparison.h"
#include "./../helpers/helpers.h"
#include "./../other/other.h"
#include "./arithmetic.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  arithmetic_error_codes code = OK;

  if (!result) {
    code = INCORRECT_INPUT_DATA;
  } else if (!decimal_is_correct(value_1) || !decimal_is_correct(value_2)) {
    code = INCORRECT_INPUT_DATA;
    *result = decimal_get_inf();
  } else if (s21_is_equal(value_2, decimal_get_zero())) {
    code = ZERO_DIV;
    *result = decimal_get_inf();
  } else {
    *result = decimal_get_zero();
    int sign1 = decimal_get_sign(value_1);
    int sign2 = decimal_get_sign(value_2);
    s21_int256 value_1l;
    s21_int256 value_2l;
    decimal_align_exponents(value_1, value_2, &value_1l, &value_2l);

    s21_int256 remainder = int256_create_from_decimal(decimal_get_zero());
    s21_int256 res;

    res = int256_binary_division(value_1l, value_2l, &remainder);

    if (res.decimals[0].bits[3] != 0 ||
        !int128_binary_equal_zero(res.decimals[1])) {
      if (sign1 != sign2) {
        code = TOO_SMALL;
      } else {
        code = TOO_BIG;
      }
      *result = decimal_get_inf();
    } else {
      code = division_core(value_2l, res, remainder, result);
      if (sign1 != sign2) {
        decimal_set_sign(result, NEGATIVE);
      }
      if (decimal_get_sign(*result) == NEGATIVE && code == TOO_BIG) {
        code = TOO_SMALL;
      }
      if (code == OK && s21_is_not_equal(value_1, decimal_get_zero()) &&
          s21_is_equal(*result, decimal_get_zero())) {
        code = TOO_SMALL;
      }
    }
  }

  return code;
}

int division_core(s21_int256 value_2l, s21_int256 res, s21_int256 remainder,
                  s21_decimal *result) {
  arithmetic_error_codes code = OK;
  int power1 = s21_div_calc_fractional(&res, value_2l, &remainder);
  s21_int256 tmp_res = int256_create_from_decimal(decimal_get_zero());
  int power2 = s21_div_calc_fractional(&tmp_res, value_2l, &remainder);
  decimal_set_power(&tmp_res.decimals[0], power2);

  if (s21_is_equal(tmp_res.decimals[0], decimal_get_point_five())) {
    if (!int128_binary_equal_zero(remainder.decimals[0]) ||
        !int128_binary_equal_zero(remainder.decimals[1])) {
      s21_add(tmp_res.decimals[0], decimal_get_min(), &tmp_res.decimals[0]);
    }
  }
  res.decimals[0] = decimal_round_banking(res.decimals[0], tmp_res.decimals[0]);
  decimal_set_power(&res.decimals[0], power1);
  if (!int128_binary_equal_zero(res.decimals[1]) ||
      !decimal_is_correct(res.decimals[0])) {
    code = TOO_BIG;
    *result = decimal_get_inf();
  } else {
    *result = res.decimals[0];
  }

  return code;
}

int s21_div_calc_fractional(s21_int256 *res, s21_int256 value_2l,
                            s21_int256 *remainder) {
  int power = 0;
  s21_int256 number = *res;

  s21_int256 tmp;
  s21_int256 tmp_remainder = *remainder;

  while ((!int128_binary_equal_zero((*remainder).decimals[0]) ||
          !int128_binary_equal_zero((*remainder).decimals[1])) &&
         power < 28) {
    s21_int256 number_stored = number;
    s21_int256 remainder_stored = tmp_remainder;

    number = int256_binary_multiplication(number, decimal_get_ten());
    tmp_remainder =
        int256_binary_multiplication(tmp_remainder, decimal_get_ten());
    tmp = int256_binary_division(tmp_remainder, value_2l, &tmp_remainder);
    number = int256_binary_addition(number, tmp);

    if (!decimal_is_correct(number.decimals[0])) {
      number = number_stored;
      tmp_remainder = remainder_stored;
      break;
    }

    ++power;
  }

  *res = number;
  *remainder = tmp_remainder;

  return power;
}
