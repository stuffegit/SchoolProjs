#include <stdio.h>
#include <string.h>

int main(void) {
  printf("Enter word to be reversed.\n");
  char carr[20] = "A";
  char rcarr[20] = "A";
  const char len = strlen(carr);
  scanf("%s", &carr);
  printf("%d\n", len);
  for (int i = 0;i < len;++i) {
    rcarr[i] = carr[i];
    printf("%s\n", carr);
    printf("%s\n", rcarr);
  }
  printf("%s - %s\n", carr, rcarr);
  return 0;
}
