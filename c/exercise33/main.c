#include <stdio.h>

int main(void) {
  double moves = (1ULL << 63) * 2 - 1; // 2^64-1 | ULL to handle giga number
  double seconds_in_a_year = 31536000; // 60sec * 60min * 24hrs * 365days
  double years = moves / seconds_in_a_year;
  printf("Moves: %.0f\n", moves);
  printf("Years: %.0f\n", years);
  return 0;
}
