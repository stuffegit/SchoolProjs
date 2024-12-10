#include <stdio.h>

int main(void) {
  int arr[5] = {1, 2, 3, 4, 5};
  int *parr = &arr[0];
  for (int i = 0; i < 5; i++) {
    printf("%d\n", *(parr+i));
  }
  for (int i = 0; i < 5; i++) {
    *(parr+i) = (i+1)*10;
  }
  for (int i = 0; i < 5; i++) {
    printf("%d\n", *(parr+i));
  }
  return 0;
}
