#include "s21_math_test.h"

START_TEST(test_pos1) { double x = 0.999; ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), 1e-6); }
END_TEST

START_TEST(test_pos2) { double x = 1; ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), 1e-6); }
END_TEST

START_TEST(test_pos3) { double x = 3.0; ck_assert_ldouble_nan(s21_acos(x));}
END_TEST

START_TEST(test_pos4) { double x = 0; ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), 1e-6); }
END_TEST

START_TEST(test_neg1) { double x = -0.001; ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), 1e-6); }
END_TEST

START_TEST(test_neg2) { double x = -0.9999; ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), 1e-6); }
END_TEST

START_TEST(test_neg3) { double x = -1 - 1e-6; ck_assert_ldouble_nan(s21_acos(x)); }
END_TEST

START_TEST(test_null1) { double x = 1.001; ck_assert_ldouble_nan(s21_acos(x)); }
END_TEST

START_TEST(test_null2) { double x = -1.1; ck_assert_ldouble_nan(s21_acos(x)); }
END_TEST

START_TEST(test_null3) { double x = S21_NAN; ck_assert_ldouble_nan(s21_acos(x)); }
END_TEST

START_TEST(test_null4) { double x = S21_INF; ck_assert_ldouble_nan(s21_acos(x)); }
END_TEST

Suite *suite_acos(void) {
    Suite *s = suite_create("suite_acos");
    TCase *tc = tcase_create("acos_tc");

    tcase_add_test(tc, test_pos1);
    tcase_add_test(tc, test_pos2);
    tcase_add_test(tc, test_pos3);
    tcase_add_test(tc, test_pos4);
    tcase_add_test(tc, test_neg1);
    tcase_add_test(tc, test_neg2);
    tcase_add_test(tc, test_neg3);
    tcase_add_test(tc, test_null1);
    tcase_add_test(tc, test_null2);
    tcase_add_test(tc, test_null3);
    tcase_add_test(tc, test_null4);

    suite_add_tcase(s, tc);
    return s;
}