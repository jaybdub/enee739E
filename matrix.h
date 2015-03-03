#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdlib.h>

typedef struct {
  size_t rows;
  size_t cols;
  float *data;
} matrix_t;

/* utilities */
void free_matrix(matrix_t m);
matrix_t new_matrix(size_t rows, size_t cols);
matrix_t new_identity_matrix(size_t size);
int set_dim(matrix_t *m, size_t rows, size_t cols);
void copy(matrix_t *to, matrix_t from);
float *ele(matrix_t m, size_t row, size_t col);
float val(matrix_t m, size_t row, size_t col);
void ones(matrix_t *m, size_t rows, size_t cols);
void zeros(matrix_t *m, size_t rows, size_t cols);
void rand_matrix(matrix_t *m, size_t rows, size_t cols);

/* input / output */
void print_matrix(matrix_t m);

/* arithmetic */
void mul(matrix_t *c, matrix_t a, matrix_t b);
void add(matrix_t *c, matrix_t a, matrix_t b);
void sub(matrix_t *c, matrix_t a, matrix_t b);
void emul(matrix_t *c, matrix_t a, matrix_t b);
void ediv(matrix_t *c, matrix_t a, matrix_t b);
void scale(matrix_t *m, float scalor);

#endif
