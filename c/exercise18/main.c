#include <stdio.h>

#define SIZE 3

int main(void)
{
  int mat[SIZE][SIZE];
  for (int i = 0;i<SIZE;i++) {
    for (int ii = 0;ii<SIZE;ii++) {
      printf("mat[%d][%d]: ",i,ii);
      scanf("%d", &mat[i][ii]);
    }
  }
  for (int i = 0;i<SIZE;i++) {
    for (int ii = 0;ii<SIZE;ii++) {
      printf("%d\t",mat[i][ii]);
    }
    printf("\n");
  }
  return 0;
}
