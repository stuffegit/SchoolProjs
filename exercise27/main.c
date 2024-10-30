#include <stdio.h>

#define LEN 10

int find_lar_in_arr(int x[LEN]);
int find_avg_in_arr(int x[LEN]);
int find_val_in_arr(int x[LEN], int val);

int main(void) {
  int arr[LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  (void)printf("%d\n", find_lar_in_arr(arr));
  (void)printf("%d\n", find_avg_in_arr(arr));
  (void)printf("%d\n", find_val_in_arr(arr, 7));
  return 0;
}

int find_lar_in_arr(int x[LEN]) {
  int temp = 0;
  for (int i = 0; i < LEN; i++) {
    if (x[i] > temp) {
      temp = x[i];
    }
  }
  return temp;
}

int find_avg_in_arr(int x[LEN]) {
  int temp = 0;
  for (int i = 0; i < LEN; i++) {
    temp = temp + x[i];
  }
  return temp / LEN;
}

int find_val_in_arr(int x[LEN], int val) {
  for (int i = 0; i < LEN; i++) {
    if (x[i] == val) {
      return i;
    }
  }
  return -1;
}
