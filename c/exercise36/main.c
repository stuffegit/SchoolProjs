#include <inttypes.h> // uint8_t
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char* name;
  uint8_t age;
} person_t;

int main(void) {
  printf("Enter length of array: ");
  int len;
  scanf("%d", &len);

  person_t structarray[len];
  for (int i = 0; i < len; i++) {
    structarray[i].name = malloc(50 * sizeof(char)); // allocate 50 chars to name
    if (structarray[i].name == NULL) {               // check if name is empty after alloc
      printf("Memory allocation failed\n");
      return 1;
    }
    printf("Enter name for struct %d: ", i + 1);
    scanf(" %49s", structarray[i].name);
    printf("Enter age for struct %d: ", i + 1);
    scanf(" %" SCNu8, &structarray[i].age); // uint8_t + <inttypes.h> lib
  }

  for (int i = 0; i < len; i++) { // prints out values
    printf("Struct %d name %s\n", i + 1, structarray[i].name);
    free(structarray[i].name);
    printf("Struct %d age %u\n", i + 1, structarray[i].age); // %u for unsigned
  }
  return 0;
}
