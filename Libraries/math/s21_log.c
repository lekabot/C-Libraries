#include "s21_math.h"

long double s21_log(double x) {
    int i;
    int ex_pow = 0;
    double result = 0;
    double compare = 0;
    for (; x >= S21_EXP; x /= S21_EXP, ex_pow++) continue;
    for (i = 0; i < 100; i++) {
        compare = result;
        result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
    }
    return (result + ex_pow);
}