#include <stdio.h>
#include "matrix.h"

main()
{
  matrix_t a, b, c;

  a = new_identity_matrix(2);
  b = new_matrix(2, 2);
  b.data[0] = 1.0;
  b.data[1] = 2.0;
  b.data[2] = 3.0;
  b.data[3] = 4.0;

  c = mult_matrix(b, b);
  //  sub_matrix(c, a, b);
  //  add_matrix(c, a, b);
  printf("a\n");
  print_matrix(a);
  printf("b\n");
  print_matrix(b);
  printf("c = a * b\n");
  printf("%f\n", *ele(b, 1, 1));
}
