#include "s21_string_tests.h"

START_TEST(test_s21_strtok_1) {
    char str[] = "This is a test";
    const char delim[] = " ";
    const char *result_s21 = s21_strtok(str, delim);
    const char *result_std = strtok(str, delim);

    ck_assert_str_eq(result_s21, result_std);
}

START_TEST(test_s21_strtok_2) {
    char str[] = "Programming,is,fun!";
    const char delim[] = ",";
    const char *result_s21 = s21_strtok(str, delim);
    const char *result_std = strtok(str, delim);

    ck_assert_str_eq(result_s21, result_std);
}

START_TEST(test_s21_strtok_3) {
    char str[] = "123-456-789";
    const char delim[] = "-";
    const char *result_s21 = s21_strtok(str, delim);
    const char *result_std = strtok(str, delim);

    ck_assert_str_eq(result_s21, result_std);
}

START_TEST(test_s21_strtok_4) {
    char str[] = "Test";
    const char delim[] = " ";
    const char *result_s21 = s21_strtok(str, delim);
    const char *result_std = strtok(str, delim);

    ck_assert_str_eq(result_s21, result_std);
}

START_TEST(test_s21_strtok_5) {
    char str[] = "Empty String";
    const char delim[] = "";
    const char *result_s21 = s21_strtok(str, delim);
    const char *result_std = strtok(str, delim);

    ck_assert_str_eq(result_s21, result_std);
}

START_TEST(test_s21_strtok_6) {
    char str[] = "No Delimiter Here";
    const char delim[] = ",";
    const char *result_s21 = s21_strtok(str, delim);
    const char *result_std = strtok(str, delim);

    ck_assert_str_eq(result_s21, result_std);
}

Suite *suite_s21_strtok(void) {
    Suite *s = suite_create("suite_strtok");
    TCase *tc = tcase_create("strtok_tc");
    tcase_add_test(tc, test_s21_strtok_1);
    tcase_add_test(tc, test_s21_strtok_2);
    tcase_add_test(tc, test_s21_strtok_3);
    tcase_add_test(tc, test_s21_strtok_4);
    tcase_add_test(tc, test_s21_strtok_5);
    tcase_add_test(tc, test_s21_strtok_6);

    suite_add_tcase(s, tc);
    return s;
}
