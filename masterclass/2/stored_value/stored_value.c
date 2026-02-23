#include <stdio.h>
int main() {
  int a = 1025;
  int *p = &a;
  printf("size of integer is %zu\n", sizeof(int));
  printf("Address = %p, value = %d\n", p, *p);
  printf("Address = %p, value = %d\n", (p+1), *(p+1));

  // fazendo isso, o compilador vai entender que tem que ler 1 byte do endereço, porque char é apenas 1 byte, e o byte 0 de 1025 é 1
  // então de (byte3)00000000 (byte2)00000000 (byte1)00000100 (byte0)00000001, ele vai ler apenas (byte0)00000001
  char *p0 = (char *)p;
  printf("size of char is %zu\n", sizeof(char));
  printf("Address = %p, value = %d\n", p0, *p0);
  printf("Address = %p, value = %d\n", p0+1, *(p0+1));

  void *p1 = p;
  printf("Address = %p\n", p1);

  return 0;
} 