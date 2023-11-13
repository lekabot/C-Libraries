#include "s21_string_tests.h"

START_TEST(test_s21_strchr_1) {
    const char str[] = "Hello, World!";
    char *result_s21 = s21_strchr(str, 'o');
    char *result_std = strchr(str, 'o');

    ck_assert_ptr_eq(result_s21, result_std);
    ck_assert_int_eq(result_s21 - str, result_std - str);
}

START_TEST(test_s21_strchr_2) {
    const char str[] = "Programming";
    char *result_s21 = s21_strchr(str, 'a');
    char *result_std = strchr(str, 'a');

    ck_assert_ptr_eq(result_s21, result_std);
    ck_assert_int_eq(result_s21 - str, result_std - str);
}

START_TEST(test_s21_strchr_3) {
    const char str[] = "12345";
    char *result_s21 = s21_strchr(str, '6');
    char *result_std = strchr(str, '6');

    ck_assert_ptr_eq(result_s21, result_std);
    ck_assert_int_eq(result_s21 - str, result_std - str);
}

START_TEST(test_s21_strchr_4) {
    const char str[] = "Test";
    char *result_s21 = s21_strchr(str, 't');
    char *result_std = strchr(str, 't');

    ck_assert_ptr_eq(result_s21, result_std);
    ck_assert_int_eq(result_s21 - str, result_std - str);
}

START_TEST(test_s21_strchr_5) {
    const char str[] = "Empty String";
    char *result_s21 = s21_strchr(str, '\0');
    char *result_std = strchr(str, '\0');

    ck_assert_ptr_eq(result_s21, result_std);
    ck_assert_int_eq(result_s21 - str, result_std - str);
}

START_TEST(test_s21_strchr_6) {
    const char str[] = "No Match";
    char *result_s21 = s21_strchr(str, 'z');
    char *result_std = strchr(str, 'z');

    ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test_s21_strchr_7) {
    const char str[] = "Another Test";
    char *result_s21 = s21_strchr(str, 'T');
    char *result_std = strchr(str, 'T');

    ck_assert_ptr_eq(result_s21, result_std);
    ck_assert_int_eq(result_s21 - str, result_std - str);
}

START_TEST(test_s21_strchr_8) {
    const char str[] = "abcde";
    char *result_s21 = s21_strchr(str, '\0');
    char *result_std = strchr(str, '\0');

    ck_assert_ptr_eq(result_s21, result_std);
    ck_assert_int_eq(result_s21 - str, result_std - str);
}

Suite *suite_s21_strchr(void) {
    Suite *s = suite_create("suite_strchr");
    TCase *tc = tcase_create("strchr_tc");
    tcase_add_test(tc, test_s21_strchr_1);
    tcase_add_test(tc, test_s21_strchr_2);
    tcase_add_test(tc, test_s21_strchr_3);
    tcase_add_test(tc, test_s21_strchr_4);
    tcase_add_test(tc, test_s21_strchr_5);
    tcase_add_test(tc, test_s21_strchr_6);
    tcase_add_test(tc, test_s21_strchr_7);
    tcase_add_test(tc, test_s21_strchr_8);

    suite_add_tcase(s, tc);
    return s;
}
