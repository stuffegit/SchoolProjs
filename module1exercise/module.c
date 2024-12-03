#include "module.h"

int CompareStrLen(char *str1, char *str2) {
  int i = 0;

  char x = 0;
  while (*(str1 + x) != '\0') {
    x++;
  }
  char y = 0;
  while (*(str2 + y) != '\0') {
    y++;
  }
  if (x == y) {
    i = 1;
  }
  return i;
}

int CompareStrContent(char *str1, char *str2) {
  int same = 1;
  if (CompareStrLen(str1, str2)) {
    int i = 0;
    while (*(str1 + i) != '\0' || *(str2 + i) != '\0') {
      if (*(str1 + i) != *(str2 + i)) {
        same = 0;
      }
      i++;
    }
  } else {
    same = 0;
  }
  return same;
}
