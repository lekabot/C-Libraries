#include "s21_matrix_tests.h"

START_TEST(create2x2_matrix) {
    matrix_t matrix_2x2;
    int status_2x2 = s21_create_matrix(2, 2, &matrix_2x2);

    ck_assert_int_eq(status_2x2, OK);
    ck_assert_int_eq(matrix_2x2.rows, 2);
    ck_assert_int_eq(matrix_2x2.columns, 2);

    s21_remove_matrix(&matrix_2x2);
}
END_TEST

START_TEST(create_neg_size_matrix) {
    matrix_t matrix_negative;
    int status_negative = s21_create_matrix(-1, 3, &matrix_negative);

    ck_assert_int_eq(status_negative, INCORRECT_MATRIX);
}
END_TEST

Suite *suite_create_matrix(void) {
    Suite *s = suite_create("suite_create_matrix");
    TCase *tc = tcase_create("create_matrix_tc");
    tcase_add_test(tc, create2x2_matrix);
    tcase_add_test(tc, create_neg_size_matrix);
    return s;
}