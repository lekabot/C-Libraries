#include "s21_string_tests.h"

START_TEST(test_s21_sprintf_1) {
    char buffer[50];
    int result_s21 = s21_sprintf(buffer, "Hello, %s!", "World");
    int result_std = sprintf(buffer, "Hello, %s!", "World");

    ck_assert_int_eq(result_s21, result_std);
    ck_assert_str_eq(buffer, "Hello, World!");
}

START_TEST(test_s21_sprintf_2) {
    char buffer[50];
    int result_s21 = s21_sprintf(buffer, "Value: %d", 42);
    int result_std = sprintf(buffer, "Value: %d", 42);

    ck_assert_int_eq(result_s21, result_std);
    ck_assert_str_eq(buffer, "Value: 42");
}

START_TEST(test_s21_sprintf_3) {
    char buffer[50];
    int result_s21 = s21_sprintf(buffer, "Floating point: %.2f", 3.14159);
    int result_std = sprintf(buffer, "Floating point: %.2f", 3.14159);

    ck_assert_int_eq(result_s21, result_std);
    ck_assert_str_eq(buffer, "Floating point: 3.14");
}

START_TEST(test_s21_sprintf_4) {
    char buffer[50];
    int result_s21 = s21_sprintf(buffer, "%c is a character", 'A');
    int result_std = sprintf(buffer, "%c is a character", 'A');

    ck_assert_int_eq(result_s21, result_std);
    ck_assert_str_eq(buffer, "A is a character");
}

START_TEST(test_s21_sprintf_5) {
    char buffer[50];
    int result_s21 = s21_sprintf(buffer, "Empty string: %s", "");
    int result_std = sprintf(buffer, "Empty string: %s", "");

    ck_assert_int_eq(result_s21, result_std);
    ck_assert_str_eq(buffer, "Empty string: ");
}

START_TEST(test_s21_sprintf_6) {
    char buffer[50];
    int result_s21 = s21_sprintf(buffer, "Hexadecimal: %x", 255);
    int result_std = sprintf(buffer, "Hexadecimal: %x", 255);

    ck_assert_int_eq(result_s21, result_std);
    ck_assert_str_eq(buffer, "Hexadecimal: ff");
}

START_TEST(test_s21_sprintf_7) {
    char buffer[50];
    int result_s21 = s21_sprintf(buffer, "Scientific notation: %e", 12345.6789);
    int result_std = sprintf(buffer, "Scientific notation: %e", 12345.6789);

    ck_assert_int_eq(result_s21, result_std);
    ck_assert_str_eq(buffer, "Scientific notation: 1.234568e+04");
}

START_TEST(test_s21_sprintf_8) {
    char buffer[50];
    int result_s21 = s21_sprintf(buffer, "Empty format: %s", "Hello");
    int result_std = sprintf(buffer, "Empty format: %s", "Hello");

    ck_assert_int_eq(result_s21, result_std);
    ck_assert_str_eq(buffer, "Empty format: Hello");
}

START_TEST(test_s21_sprintf_9) {
    char buffer[50];
    void *arg = NULL;
    
    int result_s21 = s21_sprintf(buffer, "Invalid format: %d %s", 42, (arg ? "not null" : "(null)"));
    int result_std = sprintf(buffer, "Invalid format: %d %s", 42, (arg ? "not null" : "(null)"));

    ck_assert_int_eq(result_s21, result_std);
    ck_assert_str_eq(buffer, "Invalid format: 42 (null)");
}

START_TEST(test_s21_sprintf_10) {
    char buffer[50];
    int result_s21 = s21_sprintf(buffer, "Multiple arguments: %d %s %c", 42, "Hello", 'A');
    int result_std = sprintf(buffer, "Multiple arguments: %d %s %c", 42, "Hello", 'A');

    ck_assert_int_eq(result_s21, result_std);
    ck_assert_str_eq(buffer, "Multiple arguments: 42 Hello A");
}

Suite *suite_s21_sprintf(void) {
    Suite *s = suite_create("suite_sprintf");
    TCase *tc = tcase_create("sprintf_tc");
    tcase_add_test(tc, test_s21_sprintf_1);
    tcase_add_test(tc, test_s21_sprintf_2);
    tcase_add_test(tc, test_s21_sprintf_3);
    tcase_add_test(tc, test_s21_sprintf_4);
    tcase_add_test(tc, test_s21_sprintf_5);
    tcase_add_test(tc, test_s21_sprintf_6);
    tcase_add_test(tc, test_s21_sprintf_7);
    tcase_add_test(tc, test_s21_sprintf_8);
    tcase_add_test(tc, test_s21_sprintf_9);
    tcase_add_test(tc, test_s21_sprintf_10);

    suite_add_tcase(s, tc);
    return s;
}
