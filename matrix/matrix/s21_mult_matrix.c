#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int program_code = OK;
  if (ptr_is_null(A) || ptr_is_null(B) || ptr_is_null(result)) {
    program_code = INCORRECT_MATRIX;
  } else if (!size_for_mult(A, B) || inf_or_nan(A) || inf_or_nan(B)) {
    program_code = CALCULATION_ERROR;
  } else if (s21_create_matrix(A->rows, B->columns, result)) {
    program_code = INCORRECT_MATRIX;
    s21_remove_matrix(result);
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = 0;
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return program_code;
}