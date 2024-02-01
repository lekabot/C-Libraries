#include "other.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  other_result_codes code = OTHER_OK;
  if (!result) {
    code = OTHER_ERROR;
  } else {
    *result = value;
    decimal_set_sign(result, !decimal_get_sign(*result));
    if (!decimal_is_correct(value)) {
      code = OTHER_ERROR;
    }
  }
  return code;
}