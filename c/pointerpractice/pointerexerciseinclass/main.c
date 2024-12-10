#include <stdio.h>

int main(void) {
  const int x=10;
  const int *p = &x;
  printf("val of x: %d\nadr of x: %p\nval of p's target: %d\n", x, &x, *p);
  return 0;
}
