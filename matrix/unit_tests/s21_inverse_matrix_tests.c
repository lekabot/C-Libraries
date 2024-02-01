#include "s21_matrix_tests.h"

START_TEST(test_s21_inverse_matrix_2x2) {
  matrix_t matrix_A, result;
  s21_create_matrix(2, 2, &matrix_A);

  matrix_A.matrix[0][0] = 1.0;
  matrix_A.matrix[0][1] = 2.0;
  matrix_A.matrix[1][0] = 3.0;
  matrix_A.matrix[1][1] = 4.0;

  int status = s21_inverse_matrix(&matrix_A, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], -2.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][1], 1.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][0], 1.5, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][1], -0.5, 1e-6);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_inverse_matrix_invalid_input) {
  matrix_t matrix_A, result;
  s21_create_matrix(2, 3, &matrix_A);

  int status = s21_inverse_matrix(&matrix_A, &result);

  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_det_zero) {
  matrix_t matrix_A, result;
  s21_create_matrix(2, 2, &matrix_A);
  s21_create_matrix(2, 2, &result);

  matrix_A.matrix[0][0] = 1.0;
  matrix_A.matrix[0][1] = 2.0;
  matrix_A.matrix[1][0] = 2.0;
  matrix_A.matrix[1][1] = 4.0;

  int status = s21_inverse_matrix(&matrix_A, &result);

  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_inverse_matrix_nan_input) {
  matrix_t matrix_A, result;
  s21_create_matrix(2, 2, &matrix_A);

  matrix_A.matrix[0][0] = NAN;
  matrix_A.matrix[0][1] = 2.0;
  matrix_A.matrix[1][0] = 3.0;
  matrix_A.matrix[1][1] = 4.0;

  int status = s21_inverse_matrix(&matrix_A, &result);

  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&matrix_A);
}
END_TEST

Suite *suite_inverse_matrix(void) {
  Suite *s = suite_create("S21 Matrix Tests Inverse Matrix");
  TCase *tc_s21_inverse_matrix = tcase_create("S21 Inverse Matrix");
  tcase_add_test(tc_s21_inverse_matrix, test_s21_inverse_matrix_2x2);
  tcase_add_test(tc_s21_inverse_matrix, test_s21_inverse_matrix_invalid_input);
  tcase_add_test(tc_s21_inverse_matrix, test_s21_inverse_matrix_det_zero);
  tcase_add_test(tc_s21_inverse_matrix, test_s21_inverse_matrix_nan_input);
  suite_add_tcase(s, tc_s21_inverse_matrix);

  return s;
}