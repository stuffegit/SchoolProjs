#include <stdio.h>

typedef struct {
  int age;
  float height;
  char name[16];
} person_t;

person_t get_person(void);

int main(void) {
  person_t person = get_person();
  (void)printf("\nStruct content:\nAge: %d\nHeight: %.2f\nName: %s\n",
               person.age, person.height, person.name);
  return 0;
}

person_t get_person(void) {
  person_t person1 = {0};
  (void)printf("Fill in age\n");
  scanf("%d", &person1.age);
  (void)printf("Fill in height\n");
  scanf("%f", &person1.height);
  (void)printf("Fill in name\n");
  scanf("%15s", person1.name);
  return person1;
}
