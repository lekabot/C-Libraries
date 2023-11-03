#include "s21_math.h"
#include <math.h>

int areEqual(double a, double b, double epsilon) {
    return fabs(a - b) < epsilon;
}


void s21_tan_test(void) {
    double x = 1.0;
    double y = 0.5;
    double z = -0.8;
    double epsilon = 1e-6;

    if (areEqual(s21_tan(x), tan(x), epsilon) &&
        areEqual(s21_tan(y), tan(y), epsilon) &&
        areEqual(s21_tan(z), tan(z), epsilon)) {
        printf("s21_tan_test: SUCCESS\n");
    }
    else {
        printf("s21_tan_test: FAIL\n");
        printf("%Lf %lf %Lf %lf %Lf %lf\n", s21_tan(x), tan(x), s21_tan(y), tan(y), s21_tan(z), tan(z));
    }
}


void s21_sqrt_test(void) {
    double x = 16.0;
    double y = 2.0;
    double epsilon = 1e-6;
    
    if (areEqual(s21_sqrt(x), sqrt(x), epsilon) &&
        areEqual(s21_sqrt(y), sqrt(y), epsilon)) {
        printf("s21_sqrt_test: SUCCESS\n");
    }
    else {
        printf("s21_sqrt_test: FAIL\n");
        printf("%Lf %f %Lf %f\n", s21_sqrt(x), sqrt(x), s21_sqrt(y), sqrt(y));
    }
}


void s21_fmod_test(void) {
    double x = 7.5;
    double y = 2.0;

    if (s21_fmod(x, y) == fmod(x, y)) {
        printf("s21_fmod_test: SUCCESS\n");
    }
    else {
        printf("s21_fmod_test: FAIL\n");
        printf("%Lf %f\n", s21_fmod(x, y), fmod(x, y));
    }
}


void s21_sin_test(void) {
    int x = 1;
    int y = -1;
    int z = 0;
    double epsilon = 1e-6;

    if (areEqual(s21_sin(x), sin(x), epsilon) &&
        areEqual(s21_sin(y), sin(y), epsilon) &&
        areEqual(s21_sin(z), sin(z), epsilon)) {
        printf("s21_sin_test: SUCCESS\n");
    }
    else {
        printf("s21_sin_test: FAIL\n");
        printf("%Lf %f %Lf %f %Lf %f\n", s21_sin(x), sin(x), s21_sin(y), sin(y), s21_sin(z), sin(z));
    }
}


void s21_pow_test(void) {
    double base = 2.0;
    double exp = 3.0;

    if (s21_pow(base, exp) == pow(base, exp)) {
        printf("s21_pow_test: SUCCESS\n");
    }
    else {
        printf("s21_pow_test: FAIL\n");
        printf("%Lf %lf\n", s21_pow(base, exp), pow(base, exp));
    }
}


void s21_log_test(void) {
    //Òîëüêî ïîëîæèòåëüíûå ÷èñëà
    double x = 2.0;
    double y = 3.0;
    double z = 4.0;
    double epsilon = 1e-6;

    if (areEqual(s21_log(x), log(x), epsilon) &&
        areEqual(s21_log(y), log(y), epsilon) &&
        areEqual(s21_log(z), log(z), epsilon)) {
        printf("s21_log_test: SUCCESS\n");
    }
    else {
        printf("s21_log_test: FAIL\n");
        printf("%Lf %lf %Lf %lf %Lf %lf\n", s21_log(x), log(x), s21_log(y), log(y), s21_log(z), log(z));
    }
}


void s21_floor_test(void) {
    double x = 2.3;
    double y = -3.7;
    double z = 0.0;

    if (s21_floor(x) == floor(x) && s21_floor(y) == floor(y) && s21_floor(z) == floor(z)) {
        printf("s21_floor_test: SUCCESS\n");
    }
    else {
        printf("s21_floor_test: FAIL\n");
        printf("%Lf %lf %Lf %lf %Lf %lf\n", s21_floor(x), floor(x), s21_floor(y), floor(y), s21_floor(z), floor(z));
    }
}


void s21_fabs_test(void) {
    int x = 1;
    int y = -1;
    int z = 0;
    if (s21_fabs(x) == abs(x) && s21_fabs(y) == abs(y) && s21_fabs(z) == abs(z)) {
        printf("s21_fabs_test: SUCCES\n");
    }
    else {
        printf("s21_fabs_test: FAIL\n");
        printf("%Lf %d %Lf %d %Lf %d\n", s21_fabs(x), abs(x), s21_fabs(y), abs(y), s21_fabs(z), abs(z));
    }
}


