#include <stdbool.h>
#include <stdio.h>

int check_leapyear(int year);

int main(void) {
  int year = 4;
  const int calendar[12][2] = {{1, 31},   // jan - 31
                               {2, 28},   // feb - 28
                               {3, 31},   // mar - 31
                               {4, 30},   // apr - 30
                               {5, 31},   // may - 31
                               {6, 30},   // jun - 30
                               {7, 31},   // jul - 31
                               {8, 31},   // aug - 31
                               {9, 30},   // sep - 30
                               {10, 31},  // oct - 31
                               {11, 30},  // nov - 30
                               {12, 31}}; // dec - 31

  for (int i = 0; i < 12; i++) {
    for (int ii = 0; ii < 2; ii++) {
      printf("%d\t", calendar[i][ii]);
    }
    printf("\n");
  }

  if (check_leapyear(year)) {
    printf("\nLeapyear.\n");
  } else {
    printf("\nNot leapyear.\n");
  }
  return 0;
}

int check_leapyear(int year) {
  if (year % 4 == 0) {
    return 1;
  } else {
    return 0;
  }
};
