#include "s21_string_tests.h"

START_TEST(test_s21_to_upper_1) {
    char str[] = "hello";
    char expected[] = "HELLO";

    char* res = s21_to_upper(str);

    ck_assert_str_eq(res, expected);
    if (res) {
        free(res);
    }
}

START_TEST(test_s21_to_upper_2) {
    char str[] = "Programming is Fun!";
    char expected[] = "PROGRAMMING IS FUN!";

    char* res = s21_to_upper(str);

    ck_assert_str_eq(res, expected);
    if (res) {
        free(res);
    }
}

START_TEST(test_s21_to_upper_3) {
    char str[] = "12345";
    char expected[] = "12345";

    char* res = s21_to_upper(str);

    ck_assert_str_eq(res, expected);
    if (res) {
        free(res);
    }
}

START_TEST(test_s21_to_upper_4) {
    char str[] = "Test With Spaces";
    char expected[] = "TEST WITH SPACES";

    char* res = s21_to_upper(str);

    ck_assert_str_eq(res, expected);
    if (res) {
        free(res);
    }
}

START_TEST(test_s21_to_upper_5) {
    char str[] = "lowercase";
    char expected[] = "LOWERCASE";

    char* res = s21_to_upper(str);

    ck_assert_str_eq(res, expected);
    if (res) {
        free(res);
    }
}

START_TEST(test_s21_to_upper_6) {
    char str[] = "Mixed Case";
    char expected[] = "MIXED CASE";

    char* res = s21_to_upper(str);

    ck_assert_str_eq(res, expected);
    if (res) {
        free(res);
    }
}

START_TEST(test_s21_to_upper_7) {
    char str[] = "123 abc xyz";
    char expected[] = "123 ABC XYZ";

    char* res = s21_to_upper(str);

    ck_assert_str_eq(res, expected);
    if (res) {
        free(res);
    }
}

START_TEST(test_s21_to_upper_8) {
    char str[] = "Special !@#$ Characters";
    char expected[] = "SPECIAL !@#$ CHARACTERS";

    char* res = s21_to_upper(str);

    ck_assert_str_eq(res, expected);
    if (res) {
        free(res);
    }
}

START_TEST(test_s21_to_upper_9) {
    char str[] = "No change";
    char expected[] = "NO CHANGE";

    char* res = s21_to_upper(str);

    ck_assert_str_eq(res, expected);
    if (res) {
        free(res);
    }
}

START_TEST(test_s21_to_upper_10) {
    char str[] = "";
    char expected[] = "";

    char* res = s21_to_upper(str);

    ck_assert_str_eq(res, expected);
    if (res) {
        free(res);
    }
}

Suite *suite_s21_to_upper(void) {
    Suite *s = suite_create("suite_to_upper");
    TCase *tc = tcase_create("to_upper_tc");
    tcase_add_test(tc, test_s21_to_upper_1);
    tcase_add_test(tc, test_s21_to_upper_2);
    tcase_add_test(tc, test_s21_to_upper_3);
    tcase_add_test(tc, test_s21_to_upper_4);
    tcase_add_test(tc, test_s21_to_upper_5);
    tcase_add_test(tc, test_s21_to_upper_6);
    tcase_add_test(tc, test_s21_to_upper_7);
    tcase_add_test(tc, test_s21_to_upper_8);
    tcase_add_test(tc, test_s21_to_upper_9);
    tcase_add_test(tc, test_s21_to_upper_10);
    suite_add_tcase(s, tc);
    return s;
}