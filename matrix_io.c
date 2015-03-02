#include <stdio.h>
#include "matrix.h"

/*
 *  print_matrix: prints a matrix to stdout
 */
void
print_matrix(matrix_t m)
{
  int i, j;

  for (i = 0; i < m.rows; ++i) {
    for (j = 0; j < m.cols; ++j) {
      printf("%8.4f", m.data[i*m.cols + j]);
    }
    printf("\n");
  }
};
