#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int program_code = OK;
  if (ptr_is_null(A) || ptr_is_null(B) || ptr_is_null(result)) {
    program_code = INCORRECT_MATRIX;
  } else if (inf_or_nan(A) || inf_or_nan(B) || equal_size(A, B)) {
    program_code = CALCULATION_ERROR;
  } else if (s21_create_matrix(A->rows, A->columns, result)) {
    program_code = INCORRECT_MATRIX;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return program_code;
}
