#include "s21_math.h"

long double s21_ceil(double x) {
  long double res = (long long int)(x);
  if (s21_is_inf(x) || s21_is_nan(x) || x == 0 || x == S21_NEGZERO ||
      x == __DBL_MAX__) {
    res = x;
  } else if (x == __DBL_MIN__) {
    res = 1;
  } else {
    if (s21_fabs(x) > 0. && res != x) {
      if (x > 0.) {
        res += 1;
      }
    }
  }
  return res;
}