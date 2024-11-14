#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 8

void fillarr(int n, int *arr);
void printarr(int n, int *arr);
void printmatrix(int c, int r, int (*marr)[r]);

int main(void) {
  srand(time(NULL));
  int arr1[LEN];
  int arr2[2][3] = {{8, 2, 0}, {2, 5, 4}};
  fillarr(LEN, arr1);
  printarr(LEN, arr1);
  (void)printf("\n");
  printmatrix(2, 3, arr2);
  return 0;
}

void fillarr(int n, int *arr) {
  for (int i = 0; i < n; i++) {
    *(arr + i) = rand() % 99 + 1;
  }
}
void printarr(int n, int *arr) {
  for (int i = 0; i < n; i++) {
    (void)printf("%d ", *(arr + i));
  }
  (void)printf("\n");
}
void printmatrix(int c, int r, int (*marr)[r]) {
  for (int i = 0; i < c; i++) {
    for (int ii = 0; ii < r; ii++) {
      (void)printf("%d ", marr[i][ii]);
    }
    (void)printf("\n");
  }
}
