#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Employee {
    char name;
    float DA;
    float basesalary;
} Employee;

int calcgross(float pay, float bonus);
int calcda(float pay, float bonus);

int main(void) {
  srand(time(NULL));
  struct Employee employee[50];

  for (int i = 0; i < 50; i++) {
    employee[i].name = 'a';
    employee[i].DA = 1.52;
    employee[i].basesalary = (rand() % 1000) + 10000;
  }
  for (int i = 0; i < 50; i++) {
    printf("Name: %c ", employee[i].name);
    printf("DA: %d ", calcda(employee[i].basesalary, employee[i].DA));
    printf("Base Salary: %.0f ", employee[i].basesalary);
    printf("Gross Salary: %d\n ",
           calcgross(employee[i].basesalary, employee[i].DA));
  }
  return 0;
}

int calcgross(float pay, float bonus) { return pay * bonus; }
int calcda(float pay, float bonus) { return pay * (bonus - 1); }
