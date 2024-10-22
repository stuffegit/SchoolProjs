#include <stdio.h>
#include <string.h>

int main(void) {
  char p1move[8];
  char p2move[8];
  printf("rock - paper - scissors!\n");
  printf("Enter Player 1 value: ");
  scanf("%s", p1move);
  printf("Enter Player 2 value: ");
  scanf("%s", p2move);

  printf("P1: %s, P2: %s\n", p1move, p2move);

  if (!strcmp(p1move, "rock")) {
    if (!strcmp(p2move, "rock")) {
      printf("Draw.\n");
    } else if (!strcmp(p2move, "paper")) {
      printf("P2 win, Paper > Rock\n");
    } else if (!strcmp(p2move, "scissors")) {
      printf("P1 win, Rock > Scissors\n");
    } else {
      printf("idk gl brother\n");
    }
  } else if (!strcmp(p1move, "paper")) {
    if (!strcmp(p2move, "rock")) {
      printf("P1 win, Paper > Rock\n");
    } else if (!strcmp(p2move, "paper")) {
      printf("Draw.\n");
    } else if (!strcmp(p2move, "scissors")) {
      printf("P2 win, Scissors > Paper\n");
    } else {
      printf("idk gl brother\n");
    }
  } else if (!strcmp(p1move, "scissors")) {
    if (!strcmp(p2move, "rock")) {
      printf("P2 win, Rock > Scissors\n");
    } else if (!strcmp(p2move, "paper")) {
      printf("P1 win, Scissors > Paper\n");
    } else if (!strcmp(p2move, "scissors")) {
      printf("Draw.\n");
    } else {
      printf("idk gl brother\n");
    }
  } else {
    printf("idk gl brother\n");
  }

  return 0;
}
