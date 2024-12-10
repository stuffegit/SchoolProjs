#include <stdio.h>

int main() {
  typedef struct {
    int day;
    int month;
    int year;
  } date_t;

  date_t date = {0};
  printf("Enter current year,month,day: ");
  scanf("%d, %d, %d", &date.year, &date.month, &date.day);
  printf("\n%d-%d-%d\n", date.year, date.month, date.day);
  return 0;
}
