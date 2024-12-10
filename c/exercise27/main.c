#include <stdio.h>

#define LEN 10

int find_lar_in_arr(int x[LEN]);
int find_avg_in_arr(int x[LEN]);
int find_val_in_arr(int x[LEN], int val);

int main(void) {
  int arr[LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  (void)printf("%d\n%d\n%d\n", find_lar_in_arr(arr), find_avg_in_arr(arr),
               find_val_in_arr(arr, 7));
  return 0;
}

int find_lar_in_arr(int x[LEN]) {
  int output = 0;
  for (int i = 0; i < LEN; i++) {
    if (x[i] > output) {
      output = x[i];
    }
  }
  return output;
}

int find_avg_in_arr(int x[LEN]) {
  int output = 0;
  for (int i = 0; i < LEN; i++) {
    output = output + x[i];
  }
  return output / LEN;
}

int find_val_in_arr(int x[LEN], int val) {
  for (int i = 0; i < LEN; i++) {
    if (x[i] == val) {
      return i;
    }
  }
  return -1;
}
