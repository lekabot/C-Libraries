#include "s21_matrix_tests.h"

START_TEST(create_1) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = 0;
      ck_assert_ldouble_eq_tol(0, m.matrix[i][j], 1e-07);
    }
  }
  ck_assert_int_eq(m.rows, rows);
  ck_assert_int_eq(m.columns, cols);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_2) {
  const int rows = 0;
  const int cols = 10;
  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_3) {
  const int rows = 10;
  const int cols = 0;

  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_s21_create_matrix_NULL) {
  matrix_t result = {0};
  int code = s21_create_matrix(3, 4, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(result.rows, 3);
  ck_assert_int_eq(result.columns, 4);

  ck_assert_ptr_ne(result.matrix, NULL);
  for (int i = 0; i < result.rows; i++) {
    ck_assert_ptr_ne(result.matrix[i], NULL);
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], 0.0);
    }
  }

  s21_remove_matrix(&result);
}
END_TEST

Suite *suite_create_matrix(void) {
  Suite *s = suite_create("S21 Matrix Tests Create Matrix");
  TCase *tc = tcase_create("S21 Matrix Create Matrix");

  tcase_add_test(tc, create_1);
  tcase_add_test(tc, create_2);
  tcase_add_test(tc, create_3);
  tcase_add_test(tc, test_s21_create_matrix_NULL);

  suite_add_tcase(s, tc);
  return s;
}