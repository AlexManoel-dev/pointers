#include <stdio.h>
#include <stdlib.h>

int main() {
  int *p; // stack
  p = (int *)malloc(sizeof(int)); // recebe o endereço da heap, e é tem o casting de int porque malloc retorna um ponteiro para void

  // o único jeito de usar a memória heap é através de referência por ponteiros
  *p = 10;

  // a memória alocada anteriormente é desalocada usando free()
  free(p);
  
  // agora aponta pra outro endereço, mas o endereço anterior ainda existe, a menos que use o free
  p = (int *)malloc(sizeof(int));

  *p = 20;

  // aloca a memória em quantidade de bytes int * 20
  int *arr = (int *)malloc(20 * sizeof(int));
  
  printf("malloc address: %p, and value: %d\n", p, *p);

  // se o malloc não achar espaço livre pra alocação, ele retorna NULL

  // FUNÇÕES MAIS USADAS
  // malloc, calloc, realloc, free
  // malloc - nao inicializa os endereços alocados, ainda possuem lixo
  // calloc - inicializa todos os valores alocados com 0
  // realloc - pega um bloco de memória já alocado e muda o tamanho, se quer aumentar, ele pega o que ja tem na memória a ser aumentada, e copia para uma área maior,
  // mas se tiver espaço ele apenas aumenta aquele bloco de memória, e se for diminuir, ele apenas desaloca a memória que precisa pra deixar menor,
  // e se o valor for zero, ele vai desalocar o bloco inteiro, o que seria o mesmo que usar free(), se o primeiro argumento for NULL, vai ser a mesma coisa que chamar o malloc,
  // já que vai estar tentando realocar um endereço, mas nao passou endereço, então vai alocar um novo
  int *c = calloc(3, 3 * sizeof(int));

  *c = 30;
  
  printf("calloc address: %p, and value: %d, and sizeof: %zu\n", c, *c, sizeof(c));

  int *r = realloc(c, 4 * sizeof(int));

  // passa o novo endereço ao c
  if(r != NULL) {
    c = r;
  }
  
  // ou continua usando o r mas libera o c
  // if (!r) {
  //   free(c);
  // }

  // c = NULL; // deixa claro que morreu

  int n;

  printf("Enter the size of array: ");
  scanf("%d", &n);
  // int a[n]; em compiladores novos funciona, mas para antigos é necessário alocar memória dinamicamente
  int *a = (int *)malloc(n * sizeof(int));
  printf("size of array: %zu\n", n * sizeof(int));

  for (int i = 0; i < n; i++) {
    a[i] = i + 1;
  }
  // usar free e depois usar o ponteiro da memória alocada, gera comportamento indefinido
  // free(a);
  // a = NULL; // reseta o ponteiro
  // int *b = (int *)realloc(a, (n / 2) * sizeof(int));
  // na maioria dos casos o endereço do realloc vai ser colocado no mesmo ponteiro
  // a = (int *)realloc(a, 2 * n * sizeof(int));
  int *b = (int *)realloc(a, 2 * n * sizeof(int));
  printf("Prev block address = %p, new address = %p\n", a, b);
  // for (int i = 0; i < n; i++) {
  for (int i = 0; i < 2 * n; i++) {
    printf("%d\n", b[i]);
  }
  
  return 0;
}