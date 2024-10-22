#include <stdio.h>
#define MINNUMBER 2     // Arbituary min value
#define MAXNUMBER 10000 // Arbituary max value
int main(void) {
  int isthisprime = 0;
  int successfuldivisions = 0;
  while (1) {
    printf("Enter a number in the range of 2 - 10,000.\n");
    scanf("%d", &isthisprime);
    if (isthisprime > MAXNUMBER) {
      printf("Number is too high.\n");
      return 1;
    } else if (isthisprime < MINNUMBER) {
      printf("Number is too low.\n");
      return 1;
    }
    for (int i = 1; i <= isthisprime; i++) {
      if (isthisprime % i == 0) {
        successfuldivisions++;
      }
    }
    if (isthisprime == 2) {
      printf("Not prime. Divisions: %d\n", successfuldivisions);
    } else if (successfuldivisions > 2) {
      printf("Not prime. Divisions: %d\n", successfuldivisions);
    } else {
      printf("Prime! Divisions: %d\n", successfuldivisions);
    }
    successfuldivisions = 0;
  };
  return 0;
}
