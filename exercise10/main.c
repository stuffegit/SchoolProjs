#include <stdio.h>

int main(void) {
  int x = 0;
  printf("Enter num between 0-255 to translate into binary.\n");
  do {
    scanf("%d", &x);
    if (x > 255 || x < 0) {
      printf("Out of range.\n");
    }
  } while (x > 255 || x < 0);
  printf("%0b\n", x);
  return 0;
}
