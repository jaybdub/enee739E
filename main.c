#include <stdio.h>
#include "matrix.h"

main()
{
  matrix_t a, b;

  a = new_matrix(2, 1);
  b = new_identity_matrix(10);
  copy(&a, b);
  scale(&a, 25);
  zeros(&b, 25, 5);
  scale(&b, 13.4);

  printf("b:\n");
  print_matrix(b);
  printf("a:\n");
  print_matrix(a);
}
