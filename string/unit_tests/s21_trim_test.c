#include "s21_string_tests.h"

START_TEST(test_s21_trim_1) {
  char str[] = "";
  char trim_ch[] = "";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) {
    free(got);
  }
}
END_TEST

START_TEST(test_s21_trim_2) {
  char str[] = "";
  char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) {
    free(got);
  }
}
END_TEST

START_TEST(test_s21_trim_3) {
  char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char trim_ch[] = "";
  char expected[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) {
    free(got);
  }
}
END_TEST

START_TEST(test_s21_trim_4) {
  char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) {
    free(got);
  }
}
END_TEST

START_TEST(test_s21_trim_5) {
  char str[] = "+!!++Abo+ba++00";
  char trim_ch[] = "+!0-";
  char expected[] = "Abo+ba";
  char *got = (char *)s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) {
    free(got);
  }
}
END_TEST

START_TEST(test_s21_trim_6) {
  char str[] = "Ab000cd0";
  char trim_ch[] = "003";
  char expected[] = "Ab000cd";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) {
    free(got);
  }
}
END_TEST

START_TEST(test_s21_trim_7) {
  char str[] = "DoNotTouch";
  char trim_ch[] = "Not";
  char expected[] = "DoNotTouch";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(test_s21_trim_8) {
  char str[] = "&* !!sc21 * **";
  char trim_ch[] = "&!* ";
  char expected[] = "sc21";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) {
    free(got);
  }
}
END_TEST

START_TEST(test_s21_trim_9) {
  char str[] = " Good morning!    ";
  char trim_ch[] = " ";
  char expected[] = "Good morning!";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) {
    free(got);
  }
}
END_TEST

START_TEST(test_s21_trim_10) {
  char str[] = "        abc         ";
  char trim_ch[] = "";
  char expected[] = "abc";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) {
    free(got);
  }
}
END_TEST

START_TEST(test_s21_trim_11) {
  char str[] = "        abc         ";
  char *trim_ch = NULL;
  char expected[] = "abc";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) {
    free(got);
  }
}
END_TEST

Suite *suite_s21_trim(void) {
  Suite *s = suite_create("suite_trim");
  TCase *tc = tcase_create("trim_tc");
  tcase_add_test(tc, test_s21_trim_1);
  tcase_add_test(tc, test_s21_trim_2);
  tcase_add_test(tc, test_s21_trim_3);
  tcase_add_test(tc, test_s21_trim_4);
  tcase_add_test(tc, test_s21_trim_5);
  tcase_add_test(tc, test_s21_trim_6);
  tcase_add_test(tc, test_s21_trim_7);
  tcase_add_test(tc, test_s21_trim_8);
  tcase_add_test(tc, test_s21_trim_9);
  tcase_add_test(tc, test_s21_trim_10);
  tcase_add_test(tc, test_s21_trim_11);
  suite_add_tcase(s, tc);
  return s;
}
