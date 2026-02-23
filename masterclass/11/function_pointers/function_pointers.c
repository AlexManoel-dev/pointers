#include <stdio.h>

int add(int a, int b);

int main() {
  /** 
    sobre apontar para funções, a stack armazena o endereço de retorno(próxima instrução após a chamada da função), portanto não é o endereço da função,
    mas no sentido em que preciso apontar para uma função, o ponteiro aponta para o endereço da INSTRUÇÃO da função da seção .text/.code
  */
  // sem typedef
  int c;
  int (*p)(int, int);
  p = &add;
  // funciona sem o &
  // p = add;
  c = (*p)(2,3);
  // funciona somente o nome do ponteiro da função
  // c = p(2,3);
  printf("first value: %d\n", c);

  // com typedef
  int c2;
  typedef int (*pFunc)(int, int);
  pFunc pVar = &add;
  // funciona sem o &
  // pFunc pVar = add;
  c2 = pVar(1,2);
  printf("second value: %d\n", c2);

  /**
    sobre funções de dll, o SO carrega a dll e retorna o endereço em runtime para o ponteiro
  */
  
  return 0;
}

int add(int a, int b) {
  return a  + b;
}