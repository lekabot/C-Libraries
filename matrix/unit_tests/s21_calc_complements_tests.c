#include "s21_matrix_tests.h"

START_TEST(test_s21_calc_complements_2x2) {
  matrix_t matrix_A, result;
  s21_create_matrix(2, 2, &matrix_A);

  matrix_A.matrix[0][0] = 1.0;
  matrix_A.matrix[0][1] = 2.0;
  matrix_A.matrix[1][0] = 3.0;
  matrix_A.matrix[1][1] = 4.0;

  int status = s21_calc_complements(&matrix_A, &result);

  ck_assert_int_eq(status, OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 4.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][1], -3.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][0], -2.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][1], 1.0, 1e-6);

  s21_remove_matrix(&matrix_A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_calc_complements_invalid_input) {
  matrix_t matrix_A, result;
  s21_create_matrix(2, 3, &matrix_A);

  int status = s21_calc_complements(&matrix_A, &result);

  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(test_s21_calc_complements_nan_input) {
  matrix_t matrix_A, result;
  s21_create_matrix(2, 2, &matrix_A);

  matrix_A.matrix[0][0] = NAN;
  matrix_A.matrix[0][1] = 2.0;
  matrix_A.matrix[1][0] = 3.0;
  matrix_A.matrix[1][1] = 4.0;

  int status = s21_calc_complements(&matrix_A, &result);

  ck_assert_int_eq(status, CALCULATION_ERROR);

  s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(test_one_by_one) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (codec) {
    int code = s21_calc_complements(&m, &result);
    ck_assert_int_eq(code, CALCULATION_ERROR);
  }
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_incorrect) {
  matrix_t m = {0};
  matrix_t result = {0};
  int code = s21_calc_complements(&m, &result);
  ck_assert_int_eq(code, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_not_sqare) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(3, 4, &m);
  if (codec == OK) {
    int code = s21_calc_complements(&m, &result);
    ck_assert_int_eq(code, CALCULATION_ERROR);
    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
  }
}
END_TEST

START_TEST(test_normal) {
  matrix_t expected = {0};
  matrix_t m = {0};
  matrix_t result = {0};
  int code1 = s21_create_matrix(3, 3, &m);
  int code2 = s21_create_matrix(3, 3, &expected);

  ck_assert_int_eq(code1, OK);
  ck_assert_int_eq(code2, OK);

  if (code1 == OK && code2 == OK) {
    m.matrix[0][0] = 1;
    m.matrix[0][1] = 2;
    m.matrix[0][2] = 3;

    m.matrix[1][0] = 0;
    m.matrix[1][1] = 4;
    m.matrix[1][2] = 2;

    m.matrix[2][0] = 5;
    m.matrix[2][1] = 2;
    m.matrix[2][2] = 1;

    expected.matrix[0][0] = 0;
    expected.matrix[0][1] = 10;
    expected.matrix[0][2] = -20;

    expected.matrix[1][0] = 4;
    expected.matrix[1][1] = -14;
    expected.matrix[1][2] = 8;

    expected.matrix[2][0] = -8;
    expected.matrix[2][1] = -2;
    expected.matrix[2][2] = 4;

    int code = s21_calc_complements(&m, &result);

    ck_assert_int_eq(code, OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
    s21_remove_matrix(&expected);
  }
}
END_TEST

Suite *suite_calc_complements(void) {
  Suite *s = suite_create("S21 Matrix Tests Calc Complements");
  TCase *tc_s21_calc_complements = tcase_create("S21 Calculate Complements");
  tcase_add_test(tc_s21_calc_complements, test_s21_calc_complements_2x2);
  tcase_add_test(tc_s21_calc_complements,
                 test_s21_calc_complements_invalid_input);
  tcase_add_test(tc_s21_calc_complements, test_s21_calc_complements_nan_input);

  tcase_add_test(tc_s21_calc_complements, test_one_by_one);
  tcase_add_test(tc_s21_calc_complements, test_incorrect);
  tcase_add_test(tc_s21_calc_complements, test_not_sqare);
  tcase_add_test(tc_s21_calc_complements, test_normal);

  suite_add_tcase(s, tc_s21_calc_complements);
  return s;
}