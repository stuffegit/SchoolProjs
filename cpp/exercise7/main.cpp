#include <cstdlib>
#include <ctime>
#include <iostream>

int main(int argc, char* argv[]) {
  srand(time(NULL));
  int choice{};
  while (1) {
    int win{0};
    int num{(rand() % 99) + 1};
    int count{0};
    while (count <= 10) {
      int guess{0};
      printf("Guess num: \n");
      std::cin >> guess;
      if (guess == num) {
        win = 1;
        break;
      }
      if (guess > num) {
        std::cout << "Too high!\n";
      } else {
        std::cout << "Too Low!\n";
      }
      count++;
    }
    if (win) {
      std::cout << "Correct guess!\n";
    } else {
      std::cout << "Ran out of guesses.\n";
    }
    std::cout << "Want to play again? Y/N\n";
    std::cin >> choice;
    if (choice == 'y' or choice == 'Y') {
      continue;
    } else {
      break;
    }
  }
  return 0;
}
