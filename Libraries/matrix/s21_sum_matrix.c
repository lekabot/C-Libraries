#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (ptr_is_null(A) || ptr_is_null(result)) {
    return INCORRECT_MATRIX;
  }
  if (inf_or_nan(A)) {
    return CALCULATION_ERROR;
  }
  if (s21_create_matrix(A->columns, A->rows, result)) {
    return CALCULATION_ERROR;
  }
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }
  return OK;
}
