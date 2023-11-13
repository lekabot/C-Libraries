#include "s21_math.h"

long double s21_asin(double x) {
  long double res = 0;
  if (x <= 1.0 && x >= -1.0) {
    if (s21_sqrt(1.0 - x * x) != 0) {
      x /= s21_sqrt(1.0 - x * x);
      res = s21_atan(x);
    } else {
      res = s21_atan(x)* 2;
}  } else {
    res = S21_NAN;
  }
  return res;
}
