#include "s21_math.h"

long double s21_asin(double x) {
    if (x <= -1.0 || x >= 1) {
        return (x < 0) ? -S21_PI_2 : S21_PI_2;
    }
    if (x == 0.0) {
        return S21_NAN;
    }
    return s21_tan(x / s21_sqrt(1 - x * x));
}