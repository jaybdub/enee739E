#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdlib.h>

typedef struct {
  size_t rows;
  size_t cols;
  float *data;
} matrix_t;

/* utilities */
void mat_free(matrix_t m);
matrix_t mat_new(size_t rows, size_t cols);
int mat_set_dim(matrix_t *m, size_t rows, size_t cols);
void mat_copy(matrix_t *to, matrix_t from);
float *mat_ele(matrix_t m, size_t row, size_t col);
float mat_val(matrix_t m, size_t row, size_t col);

/* matrix generators */
void mat_ones(matrix_t *m, size_t rows, size_t cols);
void mat_zeros(matrix_t *m, size_t rows, size_t cols);
void mat_randu(matrix_t *m, size_t rows, size_t cols);
void mat_identity(matrix_t *m, size_t size);

/* input / output */
void mat_print(matrix_t m);

/* arithmetic */
void mat_mult(matrix_t *c, matrix_t a, matrix_t b);
void mat_add(matrix_t *c, matrix_t a, matrix_t b);
void mat_sub(matrix_t *c, matrix_t a, matrix_t b);
void mat_emult(matrix_t *c, matrix_t a, matrix_t b);
void mat_ediv(matrix_t *c, matrix_t a, matrix_t b);
void mat_scale(matrix_t *m, float scalor);
void mat_trace(matrix_t *trace, matrix_t m);
void mat_inv(matrix_t *inv, matrix_t m);

/* algorithms */

#endif
