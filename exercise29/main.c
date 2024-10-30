#include <stdint.h>
#include <stdio.h>

void printprimes(int min, int max);

int main(void) {
  uint32_t m = 13, n = 51;
  printprimes(m, n);
  return 0;
}

void printprimes(int min, int max) {
  for (int i = min; i <= max; i++) {
    int count = 0;
    for (int ii = 2; ii <= i / 2; ii++) {
      if (i % ii == 0) {
        count++;
        break;
      }
    }
    if (count == 0 && i > 1) {
      (void)printf("%d\n", i);
    }
  }
}
