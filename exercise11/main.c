#include <ctype.h>
#include <stdio.h>

int main() {
  char ch, previous = ' ';
  int firstletter = 1;
  int onlyonespace = 0;
  printf("Enter your full name: ");
  while ((ch = getchar()) != '\n') {
    if (isalpha(ch)) {
      if (firstletter) {
        putchar(toupper(ch));
        firstletter = 0;
      } else {
        putchar(tolower(ch));
      }
      previous = ch;
    } else if (isspace(ch) && !isspace(previous) && onlyonespace == 0) {
      putchar(' ');
      firstletter = 1;
      previous = ch;
      onlyonespace = 1;
    }
  }
  printf("\n");
  return 0;
}
