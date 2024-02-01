#include "s21_math.h"

long double s21_sqrt(double x) {
  long double res = x;
  if (s21_is_nan(x) || x < 0) {
    return S21_NAN;
  } else if (s21_is_nan(x) || x <= S21_SQRT_EPS) {
    res = x;
  } else {
    res = s21_pow(x, 0.5);
  }
  return res;
}