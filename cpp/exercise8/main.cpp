#include <iostream>

int main(void) {
  int num{-1};
  while (num < 0 || num > 255) {
    std::cin >> num;
  }
  for (int i = 7; i >= 0; --i) {
    std::cout << ((num >> i) & 1);
  }
  std::cout << std::endl;
  return 0;
}
