#include <stdio.h>

int main() {
  int a;
  int *p;
  // ponteiros não podem ser usados antes de serem inicializados
  p = &a;
  a = 5;

  // printf é uma função variádica, que basicamente significa que ela não sabe quantos argumentos vão ser passados
  printf("p - same address: %p\n", (void *)p);
  printf("&a - same address: %p\n", (void *)&a);
  printf("&p: %p\n", (void *)&p);
  printf("sizeof(p): %zu\n", sizeof(p));
  // dereferencing, basicamente o ato de recuperar o valor de onde o ponteiro aponta, e não o endereço
  printf("*p: %d\n", *p);
  // num contexto hipotetico, se o endereço é 2002, o + 1 vai fazer com que o endereço serja 2006, porque o tipo int tem 4 bytes
  // (void*)p + 1	anda 1 byte (GCC trata como char*)
  // (void*)(p + 1)	anda sizeof(int) bytes
  // p + 1	anda sizeof(int) bytes
  printf("pointer plus one: %p\n", (void *)(p + 1));
  printf("value at pointer plus one: %d\n", *(p + 1));
}