#include "s21_string_tests.h"

START_TEST(test_s21_strcspn_1) {
  const char str[] = "Hello, World!";
  const char charset[] = "aeiou";
  s21_size_t result_s21 = s21_strcspn(str, charset);
  s21_size_t result_std = strcspn(str, charset);

  ck_assert_int_eq(result_s21, result_std);
}

START_TEST(test_s21_strcspn_2) {
  const char str[] = "Programming";
  const char charset[] = "aeiou";
  s21_size_t result_s21 = s21_strcspn(str, charset);
  s21_size_t result_std = strcspn(str, charset);

  ck_assert_int_eq(result_s21, result_std);
}

START_TEST(test_s21_strcspn_3) {
  const char str[] = "12345";
  const char charset[] = "aeiou";
  s21_size_t result_s21 = s21_strcspn(str, charset);
  s21_size_t result_std = strcspn(str, charset);

  ck_assert_int_eq(result_s21, result_std);
}

START_TEST(test_s21_strcspn_4) {
  const char str[] = "Test";
  const char charset[] = "aeiou";
  s21_size_t result_s21 = s21_strcspn(str, charset);
  s21_size_t result_std = strcspn(str, charset);

  ck_assert_int_eq(result_s21, result_std);
}

START_TEST(test_s21_strcspn_5) {
  const char str[] = "Empty String";
  const char charset[] = "aeiou";
  s21_size_t result_s21 = s21_strcspn(str, charset);
  s21_size_t result_std = strcspn(str, charset);

  ck_assert_int_eq(result_s21, result_std);
}

START_TEST(test_s21_strcspn_6) {
  const char str[] = "No Vowels Here";
  const char charset[] = "aeiou";
  s21_size_t result_s21 = s21_strcspn(str, charset);
  s21_size_t result_std = strcspn(str, charset);

  ck_assert_int_eq(result_s21, result_std);
}

START_TEST(test_s21_strcspn_7) {
  const char str[] = "Another Test";
  const char charset[] = "xyz";
  s21_size_t result_s21 = s21_strcspn(str, charset);
  s21_size_t result_std = strcspn(str, charset);

  ck_assert_int_eq(result_s21, result_std);
}

START_TEST(test_s21_strcspn_8) {
  const char str[] = "abcde";
  const char charset[] = "";
  s21_size_t result_s21 = s21_strcspn(str, charset);
  s21_size_t result_std = strcspn(str, charset);

  ck_assert_int_eq(result_s21, result_std);
}

Suite *suite_s21_strcspn(void) {
  Suite *s = suite_create("suite_strcspn");
  TCase *tc = tcase_create("strcspn_tc");
  tcase_add_test(tc, test_s21_strcspn_1);
  tcase_add_test(tc, test_s21_strcspn_2);
  tcase_add_test(tc, test_s21_strcspn_3);
  tcase_add_test(tc, test_s21_strcspn_4);
  tcase_add_test(tc, test_s21_strcspn_5);
  tcase_add_test(tc, test_s21_strcspn_6);
  tcase_add_test(tc, test_s21_strcspn_7);
  tcase_add_test(tc, test_s21_strcspn_8);

  suite_add_tcase(s, tc);
  return s;
}
