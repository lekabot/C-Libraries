#include "s21_math_test.h"

START_TEST(test_asin_pos) {
    double x = 0.4;
    ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST

START_TEST(test_asin_neg) {
    double x = -0.4;
    ck_assert_double_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST

START_TEST(test_asin_zero) {
    double x = 0.0;
    ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST

START_TEST(test_asin_zero_neg) {
    double x = -0.0;
    ck_assert_double_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST

START_TEST(test_asin_one) {
    double x = 1.0;
    ck_assert_double_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST

START_TEST(test_asin_one_neg) {
    double x = -1.0;
    ck_assert_double_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST

START_TEST(test_asin_huge_pos) {
    double x = 5;
    ck_assert_double_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST

START_TEST(test_asin_huge_neg) {
    double x = -5;
    ck_assert_double_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST

START_TEST(test_asin_big_mantisa) {
    double x = 0.1712645124761524765127465176;
    ck_assert_double_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST

START_TEST(test_asin_eps_pos) {
    double x = 1 + S21_ASIN_EPS;
    ck_assert_double_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST

START_TEST(test_asin_eps_neg) {
    double x = -1 + S21_ASIN_EPS;
    ck_assert_double_eq_tol(asin(x), s21_asin(x), 1e-6);
}
END_TEST

START_TEST(test_asin_nan) {
    double x = S21_NAN;
    ck_assert_double_nan(s21_asin(x));
}
END_TEST

START_TEST(test_asin_inf) {
    double x = S21_INF;
    ck_assert_double_nan(s21_asin(x));
}
END_TEST

Suite *suite_asin(void) {
    Suite *s = suite_create("suite_asin");
    TCase *tc = tcase_create("asin_tc");

    tcase_add_test(tc, test_asin_pos);
    tcase_add_test(tc, test_asin_neg);
    tcase_add_test(tc, test_asin_zero);
    tcase_add_test(tc, test_asin_zero_neg);
    tcase_add_test(tc, test_asin_one);
    tcase_add_test(tc, test_asin_one_neg);
    tcase_add_test(tc, test_asin_huge_pos);
    tcase_add_test(tc, test_asin_huge_neg);
    tcase_add_test(tc, test_asin_big_mantisa);
    tcase_add_test(tc, test_asin_eps_pos);
    tcase_add_test(tc, test_asin_eps_neg);
    tcase_add_test(tc, test_asin_nan);
    tcase_add_test(tc, test_asin_inf);

    suite_add_tcase(s, tc);
    return s;
}