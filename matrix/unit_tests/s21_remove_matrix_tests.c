#include "s21_matrix_tests.h"

START_TEST(test_s21_remove_matrix) {
  matrix_t matrix_2x2;
  s21_create_matrix(2, 2, &matrix_2x2);
  s21_remove_matrix(&matrix_2x2);

  ck_assert_ptr_null(matrix_2x2.matrix);
  ck_assert_int_eq(matrix_2x2.columns, 0);
  ck_assert_int_eq(matrix_2x2.rows, 0);
}
END_TEST

START_TEST(test_s21_remove_matrix_null_pointer) {
  matrix_t matrix = {NULL, 0, 0};

  s21_remove_matrix(&matrix);

  ck_assert_ptr_null(matrix.matrix);
  ck_assert_int_eq(matrix.rows, 0);
  ck_assert_int_eq(matrix.columns, 0);
}
END_TEST

Suite *suite_remove_matrix(void) {
  Suite *s = suite_create("S21 Matrix Tests Remove");
  TCase *tc = tcase_create("S21 Remove Matrix");
  tcase_add_test(tc, test_s21_remove_matrix);
  tcase_add_test(tc, test_s21_remove_matrix_null_pointer);

  suite_add_tcase(s, tc);

  return s;
}