#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 10

void fillarr(int x[LEN]);
void printarr(int x[LEN]);

int main(void) {
  srand(time(NULL));
  int arr[LEN] = {0};
  fillarr(arr);
  printarr(arr);
  return 0;
}

void fillarr(int x[LEN]) {
  for (int i = 0; i < LEN; i++) {
    x[i] = rand() % (99) + 1;
  }
}

void printarr(int x[LEN]) {
  for (int i = 0; i < LEN; i++) {
    (void)printf("%d ", x[i]);
  }
  (void)printf("\n");
}
