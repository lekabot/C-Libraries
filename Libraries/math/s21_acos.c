#include "s21_math.h"

long double s21_acos(double x) {
    if (x <= -1.0) {
        return S21_PI;
    }
    if (x >= 1.0) {
        return 0.0;
    }
    if (x == 0.0) {
        return S21_PI_2;
    }
    return S21_PI_2 - s21_tan(x / s21_sqrt(1 * x * x));
}
