#include "s21_string_tests.h"

START_TEST(test_s21_insert_1) {
    const char* src = "I send hello world to everyone";
    const char* str = "can ";
    s21_size_t a = 2;
    const char *expected = "I can send hello world to everyone";
    char* answer = (char*)s21_insert(src, str, a);
    ck_assert_str_eq(answer, expected);
}

START_TEST(test_s21_insert_2) {
    const char* src = "This is a test";
    const char* str = "only ";
    s21_size_t a = 5;
    const char* expected = "This only is a test";
    char* answer = (char*)s21_insert(src, str, a);
    ck_assert_str_eq(answer, expected);
}

START_TEST(test_s21_insert_3) {
    const char* src = "The quick brown fox";
    const char* str = "lazy ";
    s21_size_t a = 16;
    const char* expected = "The quick brown lazy fox";
    char* answer = (char*)s21_insert(src, str, a);
    ck_assert_str_eq(answer, expected);
}

START_TEST(test_s21_insert_4) {
    const char* src = "Programming languages";
    const char* str = "are ";
    s21_size_t a = 12;
    const char* expected = "Programming are languages";
    char* answer = (char*)s21_insert(src, str, a);
    ck_assert_str_eq(answer, expected);
}

START_TEST(test_s21_insert_5) {
    const char* src = "C is a powerful";
    const char* str = "very ";
    s21_size_t a = 7;
    const char* expected = "C is a very powerful";
    char* answer = (char*)s21_insert(src, str, a);
    ck_assert_str_eq(answer, expected);
}

START_TEST(test_s21_insert_6) {
    const char* src = "1, 2, 3";
    const char* str = "and ";
    s21_size_t a = 1;
    const char* expected = "1and , 2, 3";
    char* answer = (char*)s21_insert(src, str, a);
    ck_assert_str_eq(answer, expected);
}

START_TEST(test_s21_insert_7) {
    const char* src = "Counting backwards";
    const char* str = "down ";
    s21_size_t a = 9;
    const char* expected = "Counting down backwards";
    char* answer = (char*)s21_insert(src, str, a);
    ck_assert_str_eq(answer, expected);
}

START_TEST(test_s21_insert_8) {
    const char* src = "The answer is";
    const char* str = " 42";
    s21_size_t a = 13;
    const char* expected = "The answer is 42";
    char* answer = (char*)s21_insert(src, str, a);
    ck_assert_str_eq(answer, expected);
}

START_TEST(test_s21_insert_9) {
    const char* src = "Hello, World!";
    const char* str = " Goodbye,";
    s21_size_t a = 6;
    const char* expected = "Hello, Goodbye, World!";
    char* answer = (char*)s21_insert(src, str, a);
    ck_assert_str_eq(answer, expected);
}

START_TEST(test_s21_insert_10) {
    const char* src = "To be or not to be";
    const char* str = "that is ";
    s21_size_t a = 13;
    const char* expected = "To be or not that is to be";
    char* answer = (char*)s21_insert(src, str, a);
    ck_assert_str_eq(answer, expected);
}

Suite *suite_s21_insert(void) {
    Suite *s = suite_create("suite_insert");
    TCase *tc = tcase_create("insert_tc");
    tcase_add_test(tc, test_s21_insert_1);
    tcase_add_test(tc, test_s21_insert_2);
    tcase_add_test(tc, test_s21_insert_3);
    tcase_add_test(tc, test_s21_insert_4);
    tcase_add_test(tc, test_s21_insert_5);
    tcase_add_test(tc, test_s21_insert_6);
    tcase_add_test(tc, test_s21_insert_7);
    tcase_add_test(tc, test_s21_insert_8);
    tcase_add_test(tc, test_s21_insert_9);
    tcase_add_test(tc, test_s21_insert_10);

    suite_add_tcase(s, tc);
    return s;
}