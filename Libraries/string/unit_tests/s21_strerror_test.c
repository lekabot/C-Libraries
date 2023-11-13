#include "s21_string_tests.h"

START_TEST(test_s21_strerror_1) {
    int error_code = 0;
    const char *result_s21 = s21_strerror(error_code);
    const char *result_std = strerror(error_code);

    ck_assert_str_eq(result_s21, result_std);
}

START_TEST(test_s21_strerror_2) {
    int error_code = EINVAL;
    const char *result_s21 = s21_strerror(error_code);
    const char *result_std = strerror(error_code);

    ck_assert_str_eq(result_s21, result_std);
}

START_TEST(test_s21_strerror_3) {
    int error_code = ENOMEM;
    const char *result_s21 = s21_strerror(error_code);
    const char *result_std = strerror(error_code);

    ck_assert_str_eq(result_s21, result_std);
}

START_TEST(test_s21_strerror_4) {
    int error_code = EACCES;
    const char *result_s21 = s21_strerror(error_code);
    const char *result_std = strerror(error_code);

    ck_assert_str_eq(result_s21, result_std);
}

START_TEST(test_s21_strerror_5) {
    int error_code = EIO;
    const char *result_s21 = s21_strerror(error_code);
    const char *result_std = strerror(error_code);

    ck_assert_str_eq(result_s21, result_std);
}

START_TEST(test_s21_strerror_6) {
    int error_code = ENOENT;
    const char *result_s21 = s21_strerror(error_code);
    const char *result_std = strerror(error_code);

    ck_assert_str_eq(result_s21, result_std);
}

START_TEST(test_s21_strerror_7) {
    int error_code = EDOM;
    const char *result_s21 = s21_strerror(error_code);
    const char *result_std = strerror(error_code);

    ck_assert_str_eq(result_s21, result_std);
}

START_TEST(test_s21_strerror_8) {
    int error_code = ERANGE;
    const char *result_s21 = s21_strerror(error_code);
    const char *result_std = strerror(error_code);

    ck_assert_str_eq(result_s21, result_std);
}

Suite *suite_s21_strerror(void) {
    Suite *s = suite_create("suite_strerror");
    TCase *tc = tcase_create("strerror_tc");
    tcase_add_test(tc, test_s21_strerror_1);
    tcase_add_test(tc, test_s21_strerror_2);
    tcase_add_test(tc, test_s21_strerror_3);
    tcase_add_test(tc, test_s21_strerror_4);
    tcase_add_test(tc, test_s21_strerror_5);
    tcase_add_test(tc, test_s21_strerror_6);
    tcase_add_test(tc, test_s21_strerror_7);
    tcase_add_test(tc, test_s21_strerror_8);

    suite_add_tcase(s, tc);
    return s;
}
