#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdlib.h>

typedef struct {
  size_t rows;
  size_t cols;
  float *data;
} matrix_t;

void free_matrix(matrix_t m);
matrix_t new_matrix(size_t rows, size_t cols);
matrix_t new_identity_matrix(size_t size);
float *e(matrix_t m, size_t row, size_t col);
float e_val(matrix_t m, size_t row, size_t col);
void print_matrix(matrix_t m);
void set_mult_matrix(matrix_t c, matrix_t a, matrix_t b);
matrix_t mult_matrix(matrix_t a, matrix_t b);
void set_add_matrix(matrix_t c, matrix_t a, matrix_t b);
matrix_t add_matrix(matrix_t a, matrix_t b);
void set_sub_matrix(matrix_t c, matrix_t a, matrix_t b);
matrix_t sub_matrix(matrix_t a, matrix_t b);
void emult_matrix(matrix_t c, matrix_t a, matrix_t b);
void ediv_matrix(matrix_t c, matrix_t a, matrix_t b);
#endif
