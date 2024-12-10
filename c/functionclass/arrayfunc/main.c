#include <stdio.h>

void checkprime(int x);

int main(void) {
  checkprime(3);
  return 0;
}

void checkprime(int x) {
  int count = 0;

  for (int i = x; i > 0; i--) {
    if (x % i == 0) {
      count++;
    }
  }

  if (count <= 2) {
    (void)printf("Prime.\n");
  } else {
    (void)printf("Not prime.\n");
  }
}
