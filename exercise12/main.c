#include <stdio.h>

int main(void) {
  printf("Enter positive number: \n");
  int num = 0;
  int total = 0;
  scanf("%d", &num);
  if (num >= 0) {
    do {
      if (num % 2 == 0) {
        total = total + num;
      }
      num--;
    } while (num > 0);
    printf("Sum of your number and all lower numbers: %d\n", total);
  }
  return 0;
}
