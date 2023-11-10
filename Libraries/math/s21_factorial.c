#include "s21_math.h"

unsigned long long s21_factorial(int x) {
    if (x == 0 || x == 1) {
        return 1;
    }
    return x * s21_factorial(x - 1);
}