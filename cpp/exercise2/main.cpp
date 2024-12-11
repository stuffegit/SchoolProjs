#include <iostream>

int main() {
  int num{};
  while (1) {
    std::cout << "Enter num between 0-255:\n";
    std::cin >> num;
    if (num >= 0 && num <= 255) {
      break;
    }
  }
  std::cout << std::hex << "Num is: " << num << std::endl;
  return 0;
}
