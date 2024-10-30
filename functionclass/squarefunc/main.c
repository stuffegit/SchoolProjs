#include <stdio.h>

int sqr(int x);

int main(void) {
  (void)printf("%d\n", sqr(4));
  return 0;
}

int sqr(int x) {
  return x*x;
}
