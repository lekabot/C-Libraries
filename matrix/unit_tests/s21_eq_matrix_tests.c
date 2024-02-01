#include "s21_matrix_tests.h"

START_TEST(test_s21_eq_matrix_equal) {
  matrix_t matrix_A, matrix_B;
  s21_create_matrix(3, 3, &matrix_A);
  s21_create_matrix(3, 3, &matrix_B);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_A.matrix[i][j] = 1.0;
      matrix_B.matrix[i][j] = 1.0;
    }
  }

  int result = s21_eq_matrix(&matrix_A, &matrix_B);

  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&matrix_B);
}
END_TEST

START_TEST(test_s21_eq_matrix_unequal) {
  matrix_t matrix_A, matrix_B;
  s21_create_matrix(2, 2, &matrix_A);
  s21_create_matrix(2, 2, &matrix_B);

  matrix_A.matrix[0][0] = 1.0;
  matrix_A.matrix[0][1] = 2.0;
  matrix_A.matrix[1][0] = 3.0;
  matrix_A.matrix[1][1] = 4.0;

  matrix_B.matrix[0][0] = 1.0;
  matrix_B.matrix[0][1] = 2.0;
  matrix_B.matrix[1][0] = 3.0;
  matrix_B.matrix[1][1] = 5.0;

  int result = s21_eq_matrix(&matrix_A, &matrix_B);

  ck_assert_int_eq(result, FAILURE);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&matrix_B);
}
END_TEST

START_TEST(test_s21_eq_matrix_null_matrices) {
  matrix_t matrix_A = {NULL, 0, 0};
  matrix_t matrix_B = {NULL, 0, 0};

  int result = s21_eq_matrix(&matrix_A, &matrix_B);

  ck_assert_int_eq(result, INCORRECT_MATRIX);
}
END_TEST

Suite *suite_eq_matrix(void) {
  Suite *s = suite_create("S21 Matrix Tests Eqel");
  TCase *tc = tcase_create("S21 Eqel Matrix");
  tcase_add_test(tc, test_s21_eq_matrix_equal);
  tcase_add_test(tc, test_s21_eq_matrix_unequal);
  tcase_add_test(tc, test_s21_eq_matrix_null_matrices);
  suite_add_tcase(s, tc);
  return s;
}