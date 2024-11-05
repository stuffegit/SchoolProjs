#include <stdio.h>

void printarr(int arr[8], int n);
void sortarr(int arr[8], int n);

int main(void) {
  int arr[8] = {8, 3, 5, 2, 9, 2, 4, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Unsorted array: ");
  printarr(arr, n);
  sortarr(arr, n);
  printf("Sorted array: ");
  printarr(arr, n);
  return 0;
}

void printarr(int arr[8], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d", arr[i]);
  }
  printf("\n");
}

void sortarr(int arr[8], int n) {
  int temp;
  for (int i = 0; i < n - 1; i++) {
    for (int y = 0; y < n - i - 1; y++) {
      if (arr[y] > arr[y + 1]) {
        int temp = arr[y];
        arr[y] = arr[y + 1];
        arr[y + 1] = temp;
      }
    }
  }
}
