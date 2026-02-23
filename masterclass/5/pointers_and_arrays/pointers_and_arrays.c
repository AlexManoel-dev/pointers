#include <stdio.h>

int main() {
  int a[5] = { 2, 4, 5, 8, 1 };

  // se passar apenas o array como endereço pro ponteiro, ele ja aponta para o primeiro elemento
  // só de usar o a ele já entende como &a[0]
  // se usar o &a ele lida com o array inteiro, e nao apenas o primeiro
  // nem precisa colocar num ponteiro, só de printar o a, ele já entende como o endereço do primeiro elemento
  // e se fizer a derreferência ele já aponta pro valor
  // pra pegar o endereço de um valor em específico, da pra fazer &a[i] ou apenas (a + i)
  // pra pegar o valor da pra fazer a[i] ou *(a + i)
  // o primeiro endereço do array é chamado de base address(endereço de base)

  // ADDRESS
  printf("array address: %p\n", a);
  printf("array address: %p\n", &a);
  printf("array address: %p\n", &a[0]);

  // VALUE
  printf("array first value: %d\n", a[0]);
  printf("array first value: %d\n", *a);

  // FOR
  for (int i = 0; i < 5; i++) {
    printf("address = %p\n", a + i);
    printf("address = %p\n", &a + i);
    printf("address = %p\n", &a[i]);
    printf("value = %d\n", a[i]);
    printf("value = %d\n", *(a + i));
  }
  
  // com ponteiro
  // a++ não da pra fazer, mas p++ da
  int *p = a;
  p++;

  printf("first value: %d\n", *p);
  
  return 0;
}