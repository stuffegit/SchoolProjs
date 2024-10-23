#include <stdio.h>
int main() {
  printf("Printing 0 to 1000 where the last number is 7.\n");
  for (int i = 0; i < 1000; i++) {
    if (i % 10 == 7) {
      printf("%d ", i);
    }
  }
  printf("\n");
  return 0;
}
