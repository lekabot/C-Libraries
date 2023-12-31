#include "s21_matrix_tests.h"

START_TEST(test_s21_sum_matrix_valid) {
  matrix_t matrix_A, matrix_B, result;
  s21_create_matrix(2, 2, &matrix_A);
  s21_create_matrix(2, 2, &matrix_B);

  matrix_A.matrix[0][0] = 1.0;
  matrix_A.matrix[0][1] = 2.0;
  matrix_A.matrix[1][0] = 3.0;
  matrix_A.matrix[1][1] = 4.0;

  matrix_B.matrix[0][0] = 5.0;
  matrix_B.matrix[0][1] = 6.0;
  matrix_B.matrix[1][0] = 7.0;
  matrix_B.matrix[1][1] = 8.0;

  int status = s21_sum_matrix(&matrix_A, &matrix_B, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 6.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][1], 8.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][0], 10.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][1], 12.0, 1e-6);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&matrix_B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sum_matrix_invalid_input) {
  matrix_t matrix_A, matrix_B, result;
  s21_create_matrix(2, 2, &matrix_A);
  s21_create_matrix(3, 2, &matrix_B);

  int status = s21_sum_matrix(&matrix_A, &matrix_B, &result);

  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&matrix_B);
}
END_TEST

START_TEST(test_s21_sum_matrix_null_result) {
  matrix_t matrix_A, matrix_B;
  s21_create_matrix(2, 2, &matrix_A);
  s21_create_matrix(2, 2, &matrix_B);

  int status = s21_sum_matrix(&matrix_A, &matrix_B, NULL);

  ck_assert_int_eq(status, INCORRECT_MATRIX);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&matrix_B);
}
END_TEST

Suite *suite_sum_matrix(void) {
  Suite *s = suite_create("S21 Matrix Tests Sum Matrix");
  TCase *tc = tcase_create("S21 Sum Matrix");

  tcase_add_test(tc, test_s21_sum_matrix_valid);
  tcase_add_test(tc, test_s21_sum_matrix_invalid_input);
  tcase_add_test(tc, test_s21_sum_matrix_null_result);

  suite_add_tcase(s, tc);

  return s;
}