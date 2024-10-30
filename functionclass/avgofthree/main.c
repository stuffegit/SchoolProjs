#include <stdio.h>

int avg(int x, int y, int z);

int main(void) {
  (void)printf("%d\n", avg(4,5,6));
  return 0;
}

int avg(int x, int y, int z) {
  return (x+y+z)/3;
}
