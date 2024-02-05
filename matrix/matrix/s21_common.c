#include "../s21_matrix.h"

// int negative_size(int rows, int columns) { return rows <= 0 || columns <= 0;
// }

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

void record_det_matrix(matrix_t *det, matrix_t *A, int minor_row,
                       int minor_col) {
  for (int src_row = 0, det_row = 0; src_row < A->rows; src_row++) {
    for (int src_col = 0, det_col = 0; src_col < A->columns; src_col++) {
      if (src_row != minor_row && src_col != minor_col) {
        det->matrix[det_row][det_col] = A->matrix[src_row][src_col];
        det_col++;
        if (det_col == det->columns) {
          det_row++;
          det_col = 0;
        }
      }
    }
  }
}

int s21_is_empty(matrix_t *matrix) {
  int res = 0;
  if (matrix == NULL || matrix->matrix == NULL || matrix->rows <= 0 ||
      matrix->columns <= 0) {
    res = 1;
  } else {
    res = 0;
  }
  return res;
}

void s21_get_matrix(int row, int col, matrix_t *A, matrix_t *result) {
  int m_row = 0;
  int m_col = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == row) {
      continue;
    }
    m_col = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == col) {
        continue;
      }
      result->matrix[m_row][m_col] = A->matrix[i][j];
      m_col++;
    }
    m_row++;
  }
}

// int is_correct(matrix_t *A) {
//     return A && A->rows > 0 && A->columns > 0;
// }