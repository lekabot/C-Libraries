#include "s21_matrix_tests.h"

START_TEST(test_s21_determinant_2x2)
{
    matrix_t matrix_A;
    s21_create_matrix(2, 2, &matrix_A);

    // Fill the matrix with values
    matrix_A.matrix[0][0] = 1.0;
    matrix_A.matrix[0][1] = 2.0;
    matrix_A.matrix[1][0] = 3.0;
    matrix_A.matrix[1][1] = 4.0;

    double result = 0.0;
    int status = s21_determinant(&matrix_A, &result);

    // Check if the determinant is calculated correctly for a 2x2 matrix
    ck_assert_int_eq(status, OK);
    ck_assert_double_eq_tol(result, -2.0, 1e-6);

    // Clean up
    s21_remove_matrix(&matrix_A);
}
END_TEST

// Test case 2: Check if the function handles incorrect input matrices gracefully
START_TEST(test_s21_determinant_invalid_input)
{
    matrix_t matrix_A;
    s21_create_matrix(2, 3, &matrix_A);  // Non-square matrix

    double result = 0.0;
    int status = s21_determinant(&matrix_A, &result);

    // Check if the function handles incorrect input matrices gracefully
    ck_assert_int_eq(status, INCORRECT_MATRIX);

    // Clean up
    s21_remove_matrix(&matrix_A);
}
END_TEST

// Test case 3: Check if the function handles matrix with NaN values gracefully
START_TEST(test_s21_determinant_nan_input)
{
    matrix_t matrix_A;
    s21_create_matrix(2, 2, &matrix_A);

    // Fill the matrix with NaN values
    matrix_A.matrix[0][0] = NAN;
    matrix_A.matrix[0][1] = 2.0;
    matrix_A.matrix[1][0] = 3.0;
    matrix_A.matrix[1][1] = 4.0;

    double result = 0.0;
    int status = s21_determinant(&matrix_A, &result);

    // Check if the function handles matrix with NaN values gracefully
    ck_assert_int_eq(status, CALCULATION_ERROR);

    // Clean up
    s21_remove_matrix(&matrix_A);
}
END_TEST

Suite *suite_determinant(void) {
    Suite *s = suite_create("S21 Matrix Tests");
    TCase *tc_s21_determinant = tcase_create("S21 Calculate Determinant");
    tcase_add_test(tc_s21_determinant, test_s21_determinant_2x2);
    tcase_add_test(tc_s21_determinant, test_s21_determinant_invalid_input);
    tcase_add_test(tc_s21_determinant, test_s21_determinant_nan_input);
    suite_add_tcase(s, tc_s21_determinant);
    return s;
}