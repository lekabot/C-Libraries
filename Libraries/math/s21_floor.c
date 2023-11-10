#include "s21_math.h"

long double s21_floor(double x) {
    long long int_part = (long long)x;
    if (x >= 0.0) {
        return int_part;
    }
    else {
        return (x == int_part) ? int_part : int_part - 1;
    }
}