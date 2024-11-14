#include <stdio.h>
#include <stdlib.h>

#define READ_NUM 5
#define WRITE_NUM 10
#define STRING "Hello World!\n"

int main(void) {
  FILE *file = fopen("text.txt", "w");
  if (!file) {
    (void)printf("Failed to open the file!\n");
    exit(1);
  }

  for (int i = 0; i < WRITE_NUM; i++) {
    if (EOF == fputs(STRING, file)) {
      (void)fclose(file);
      (void)printf("Failed to write to the file!\n");
      exit(1);
    }
  }

  if (fclose(file)) {
    (void)printf("Failed to close the file!\n");
    exit(1);
  }

  file = fopen("text.txt", "r");
  if (!file) {
    (void)printf("Failed to open the file!\n");
    exit(1);
  }

  for (int i = 0; i < READ_NUM; i++) {
    char buffer[sizeof(STRING)] = {0};
    if (!fgets(buffer, sizeof(STRING), file)) {
      (void)fclose(file);
      (void)printf("Failed to read from the file!\n");
      exit(1);
    }
    (void)printf("%s", buffer);
  }

  if (fclose(file)) {
    (void)printf("Failed to close the file!\n");
  }

  return 0;
}
