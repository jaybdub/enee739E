#include <assert.h>
#include "matrix.h"

/*
 *  set_mul: multiplies two matrices, stores the result in c
 *  c = a * b
 */
void
mat_mult(matrix_t *c, matrix_t a, matrix_t b)
{
  int i, j, k;
  assert(a.cols == b.rows);
  assert(mat_set_dim(c, a.rows, b.cols));

  for (i = 0; i < a.rows; i++) {
    for (j = 0; j < b.cols; j++) {
      c->data[i*c->cols + j] = 0;
      for (k = 0; k < a.cols; k++) {
	c->data[i*c->cols + j] += a.data[i*a.cols + k] * b.data[k*b.cols+j];
      }
    }
  }
};

/*
 *  set_add: adds two matrices, stores the result in c
 */
void
mat_add(matrix_t *c, matrix_t a, matrix_t b)
{
  int i, j, idx;
  assert(a.cols == b.cols && a.rows == b.rows);
  assert(mat_set_dim(c, a.rows, b.cols));

  for (i = 0; i < c->rows; i++) {
    for (j = 0; j < c->cols; j++) {
      idx = i * c->cols + j;
      c->data[idx] = a.data[idx] + b.data[idx];
    }
  }
};

/*
 *  set_sub: subtracts matrix b from matrix a, stores the result
 *  in c
 */
void
mat_sub(matrix_t *c, matrix_t a, matrix_t b)
{
  int i, j, idx;
  assert(a.cols == b.cols && a.rows == b.rows);
  assert(mat_set_dim(c, a.rows, b.cols));

  for (i = 0; i < c->rows; i++) {
    for (j = 0; j < c->cols; j++) {
      idx = i * c->cols + j;
      c->data[idx] = a.data[idx] - b.data[idx];
    }
  }
};

/*
 *  set_emult: performs element-wise multiplication of 'a'
 and 'b', 
 *  stores the result in c
 */
void
mat_emult(matrix_t *c, matrix_t a, matrix_t b)
{
  int i, j, idx;
  assert(a.cols == b.cols && a.rows == b.rows);
  assert(mat_set_dim(c, a.rows, b.cols));

  for (i = 0; i < c->rows; i++) {
    for (j = 0; j < c->cols; j++) {
      idx = i * c->cols + j;
      c->data[idx] = a.data[idx] * b.data[idx];
    }
  }
};

/*
 *  set_ediv: peforms element-wise division of a and b, stores
 *  the result in c.  Elements in a are numerators, elements in
 *  b are denomenators.
 */
void
mat_ediv(matrix_t *c, matrix_t a, matrix_t b)
{
  int i, j, idx;
  assert(a.cols == b.cols && a.rows == b.rows);
  assert(mat_set_dim(c, a.rows, b.cols));

  for (i = 0; i < c->rows; i++) {
    for (j = 0; j < c->cols; j++) {
      idx = i * c->cols + j;
      c->data[idx] = a.data[idx] / b.data[idx];
    }
  }
};

/*
 *  scale: scales m by 'scalor'
 */
void
mat_scale(matrix_t *m, float scalor)
{
  int i, lim;

  lim = m->rows * m->cols;
  for (i = 0; i < lim; i++)
    m->data[i] *= scalor;
}

/*
 *  trace: calculates the matrix trace of the square matrix 'm', 
 *  stores the result in 'trace'
 */
void
mat_trace(matrix_t *trace, matrix_t m)
{
  int i;
  assert(m.cols == m.rows);

  if (mat_set_dim(trace, m.rows, 1))
    for (i = 0; i < m.rows; i++)
      trace->data[i] = mat_val(m, i, i);
}
