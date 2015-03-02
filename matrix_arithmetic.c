#include <assert.h>
#include "matrix.h"

/*
 *  set_mul: multiplies two matrices, stores the result in c
 *  c = a * b
 */
void
set_mul(matrix_t c, matrix_t a, matrix_t b)
{
  int i, j, k;
  assert(a.cols == b.rows);
  assert(c.rows == a.rows);
  assert(c.cols == b.cols);

  for (i = 0; i < a.rows; i++) {
    for (j = 0; j < b.cols; j++) {
      c.data[i*c.cols + j] = 0;
      for (k = 0; k < a.cols; k++) {
	c.data[i*c.cols + j] += a.data[i*a.cols + k] * b.data[k*b.cols+j];
      }
    }
  }
};

/*
 *  mul: multiplies two matrices, returns a * b
 */
matrix_t
mul(matrix_t a, matrix_t b)
{
  matrix_t c;

  c = new_matrix(a.rows, b.cols);
  set_mul(c, a, b);
  return c;
}

/*
 *  set_add: adds two matrices, stores the result in c
 */
void
set_add(matrix_t c, matrix_t a, matrix_t b)
{
  int i, j, idx;
  assert(c.rows == a.rows && c.rows == b.rows);
  assert(c.cols == a.cols && c.cols == b.cols);

  for (i = 0; i < c.rows; i++) {
    for (j = 0; j < c.cols; j++) {
      idx = i * c.cols + j;
      c.data[idx] = a.data[idx] + b.data[idx];
    }
  }
};

/*
 *  add: adds two matrix, returns the result a+b
 */
matrix_t
add(matrix_t a, matrix_t b)
{
  matrix_t c;

  c = new_matrix(a.rows, a.cols);
  set_add(c, a, b);
  return c;
};

/*
 *  set_sub: subtracts matrix b from matrix a, stores the result
 *  in c
 */
void
set_sub(matrix_t c, matrix_t a, matrix_t b)
{
  int i, j, idx;
  assert(c.rows == a.rows && c.rows == b.rows);
  assert(c.cols == a.cols && c.cols == b.cols);

  for (i = 0; i < c.rows; i++) {
    for (j = 0; j < c.cols; j++) {
      idx = i * c.cols + j;
      c.data[idx] = a.data[idx] - b.data[idx];
    }
  }
};

/*
 *  sub: subtracts matrix b from matrix a, returns the result a-b
 */
matrix_t
sub(matrix_t a, matrix_t b)
{
  matrix_t c;

  c = new_matrix(a.rows, a.cols);
  set_sub(c, a, b);
  return c;
}
