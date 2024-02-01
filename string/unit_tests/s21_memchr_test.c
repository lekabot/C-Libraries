#include "s21_string_tests.h"

START_TEST(test_s21_memchr_1) {
  const char str[] = "Hello, World!";
  int character = 'W';
  size_t n = sizeof(str);

  ck_assert_ptr_eq(s21_memchr(str, character, n), memchr(str, character, n));
}

START_TEST(test_s21_memchr_2) {
  const char str[] = "Hello, World!";
  int character = 'o';
  size_t n = 5;

  ck_assert_ptr_eq(s21_memchr(str, character, n), memchr(str, character, n));
}

START_TEST(test_s21_memchr_3) {
  const char str[] = "Programming";
  int character = 'x';
  size_t n = sizeof(str);

  ck_assert_ptr_eq(s21_memchr(str, character, n), memchr(str, character, n));
}

START_TEST(test_s21_memchr_4) {
  const char str[] = "C programming";
  int character = 'C';
  size_t n = 1;

  ck_assert_ptr_eq(s21_memchr(str, character, n), memchr(str, character, n));
}

START_TEST(test_s21_memchr_5) {
  const char str[] = "Testing s21_memchr function";
  int character = 's';
  size_t n = sizeof(str);

  ck_assert_ptr_eq(s21_memchr(str, character, n), memchr(str, character, n));
}

START_TEST(test_s21_memchr_6) {
  const char str[] = "AbCdEfG";
  int character = 'C';
  size_t n = sizeof(str);

  ck_assert_ptr_eq(s21_memchr(str, character, n), memchr(str, character, n));
}

START_TEST(test_s21_memchr_7) {
  const char str[] = "12345";
  int character = '2';
  size_t n = sizeof(str);

  ck_assert_ptr_eq(s21_memchr(str, character, n), memchr(str, character, n));
}

START_TEST(test_s21_memchr_8) {
  const char str[] = "Special characters: @#$%";
  int character = '$';
  size_t n = sizeof(str);

  ck_assert_ptr_eq(s21_memchr(str, character, n), memchr(str, character, n));
}

START_TEST(test_s21_memchr_9) {
  const char str[] = "";
  int character = 'A';
  size_t n = 0;

  ck_assert_ptr_eq(s21_memchr(str, character, n), memchr(str, character, n));
}

START_TEST(test_s21_memchr_10) {
  const char str[] = "abc";
  int character = '\0';
  size_t n = sizeof(str);

  ck_assert_ptr_eq(s21_memchr(str, character, n), memchr(str, character, n));
}

Suite *suite_s21_memchr(void) {
  Suite *s = suite_create("suite_memchr");
  TCase *tc = tcase_create("memchr_tc");
  tcase_add_test(tc, test_s21_memchr_1);
  tcase_add_test(tc, test_s21_memchr_2);
  tcase_add_test(tc, test_s21_memchr_3);
  tcase_add_test(tc, test_s21_memchr_4);
  tcase_add_test(tc, test_s21_memchr_5);
  tcase_add_test(tc, test_s21_memchr_6);
  tcase_add_test(tc, test_s21_memchr_7);
  tcase_add_test(tc, test_s21_memchr_8);
  tcase_add_test(tc, test_s21_memchr_9);
  tcase_add_test(tc, test_s21_memchr_10);

  suite_add_tcase(s, tc);
  return s;
}