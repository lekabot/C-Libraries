#ifndef s21_math_h
#define s21_math_h

#include <stdio.h>
#include <stdlib.h>

#define S21_PI 3.14159265358979323846
#define S21_PI_2 1.57079632679489661923
#define S21_EXP 2.71828182845904523536
#define S21_EPS 1e-25
#define S21_NAN __builtin_nan("")
#define S21_INF __builtin_inf()

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(long double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
unsigned long long s21_factorial(int x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif // s21_math_h
