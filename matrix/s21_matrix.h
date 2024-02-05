#ifndef s21_matrix_h
#define s21_matrix_h

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

enum result_code { OK, INCORRECT_MATRIX, CALCULATION_ERROR };

// Operations with matrices

// 0 - OK
// 1 - Error, incorrect matrix
// 2 - Calculation error (mismatched matrix sizes; matrix for which calculations
// cannot be performed, etc.)
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// Help functions
// Is checks size
// int negative_size(int rows, int columns);

// Is checks pointer is null
int ptr_is_null(matrix_t *A);

// Is checks matrices for equal size
int equal_size(matrix_t *A, matrix_t *B);

// Is checks the matrices for the available size when multiplying
int size_for_mult(matrix_t *A, matrix_t *B);

// Is checks the matrices is not infinit or nan
int inf_or_nan(matrix_t *A);

void algebraic_complements(matrix_t *A, matrix_t *result);

void record_det_matrix(matrix_t *det, matrix_t *A, int minor_row,
                       int minor_col);

int s21_is_empty(matrix_t *matrix);
void s21_get_matrix(int row, int col, matrix_t *A, matrix_t *result);

double s21_get_determinant(matrix_t *A);
// int is_zero_matrix(matrix_t *A);
// int is_correct(matrix_t *A);

#endif /* s21_matrix_h */
