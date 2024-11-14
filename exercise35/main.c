#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void printprimes(int prime);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    (void)printf("%s <number>\n", argv[0]);
    return 1;
  }
  int arg_as_int = (int)atoi(argv[1]);
  if (arg_as_int < 1) {
    (void)printf("Enter a positive integer greater than 0\n");
    return 1;
  }
  printprimes(arg_as_int);
  return 0;
}

void printprimes(int prime) {
  int count = 0;
  for (int i = 2; i * i <= prime; i++) {
    if (prime % i == 0) {
      count++;
      break;
    }
  }
  if (count == 0 && prime > 1) {
    (void)printf("Prime\n");
  } else {
    (void)printf("Not prime\n");
  }
}
