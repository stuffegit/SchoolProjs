#include <iostream>

int main(void) {
  int num{};
  while (1) {
    std::cout << "Enter positive int:\n";
    std::cin >> num;
    if (num >= 0) {
      break;
    }
  }
  int total{0};
  for (int i = 0; i < num + 1; i++) {
    if (!(i % 2)) {
      total += i;
    }
  }
  std::cout << num << " and even lower numbers summed to " << total << std::endl;
  return 0;
}
