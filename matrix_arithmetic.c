#include <assert.h>
#include "matrix.h"

/*
 *  mult_matrix: multiplies two matrices, stores the result in c
 *  c = a * b
 */
void
set_mult_matrix(matrix_t c, matrix_t a, matrix_t b)
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
 *  mult_matrix: multiplies two matrices, returns a * b
 */
matrix_t
mult_matrix(matrix_t a, matrix_t b)
{
  matrix_t c;

  c = new_matrix(a.rows, b.cols);
  set_mult_matrix(c, a, b);
  return c;
}

/*
 *  add_matrix: adds two matrices, stores the result in c
 */
void
set_add_matrix(matrix_t c, matrix_t a, matrix_t b)
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
 *  sub_matrix: subtracts matrix b from matrix a, stores the result
 *  in c
 */
void
set_sub_matrix(matrix_t c, matrix_t a, matrix_t b)
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
}
