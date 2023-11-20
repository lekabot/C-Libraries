#include "s21_matrix.h"

int negative_size(int rows, int columns) { return rows <= 0 || columns <= 0; }

int ptr_is_null(matrix_t *A) { return A == NULL; }

int equal_size(matrix_t *A, matrix_t *B) {
  return A->rows != B->rows || A->columns != B->columns;
}

int size_for_mult(matrix_t *A, matrix_t *B) { return A->columns == B->rows; }

int inf_or_nan(matrix_t *A) {
  int res = OK;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (isinf(A->matrix[i][j]) || isnan(A->matrix[i][j])) {
        res = CALCULATION_ERROR;
        j = A->columns;
        i = A->rows;
      }
    }
  }
  return res;
}

void algebraic_complements(matrix_t *A, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if ((i + j) % 2) {
        result->matrix[i][j] *= -1;
      }
    }
  }
}

void record_det_matrix(matrix_t *det, matrix_t *A, int minor_row, int minor_col) {
  for (int src_row = 0, det_row = 0; src_row < A->rows; src_row++) {
    for (int src_col = 0, det_col = 0; src_col < A->columns; src_col++) {
      det->matrix[det_row][det_col] = A->matrix[src_row][src_col];
      det_col++;
      if (det_col == det->columns) {
        det_row++;
        det_col = 0;
      }
    }
  }

}