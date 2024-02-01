#include <stdlib.h>

#include "./../binary/binary.h"
#include "./../helpers/helpers.h"
#include "./../other/other.h"
#include "./arithmetic.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  arithmetic_error_codes code = OK;
  if (!result) {
    code = INCORRECT_INPUT_DATA;
  } else if (!decimal_is_correct(value_1) || !decimal_is_correct(value_2)) {
    code = INCORRECT_INPUT_DATA;
    *result = decimal_get_inf();
  } else {
    *result = decimal_get_zero();
    s21_decimal res = decimal_get_zero();

    int sign1 = decimal_get_sign(value_1);
    int sign2 = decimal_get_sign(value_2);

    if (sign1 == POSITIVE && sign2 == POSITIVE) {
      code = additional_core(value_1, value_2, &res);
    } else if (sign1 == POSITIVE && sign2 == NEGATIVE) {
      code = s21_sub(value_1, s21_abs(value_2), &res);
    } else if (sign1 == NEGATIVE && sign2 == POSITIVE) {
      code = s21_sub(s21_abs(value_1), value_2, &res);
      s21_negate(res, &res);
    } else if (sign1 == NEGATIVE && sign2 == NEGATIVE) {
      code = additional_core(s21_abs(value_1), s21_abs(value_2), &res);
      s21_negate(res, &res);
    }

    if (decimal_get_sign(res) == NEGATIVE && code == TOO_BIG) {
      code = TOO_SMALL;
    }

    *result = res;
  }

  return code;
}

int additional_core(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result) {
  arithmetic_error_codes code = OK;
  s21_int256 value_1l;
  s21_int256 value_2l;
  int power1 = decimal_get_power(value_1);
  int power2 = decimal_get_power(value_2);
  int max_power = max(power1, power2);
  decimal_align_exponents(value_1, value_2, &value_1l, &value_2l);
  s21_int256 res = int256_binary_addition(value_1l, value_2l);
  int shift = int256_get_shift_to_decimal(res);
  int res_power = max_power - shift;
  if (res_power < 0) {
    code = TOO_BIG;
    *result = decimal_get_inf();
  } else {
    while (shift > 28) {
      res = int256_binary_division(
          res, int256_create_from_decimal(decimal_get_ten()), NULL);
      --shift;
    }
    s21_int256 remainder = int256_create_from_decimal(decimal_get_zero());
    s21_int256 powerten = int256_create_from_decimal(int128_get_ten_pow(shift));
    res = int256_binary_division(res, powerten, &remainder);
    decimal_set_power(&remainder.decimals[0], shift);
    res.decimals[0] =
        decimal_round_banking(res.decimals[0], remainder.decimals[0]);
    decimal_set_power(&res.decimals[0], res_power);

    if (!int128_binary_equal_zero(res.decimals[1]) ||
        !decimal_is_correct(res.decimals[0])) {
      code = TOO_BIG;
      *result = decimal_get_inf();
    } else {
      *result = res.decimals[0];
    }
  }

  return code;
}
