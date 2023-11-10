#include "s21_math.h"

long double s21_exp(double x) {
    long double result = 1.0;
    long double term = 1.0;
    long double factorial = 1.0;
    int i = 1;
    while (i <= 100) {
        term *= x;
        factorial *= i;
        result += term / factorial;
        i++;
    }
    return result;
}