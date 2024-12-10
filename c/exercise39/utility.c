#include "utility.h"
#include <assert.h>
#include <ctype.h>
#include <string.h>

int get_gcd(int num1, int num2) {
  assert(num1 > 0 && num2 > 0);
  int gcd = 0;
  if (num1 > num2) {
    gcd = num1;
  } else if (num2 > num1) {
    gcd = num2;
  }
  assert(gcd > 0);
  while (num1 % gcd != 0 || num2 % gcd != 0) {
    // printf("n1 %d, n2 %d, gcd %d\n", num1, num2, gcd);
    gcd--;
  }
  assert(num1 % gcd == 0 && num2 % gcd == 0);
  return gcd;
}
int get_lcm(int num1, int num2) {
  assert(num1 > 0 && num2 > 0);
  int lcm1 = 1;
  int lcm2 = 1;

  while (1) {
    while ((num1 * lcm1) > (num2 * lcm2)) {
      lcm2++;
    }
    while ((num2 * lcm2) > (num1 * lcm1)) {
      lcm1++;
    }
    if ((num1 * lcm1) == (num2 * lcm2)) {
      break;
    }
  }
  assert((num1 * lcm1) == (num2 * lcm2));
  return ((num1 * lcm1) + (num2 * lcm2)) / 2;
}
void sort_string(char* str) {
  assert(str != NULL);
  int len = 0;
  while (str[len] != '\0') {
    len++;
  }

  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      assert(i < len && j < len);
      if (tolower((unsigned char)str[i]) > tolower((unsigned char)str[j])) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
      }
    }
  }
  assert(str[len] == '\0');
}
