#include "s21_matrix_tests.h"

START_TEST(test_s21_mult_number_valid) {
  matrix_t matrix_A, result;
  s21_create_matrix(2, 2, &matrix_A);

  matrix_A.matrix[0][0] = 1.0;
  matrix_A.matrix[0][1] = 2.0;
  matrix_A.matrix[1][0] = 3.0;
  matrix_A.matrix[1][1] = 4.0;

  double number = 2.0;

  int status = s21_mult_number(&matrix_A, number, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 2.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][1], 4.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][0], 6.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][1], 8.0, 1e-6);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number_invalid_input) {
  matrix_t matrix_A;
  s21_create_matrix(2, 2, &matrix_A);

  matrix_A.matrix[0][0] = 1.0;
  matrix_A.matrix[0][1] = 2.0;
  matrix_A.matrix[1][0] = 3.0;
  matrix_A.matrix[1][1] = 4.0;

  double number = 2.0;

  int status = s21_mult_number(&matrix_A, number, NULL);

  ck_assert_int_eq(status, INCORRECT_MATRIX);

  s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(test_s21_mult_number_inf_nan) {
  matrix_t matrix_A, result;
  s21_create_matrix(2, 2, &matrix_A);

  matrix_A.matrix[0][0] = 1.0;
  matrix_A.matrix[0][1] = 2.0;
  matrix_A.matrix[1][0] = 3.0;
  matrix_A.matrix[1][1] = 4.0;

  double number = INFINITY;

  int status = s21_mult_number(&matrix_A, number, &result);

  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(test_s21_mult_number_nan_result) {
  matrix_t matrix_A, result;
  s21_create_matrix(2, 2, &matrix_A);

  matrix_A.matrix[0][0] = 1.0;
  matrix_A.matrix[0][1] = 2.0;
  matrix_A.matrix[1][0] = 3.0;
  matrix_A.matrix[1][1] = 4.0;

  double number = NAN;

  int status = s21_mult_number(&matrix_A, number, &result);

  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(mult_number_matrix) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t check = {0};
  s21_create_matrix(rows, cols, &check);
  double mult_number = get_rand(-10e5, 10e5);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      check.matrix[i][j] = m.matrix[i][j] * mult_number;
    }
  }
  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_number(&m, mult_number, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_number_matrix2) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  rows = -rows;
  cols = -cols;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t check = {0};
  s21_create_matrix(rows, cols, &check);
  double mult_number = get_rand(-10e5, 10e5);

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_number(&m, mult_number, &res), INCORRECT_MATRIX);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

Suite *suite_mult_number(void) {
  Suite *s = suite_create("S21 Matrix Tests Multiply Number");
  TCase *tc_s21_mult_number = tcase_create("S21 Multiply Number");
  tcase_add_test(tc_s21_mult_number, test_s21_mult_number_valid);
  tcase_add_test(tc_s21_mult_number, test_s21_mult_number_invalid_input);
  tcase_add_test(tc_s21_mult_number, test_s21_mult_number_inf_nan);
  tcase_add_test(tc_s21_mult_number, test_s21_mult_number_nan_result);

  tcase_add_loop_test(tc_s21_mult_number, mult_number_matrix, 0, 100);
  tcase_add_loop_test(tc_s21_mult_number, mult_number_matrix2, 0, 100);

  suite_add_tcase(s, tc_s21_mult_number);
  return s;
}