#include "s21_math.h"

long double s21_atan(long double x) {
    if (x == 0.0) {
        return S21_NAN;
    }

    long double result = 0.0;

    if (-1. < x && x < 1.) {
        for (register int i = 0; i < 5000; i++) {
            result += s21_pow(-1, i) * s21_pow(x, 1 + (2 * i)) / (1 + (2 * i));
        }
    } else {
        for (register int i = 0; i < 7000; i++) {
            result += s21_pow(-1, i) * s21_pow(x, -1 - (2 * i)) / (1 + (2 * i));
        }
        result = S21_PI * s21_sqrt(x * x) / (2 * x) - result;
    }

    return result;
}