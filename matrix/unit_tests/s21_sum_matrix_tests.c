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

START_TEST(sum_matrix) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(rows, cols, &mtx);
  matrix_t check = {0};
  s21_create_matrix(rows, cols, &check);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      mtx.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      check.matrix[i][j] = m.matrix[i][j] + mtx.matrix[i][j];
    }
  }
  matrix_t res = {0};

  ck_assert_int_eq(s21_sum_matrix(&m, &mtx, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(sum_matrix1) {
  matrix_t m = {0};
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  const int rows1 = rand() % 100 + 1;
  const int cols1 = rand() % 100 + 1;
  s21_create_matrix(rows1, cols1, &mtx);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
    }
  }
  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < cols1; j++) {
      mtx.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
    }
  }

  matrix_t res = {0};
  ck_assert_int_eq(s21_sum_matrix(&m, &mtx, &res), CALCULATION_ERROR);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sum_matrix2) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  rows = -rows;
  cols = -cols;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(rows, cols, &mtx);

  matrix_t res = {0};

  ck_assert_int_eq(s21_sum_matrix(&m, &mtx, &res), INCORRECT_MATRIX);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
}
END_TEST

Suite *suite_sum_matrix(void) {
  Suite *s = suite_create("S21 Matrix Tests Sum Matrix");
  TCase *tc = tcase_create("S21 Sum Matrix");

  tcase_add_test(tc, test_s21_sum_matrix_valid);
  tcase_add_test(tc, test_s21_sum_matrix_invalid_input);
  tcase_add_test(tc, test_s21_sum_matrix_null_result);

  tcase_add_loop_test(tc, sum_matrix, 0, 100);
  tcase_add_loop_test(tc, sum_matrix1, 0, 100);
  tcase_add_loop_test(tc, sum_matrix2, 0, 100);

  suite_add_tcase(s, tc);

  return s;
}