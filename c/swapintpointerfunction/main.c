#include <stdio.h>

void swapints(int *x, int *y);

int main(void) {
  int x = 5;
  int y = 7;
  (void)printf("x = %d, y = %d\n", x, y);
  swapints(&x, &y);
  return 0;
}

void swapints(int *x, int *y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
  (void)printf("x = %d, y = %d\n", *x, *y);
}
