#include "s21_math.h"

long double s21_tan(double x) {
  long double sin_x = s21_sin(x);
  long double cos_x = s21_cos(x);
  if (cos_x == 0) {
    return S21_NAN;
  }
  return sin_x / cos_x;
}