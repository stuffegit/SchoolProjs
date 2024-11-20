#include "arraysort.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
  printf("Arr1 test\n");
  int arr1[9] = {1, 3, 5, 7, 9, 2, 4, 6, 8};

  checkarrsort(arr1, sizeof(arr1) / sizeof(arr1[0]));
  arrsort(arr1, sizeof(arr1) / sizeof(arr1[0]));
  checkarrsort(arr1, sizeof(arr1) / sizeof(arr1[0]));

  printf("\nArr2 test\n");
  int arr2[9] = {2, 3, 3, 7, 4, 2, 4, 3, 3};

  checkarrsort(arr2, sizeof(arr2) / sizeof(arr2[0]));
  arrsort(arr2, sizeof(arr2) / sizeof(arr2[0]));
  checkarrsort(arr2, sizeof(arr2) / sizeof(arr2[0]));
  return 0;
}
