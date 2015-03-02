#include <stdio.h>
#include "matrix.h"

main()
{
  matrix_t a, b, c;

  a = new_identity_matrix(2);
  b = new_matrix(2, 1);
  b.data[0] = 1.0;
  b.data[1] = 2.0;

  c = mul(a, add(b, b));
  //  c = add_matrix(c, a);
  //  add_matrix(c, a, b);
  printf("a\n");
  print_matrix(a);
  printf("b\n");
  print_matrix(b);
  printf("c = a * b\n");
  print_matrix(c);
}
