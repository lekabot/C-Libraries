#include "s21_math.h"

long double s21_fmod(double x, double y) {
    if (y == 0) {
        return x;
    }
    long double qotient = x / y;
    long double int_part = (long long)qotient;
    long double result = x - (y * int_part);
    if (result < 0) {
        result += y;
    }
    return result;
}