#include "s21_string_tests.h"

START_TEST(test_s21_strrchr_1) {
  const char str[] = "Hello, World!";
  int ch = 'o';

  ck_assert_pstr_eq(s21_strrchr(str, ch), strrchr(str, ch));
}

START_TEST(test_s21_strrchr_2) {
  const char str[] = "Programming";
  int ch = 'g';
  ck_assert_pstr_eq(s21_strrchr(str, ch), strrchr(str, ch));
}

START_TEST(test_s21_strrchr_3) {
  const char str[] = "12345";
  int ch = '5';
  ck_assert_pstr_eq(s21_strrchr(str, ch), strrchr(str, ch));
}

START_TEST(test_s21_strrchr_4) {
  const char str[] = "Test";
  int ch = 't';
  ck_assert_pstr_eq(s21_strrchr(str, ch), strrchr(str, ch));
}

START_TEST(test_s21_strrchr_5) {
  const char str[] = "Empty String";
  int ch = 'z';
  ck_assert_pstr_eq(s21_strrchr(str, ch), strrchr(str, ch));
}

START_TEST(test_s21_strrchr_6) {
  const char str[] = "No Occurrence";
  int ch = 'X';
  ck_assert_pstr_eq(s21_strrchr(str, ch), strrchr(str, ch));
}

START_TEST(test_s21_strrchr_7) {
  const char str[] = "Test Null \0 Character";
  int ch = '\0';
  ck_assert_pstr_eq(s21_strrchr(str, ch), strrchr(str, ch));
}

Suite *suite_s21_strrchr(void) {
  Suite *s = suite_create("suite_strrchr");
  TCase *tc = tcase_create("strrchr_tc");
  tcase_add_test(tc, test_s21_strrchr_1);
  tcase_add_test(tc, test_s21_strrchr_2);
  tcase_add_test(tc, test_s21_strrchr_3);
  tcase_add_test(tc, test_s21_strrchr_4);
  tcase_add_test(tc, test_s21_strrchr_5);
  tcase_add_test(tc, test_s21_strrchr_6);
  tcase_add_test(tc, test_s21_strrchr_7);

  suite_add_tcase(s, tc);
  return s;
}
