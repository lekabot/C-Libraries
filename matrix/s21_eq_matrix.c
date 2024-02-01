#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (ptr_is_null(A) || ptr_is_null(B) || equal_size(A, B)) {
    return FAILURE;
  }
  int res = SUCCESS;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
        res = FAILURE;
        j = A->columns;
        i = A->rows;
      }
    }
  }
  return res;
}
