#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (ptr_is_null(A) || ptr_is_null(B)) {
    return INCORRECT_MATRIX;
  }
  if (!equal_size(A, B)) {
    return INCORRECT_MATRIX;
  }
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j] > 1e-7)) {
        return FAILURE;
      }
    }
  }
  return SUCCESS;
}
