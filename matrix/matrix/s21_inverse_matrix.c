#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (ptr_is_null(A) || ptr_is_null(result)) {
    return INCORRECT_MATRIX;
  }
  if (A->rows != A->columns || inf_or_nan(A)) {
    return CALCULATION_ERROR;
  }

  double det = 0.;
  s21_determinant(A, &det);

  if (!det) {
    return CALCULATION_ERROR;
  }

  matrix_t complements, transpose;

  s21_calc_complements(A, &complements);
  s21_transpose(&complements, &transpose);

  det = 1 / det;

  s21_mult_number(&transpose, det, result);
  s21_remove_matrix(&transpose);
  s21_remove_matrix(&complements);

  return OK;
}