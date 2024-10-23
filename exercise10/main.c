#include <stdio.h>

int main(void) {
  int num = 0;
  do {
    printf("Enter a number between 0 - 255\n");
    scanf("%d", &num);
    if (num > 255) {
      printf("Too high number.\n");
    } else if (num < 0) {
      printf("Too low number.\n");
    }
  } while (num < 0 || num > 255);
  printf("Binary of %d = %b\n", num, num);
  return 0;
}
