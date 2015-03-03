#include <assert.h>
#include "matrix.h"

/*
 *  set_mul: multiplies two matrices, stores the result in c
 *  c = a * b
 */
void
mul(matrix_t *c, matrix_t a, matrix_t b)
{
  int i, j, k;
  assert(a.cols == b.rows);
  assert(set_dim(c, a.rows, b.cols));

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
add(matrix_t *c, matrix_t a, matrix_t b)
{
  int i, j, idx;
  assert(a.cols == b.cols && a.rows == b.rows);
  assert(set_dim(c, a.rows, b.cols));

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
sub(matrix_t *c, matrix_t a, matrix_t b)
{
  int i, j, idx;
  assert(a.cols == b.cols && a.rows == b.rows);
  assert(set_dim(c, a.rows, b.cols));

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
emul(matrix_t *c, matrix_t a, matrix_t b)
{
  int i, j, idx;
  assert(a.cols == b.cols && a.rows == b.rows);
  assert(set_dim(c, a.rows, b.cols));

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
ediv(matrix_t *c, matrix_t a, matrix_t b)
{
  int i, j, idx;
  assert(a.cols == b.cols && a.rows == b.rows);
  assert(set_dim(c, a.rows, b.cols));

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
scale(matrix_t *m, float scalor)
{
  int i, lim;

  lim = m->rows * m->cols;
  for (i = 0; i < lim; i++)
    m->data[i] *= scalor;
}
