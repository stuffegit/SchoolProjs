#include <stdio.h>

#define matX 2
#define matY 3

int main(void)
{
  int mat[matX][matY];
  int *pmat = &mat[0][0];
  for (int i = 0;i<matX;i++) {
    for (int ii = 0;ii<matY;ii++) {
      printf("mat[%d][%d]: ",i,ii);
      scanf("%d", &pmat[i*matY+ii]);
    }
  }
  for (int i = 0;i<matX;i++) {
    for (int ii = 0;ii<matY;ii++) {
      printf("%d\t",pmat[i*matY+ii]);
    }
    printf("\n");
  }
  return 0;
}
