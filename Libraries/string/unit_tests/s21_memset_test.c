#include "s21_string_tests.h"

START_TEST(test_s21_memset_1) {
    char dest[] = "Hello, World!";
    char expected[] = "Hello, World!";

    s21_memset(dest, 'A', sizeof(dest));
    memset(expected, 'A', sizeof(expected));

    ck_assert_str_eq(dest, expected);
}

START_TEST(test_s21_memset_2) {
    char dest[] = "ABCDE";
    char expected[] = "ABCDE";

    s21_memset(dest, 'A', 5);
    memset(expected, 'A', 5);

    ck_assert_str_eq(dest, expected);
}

START_TEST(test_s21_memset_3) {
    char dest[10] = "abcdefghij";
    char expected[10] = "abcdefghij";

    s21_memset(dest, 'C', sizeof(dest));
    memset(expected, 'C', sizeof(dest));

    ck_assert_str_eq(dest, expected);
}

START_TEST(test_s21_memset_4) {
    char dest[] = "12345";
    char expected[] = "12345";
    s21_size_t size = 0;

    s21_memset(dest, 'C', size);
    memset(expected, 'C', size);

    ck_assert_str_eq(dest, expected);
}

START_TEST(test_s21_memset_5) {
    char res[] = "aboba";
    char expected[] = "aboba";
    char replace = 'g';
    s21_size_t n_byte = 5;

    s21_memset(res, replace, n_byte);
    memset(expected, replace, n_byte);

    ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(test_s21_memset_6) {
    char res[] = "aboba";
    char expected[] = "aboba";
    char replace = 'g';
    s21_size_t n_byte = 0;

    s21_memset(res, replace, n_byte);
    memset(expected, replace, n_byte);

    ck_assert_str_eq(res, expected);
}
END_TEST
START_TEST(test_s21_memset_7) {
    char res[] = "";
    char expected[] = "";
    char replace = '\0';
    s21_size_t n_byte = 0;

    s21_memset(res, replace, n_byte);
    memset(expected, replace, n_byte);

    ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(test_s21_memset_8) {
    char res[] = "aboba";
    char expected[] = "aboba";
    char replace = 'A';
    s21_size_t n_byte = 3;

    s21_memset(res, replace, n_byte);
    memset(expected, replace, n_byte);

    ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(test_s21_memset_9) {
    char res[] = "a1obA";
    char expected[] = "a1obA";
    char replace = '1';
    s21_size_t n_byte = 5;

    s21_memset(res, replace, n_byte);
    memset(expected, replace, n_byte);

    ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(test_s21_memset_10) {
    char res[] = "a1oas[pifjaosidfj oapisjdfpoi asjdfoij ouh12oi3 uh12i3 hiajhIOUAHSDiouAHSdu1).bA";
    char expected[] = "a1oas[pifjaosidfj oapisjdfpoi asjdfoij ouh12oi3 uh12i3 hiajhIOUAHSDiouAHSdu1).bA";
    char replace = '1';
    s21_size_t n_byte = 5;

    s21_memset(res, replace, n_byte);
    memset(expected, replace, n_byte);

    ck_assert_str_eq(res, expected);
}
END_TEST

Suite *suite_s21_memset(void) {
    Suite *s = suite_create("suite_memset");
    TCase *tc = tcase_create("memset_tc");
    tcase_add_test(tc, test_s21_memset_1);
    tcase_add_test(tc, test_s21_memset_2);
    tcase_add_test(tc, test_s21_memset_3);
    tcase_add_test(tc, test_s21_memset_4);
    tcase_add_test(tc, test_s21_memset_5);
    tcase_add_test(tc, test_s21_memset_6);
    tcase_add_test(tc, test_s21_memset_7);
    tcase_add_test(tc, test_s21_memset_8);
    tcase_add_test(tc, test_s21_memset_9);
    tcase_add_test(tc, test_s21_memset_10);

    suite_add_tcase(s, tc);
    return s;
}