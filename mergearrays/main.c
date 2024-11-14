#include <stdio.h>

void sortarr(int *arr, int n);
void mergearr(int *arr1, int n1, int *arr2, int n2, int *arr3);
void printarr(int *arr, int n);

int main(void) {
  int arr1[] = {1, 2, 3, 6, 1, 2, 5, 6, 7, 8, 5, 3, 1};
  int arr2[] = {3, 2, 1, 5, 8, 2, 4};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  int arr3[n1 + n2];
  printarr(arr1, n1);
  printarr(arr2, n2);
  printf("\n");
  sortarr(arr1, n1);
  sortarr(arr2, n2);
  mergearr(arr1, n1, arr2, n2, arr3);
  return 0;
}

void sortarr(int *arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int ii = 0; ii < n - i - 1; ii++) {
      if (arr[ii] > arr[ii + 1]) {
        int temp = arr[ii];
        arr[ii] = arr[ii + 1];
        arr[ii + 1] = temp;
      }
    }
  }
  printarr(arr, n);
}
void printarr(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
void mergearr(int *arr1, int n1, int *arr2, int n2, int *arr3) {
  for (int i = 0; i < n1; i++) {
    arr3[i] = *(arr1 + i);
  }
  for (int i = 0; i < n2; i++) {
    arr3[n1 + i] = *(arr2 + i);
  }
  sortarr(arr3, n1 + n2);
}
