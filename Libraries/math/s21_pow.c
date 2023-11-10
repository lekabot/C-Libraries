#include "s21_math.h"

long double s21_pow(double base, double exp) {
    if (exp < 0) {
        return 1.0 / s21_pow(base, -exp);
    } else if (exp == 0) {
        return 1;
    } else {
        double res = 1.0;
        for (int i = 0; i < exp; i++) {
            res *= base;
        }
        return res;
    }
}