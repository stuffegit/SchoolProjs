#include <stdio.h>

int main(void) {
  int rows = 0;
  printf("Enter rows: ");
  scanf("%d", &rows);
  int align = rows;
  for (int i = -1; i < rows * 2; i += 2) {
    for (int ii = 0; ii < align; ++ii) {
      printf(" ");
    }
    for (int iii = 0; iii < i; ++iii) {
      printf("*");
    }
    printf("\n");
    align--;
  }
  for (int i = 0; i < rows - 1; ++i) {
    printf(" ");
  }
  printf("*\n");
  for (int i = 0; i < rows - 1; ++i) {
    printf(" ");
  }
  printf("*\n");
  for (int i = 0; i < rows - 1; ++i) {
    printf(" ");
  }
  printf("*\n");
  return 0;
}
