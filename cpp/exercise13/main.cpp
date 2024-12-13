#include <cctype>
#include <iostream>

int main(void) {
  std::string input;
  const std::string* pinput = &input;
  std::cin >> input;
  for (auto letter : *pinput) {
    if (std::isupper(letter)) {
      std::cout << static_cast<char>(std::tolower(letter));
    } else if (std::islower(letter)) {
      std::cout << static_cast<char>(std::toupper(letter));
    } else {
      std::cout << letter;
    }
  }
  std::cout << std::endl;
  return 0;
}
