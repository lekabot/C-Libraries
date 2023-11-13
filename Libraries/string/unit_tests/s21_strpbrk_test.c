#include "s21_string_tests.h"

START_TEST(test_s21_strpbrk_1) {
    const char str[] = "Hello, World!";
    const char charset[] = "aeiou";
    char *result_s21 = s21_strpbrk(str, charset);
    char *result_std = strpbrk(str, charset);

    ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test_s21_strpbrk_2) {
    const char str[] = "Programming";
    const char charset[] = "aeiou";
    char *result_s21 = s21_strpbrk(str, charset);
    char *result_std = strpbrk(str, charset);

    ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test_s21_strpbrk_3) {
    const char str[] = "12345";
    const char charset[] = "aeiou";
    char *result_s21 = s21_strpbrk(str, charset);
    char *result_std = strpbrk(str, charset);

    ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test_s21_strpbrk_4) {
    const char str[] = "Test";
    const char charset[] = "aeiou";
    char *result_s21 = s21_strpbrk(str, charset);
    char *result_std = strpbrk(str, charset);

    ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test_s21_strpbrk_5) {
    const char str[] = "Empty String";
    const char charset[] = "aeiou";
    char *result_s21 = s21_strpbrk(str, charset);
    char *result_std = strpbrk(str, charset);

    ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test_s21_strpbrk_6) {
    const char str[] = "No Vowels Here";
    const char charset[] = "aeiou";
    char *result_s21 = s21_strpbrk(str, charset);
    char *result_std = strpbrk(str, charset);

    ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test_s21_strpbrk_7) {
    const char str[] = "Another Test";
    const char charset[] = "xyz";
    char *result_s21 = s21_strpbrk(str, charset);
    char *result_std = strpbrk(str, charset);

    ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test_s21_strpbrk_8) {
    const char str[] = "abcde";
    const char charset[] = "";
    char *result_s21 = s21_strpbrk(str, charset);
    char *result_std = strpbrk(str, charset);

    ck_assert_ptr_eq(result_s21, result_std);
}

Suite *suite_s21_strpbrk(void) {
    Suite *s = suite_create("suite_strpbrk");
    TCase *tc = tcase_create("strpbrk_tc");
    tcase_add_test(tc, test_s21_strpbrk_1);
    tcase_add_test(tc, test_s21_strpbrk_2);
    tcase_add_test(tc, test_s21_strpbrk_3);
    tcase_add_test(tc, test_s21_strpbrk_4);
    tcase_add_test(tc, test_s21_strpbrk_5);
    tcase_add_test(tc, test_s21_strpbrk_6);
    tcase_add_test(tc, test_s21_strpbrk_7);
    tcase_add_test(tc, test_s21_strpbrk_8);

    suite_add_tcase(s, tc);
    return s;
}
