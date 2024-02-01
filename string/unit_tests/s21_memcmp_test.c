#include "s21_string_tests.h"

START_TEST(test_s21_memcmp_1) {
  const char str1[] = "Hello, World!";
  const char str2[] = "Hello, World!";
  size_t n = sizeof(str1);

  int result_s21 = s21_memcmp(str1, str2, n);
  int result_mem = memcmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_mem);
}

START_TEST(test_s21_memcmp_2) {
  const char str1[] = "Programming";
  const char str2[] = "Programming";
  size_t n = sizeof(str1);

  int result_s21 = s21_memcmp(str1, str2, n);
  int result_mem = memcmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_mem);
}

START_TEST(test_s21_memcmp_3) {
  const char str1[] = "12345";
  const char str2[] = "54321";
  size_t n = sizeof(str1);

  int result_s21 = s21_memcmp(str1, str2, n);
  int result_mem = memcmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_mem);
}

START_TEST(test_s21_memcmp_4) {
  const char str1[] = "C programming";
  const char str2[] = "C programming language";
  size_t n = sizeof(str1);

  int result_s21 = s21_memcmp(str1, str2, n);
  int result_mem = memcmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_mem);
}

START_TEST(test_s21_memcmp_5) {
  const char str1[] = "abcdef";
  const char str2[] = "ABCDEF";
  size_t n = sizeof(str1);

  int result_s21 = s21_memcmp(str1, str2, n);
  int result_mem = memcmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_mem);
}

START_TEST(test_s21_memcmp_6) {
  const char str1[] = "Hello";
  const char str2[] = "Hella";
  size_t n = sizeof(str1);

  int result_s21 = s21_memcmp(str1, str2, n);
  int result_mem = memcmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_mem);
}

START_TEST(test_s21_memcmp_7) {
  const char str1[] = "";
  const char str2[] = "Hello";
  size_t n = 0;

  int result_s21 = s21_memcmp(str1, str2, n);
  int result_mem = memcmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_mem);
}

START_TEST(test_s21_memcmp_8) {
  const char str1[] = "Hello, World!";
  const char str2[] = "Hello, World";
  size_t n = sizeof(str1) - 1;  // Exclude the null terminator in str2

  int result_s21 = s21_memcmp(str1, str2, n);
  int result_mem = memcmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_mem);
}

START_TEST(test_s21_memcmp_9) {
  const char str1[] = "Same";
  const char str2[] = "Same";
  size_t n = sizeof(str1);

  int result_s21 = s21_memcmp(str1, str2, n);
  int result_mem = memcmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_mem);
}

START_TEST(test_s21_memcmp_10) {
  const char str1[] = "Different";
  const char str2[] = "D1fferent";
  size_t n = sizeof(str1);

  int result_s21 = s21_memcmp(str1, str2, n);
  int result_mem = memcmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_mem);
}

Suite *suite_s21_memcmp(void) {
  Suite *s = suite_create("suite_memcmp");
  TCase *tc = tcase_create("memcmp_tc");
  tcase_add_test(tc, test_s21_memcmp_1);
  tcase_add_test(tc, test_s21_memcmp_2);
  tcase_add_test(tc, test_s21_memcmp_3);
  tcase_add_test(tc, test_s21_memcmp_4);
  tcase_add_test(tc, test_s21_memcmp_5);
  tcase_add_test(tc, test_s21_memcmp_6);
  tcase_add_test(tc, test_s21_memcmp_7);
  tcase_add_test(tc, test_s21_memcmp_8);
  tcase_add_test(tc, test_s21_memcmp_9);
  tcase_add_test(tc, test_s21_memcmp_10);

  suite_add_tcase(s, tc);
  return s;
}