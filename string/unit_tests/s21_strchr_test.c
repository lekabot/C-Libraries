#include "s21_string_tests.h"

START_TEST(test_s21_strchr_1) {
  char src[] = "abobasnutsa";
  char find = 'a';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(test_s21_strchr_2) {
  char src[] = "abobasnutAsa";
  char find = 'A';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(test_s21_strchr_3) {
  char src[] = "abobasnutA1sa";
  char find = '1';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(test_s21_strchr_4) {
  char src[] = "abobasnutAsa";
  char find = 'Z';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(test_s21_strchr_5) {
  char src[] = "abobasnutAsa";
  char find = '3';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(test_s21_strchr_6) {
  char src[] = "";
  char find = '3';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

Suite *suite_s21_strchr(void) {
  Suite *s = suite_create("suite_strchr");
  TCase *tc = tcase_create("strchr_tc");
  tcase_add_test(tc, test_s21_strchr_1);
  tcase_add_test(tc, test_s21_strchr_2);
  tcase_add_test(tc, test_s21_strchr_3);
  tcase_add_test(tc, test_s21_strchr_4);
  tcase_add_test(tc, test_s21_strchr_5);
  tcase_add_test(tc, test_s21_strchr_6);

  suite_add_tcase(s, tc);
  return s;
}
