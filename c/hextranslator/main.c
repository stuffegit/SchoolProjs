#include <stdio.h>

int main(void) {
  printf("Enter integer to translate it to hexadecimal.\n");
  int providedint = 0;
  scanf("%d", &providedint);
  printf("%#010x\n", providedint);
  return 0;
}
