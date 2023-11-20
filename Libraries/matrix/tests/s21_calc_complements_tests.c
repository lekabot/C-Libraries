#include "s21_matrix_tests.h"

START_TEST(test_s21_calc_complements_2x2)
{
    matrix_t matrix_A, result;
    s21_create_matrix(2, 2, &matrix_A);

    // Fill the matrix with values
    matrix_A.matrix[0][0] = 1.0;
    matrix_A.matrix[0][1] = 2.0;
    matrix_A.matrix[1][0] = 3.0;
    matrix_A.matrix[1][1] = 4.0;

    int status = s21_calc_complements(&matrix_A, &result);

    // Check if the complements are calculated correctly
    ck_assert_int_eq(status, OK);
    ck_assert_double_eq_tol(result.matrix[0][0], 4.0, 1e-6);
    ck_assert_double_eq_tol(result.matrix[0][1], -3.0, 1e-6);
    ck_assert_double_eq_tol(result.matrix[1][0], -2.0, 1e-6);
    ck_assert_double_eq_tol(result.matrix[1][1], 1.0, 1e-6);

    // Clean up
    s21_remove_matrix(&matrix_A);
    s21_remove_matrix(&result);
}
END_TEST

// Test case 2: Check if the function handles incorrect input matrices gracefully
START_TEST(test_s21_calc_complements_invalid_input)
{
    matrix_t matrix_A, result;
    s21_create_matrix(2, 3, &matrix_A);  // Non-square matrix

    int status = s21_calc_complements(&matrix_A, &result);

    // Check if the function handles incorrect input matrices gracefully
    ck_assert_int_eq(status, INCORRECT_MATRIX);

    // Clean up
    s21_remove_matrix(&matrix_A);
    s21_remove_matrix(&result);
}
END_TEST

// Test case 3: Check if the function handles matrix with NaN gracefully
START_TEST(test_s21_calc_complements_nan_input)
{
    matrix_t matrix_A, result;
    s21_create_matrix(2, 2, &matrix_A);

    // Fill the matrix with NaN values
    matrix_A.matrix[0][0] = NAN;
    matrix_A.matrix[0][1] = 2.0;
    matrix_A.matrix[1][0] = 3.0;
    matrix_A.matrix[1][1] = 4.0;

    int status = s21_calc_complements(&matrix_A, &result);

    // Check if the function handles matrix with NaN gracefully
    ck_assert_int_eq(status, CALCULATION_ERROR);

    // Clean up
    s21_remove_matrix(&matrix_A);
    s21_remove_matrix(&result);
}
END_TEST

Suite *suite_calc_complements(void) {
    Suite *s = suite_create("S21 Matrix Tests");
    TCase *tc_s21_calc_complements = tcase_create("S21 Calculate Complements");
    tcase_add_test(tc_s21_calc_complements, test_s21_calc_complements_2x2);
    tcase_add_test(tc_s21_calc_complements, test_s21_calc_complements_invalid_input);
    tcase_add_test(tc_s21_calc_complements, test_s21_calc_complements_nan_input);
    suite_add_tcase(s, tc_s21_calc_complements);
    return s;
}