#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int guess = 0;
  int game = 1;
  char tryagain = 'y';
  int guesses = 1;
  while (1) {
    srand(time(NULL));
    int r = rand() % 100;
    guesses = 1;
    printf("******************************************\n");
    printf("************** Game Started **************\n");
    printf("******************************************\n");
    while (game) {
      printf("%d)Guess a number [0, 99]:", guesses);
      guesses++;
      scanf("%d", &guess);
      if (guess == r) {
        printf("Correct. Number was: %d\n", r);
        game = 0;
      } else if (guess > r) {
        printf("Too high.\n");
      } else if (guess < r) {
        printf("Too low.\n");
      }
      if (guesses > 10) {
        printf("Out of attempts.\n");
        game = 0;
      }
    }
    printf("Do you want to try again?");
    scanf(" %c", &tryagain);
    if (tryagain != 'y') {
      return 0;
    }
    game = 1;
  }
  return 0;
}
