#include "s21_math.h"

long double s21_cos(double x) {
    long double result = 0.0;
    long double term = 1.0;
    int sign = 1;

    for (int n = 0; n < 10; n++) {
        result += sign * term;
        term = term * (x * x) / ((2 * n + 1) * (2 * n + 2));
        sign = -sign;
    }

    return result;
}