#include <cmath>
#include <iostream>

int main(int argc, const char* argv[]) {
  if (argc < 2) {
    std::cout << "No argument given\n";
    exit(1);
  }
  int input{std::stoi(argv[1])};

  if (input <= 0) {
    std::cout << "Need positive num\n";
    exit(1);
  }
  int prime = 1;
  for (int i = 2; i <= std::sqrt(input); i++) {
    if (!(input % i)) {
      std::cout << "Not prime." << std::endl;
      prime = 0;
      break;
    }
  }
  if (prime) {
    std::cout << "Prime." << std::endl;
  }
  return 0;
}
