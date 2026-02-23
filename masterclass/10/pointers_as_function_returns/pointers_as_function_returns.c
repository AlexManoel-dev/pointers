#include <stdio.h>
#include <stdlib.h>

int *add(int *a, int *b);

int main() {
  int x = 2, y = 4;
  int *z = add(&x, &y);
  printf("sum = %d\n", *z);
  // free(z);
  
  return 0;
}

int *add(int *a, int *b) {
  int *c = (int *)malloc(sizeof(int));
  *c = *a + *b;
  return c;
  // int c = *a + *b;
  // return &c; // não da pra fazer isso porque ele retorna o endereço de uma variável do stackframe dessa função, ou seja, quando a função acabar, o ponteiro vai apontar pra lixo, pois a variável não vai existir mais
  // pode até funcionar se não chamais mais nada depois da função, mas aí é pura sorte, sorte do sistema não alocar ou apagar aquela região da memória e o valor ainda continuar lá
  // funciona ok se o valor estiver na memória heap ou global
}