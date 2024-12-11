#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(int argc, char* argv[]) {
  srand(time(NULL));
  std::cout << "Enter lowercase char\n";
  char ltr;
  std::cin >> ltr;
  std::cout << static_cast<char>(std::toupper(ltr)) << std::endl;
  std::cout << "Rand1: " << rand() << std::endl;
  std::cout << "Rand2: " << rand() << std::endl;
  return 0;
}
