#include <stdio.h>

int main(void)
{
  struct person {
    char name[20];
    int age;
  };

  struct person student = {"Carl", 32};
  struct person *p = &student;
  printf("%s\n", p->name);
  printf("%d\n", p->age);
  return 0;
}
