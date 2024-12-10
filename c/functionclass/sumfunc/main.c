#include <stdio.h>

int foo(int x, int y);

int main(void) {
  (void)printf("%d\n", foo(5,7));
  return 0;
}

int foo(int x, int y) {
  return (x+y);
}
