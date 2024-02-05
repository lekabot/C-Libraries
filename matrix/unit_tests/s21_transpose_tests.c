#include "s21_matrix_tests.h"

START_TEST(test_s21_transpose_valid) {
  matrix_t matrix_A, result;
  s21_create_matrix(2, 3, &matrix_A);

  matrix_A.matrix[0][0] = 1.0;
  matrix_A.matrix[0][1] = 2.0;
  matrix_A.matrix[0][2] = 3.0;
  matrix_A.matrix[1][0] = 4.0;
  matrix_A.matrix[1][1] = 5.0;
  matrix_A.matrix[1][2] = 6.0;

  int status = s21_transpose(&matrix_A, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 1.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][0], 2.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][0], 3.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][1], 4.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][1], 5.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[2][1], 6.0, 1e-6);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose_invalid_input) {
  matrix_t matrix_A;
  s21_create_matrix(2, 3, &matrix_A);

  matrix_A.matrix[0][0] = 1.0;
  matrix_A.matrix[0][1] = 2.0;
  matrix_A.matrix[0][2] = 3.0;
  matrix_A.matrix[1][0] = 4.0;
  matrix_A.matrix[1][1] = 5.0;
  matrix_A.matrix[1][2] = 6.0;

  int status = s21_transpose(&matrix_A, NULL);

  ck_assert_int_eq(status, INCORRECT_MATRIX);

  s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(transpose_matrix) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);

  matrix_t check = {0};
  s21_create_matrix(cols, rows, &check);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      double rand_val = get_rand(-10e10, 10e10);
      m.matrix[i][j] = rand_val;
      check.matrix[j][i] = rand_val;
    }
  }

  matrix_t res = {0};
  ck_assert_int_eq(s21_transpose(&m, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(transpose_matrix2) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  rows = -rows;
  cols = -cols;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t check = {0};
  s21_create_matrix(cols, rows, &check);

  matrix_t res = {0};
  ck_assert_int_eq(s21_transpose(&m, &res), INCORRECT_MATRIX);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

Suite *suite_transpose_matrix(void) {
  Suite *s = suite_create("S21 Matrix Tests Transpose");
  TCase *tc = tcase_create("S21 Transpose Matrix");

  tcase_add_test(tc, test_s21_transpose_valid);
  tcase_add_test(tc, test_s21_transpose_invalid_input);

  tcase_add_loop_test(tc, transpose_matrix, 0, 100);
  tcase_add_loop_test(tc, transpose_matrix2, 0, 100);

  suite_add_tcase(s, tc);

  return s;
}