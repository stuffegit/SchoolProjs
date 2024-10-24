#include <ctype.h>
#include <stdio.h>

int main() {
  printf("Enter string: ");
  char ch;
  char *pch = &ch;
  while ((*pch = getchar()) != '\n') {
    if (isalpha(*pch)) {
      if (isupper(*pch)) {
        putchar(tolower(*pch));
      } else {
        putchar(toupper(*pch));
      }
    } else if (isspace(*pch)) {
      putchar(' ');
    }
  }
  printf("\n");
  return 0;
}
