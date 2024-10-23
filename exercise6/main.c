#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

int main(){
  srand(time(NULL));
  char var;
  scanf("%c", &var);
  var = toupper(var);
  printf("%c\n", var);
  int randy = rand();
  printf("%d\n", randy);
  randy = rand();
  printf("%d\n", randy);
  return 0;
}
