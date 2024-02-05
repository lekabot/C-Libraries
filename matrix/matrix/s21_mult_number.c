#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int program_code = OK;
  if (ptr_is_null(A) || ptr_is_null(result)) {
    program_code = INCORRECT_MATRIX;
  } else if (inf_or_nan(A) || isinf(number) || isnan(number)) {
    program_code = CALCULATION_ERROR;
  } else if (s21_create_matrix(A->rows, A->columns, result)) {
    program_code = INCORRECT_MATRIX;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = number * A->matrix[i][j];
      }
    }
  }
  return program_code;
}