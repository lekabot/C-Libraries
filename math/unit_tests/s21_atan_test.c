#include "s21_math_test.h"

START_TEST(test_atan_pos) {
    double x = 0.4;
    ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_neg) {
    double x = -0.4;
    ck_assert_double_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_zero) {
    double x = 0.0;
    ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_zero_neg) {
    double x = -0.0;
    ck_assert_double_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_one) {
    double x = 1.0;
    ck_assert_double_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_one_neg) {
    double x = -1.0;
    ck_assert_double_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_huge_pos) {
    double x = 9999999.0;
    ck_assert_double_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_huge_neg) {
    double x = -9999999.0;
    ck_assert_double_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_big_mantisa) {
    double x = 0.1712645124761524765127465176;
    ck_assert_double_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_nan) {
    double x = S21_NAN;
    ck_assert_double_nan(s21_atan(x));
}
END_TEST

START_TEST(test_atan_inf) {
    double x = S21_INF;
    ck_assert_double_nan(s21_atan(x));
}
END_TEST

START_TEST(test_atan_loop_value) {
    double i = _i;
    ck_assert_double_eq_tol(atan(i / 20.0), s21_atan(i / 20.0), 1e-6);
}
END_TEST

START_TEST(test_atan_dbl_max) {
    double x = DBL_MAX;
    ck_assert_double_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

START_TEST(test_atan_dbl_min) {
    double x = DBL_MIN;
    ck_assert_double_eq_tol(atan(x), s21_atan(x), 1e-6);
}
END_TEST

Suite *suite_atan(void) {
    Suite *s = suite_create("suite_atan");
    TCase *tc = tcase_create("atan_tc");

    tcase_add_test(tc, test_atan_pos);
    tcase_add_test(tc, test_atan_neg);
    tcase_add_test(tc, test_atan_zero);
    tcase_add_test(tc, test_atan_zero_neg);
    tcase_add_test(tc, test_atan_one);
    tcase_add_test(tc, test_atan_one_neg);
    tcase_add_test(tc, test_atan_huge_pos);
    tcase_add_test(tc, test_atan_huge_neg);
    tcase_add_test(tc, test_atan_big_mantisa);
    tcase_add_test(tc, test_atan_nan);
    tcase_add_test(tc, test_atan_inf);
    tcase_add_test(tc, test_atan_loop_value);
    tcase_add_test(tc, test_atan_dbl_max);
    tcase_add_test(tc, test_atan_dbl_min);

    suite_add_tcase(s, tc);
    return s;
}