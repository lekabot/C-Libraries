#include "s21_string_tests.h"

START_TEST(test_s21_strlen_1) {
  const char str[] = "Hello, World!";
  s21_size_t result_s21 = s21_strlen(str);
  s21_size_t result_std = strlen(str);

  ck_assert_int_eq(result_s21, result_std);
}

START_TEST(test_s21_strlen_2) {
  const char str[] = "Programming";
  s21_size_t result_s21 = s21_strlen(str);
  s21_size_t result_std = strlen(str);

  ck_assert_int_eq(result_s21, result_std);
}

START_TEST(test_s21_strlen_3) {
  const char str[] = "12345";
  s21_size_t result_s21 = s21_strlen(str);
  s21_size_t result_std = strlen(str);

  ck_assert_int_eq(result_s21, result_std);
}

START_TEST(test_s21_strlen_4) {
  const char str[] = "Test";
  s21_size_t result_s21 = s21_strlen(str);
  s21_size_t result_std = strlen(str);

  ck_assert_int_eq(result_s21, result_std);
}

START_TEST(test_s21_strlen_5) {
  const char str[] = "Empty String";
  s21_size_t result_s21 = s21_strlen(str);
  s21_size_t result_std = strlen(str);

  ck_assert_int_eq(result_s21, result_std);
}

START_TEST(test_s21_strlen_6) {
  const char str[] = "";
  s21_size_t result_s21 = s21_strlen(str);
  s21_size_t result_std = strlen(str);

  ck_assert_int_eq(result_s21, result_std);
}

Suite *suite_s21_strlen(void) {
  Suite *s = suite_create("suite_strlen");
  TCase *tc = tcase_create("strlen_tc");
  tcase_add_test(tc, test_s21_strlen_1);
  tcase_add_test(tc, test_s21_strlen_2);
  tcase_add_test(tc, test_s21_strlen_3);
  tcase_add_test(tc, test_s21_strlen_4);
  tcase_add_test(tc, test_s21_strlen_5);
  tcase_add_test(tc, test_s21_strlen_6);

  suite_add_tcase(s, tc);
  return s;
}
