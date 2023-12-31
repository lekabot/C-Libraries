#include "s21_matrix_tests.h"

START_TEST(create2x2_matrix) {
  matrix_t matrix_2x2;
  int status_2x2 = s21_create_matrix(2, 2, &matrix_2x2);

  ck_assert_int_eq(status_2x2, OK);
  ck_assert_int_eq(matrix_2x2.rows, 2);
  ck_assert_int_eq(matrix_2x2.columns, 2);

  s21_remove_matrix(&matrix_2x2);
}
END_TEST

START_TEST(create_wrong_matrix) {
  matrix_t matrix;
  int status = s21_create_matrix((int)999999999999999999,
                                 (int)999999999999999999, &matrix);

  ck_assert_int_eq(status, INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_neg_size_matrix) {
  matrix_t matrix_negative;
  int status_negative = s21_create_matrix(-1, 3, &matrix_negative);

  ck_assert_int_eq(status_negative, INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_null_matrix) {
  int status_negative = s21_create_matrix(-1, 3, NULL);

  ck_assert_int_eq(status_negative, INCORRECT_MATRIX);
}
END_TEST

Suite *suite_create_matrix(void) {
  Suite *s = suite_create("S21 Matrix Tests Create Matrix");
  TCase *tc = tcase_create("S21 Create Matrix");

  tcase_add_test(tc, create2x2_matrix);
  tcase_add_test(tc, create_neg_size_matrix);
  tcase_add_test(tc, create_null_matrix);
  tcase_add_test(tc, create_wrong_matrix);

  suite_add_tcase(s, tc);
  return s;
}