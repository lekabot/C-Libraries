#include "s21_matrix_tests.h"

START_TEST(test_s21_transpose_valid)
{
    matrix_t matrix_A, result;
    s21_create_matrix(2, 3, &matrix_A);

    // Fill the matrix with values
    matrix_A.matrix[0][0] = 1.0;
    matrix_A.matrix[0][1] = 2.0;
    matrix_A.matrix[0][2] = 3.0;
    matrix_A.matrix[1][0] = 4.0;
    matrix_A.matrix[1][1] = 5.0;
    matrix_A.matrix[1][2] = 6.0;

    int status = s21_transpose(&matrix_A, &result);

    // Check if the matrix is transposed correctly
    ck_assert_int_eq(status, OK);
    ck_assert_double_eq_tol(result.matrix[0][0], 1.0, 1e-6);
    ck_assert_double_eq_tol(result.matrix[1][0], 2.0, 1e-6);
    ck_assert_double_eq_tol(result.matrix[2][0], 3.0, 1e-6);
    ck_assert_double_eq_tol(result.matrix[0][1], 4.0, 1e-6);
    ck_assert_double_eq_tol(result.matrix[1][1], 5.0, 1e-6);
    ck_assert_double_eq_tol(result.matrix[2][1], 6.0, 1e-6);

    // Clean up
    s21_remove_matrix(&matrix_A);
    s21_remove_matrix(&result);
}
END_TEST

// Test case 2: Check if the function handles incorrect input matrices gracefully
START_TEST(test_s21_transpose_invalid_input)
{
    matrix_t matrix_A, result;
    s21_create_matrix(2, 3, &matrix_A);

    // Fill the matrix with values
    matrix_A.matrix[0][0] = 1.0;
    matrix_A.matrix[0][1] = 2.0;
    matrix_A.matrix[0][2] = 3.0;
    matrix_A.matrix[1][0] = 4.0;
    matrix_A.matrix[1][1] = 5.0;
    matrix_A.matrix[1][2] = 6.0;

    // Set result matrix to NULL intentionally
    matrix_t result_invalid = {NULL, 0, 0};

    int status = s21_transpose(&matrix_A, &result_invalid);

    // Check if the function handles incorrect input matrices gracefully
    ck_assert_int_eq(status, INCORRECT_MATRIX);

    // Clean up
    s21_remove_matrix(&matrix_A);
    s21_remove_matrix(&result_invalid);
}
END_TEST

Suite *suite_transpose_matrix(void) {
    Suite *s = suite_create("S21 Matrix Tests");
    TCase *tc_s21_transpose = tcase_create("S21 Transpose Matrix");
    tcase_add_test(tc_s21_transpose, test_s21_transpose_valid);
    tcase_add_test(tc_s21_transpose, test_s21_transpose_invalid_input);
    suite_add_tcase(s, tc_s21_transpose);

    return s;
}