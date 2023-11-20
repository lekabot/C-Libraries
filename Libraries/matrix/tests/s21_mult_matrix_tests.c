#include "s21_matrix_tests.h"

START_TEST(test_s21_mult_matrix_valid)
{
    matrix_t matrix_A, matrix_B, result;
    s21_create_matrix(2, 2, &matrix_A);
    s21_create_matrix(2, 2, &matrix_B);

    // Fill matrices with values
    matrix_A.matrix[0][0] = 1.0;
    matrix_A.matrix[0][1] = 2.0;
    matrix_A.matrix[1][0] = 3.0;
    matrix_A.matrix[1][1] = 4.0;

    matrix_B.matrix[0][0] = 5.0;
    matrix_B.matrix[0][1] = 6.0;
    matrix_B.matrix[1][0] = 7.0;
    matrix_B.matrix[1][1] = 8.0;

    int status = s21_mult_matrix(&matrix_A, &matrix_B, &result);

    // Check if the matrices are multiplied correctly
    ck_assert_int_eq(status, OK);
    ck_assert_double_eq_tol(result.matrix[0][0], 19.0, 1e-6);
    ck_assert_double_eq_tol(result.matrix[0][1], 22.0, 1e-6);
    ck_assert_double_eq_tol(result.matrix[1][0], 43.0, 1e-6);
    ck_assert_double_eq_tol(result.matrix[1][1], 50.0, 1e-6);

    // Clean up
    s21_remove_matrix(&matrix_A);
    s21_remove_matrix(&matrix_B);
    s21_remove_matrix(&result);
}
END_TEST

// Test case 2: Check if the function handles incorrect input matrices gracefully
START_TEST(test_s21_mult_matrix_invalid_input)
{
    matrix_t matrix_A, matrix_B, result;
    s21_create_matrix(2, 2, &matrix_A);
    s21_create_matrix(3, 2, &matrix_B);  // Incompatible size

    int status = s21_mult_matrix(&matrix_A, &matrix_B, &result);

    // Check if the function handles incorrect input matrices gracefully
    ck_assert_int_eq(status, INCORRECT_MATRIX);

    // Clean up
    s21_remove_matrix(&matrix_A);
    s21_remove_matrix(&matrix_B);
    s21_remove_matrix(&result);
}
END_TEST

// Test case 3: Check if the function handles infinity or NaN gracefully
START_TEST(test_s21_mult_matrix_inf_nan)
{
    matrix_t matrix_A, matrix_B, result;
    s21_create_matrix(2, 2, &matrix_A);
    s21_create_matrix(2, 2, &matrix_B);

    // Fill matrices with values
    matrix_A.matrix[0][0] = 1.0;
    matrix_A.matrix[0][1] = 2.0;
    matrix_A.matrix[1][0] = 3.0;
    matrix_A.matrix[1][1] = 4.0;

    matrix_B.matrix[0][0] = INFINITY;
    matrix_B.matrix[0][1] = 6.0;
    matrix_B.matrix[1][0] = 7.0;
    matrix_B.matrix[1][1] = 8.0;

    int status = s21_mult_matrix(&matrix_A, &matrix_B, &result);

    // Check if the function handles infinity or NaN gracefully
    ck_assert_int_eq(status, CALCULATION_ERROR);

    // Clean up
    s21_remove_matrix(&matrix_A);
    s21_remove_matrix(&matrix_B);
}

Suite *suite_mult_matrix(void) {
    Suite *s = suite_create("S21 Matrix Tests");
    TCase *tc_s21_mult_matrix = tcase_create("S21 Multiply Matrix");
    tcase_add_test(tc_s21_mult_matrix, test_s21_mult_matrix_valid);
    tcase_add_test(tc_s21_mult_matrix, test_s21_mult_matrix_invalid_input);
    tcase_add_test(tc_s21_mult_matrix, test_s21_mult_matrix_inf_nan);
    suite_add_tcase(s, tc_s21_mult_matrix);
    return s;
}