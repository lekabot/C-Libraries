#include "s21_string_tests.h"

START_TEST(test_s21_strstr_1) {
  const char str[] = "Hello, World!";
  const char substr[] = "World";
  char *result_s21 = s21_strstr(str, substr);
  char *result_std = strstr(str, substr);

  ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test_s21_strstr_2) {
  const char str[] = "Programming is fun!";
  const char substr[] = "is";
  char *result_s21 = s21_strstr(str, substr);
  char *result_std = strstr(str, substr);

  ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test_s21_strstr_3) {
  const char str[] = "12345";
  const char substr[] = "345";
  char *result_s21 = s21_strstr(str, substr);
  char *result_std = strstr(str, substr);

  ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test_s21_strstr_4) {
  const char str[] = "Test";
  const char substr[] = "Testing";
  char *result_s21 = s21_strstr(str, substr);
  char *result_std = strstr(str, substr);

  ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test_s21_strstr_5) {
  const char str[] = "Empty String";
  const char substr[] = "";
  char *result_s21 = s21_strstr(str, substr);
  char *result_std = strstr(str, substr);

  ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test_s21_strstr_6) {
  const char str[] = "No Occurrence";
  const char substr[] = "X";
  char *result_s21 = s21_strstr(str, substr);
  char *result_std = strstr(str, substr);

  ck_assert_ptr_eq(result_s21, result_std);
}

START_TEST(test_s21_strstr_7) {
  const char str[] = "Test Null \0 Character";
  const char substr[] = "\0";
  char *result_s21 = s21_strstr(str, substr);
  char *result_std = strstr(str, substr);

  ck_assert_ptr_eq(result_s21, result_std);
}

Suite *suite_s21_strstr(void) {
  Suite *s = suite_create("suite_strstr");
  TCase *tc = tcase_create("strstr_tc");
  tcase_add_test(tc, test_s21_strstr_1);
  tcase_add_test(tc, test_s21_strstr_2);
  tcase_add_test(tc, test_s21_strstr_3);
  tcase_add_test(tc, test_s21_strstr_4);
  tcase_add_test(tc, test_s21_strstr_5);
  tcase_add_test(tc, test_s21_strstr_6);
  tcase_add_test(tc, test_s21_strstr_7);

  suite_add_tcase(s, tc);
  return s;
}
