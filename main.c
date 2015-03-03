#include <stdio.h>
#include "matrix.h"

main()
{
  matrix_t a, b, c;
  a = mat_new(0, 0);
  b = mat_new(0, 0);
  c = mat_new(0, 0);
  mat_ones(&a, 1, 100);
  mat_randu(&b, 100, 9);
  mat_mult(&c, a, b);
  mat_scale(&c, 1.0/100.0);
  
  printf("a:\n");
  print_matrix(c);
  printf("b:\n");
  print_matrix(b);
}
