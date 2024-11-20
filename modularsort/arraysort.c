#include <assert.h>
#include <stdio.h>

void arrsort(int* arr1, const int arrlen) {
  assert(*arr1);
  assert(arrlen);
  int sorter;
  for (int i = 0; i < arrlen; i++) {
    for (int ii = 0; ii < arrlen; ii++) {
      if (arr1[ii] > arr1[i]) {
        sorter = arr1[i];
        arr1[i] = arr1[ii];
        arr1[ii] = sorter;
      }
    }
  }
}

void checkarrsort(const int* arr1, const int arrlen) {
  assert(*arr1);
  assert(arrlen);
  int is_sorted = 1;
  for (int i = 0; i < arrlen - 1; i++) {
    if (arr1[i] > arr1[i + 1]) {
      is_sorted = 0;
    }
  }
  if (is_sorted) {
    printf("Is sorted\n");
  } else {
    printf("Not sorted\n");
  }
}