void s21_exp_test(void) {
    int x = 1;
    int y = -1;
    int z = 0;
    double epsilon = 1e-6;

    if (areEqual(s21_exp(x), exp(x), epsilon) &&
        areEqual(s21_exp(y), exp(y), epsilon) &&
        areEqual(s21_exp(z), exp(z), epsilon)) {
        printf("s21_exp_test: SUCCESS\n");
    }
    else {
        printf("s21_exp_test: FAIL\n");
        printf("%Lf %f %Lf %f %Lf %f\n", s21_exp(x), exp(x), s21_exp(y), exp(y), s21_exp(z), exp(z));
    }
}


void s21_cos_test(void) {
    int x = 1;
    int y = -1;
    int z = 0;
    double epsilon = 1e-6;

    if (areEqual(s21_cos(x), cos(x), epsilon) &&
        areEqual(s21_cos(y), cos(y), epsilon) &&
        areEqual(s21_cos(z), cos(z), epsilon)) {
        printf("s21_cos_test: SUCCESS\n");
    }
    else {
        printf("s21_cos_test: FAIL\n");
        printf("%Lf %f %Lf %f %Lf %f\n", s21_cos(x), cos(x), s21_cos(y), cos(y), s21_cos(z), cos(z));
    }
}


void s21_ceil_test(void) {
    int x = 1;
    int y = -1;
    int z = 0;
    if (s21_ceil(x) == ceil(x) && s21_ceil(y) == ceil(y) && s21_ceil(z) == ceil(z)) {
        printf("s21_ceil_test: SUCCES\n");
    }
    else {
        printf("s21_ceil_test: FAIL\n");
        printf("%Lf %f %Lf %f %Lf %f\n", s21_ceil(x), ceil(x), s21_ceil(y), ceil(y), s21_ceil(z), ceil(z));
    }
}


void s21_atan_test(void) {
    double x = -1;
    double y = 1;
    double z = 0;
    double epsilon = 2;

    if (areEqual(s21_atan(x), atan(x), epsilon) &&
        areEqual(s21_atan(y), atan(y), epsilon) &&
        areEqual(s21_atan(z), atan(z), epsilon)) {
        printf("s21_atan_test: SUCCESS\n");
    }
    else {
        printf("s21_atan_test: FAIL\n");
        printf("%Lf %lf %Lf %lf %Lf %lf\n", s21_atan(x), atan(x), s21_atan(y), atan(y), s21_atan(z), atan(z));
    }
}


void s21_asin_test(void) {
    int x = 1;
    int y = -1;
    int z = 0;
    if (s21_asin(x) == asin(x) && s21_asin(y) == asin(y) && s21_asin(z) == asin(z)) {
        printf("s21_asin_test: SUCCES\n");
    }
    else {
        printf("s21_asin_test: FAIL\n");
        printf("%Lf %f %Lf %f %Lf %f\n", s21_asin(x), asin(x), s21_asin(y), asin(y), s21_asin(z), asin(z));
    }
}


void s21_acos_test(void) {
    int x = 1;
    int y = -1;
    int z = 0;
    if (s21_acos(x) == acos(x) && s21_acos(y) == acos(y) && s21_acos(z) == acos(z)) {
        printf("s21_acos_test: SUCCES\n");
    }
    else {
        printf("s21_acos_test: FAIL\n");
        printf("%Lf %f %Lf %f %Lf %f\n", s21_acos(x), acos(x), s21_acos(y), acos(y), s21_acos(z), acos(z));
    }
}


void s21_abs_test(void) {
    int x = 1;
    int y = -1;
    int z = 0;
    if (s21_abs(x) == abs(x) && s21_abs(y) == abs(y) && s21_abs(z) == abs(z)) {
        printf("s21_abs_test: SUCCES\n");
    } else {
        printf("s21_abs_test: FAIL\n");
        printf("%d %d %d %d %d %d\n", s21_abs(x), abs(x), s21_abs(y), abs(y), s21_abs(z), abs(z));
    }
}


int main(void) {
    s21_abs_test();
    s21_acos_test();
    s21_asin_test();
    s21_atan_test();
    s21_ceil_test();
    s21_cos_test();
    s21_sin_test();
    s21_exp_test();
    s21_sqrt_test();
    s21_fmod_test();
    s21_log_test();
    s21_pow_test();
    s21_floor_test();
    s21_fabs_test();
    s21_tan_test();
}
