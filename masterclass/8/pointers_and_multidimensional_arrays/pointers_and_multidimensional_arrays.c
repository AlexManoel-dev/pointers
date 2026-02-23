#include <stdio.h>

void Func(int (*a)[3]);

int main() {
  int b[2][3] = { // 2 arrays de 3 int cada, b[0] é um array e b[1] é outro array
    {2, 3, 6},
    {4, 5, 8}
  };

  printf("sizeof(b): %zu\n", sizeof(b)); // 24 bytes, int é 4, cada array tem 3, existem 2 arrays, portanto 12 + 12 = 24 bytes

  // b + 1 é a mesma coisa que &b[1]
  // *(b + 1) = b[1] = &b[1][0]
  // *(b + 1) = b[1] + 2 = &b[1][2]
  // b[i][j] = *(b[i] + j) = *(*(b + i) + j)
  printf("%-9s %p\n", "b + 1:", (void *)(b + 1)); // mostra o começo do segundo array, dado o fato de que o + 1, move o ponteiro 1 tamanho de array de 3 int, que da 12 em bytes

  int *p = b[1]; // aponta para &b[1][0]

  // como cada array é um int[3], o b decai pra int[3], que é o tipo de &b[0], e b = &b[0], por isso o ponteiro abaixo funciona
  int (*ptr)[3] = b; // b = &b[0], *b = b[0] = &b[0][0]

  // (void *) porque o %p não precisa saber o tipo de nada, ele só quer ler o endereço do ponteiro
  // hoje em dia da pra printar o ponteiro sem o (void *), mas dependendo do sistema, não
  printf("%-9s %p\n", "b:",        (void *)b);        // endereço do primeiro array, retorna um ponteiro para um array int[3]
  printf("%-9s %p\n", "&b[0]:",    (void *)&b[0]);    // endereço do primeiro array
  printf("%-9s %p\n", "*b:",       (void *)*b);       // endereço do PRIMEIRO elemento do PRIMEIRO array, retorna um ponteiro para um int
  printf("%-9s %p\n", "b[0]:",     (void *)b[0]);     // endereço do PRIMEIRO elemento do PRIMEIRO array
  printf("%-9s %p\n", "&b[0][0]:", (void *)&b[0][0]); // endereço do PRIMEIRO elemento do PRIMEIRO array
  printf("%-9s %d\n", "*(*b + 1):", *(*b + 1));
  printf("%-9s %d\n", "*(b[0] + 1):", *(b[0] + 1));

  // b[i][j] é o mesmo que *(b[i] + j) que basicamente pega o array especificado em i, o elemento em j fazendo aritmética com o ponteiro b[i] de depois derreferenciando,
  // que também pode ser representado por *(*(b + i) + j)

  // é um grupo de 3 blocos, onde dentro de cada bloco, tem mais 2 blocos de 2 elementos,
  // então pra acessar o primeiro valor de todos, é c[0][0][0]
  int c[3][2][2] = {
    2, 5,   // primeiro bloco do primeiro blocão
    7, 9,   // segundo bloco do primeiro blocão

    3, 4,   // primeiro bloco do segundo blocão
    6, 1,   // segundo bloco do segundo blocão

    0, 8,   // primeiro bloco do terceiro blocão
    11, 13  // segundo bloco do terceiro blocão
  };

  // *c == c[0] == &c[0][0]
  // *(c[0][1] + 1) == c[0][1][1]
  // *(c[1] + 1) == c[1][1] == &c[1][1][0]

  printf("%p %p %p %p\n", c, *c, c[0], &c[0][0]);

  Func(b);

  return 0;
}

// void Func(int (*a)[2][2]) {
// void Func(int a[][2][2]) {
// void Func(int (*a)[3]) {
// em função assim que chamam arrays multidimensionais, não faz sentido usar ponteiros de ponteiros, tem que ser dessa forma que está feito aqui, ou as comentadas
void Func(int a[][3]) {
  
}