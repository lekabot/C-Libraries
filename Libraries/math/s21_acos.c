#include "s21_math.h"

long double s21_acos(double x) {
    if (x == 1) {
        return 0.0;
    }
    return (S21_PI_2 - s21_asin(x));
}