#include "s21_matrix_tests.h"

START_TEST(test_s21_sub_matrix_valid)
{
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

    int status = s21_sub_matrix(&matrix_A, &matrix_B, &result);

    ck_assert_int_eq(status, OK);
    ck_assert_int_eq(s21_eq_matrix(&matrix_A, &matrix_B), SUCCESS);

    s21_remove_matrix(&matrix_A);
    s21_remove_matrix(&matrix_B);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix_invalid_input)
{
    matrix_t matrix_A, matrix_B, result;
    s21_create_matrix(2, 2, &matrix_A);
    s21_create_matrix(3, 2, &matrix_B);

    int status = s21_sub_matrix(&matrix_A, &matrix_B, &result);

    ck_assert_int_eq(status, INCORRECT_MATRIX);

    s21_remove_matrix(&matrix_A);
    s21_remove_matrix(&matrix_B);
    s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix_null_result)
{
    matrix_t matrix_A, matrix_B, result = {NULL, 0, 0};
    s21_create_matrix(2, 2, &matrix_A);
    s21_create_matrix(2, 2, &matrix_B);

    int status = s21_sub_matrix(&matrix_A, &matrix_B, &result);

    ck_assert_int_eq(status, INCORRECT_MATRIX);

    s21_remove_matrix(&matrix_A);
    s21_remove_matrix(&matrix_B);
}
END_TEST

Suite *suite_sub_matrix(void) {
    Suite *s = suite_create("S21 Matrix Tests Sub Matrix");
    TCase *tc = tcase_create("S21 Matrix Sub");

    tcase_add_test(tc, test_s21_sub_matrix_valid);
    tcase_add_test(tc, test_s21_sub_matrix_invalid_input);
    tcase_add_test(tc, test_s21_sub_matrix_null_result);

    return s;
}