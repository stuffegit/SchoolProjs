#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
  char line[256];
  char* word = argv[1];

  FILE* file = fopen("text.txt", "r");
  if (!file) {
    printf("fopen(); error\n");
  } else {
    while (fgets(line, sizeof(line), file)) {
      if (strstr(line, word) != NULL) {
        printf("%s", line);
      }
    }
  }
  return 0;
}
