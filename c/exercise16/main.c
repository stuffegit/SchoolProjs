#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int compare (const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

int main(void) {
  srand(time(NULL));
  int arr[10];
  for (int i = 0; i < 10; i++) {
    arr[i] = rand() % 10;
  }
  for (int i = 0; i < 10; i++) {
    printf("%d", arr[i]);
  }
  printf("\n");
  qsort(arr, 10, sizeof(int), compare);
  for (int i = 0; i < 10; i++) {
    printf("%d", arr[i]);
  }
  printf("\n");
  return 0;
}
