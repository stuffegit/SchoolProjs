#include <stdio.h>

static void func2(int *x) { *x = 20; }

int main() {
  int var = 2;

  func2(&var); 
  printf("Value of var is %d\n", var); 
  return 0;
}
