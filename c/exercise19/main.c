#include <ctype.h>
#include <stdio.h>

int main() {
  char ch;
  printf("Enter sentence: ");
  while ((ch = getchar()) != '\n') {
    if (isalpha(ch)) {
      printf("%c", ch);
    } else if (isspace(ch)) {
      printf("\n");
    }
  }
  printf("\n");
  return 0;
}
