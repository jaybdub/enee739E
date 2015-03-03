#include <stdlib.h>
#include "matrix.h"

/*
 *  ones: turns matrix 'm' into a 'rows'x'cols' matrix where each entry is 1
 */
void
mat_ones(matrix_t *m, size_t rows, size_t cols)
{
  int i, lim;

  if (mat_set_dim(m, rows, cols)) {
    lim = m->rows * m->cols;
    for (i = 0; i < lim; i++)
      m->data[i] = 1.0f;
  }
}

/*
 *  zeros: turns matrix 'm' into a 'rows'x'cols' matrix where each entry is 0
 */
void
mat_zeros(matrix_t *m, size_t rows, size_t cols)
{
  int i, lim;

  if (mat_set_dim(m, rows, cols)) {
    lim = m->rows * m->cols;
    for (i = 0; i < lim; i++)
      m->data[i] = 0.0f;
  }
}

/*
 *  randu: generates a random matrix, uniformily distrubted between 0 and 1,
 *  stores the result in m
 */
void
mat_randu(matrix_t *m, size_t rows, size_t cols)
{
  int i, lim;

  if(mat_set_dim(m, rows, cols)) {
    lim = rows * cols;
    for (i = 0; i < lim; i++)
      m->data[i] = (float) rand() / (float) RAND_MAX;
  }
}
