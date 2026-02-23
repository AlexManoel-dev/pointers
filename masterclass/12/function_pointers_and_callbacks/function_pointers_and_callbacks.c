#include <stdio.h>
#include <stdlib.h>

void a();
void b(void (*ptr)());
void bubble_sort(int a[], int n, int (*compare)(int,int));
int compare(int a, int b);
int absolute_compare(int a, int b);
int qsort_compare(const void *a, const void *b);

int main() {
  // ponteiros de função podem ser passados como argumento para funções,
  // e então a função que receberia um ponteiro de função como argumento poderia fazer uma callback com essa função que o ponteiro aponta
  // b(a); // funciona normalmente, pois o nome da função já retorna um ponteiro
  // o fato de chamar uma função através de um ponteiro pra função, dentro de OUTRA função como argumento, se chama callback
  void (*p)() = a;
  b(p);

  // EXEMPLO COM COMPARE SIMPLES
  int i, a[] = {3, 2, 1, 5, 6, 4};
  bubble_sort(a, 6, compare);
  for(i = 0; i < 6; i++) printf("%d ", a[i]);
  printf("\n");
  // for(i = 0; i < 6; i++) {
  //   if(i == 6 - 1) {
  //     printf("%d\n", a[i]);
  //   } else {
  //     printf("%d ", a[i]);
  //   }
  // }

  // EXEMPLO COM ABS
  int j, b[] = {-31, 22, -1, 50, -6 ,4};
  bubble_sort(b, 6, absolute_compare);
  for(j = 0; j < 6; j++) printf("%d ", b[j]);
  printf("\n");

  // EXEMPLO COM QSORT
  int k, c[] = {-31, 22, -1, 50, -6 ,4};
  qsort(c, 6, sizeof(int), qsort_compare);
  for(k = 0; k < 6; k++) printf("%d ", c[k]);
  printf("\n");
}

void a() {
  printf("Hello\n");
}

void b(void (*ptr)()) {
  ptr();
}

// 0 - decreasing
// 1 - encreasing
// a função callback deve comparar 2 valores inteiros, deve retornar 1 se o primeiro elemento é maior, 0 se os elementos são iguais, e -1 se o segundo elemento é maior
void bubble_sort(int a[], int n, int (*compare)(int, int)) {
  int i, j, temp;
    for (i = 0; i < n; i++) {
      for (j = 0; j < n - 1; j++) {
        // if (a[j] > a[j + 1]) {
        if (compare(a[j], a[j + 1]) > 0) {
          temp = a[j];
          a[j] = a[j + 1];
          a[j + 1] = temp;
        }
      }
    }
}

// é possível escolher se a ordem é crescente ou decrescente ao mudar os valores que retorna
// se quiser decrescente, deixe o primeiro return como -1 e o segundo como 1
int compare(int a, int b) {
  if(a > b) return 1;
  else return -1;
}

int absolute_compare(int a, int b) {
  if(abs(a) > abs(b)) return 1;
  else return -1;
}

int qsort_compare(const void *a, const void *b) {
  int c = *((int *)a);
  int d = *((int *)b);
  
  return c - d;
}