#include <stdio.h>

int count_digits(int n);
int power(int x, int y);

int main() {
  (void)printf("Number of digits: %d\n", count_digits(1234567));
  (void)printf("%d^%d = %d\n", 2, 3, power(2, 3));
  return 0;
}

int count_digits(int n) {
  if (n / 10 == 0) { // if n is only a single digit return 1
    return 1;
  }
  return 1 + count_digits(n / 10); // +1 for extra digit(cus of /10 operation)
}

int power(int x, int y) {
  if (y == 0) { // anything ^0 = 1
    return 1;
  }
  return x * power(x, y - 1); // breaks my brain but works."loops" until y=0
}
