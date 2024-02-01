#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (ptr_is_null(A) || ptr_is_null(result)) {
    return INCORRECT_MATRIX;
  }
  if (inf_or_nan(A) || isinf(number) || isnan(number)) {
    return CALCULATION_ERROR;
  }
  s21_create_matrix(A->rows, A->columns, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = number * A->matrix[i][j];
    }
  }
  return OK;
}