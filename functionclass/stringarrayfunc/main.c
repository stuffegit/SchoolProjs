#include <stdio.h>

void checkstring();

int main(void) {
  checkstring();
  return 0;
}

void checkstring() {
  for (int ch; (ch = getchar()) != EOF;) {
    (void)printf("%c\n", ch);
  }  
  (void)printf("\n"); 
}
