#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  *result = 0.0;
  int flag = 0;
  if (s21_is_empty(A) == 0) {
    if (A->rows == A->columns) {
      *result = s21_get_determinant(A);
    } else {
      flag = CALCULATION_ERROR;
    }
  } else {
    flag = INCORRECT_MATRIX;
  }
  return flag;
}

double s21_get_determinant(matrix_t *A) {
  double flag = 0.0;
  if (A->rows == 1) {
    flag = A->matrix[0][0];
  } else {
    matrix_t tmp = {0};
    s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
    for (int i = 0; i < A->columns; i++) {
      s21_get_matrix(0, i, A, &tmp);
      if (i % 2) {
        flag -= A->matrix[0][i] * s21_get_determinant(&tmp);
      } else {
        flag += A->matrix[0][i] * s21_get_determinant(&tmp);
      }
    }
    s21_remove_matrix(&tmp);
  }
  return flag;
}