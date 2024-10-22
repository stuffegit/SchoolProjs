#include <stdio.h>

int main() {
  int arr[10][10];
  for (int i = 0; i < 10; ++i) {
    for (int ii = 0; ii < 10; ++ii) {
      arr[i][ii] = ii;
    }
  }

  for (int i = 0; i < 10; ++i) {
    for (int ii = 0; ii < 10; ++ii) {
      printf("%d ", arr[i][ii]);
    }
    printf("\n");
  }
  return 0;
}
