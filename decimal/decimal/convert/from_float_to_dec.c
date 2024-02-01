#include <stdio.h>

#include "convert.h"

/**
 * @brief конвертирует float src в decimal dst
 * @param src конвертируемый float
 * @param dst указатель на decimal, в который запишется результат функции
 * @return int код ошибки:
 * 0 - OK
 * 1 - ошибка конвертации
 */
int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  conversion_result_code code = CONVERSION_OK;
  if (!dst) {
    code = CONVERSION_ERROR;
  } else if (src == 0.0) {
    code = CONVERSION_OK;
    *dst = decimal_get_zero();
    if (signbit(src)) {
      decimal_set_sign(dst, NEGATIVE);
    }
  } else if (isinf(src) || isnan(src)) {
    code = CONVERSION_ERROR;
    *dst = decimal_get_inf();
    if (signbit(src)) {
      decimal_set_sign(dst, NEGATIVE);
    }
  } else if (fabsf(src) > MAX_FLOAT_TO_CONVERT) {
    code = CONVERSION_ERROR;
    *dst = decimal_get_inf();
    if (signbit(src)) {
      decimal_set_sign(dst, NEGATIVE);
    }
  } else if (fabsf(src) < MIN_FLOAT_TO_CONVERT) {
    code = CONVERSION_ERROR;
    *dst = decimal_get_zero();
  } else {
    *dst = decimal_get_zero();
    s21_decimal result;
    char src_float[64];
    sprintf(src_float, "%.6E", fabsf(src));
    int exp = float_get_exp_from_string(src_float);
    if (exp <= -23) {
      // Если степень слишком маленькая, то корректируем её
      // и заново приводим float в научную запись уже с новой точностью
      const int float_precision = exp + 28;
      sprintf(src_float, "%.*E", float_precision, fabsf(src));
    }
    result = float_string_to_decimal(src_float);
    if (signbit(src) != 0) {
      decimal_set_sign(&result, NEGATIVE);
    }
    *dst = result;
  }
  return code;
}