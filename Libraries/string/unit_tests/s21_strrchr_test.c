#include "s21_string_tests.h"

START_TEST(test_s21_strrchr_1) {
    const char str[] = "Hello, World!";
    int ch = 'o';
    char *result_s21 = s21_strrchr(str, ch);
    char *result_std = strrchr(str, ch);

    ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test_s21_strrchr_2) {
    const char str[] = "Programming";
    int ch = 'g';
    char *result_s21 = s21_strrchr(str, ch);
    char *result_std = strrchr(str, ch);

    ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test_s21_strrchr_3) {
    const char str[] = "12345";
    int ch = '5';
    char *result_s21 = s21_strrchr(str, ch);
    char *result_std = strrchr(str, ch);

    ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test_s21_strrchr_4) {
    const char str[] = "Test";
    int ch = 't';
    char *result_s21 = s21_strrchr(str, ch);
    char *result_std = strrchr(str, ch);

    ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test_s21_strrchr_5) {
    const char str[] = "Empty String";
    int ch = 'z';
    char *result_s21 = s21_strrchr(str, ch);
    char *result_std = strrchr(str, ch);

    ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test_s21_strrchr_6) {
    const char str[] = "No Occurrence";
    int ch = 'X';
    char *result_s21 = s21_strrchr(str, ch);
    char *result_std = strrchr(str, ch);

    ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test_s21_strrchr_7) {
    const char str[] = "Test Null \0 Character";
    int ch = '\0';
    char *result_s21 = s21_strrchr(str, ch);
    char *result_std = strrchr(str, ch);

    ck_assert_ptr_eq(result_s21, result_std);
}

Suite *suite_s21_strrchr(void) {
    Suite *s = suite_create("suite_strrchr");
    TCase *tc = tcase_create("strrchr_tc");
    tcase_add_test(tc, test_s21_strrchr_1);
    tcase_add_test(tc, test_s21_strrchr_2);
    tcase_add_test(tc, test_s21_strrchr_3);
    tcase_add_test(tc, test_s21_strrchr_4);
    tcase_add_test(tc, test_s21_strrchr_5);
    tcase_add_test(tc, test_s21_strrchr_6);
    tcase_add_test(tc, test_s21_strrchr_7);

    suite_add_tcase(s, tc);
    return s;
}
