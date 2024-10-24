#include <ctype.h>
#include <stdio.h>

int main(void)
{
  printf("Enter current time.\nFormat: YYYY-MM-DD HH:mm:ss");
  char datecheck[20];
  scanf("%c", datecheck);
  while ((datecheck = getchar()) != '\n') {
    if (isalpha(datecheck)) {
        putchar(datecheck);
      }
    } else if (isspace(datecheck) && !isspace(previous) && onlyonespace == 0) {
      putchar(' ');
    }
  }
  return 0;
}
