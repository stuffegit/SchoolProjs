#include <stdio.h>

int main(void) {
  int x = 1;
  int *y = &x;
  int **z = &y;
  printf("using y\nval of x: %d\nadr of y: %p\n\n", *y, y);
  printf("using z\nadr of y: %p\nadr of z: %p\n", *z, z);
  return 0;
}
