#include <stdio.h>

int checklength(char *p);

int main(void) {
  char string[] = "this string should be 37 without null";
  printf("Str length: %d\n", checklength(string));
  return 0;
}

int checklength(char *p) {
  int count = 0;
  while (*p != '\0') {
    count++;
    p++;
  }

  return count;
}
