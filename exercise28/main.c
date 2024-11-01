#include <stdio.h>
#include <string.h>

int compare_string(char *str1, char *str2);

int main(void) {
  (void)printf("Enter two strings: \n");
  char string1[16];
  char string2[16];
  scanf("%15s", string1);
  scanf("%15s", string2);
  (void)printf("Result = %d\n", compare_string(string1, string2));
  return 0;
}

int compare_string(char *str1, char *str2) {
  int output = 0;
  if (strcmp(str1, str2) == 0) {
    output = 1;
  } else {
    output = 0;
  }
  return output;
}
