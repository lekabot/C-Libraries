#include "s21_math.h"

long double s21_sqrt(double x) {
    if (x < 0) {
        return S21_NAN;
    }
    long double guess = x;
    for (int i = 0; i < 100; i++) {
        guess = 0.5 * (guess + x / guess);
    }
    return guess;
}