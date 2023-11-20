#include "s21_matrix_tests.h"

START_TEST(test_s21_mult_number_valid)
{
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

START_TEST(test_s21_mult_number_invalid_input)
{
    matrix_t matrix_A, result;
    s21_create_matrix(2, 2, &matrix_A);

    matrix_A.matrix[0][0] = 1.0;
    matrix_A.matrix[0][1] = 2.0;
    matrix_A.matrix[1][0] = 3.0;
    matrix_A.matrix[1][1] = 4.0;

    double number = 2.0;

    matrix_t result_invalid = {NULL, 0, 0};

    int status = s21_mult_number(&matrix_A, number, &result_invalid);

    ck_assert_int_eq(status, INCORRECT_MATRIX);

    s21_remove_matrix(&matrix_A);
}
END_TEST

START_TEST(test_s21_mult_number_inf_nan)
{
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

START_TEST(test_s21_mult_number_nan_result)
{
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

Suite *suite_mult_number(void) {
    Suite *s = suite_create("S21 Matrix Tests");
    TCase *tc_s21_mult_number = tcase_create("S21 Multiply Number");
    tcase_add_test(tc_s21_mult_number, test_s21_mult_number_valid);
    tcase_add_test(tc_s21_mult_number, test_s21_mult_number_invalid_input);
    tcase_add_test(tc_s21_mult_number, test_s21_mult_number_inf_nan);
    tcase_add_test(tc_s21_mult_number, test_s21_mult_number_nan_result);
    suite_add_tcase(s, tc_s21_mult_number);
    return s;
}