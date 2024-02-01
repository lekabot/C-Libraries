#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (ptr_is_null(A) || ptr_is_null(B) || ptr_is_null(result)) {
    return INCORRECT_MATRIX;
  }
  if (inf_or_nan(A) || inf_or_nan(B) || equal_size(A, B)) {
    return CALCULATION_ERROR;
  }
  s21_create_matrix(A->rows, A->columns, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }
  return OK;
}
