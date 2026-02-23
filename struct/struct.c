#include <stdio.h>
#include <stdlib.h>

// tipos maiores primeiro, melhor otimização, e flexible arrays ou ponteiros por último
struct OnlyStruct {
  unsigned char values[100];
  int data;
  unsigned char bytes[];
};

// tipos maiores primeiro, melhor otimização, e flexible arrays ou ponteiros por último
typedef struct StructWithTypedef {
  unsigned char values[100];
  int data;
  unsigned char bytes[];
} StructWithTypedef;

int main(int argc, char** argv) {
  printf("Quantidade de argumentos: %d\n", argc);
  printf("Argumentos: %s\n", argv[1]);

  size_t size = sizeof(struct OnlyStruct) + 100;
  struct OnlyStruct only_struct;
  only_struct.data = 10;
  printf("OnlyStruct data: %d\n", only_struct.data);

  struct OnlyStruct *ptr_only_struct = malloc(size);
  // ptr_only_struct = &only_struct;
  ptr_only_struct->bytes[0] = 0x90;
  printf("ptr_only_struct data: %d\n", ptr_only_struct->data);
  printf("ptr_only_struct bytes: 0x%02X\n", ptr_only_struct->bytes[0]);

  StructWithTypedef struct_with_type;
  struct_with_type.data = 20;
  printf("StructWithTypedef data: %d\n", struct_with_type.data);

  return 0;
}