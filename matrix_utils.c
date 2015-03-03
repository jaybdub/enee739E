#include <stdlib.h>
#include <assert.h>
#include "matrix.h"

/*
 *  free_matrix: frees the memory which holds the matrix data.
 *  This does not free the rows or cols properties.
 */
void
mat_free(matrix_t m)
{
  free(m.data);
};

/*
 *  new_matrix: allocates space for a 'rows'x'cols' matrix,
 *  returns a 'rows'x'cols' matrix with 'data' pointing
 *  to the allocated space
 */
matrix_t
mat_new(size_t rows, size_t cols)
{
  matrix_t m;

  m.rows = rows;
  m.cols = cols;
  m.data = (float *) calloc(rows * cols, sizeof(float));
  return m;
};

/*
 *  set_dim: set the dimension of the matrix 'm' to 'rows'x'cols'.  If
 *  the amount of memory used by the matrix is not changed, reallocation
 *  is not performed.  Returns 1 if matrix is successful, 0 otherwise
 */
int
mat_set_dim(matrix_t *m, size_t rows, size_t cols)
{
  if (m->rows == rows && m->cols == cols) {
    /* dimensions are consistent, do nothing */
    return 1;
  } else if (m->rows * m->cols == rows * cols) {
    /* data storage size is consistent, adjust dimensions */
    m->rows = rows;
    m->cols = cols;
    return 1;
  } else {
    /* data storage size is inconsistent, realloc space & adjust dimensions */
    if ((m->data = (float *) realloc(m->data, sizeof(float) * rows * cols))
	!= NULL) {
      m->rows = rows;
      m->cols = cols;
      return 1;
    }
  }
  return 0;
}

/*
 *  copy: copies data from one matrix to another. 'to' will be forced to
 *  have same dimensions as 'from'
 */
void
mat_copy(matrix_t *to, matrix_t from)
{
  int i, lim;
  
  mat_set_dim(to, from.rows, from.cols);

  /* copy data */
  lim = from.rows * from.cols;
  for (i = 0; i < lim; i++)
    to->data[i] = from.data[i];
}

/*
 *  e: returns a pointer to the matrix element at ('row','col')
 */
float *
mat_ele(matrix_t m, size_t row, size_t col)
{
  assert(row < m.rows);
  assert(col < m.cols);

  return &m.data[row * m.cols + col];
}

/*
 *  e_val: returns the value of the matrix element at ('row','col')
 */
float
mat_val(matrix_t m, size_t row, size_t col)
{
  return *mat_ele(m, row, col);
}
