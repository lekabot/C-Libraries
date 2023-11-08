//#include "s21_math.h"
//
/////////////////////////////////////
//double s21_sign(double x) {
//    if (x > 0) {
//        return 1;
//    }
//    else if (x < 0) {
//        return -1;
//    }
//    else {
//        return 0;
//    }
//}
//
//
//int s21_factorial(int x) {
//    if (x == 0 || x == 1) {
//        return 1;
//    }
//    return x * s21_factorial(x - 1);
//}
///////////////////////////////////
//
//
//long double s21_tan(double x) {
//    long double sin_x = s21_sin(x);
//    long double cos_x = s21_cos(x);
//    if (cos_x == 0) {
//        return 0.0;
//    }
//    return sin_x / cos_x;
//}
//
//
//long double s21_sqrt(double x) {
//    if (x < 0) {
//        return 0.0;
//    }
//    long double guess = x;
//    for (int i = 0; i < 100; i++) {
//        guess = 0.5 * (guess + x / guess);
//    }
//    return guess;
//}
//
//
//long double s21_sin(double x) {
//    while (s21_fabs(x) >= 2 * S21_PI) {
//        x -= s21_sign(x) * 2 * S21_PI;
//    }
//    long double result = x;
//    for (int i = 1; i <= 4; i++) {
//        double term = (double)s21_pow(x, 1 + 2 * i) / s21_factorial(1 + 2 * i);
//        if (i % 2 == 1) {
//            result -= term;
//        }
//        else {
//            result += term;
//        }
//    }
//    return result;
//}
//
//
//long double s21_pow(double base, double exp) {
//    if (exp < 0) {
//        return 1.0 / s21_pow(base, -exp);
//    } else if (exp == 0) {
//        return 1;
//    } else {
//        double res = 1.0;
//        for (int i = 0; i < exp; i++) {
//            res *= base;
//        }
//        return res;
//    }
//}
//
//
//long double s21_log(double x) {
//    int i;
//    int ex_pow = 0;
//    double result = 0;
//    double compare = 0;
//    for (; x >= S21_EXP; x /= S21_EXP, ex_pow++) continue;
//    for (i = 0; i < 100; i++) {
//        compare = result;
//        result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
//    }
//    return (result + ex_pow);
//}
//
//
//long double s21_fmod(double x, double y) {
//    if (y == 0) {
//        return x;
//    }
//    long double qotient = x / y;
//    long double int_part = (long long)qotient;
//    long double result = x - (y * int_part);
//    if (result < 0) {
//        result += y;
//    }
//    return result;
//}
//
//
//long double s21_floor(double x) {
//    long long int_part = (long long)x;
//    if (x >= 0.0) {
//        return int_part;
//    }
//    else {
//        return (x == int_part) ? int_part : int_part - 1;
//    }
//}
//
//
//long double s21_fabs(double x) {
//    return x < 0 ? -x : x;
//}
//
//
//int s21_abs(int x) {
//    return x < 0 ? -x : x;
//}
//
//
//long double s21_exp(double x) {
//    long double result = 1.0;
//    long double term = 1.0;
//    long double factorial = 1.0;
//    int i = 1;
//    while (i <= 100) {
//        term *= x;
//        factorial *= i;
//        result += term / factorial;
//        i++;
//    }
//    return result;
//}
//
//
//long double s21_cos(double x) {
//    long double result = 0.0;
//    long double term = 1.0;
//    int sign = 1;
//
//    for (int n = 0; n < 10; n++) {
//        result += sign * term;
//        term = term * (x * x) / ((2 * n + 1) * (2 * n + 2));
//        sign = -sign;
//    }
//
//    return result;
//}
//
//
//long double s21_ceil(double x) {
//    int int_part = (int)x;
//    if (x > 0) {
//        if (x != int_part) {
//            return int_part + 1.0;
//        } else {
//            return x;
//        }
//    } else if (x < 0) {
//        if (x != int_part) {
//            return int_part;
//        } else {
//            return x;
//        }
//    } else {
//        return x;
//    }
//}
//
//
//long double s21_atan(long double x) {
//    if (x == 0.0) {
//        return 0.0;
//    }
//
//    long double result = 0.0;
//
//    if (-1. < x && x < 1.) {
//        for (register int i = 0; i < 5000; i++) {
//            result += s21_pow(-1, i) * s21_pow(x, 1 + (2 * i)) / (1 + (2 * i));
//        }
//    } else {
//        for (register int i = 0; i < 7000; i++) {
//            result += s21_pow(-1, i) * s21_pow(x, -1 - (2 * i)) / (1 + (2 * i));
//        }
//        result = S21_PI * s21_sqrt(x * x) / (2 * x) - result;
//    }
//
//    return result;
//}
//
//
//long double s21_asin(double x) {
//    if (x <= -1.0 || x >= 1) {
//        return (x < 0) ? -S21_PI_2 : S21_PI_2;
//    }
//    if (x == 0.0) {
//        return 0.0;
//    }
//    return s21_tan(x / s21_sqrt(1 - x * x));
//}
//
//
//long double s21_acos(double x) {
//    if (x <= -1.0) {
//        return S21_PI;
//    }
//    if (x >= 1.0) {
//        return 0.0;
//    }
//    if (x == 0.0) {
//        return S21_PI_2;
//    }
//    return S21_PI_2 - s21_tan(x / s21_sqrt(1 * x * x));
//}
