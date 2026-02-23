#include <stdio.h>

int main() {
  // aloca memoria pro x e escreve o 5
  int x = 5;
  // aloca memoria pro ponteiro e escreve o endereço
  int *p = &x;
  *p = 6;
  // aloca memoria pro ponteiro do ponteiro e escreve o endereço de p
  int **q = &p;
  // aloca memoria pro ponteiro do ponteiro do ponteiro e escreve o endereço de q
  int ***r = &q;

  printf("X address: %p\n", &x);
  printf("P - X address: %p\n", p);
  printf("P dereference: %d\n", *p);
  printf("Q - P address: %p\n", q);
  printf("Q - X address: %p\n", *q);
  printf("Q dereference: %d\n", **q);
  // guarda o endereço de Q
  printf("R - Q address: %p\n", r);
  // guarda o endereço de P
  printf("R - P address: %p\n", *r);
  // guarda o endereço de X
  printf("R - X address: %p\n", **r);
  printf("R dereference: %d\n", ***r);
}