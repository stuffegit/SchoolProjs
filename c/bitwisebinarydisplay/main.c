#include <stdio.h>

void converttobinary(int x);

int main(void) {
  int decimal = 0;
  while (decimal == 0) {
    printf("Enter decimal between 0-255: ");
    scanf(" %d", &decimal);
    if (decimal < 0 || decimal > 255) {
      decimal = 0;
    }
  }
  converttobinary(decimal);
  return 0;
}

void converttobinary(int x) {
  while (x != 0) {
    if ((x & 1) == 1) {
      printf("1");
    } else {
      printf("0");
    }
    printf("\n");
    x = x >> 1;
  }
}
