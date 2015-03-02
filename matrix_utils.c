#include <stdlib.h>
#include <assert.h>
#include "matrix.h"

/*
 *  free_matrix: frees the memory which holds the matrix data.
 *  This does not free the rows or cols properties.
 */
void
free_matrix(matrix_t m)
{
  free(m.data);
};

/*
 *  new_matrix: allocates space for a 'rows'x'cols' matrix,
 *  returns a 'rows'x'cols' matrix with 'data' pointing
 *  to the allocated space
 */
matrix_t
new_matrix(size_t rows, size_t cols)
{
  matrix_t m;

  m.rows = rows;
  m.cols = cols;
  m.data = (float *) calloc(rows * cols, sizeof(float));
  return m;
};

/*
 *  new_identity_matrix: creates a new 'size'x'size' identity matrix
 */
matrix_t
new_identity_matrix(size_t size)
{
  int i;
  matrix_t m;

  m = new_matrix(size, size);
  for (i = 0; i < size; i++)
    m.data[i * size + i] = 1.0;
  return m;
};

/*
 *  e: returns a pointer to the matrix element at ('row','col')
 */
float *
e(matrix_t m, size_t row, size_t col)
{
  assert(row < m.rows);
  assert(col < m.cols);

  return &m.data[row * m.cols + col];
}

/*
 *  e_val: returns the value of the matrix element at ('row','col')
 */
float
e_val(matrix_t m, size_t row, size_t col)
{
  return *e(m, row, col);
}
