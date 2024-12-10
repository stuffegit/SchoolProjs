#include "utility.h"
#include <stdio.h>

int main(void) {
  int num1 = 4;
  int num2 = 12;
  char string1[] = "HeLloWorld";
  printf("Greatest Common divisor of %d and %d is %d\n", num1, num2, get_gcd(num1, num2));
  printf("Least Common multiple of %d and %d is %d\n", num1, num2, get_lcm(num1, num2));
  printf("Sorting the string: \"%s\"", string1);
  sort_string(string1);
  printf(" in alphabetical order: \"%s\"\n", string1);
  return 0;
}
