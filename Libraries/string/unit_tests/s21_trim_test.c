#include "s21_string_tests.h"

START_TEST(test_s21_trim_1) {
    const char str[] = "   Trim Me   ";
    const char trim_chars[] = " ";
    const char expected[] = "Trim Me";

    char *result = s21_trim(str, trim_chars);

    ck_assert_str_eq(result, expected);
    free(result);
}

START_TEST(test_s21_trim_2) {
    const char str[] = "   Leading and Trailing   ";
    const char trim_chars[] = " ";
    const char expected[] = "Leading and Trailing";

    char *result = s21_trim(str, trim_chars);

    ck_assert_str_eq(result, expected);
    free(result);
}

START_TEST(test_s21_trim_3) {
    const char str[] = "12345";
    const char trim_chars[] = " ";
    const char expected[] = "12345";

    char *result = s21_trim(str, trim_chars);

    ck_assert_str_eq(result, expected);
    free(result);
}

START_TEST(test_s21_trim_4) {
    const char str[] = "No Trim Needed";
    const char trim_chars[] = " ";
    const char expected[] = "No Trim Needed";

    char *result = s21_trim(str, trim_chars);

    ck_assert_str_eq(result, expected);
    free(result);
}

START_TEST(test_s21_trim_5) {
    const char str[] = "";
    const char trim_chars[] = " ";
    const char expected[] = "";

    char *result = s21_trim(str, trim_chars);

    ck_assert_str_eq(result, expected);
    free(result);
}

START_TEST(test_s21_trim_6) {
    const char str[] = "NoLeadingTrim";
    const char trim_chars[] = " ";
    const char expected[] = "NoLeadingTrim";

    char *result = s21_trim(str, trim_chars);

    ck_assert_str_eq(result, expected);
    free(result);
}

START_TEST(test_s21_trim_7) {
    const char str[] = "TrailingTrim ";
    const char trim_chars[] = " ";
    const char expected[] = "TrailingTrim";

    char *result = s21_trim(str, trim_chars);

    ck_assert_str_eq(result, expected);
    free(result);
}

START_TEST(test_s21_trim_8) {
    const char str[] = "    ";
    const char trim_chars[] = " ";
    const char expected[] = "";

    char *result = s21_trim(str, trim_chars);

    ck_assert_str_eq(result, expected);
    free(result);
}

START_TEST(test_s21_trim_9) {
    const char str[] = "    Mixed Trim    ";
    const char trim_chars[] = " ";
    const char expected[] = "Mixed Trim";

    char *result = s21_trim(str, trim_chars);

    ck_assert_str_eq(result, expected);
    free(result);
}

START_TEST(test_s21_trim_10) {
    const char str[] = "SpecialChars!@#$";
    const char trim_chars[] = "!@#";
    const char expected[] = "SpecialChars";

    char *result = s21_trim(str, trim_chars);

    ck_assert_str_eq(result, expected);
    free(result);
}

Suite *suite_s21_trim(void) {
    Suite *s = suite_create("suite_trim");
    TCase *tc = tcase_create("trim_tc");
    tcase_add_test(tc, test_s21_trim_1);
    tcase_add_test(tc, test_s21_trim_2);
    tcase_add_test(tc, test_s21_trim_3);
    tcase_add_test(tc, test_s21_trim_4);
    tcase_add_test(tc, test_s21_trim_5);
    tcase_add_test(tc, test_s21_trim_6);
    tcase_add_test(tc, test_s21_trim_7);
    tcase_add_test(tc, test_s21_trim_8);
    tcase_add_test(tc, test_s21_trim_9);
    tcase_add_test(tc, test_s21_trim_10);
    suite_add_tcase(s, tc);
    return s;
}
