#include "s21_string_tests.h"

START_TEST(test_s21_to_lower_1) {
    char str[] = "HELLO";
    char expected[] = "hello";

    s21_to_lower(str);

    ck_assert_str_eq(str, expected);
}

START_TEST(test_s21_to_lower_2) {
    char str[] = "Programming is FUN!";
    char expected[] = "programming is fun!";

    s21_to_lower(str);

    ck_assert_str_eq(str, expected);
}

START_TEST(test_s21_to_lower_3) {
    char str[] = "12345";
    char expected[] = "12345";

    s21_to_lower(str);

    ck_assert_str_eq(str, expected);
}

START_TEST(test_s21_to_lower_4) {
    char str[] = "Test With Spaces";
    char expected[] = "test with spaces";

    s21_to_lower(str);

    ck_assert_str_eq(str, expected);
}

START_TEST(test_s21_to_lower_5) {
    char str[] = "UPPERCASE";
    char expected[] = "uppercase";

    s21_to_lower(str);

    ck_assert_str_eq(str, expected);
}

START_TEST(test_s21_to_lower_6) {
    char str[] = "MiXeD CaSe";
    char expected[] = "mixed case";

    s21_to_lower(str);

    ck_assert_str_eq(str, expected);
}

START_TEST(test_s21_to_lower_7) {
    char str[] = "123 Abc XYZ";
    char expected[] = "123 abc xyz";

    s21_to_lower(str);

    ck_assert_str_eq(str, expected);
}

START_TEST(test_s21_to_lower_8) {
    char str[] = "Special !@#$ Characters";
    char expected[] = "special !@#$ characters";

    s21_to_lower(str);

    ck_assert_str_eq(str, expected);
}

START_TEST(test_s21_to_lower_9) {
    char str[] = "No change";
    char expected[] = "no change";

    s21_to_lower(str);

    ck_assert_str_eq(str, expected);
}

START_TEST(test_s21_to_lower_10) {
    char str[] = "";
    char expected[] = "";

    s21_to_lower(str);

    ck_assert_str_eq(str, expected);
}

Suite *suite_s21_to_lower(void) {
    Suite *s = suite_create("suite_to_lower");
    TCase *tc = tcase_create("to_lower_tc");
    tcase_add_test(tc, test_s21_to_lower_1);
    tcase_add_test(tc, test_s21_to_lower_2);
    tcase_add_test(tc, test_s21_to_lower_3);
    tcase_add_test(tc, test_s21_to_lower_4);
    tcase_add_test(tc, test_s21_to_lower_5);
    tcase_add_test(tc, test_s21_to_lower_6);
    tcase_add_test(tc, test_s21_to_lower_7);
    tcase_add_test(tc, test_s21_to_lower_8);
    tcase_add_test(tc, test_s21_to_lower_9);
    tcase_add_test(tc, test_s21_to_lower_10);
    suite_add_tcase(s, tc);
    return s;
}
