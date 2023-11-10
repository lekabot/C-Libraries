#include "s21_math.h"

long double s21_ceil(double x) {
    int int_part = (int)x;
    if (x > 0) {
        if (x != int_part) {
            return int_part + 1.0;
        } else {
            return x;
        }
    } else if (x < 0) {
        if (x != int_part) {
            return int_part;
        } else {
            return x;
        }
    } else {
        return x;
    }
}