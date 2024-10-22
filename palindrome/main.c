#include <stdio.h>
#include <string.h>

int main() {
  const char palincheck[] = "ABBA";
  const char len = strlen(palincheck);
  int true = 0;
  for (int i = 0; i < len/2; ++i) {
    if (palincheck[i] == palincheck[len - i - 1]) {
      true ++;
    }
  }
  if (true == len/2) {
    printf("\nPalindrome = true.\nTrue var = %d/%d\n", true, len/2);
  }else {
    printf("\nPalindrome = false.\nTrue var = %d/%d\n", true, len/2);
  }
  return 0;
}
