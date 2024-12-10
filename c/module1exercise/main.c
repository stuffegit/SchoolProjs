#include "module.h"
#include <stdio.h>

int main(void) {
  char *string1 = "String";
  char *string2 = "String";
  char *string3 = "Stringc";

  printf("String Length comparison:\n");
  if (CompareStrLen(string1, string2)) {
    printf("str1 == str2\n");
  }
  if (CompareStrLen(string1, string3)) {
    printf("str1 == str3\n");
  }

  printf("String Content comparison:\n");
  if (CompareStrContent(string1, string2)) {
    printf("str1 == str2\n");
  }
  if (CompareStrContent(string1, string3)) {
    printf("str1 == str3\n");
  }
  return 0;
}
