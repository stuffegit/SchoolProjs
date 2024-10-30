/**
 * @file main.c
 * @brief
 * @author Christoffer Sundström
 * @date 2024-10-28
 */

#include <stdio.h>
#include <stdlib.h>

int check_leapyear(int year);
int validate_month(int month);
int validate_day(int year, int month, int day);
int validate_time(int hour, int minute, int second);
int parse_datetime(const char *input, int *year, int *month, int *day,
                   int *hour, int *minute, int *second);

int main(void) {
  char buffer[20];
  int year, month, day, hour, minute, second;

  printf("Enter date and time (YYYY-MM-DD HH:mm:ss): ");
  // read input from term - fgets is op
  if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
    if (parse_datetime(buffer, &year, &month, &day, &hour, &minute, &second) !=
        6) {
      printf("Invalid input format. Please use YYYY-MM-DD HH:mm:ss.\n");
      return 1;
    }
  } else {
    printf("Error reading input.\n");
    return 1;
  }

  // Validate the month, day, time
  if (!validate_month(month)) {
    printf("Invalid month.\n");
    return 1;
  }
  if (!validate_day(year, month, day)) {
    printf("Invalid day for the given month and year.\n");
    return 1;
  }
  if (!validate_time(hour, minute, second)) {
    printf("Invalid time.\n");
    return 1;
  }

  // if all checks pass
  printf("Valid date and time: %d-%02d-%02d %02d:%02d:%02d\n", year, month, day,
         hour, minute, second);

  return 0;
}

// check if the year is a leap year
int check_leapyear(int year) {
  if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
    return 1; // Leap
  } else {
    return 0; // Not leap
  }
}

// validate the month
int validate_month(int month) {
  if (month >= 1 && month <= 12) {
    return 1;
  }
  return 0;
}

// validate leap year
int validate_day(int year, int month, int day) {
  const int days_in_month[12] = {31, 28, 31, 30, 31, 30,
                                 31, 31, 30, 31, 30, 31};
  int max_days = days_in_month[month - 1];

  // fix Feb for leap year
  if (month == 2 && check_leapyear(year)) {
    max_days = 29;
  }

  if (day >= 1 && day <= max_days) {
    return 1;
  }
  return 0;
}

// validate the time
int validate_time(int hour, int minute, int second) {
  if (hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59 && second >= 0 &&
      second <= 59) {
    return 1;
  }
  return 0;
}

// parse date and time from the input string -> returns amount of items
// soufiens gonna hate this mess
int parse_datetime(const char *input, int *year, int *month, int *day,
                   int *hour, int *minute, int *second) {
  return sscanf(input, "%d-%d-%d %d:%d:%d", year, month, day, hour, minute,
                second);
}
