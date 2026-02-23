#include <stdio.h>
#include <string.h>

void print(char c[]);

int main() {
  // o tamanho de um array que vai guardar uma string deve ser a quantidade de caracteres + 1, sendo o 1 o terminador nulo

  // null terminator fica implícito, e não da pra criar a variável e depois atribuir o valor, tem que ser diretamente na criação da variável
  char literal[] = "JOHN";
  printf("Size in bytes = %zu\n", sizeof(literal));

  // separado por vírgula
  char separated[5] = { 'J', 'O', 'H', 'N', '\0' };

  char c[5];
  c[0] = 'J';
  c[1] = 'O';
  c[2] = 'H';
  c[3] = 'N';
  c[4] = '\0';
  int len = strlen(c);

  printf("%s\n", c);
  printf("Length = %d\n", len);

  // arrays e ponteiros são coisas diferentes, porém usados de formas similares
  char c1[] = "Hello";
  char *c2;

  c2 = c1;

  // c2[i] is *(c2 + i)
  // c1[i] or *(c2 + i)

  // NÃO FUNCIONA
  // c1 = c2;
  // c1 = c1 + 1;
  // c1++;

  
  // FUNCIONA
  c2++;

  // array sempre é passado por referência

  char c3[20] = "Hello"; // armazenado na stack
  print(c3);
  printf("random null character in the array: %d\n", c3[18]); // 0, porque é o caracter nulo

  char *const_literal = "Hello"; // armazenado na seção text como const, e é ímutável
  //const_literal[0] = 'A'; // imutável

  return 0;
}

// void print(const char *c) {
void print(char c[]) {
  // int i = 0;
  // while (c[i] != '\0') {
  // dessa forma o código também funciona, porque o c[] está sendo tratado como um ponteiro char *c
  // e com o ponteiro pode-se fazer c++, aí vai vendo caracter por caracter se ele é o '\0' via derreferẽncia
  while (*c != '\0') {
    printf("%c", *c);
    c++;
  }

  printf("\n");
}