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

START_TEST(s21_inverse_1) {
  matrix_t A, C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 1.0;
  C.matrix[0][1] = -1.0;
  C.matrix[0][2] = 1.0;
  C.matrix[1][0] = -38.0;
  C.matrix[1][1] = 41.0;
  C.matrix[1][2] = -34.0;
  C.matrix[2][0] = 27.0;
  C.matrix[2][1] = -29.0;
  C.matrix[2][2] = 24.0;
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  matrix_t B;
  s21_inverse_matrix(&A, &B);
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_one_by_one) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);

  if (codec == OK) {
    m.matrix[0][0] = 1431.12312331;

    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(code, OK);

    ck_assert_double_eq_tol(result.matrix[0][0], (1.0 / m.matrix[0][0]), 1e-6);

    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
  }
}
END_TEST

START_TEST(test_zero_det) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);

  if (codec == OK) {
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(code, CALCULATION_ERROR);

    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
  }
}
END_TEST

START_TEST(determinant) {
  const int size = 2;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 1;
  m.matrix[1][0] = 1;
  m.matrix[1][1] = 1;

  matrix_t result = {0};
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, CALCULATION_ERROR);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_not_square) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 4, &m);

  if (codec == OK) {
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(code, CALCULATION_ERROR);

    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
  }
}
END_TEST

START_TEST(inverse) {
  const int size = 3;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 5;
  m.matrix[0][2] = 7;
  m.matrix[1][0] = 6;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -3;

  matrix_t res = {0};
  s21_inverse_matrix(&m, &res);

  matrix_t expected = {0};
  s21_create_matrix(size, size, &expected);
  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = -1;
  expected.matrix[0][2] = 1;
  expected.matrix[1][0] = -38;
  expected.matrix[1][1] = 41;
  expected.matrix[1][2] = -34;
  expected.matrix[2][0] = 27;
  expected.matrix[2][1] = -29;
  expected.matrix[2][2] = 24;

  ck_assert_int_eq(s21_eq_matrix(&expected, &res), SUCCESS);

  s21_remove_matrix(&expected);
  s21_remove_matrix(&res);
  s21_remove_matrix(&m);
}
END_TEST

Suite *suite_inverse_matrix(void) {
  Suite *s = suite_create("S21 Matrix Tests Inverse Matrix");
  TCase *tc_s21_inverse_matrix = tcase_create("S21 Inverse Matrix");
  tcase_add_test(tc_s21_inverse_matrix, test_s21_inverse_matrix_2x2);
  tcase_add_test(tc_s21_inverse_matrix, test_s21_inverse_matrix_invalid_input);
  tcase_add_test(tc_s21_inverse_matrix, test_s21_inverse_matrix_det_zero);
  tcase_add_test(tc_s21_inverse_matrix, test_s21_inverse_matrix_nan_input);

  tcase_add_test(tc_s21_inverse_matrix, s21_inverse_1);
  tcase_add_test(tc_s21_inverse_matrix, test_one_by_one);
  tcase_add_test(tc_s21_inverse_matrix, test_zero_det);
  tcase_add_test(tc_s21_inverse_matrix, determinant);

  tcase_add_test(tc_s21_inverse_matrix, test_not_square);
  tcase_add_test(tc_s21_inverse_matrix, inverse);

  suite_add_tcase(s, tc_s21_inverse_matrix);

  return s;
}