#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (ptr_is_null(result) || negative_size(rows, columns)) {
    return INCORRECT_MATRIX;
  }

  result->matrix = (double **)calloc(rows, sizeof(double *));
  if (ptr_is_null(result->matrix)) {
    return CALCULATION_ERROR;
  }

  for (int i = 0; i < rows; i++) {
    result->matrix[i] = (double **)calloc(columns, sizeof(double *));
    if (ptr_is_null(result->matrix[i])) {
      s21_remove_matrix(result);
      return CALCULATION_ERROR;
    }
  }

  result->rows = rows;
  result->columns = columns;

  return OK;
}