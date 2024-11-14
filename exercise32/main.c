#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef bool (*compare_t)(int, int);

void fillarr(int n, int *arr);
void printarr(int n, int *arr);
void swapints(int *a, int *b);
void sort_array(int *arr, int n, compare_t compare);
bool compare_asc(int a, int b);
bool compare_desc(int a, int b);

int main(void) {
  srand(time(NULL));
  int arr1[5] = {0, 0, 0, 0, 0};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  int a = 7;
  int b = 9;

  (void)printf("Initial values:\na: %d, b: %d\n", a, b);
  swapints(&a, &b);
  (void)printf("After swapping:\na: %d, b: %d\n\n", a, b);

  fillarr(n1, arr1);
  printarr(n1, arr1);
  sort_array(arr1, n1, compare_asc);
  printarr(n1, arr1);
  sort_array(arr1, n1, compare_desc);
  printarr(n1, arr1);
  return 0;
}

void fillarr(int n, int *arr) {
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 99 + 1;
  }
}

void printarr(int n, int *arr) {
  for (int i = 0; i < n; i++) {
    (void)printf("%d ", arr[i]);
  }
  (void)printf("\n");
}

void swapints(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void sort_array(int *arr, int n, compare_t compare) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (compare(arr[i], arr[j])) {
        swapints(&arr[i], &arr[j]);
      }
    }
  }
}

bool compare_asc(int a, int b) { return a > b; }
bool compare_desc(int a, int b) { return a < b; }
