#include <stdio.h>

int sum_of_elements(int a[], int size);
void double_of_elements(int *a, int size);

int main() {
  int a[] = { 1, 2, 3, 4, 5 };
  // sizeof(array) retorna o tamanho em bytes
  // sizeof(array) / sizeof(array[0]) retorna o tamanho em bytes dividido pelo tamanho de cada elemento, entao podia ser sizeof(array) / sizeof(int) também
  int size = sizeof(a) / sizeof(a[0]);
  int total = sum_of_elements(a, size);
  double_of_elements(a, size);

  printf("total: %d\n", total);

  for (int i = 0; i < size; i++) {
    printf("doubled: %d\n", a[i]);
  }
  
  return 0;
}

// quando o array é passado como argumento, ele deixa de ser int a[] e passa a ser int *a
int sum_of_elements(int a[], int size) {
  int total;

  for (int i = 0; i < size; i++) {
    total += a[i];
  }

  return total;
};

void double_of_elements(int *a, int size) {
  int i, total;

  for (i = 0; i < size; i++) {
    a[i] = 2 * a[i];
  }
}