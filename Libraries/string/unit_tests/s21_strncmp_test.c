#include "s21_string_tests.h"

START_TEST(test_s21_strncmp_1) {
  const char str1[] = "Hello, World!";
  const char str2[] = "Hello, Everyone!";
  s21_size_t n = 6;
  int result_s21 = s21_strncmp(str1, str2, n);
  int result_std = strncmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_std);
}

START_TEST(test_s21_strncmp_2) {
  const char str1[] = "Programming";
  const char str2[] = "Program";
  s21_size_t n = 7;
  int result_s21 = s21_strncmp(str1, str2, n);
  int result_std = strncmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_std);
}

START_TEST(test_s21_strncmp_3) {
  const char str1[] = "12345";
  const char str2[] = "123";
  s21_size_t n = 3;
  int result_s21 = s21_strncmp(str1, str2, n);
  int result_std = strncmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_std);
}

START_TEST(test_s21_strncmp_4) {
  const char str1[] = "Test";
  const char str2[] = "Testing";
  s21_size_t n = 4;
  int result_s21 = s21_strncmp(str1, str2, n);
  int result_std = strncmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_std);
}

START_TEST(test_s21_strncmp_5) {
  const char str1[] = "Equal";
  const char str2[] = "Equal";
  s21_size_t n = 5;
  int result_s21 = s21_strncmp(str1, str2, n);
  int result_std = strncmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_std);
}

START_TEST(test_s21_strncmp_6) {
  const char str1[] = "abcdef";
  const char str2[] = "abcXYZ";
  s21_size_t n = 3;
  int result_s21 = s21_strncmp(str1, str2, n);
  int result_std = strncmp(str1, str2, n);

  ck_assert_int_eq(result_s21, result_std);
}

Suite *suite_s21_strncmp(void) {
  Suite *s = suite_create("suite_strncmp");
  TCase *tc = tcase_create("strncmp_tc");
  tcase_add_test(tc, test_s21_strncmp_1);
  tcase_add_test(tc, test_s21_strncmp_2);
  tcase_add_test(tc, test_s21_strncmp_3);
  tcase_add_test(tc, test_s21_strncmp_4);
  tcase_add_test(tc, test_s21_strncmp_5);
  tcase_add_test(tc, test_s21_strncmp_6);

  suite_add_tcase(s, tc);
  return s;
}
