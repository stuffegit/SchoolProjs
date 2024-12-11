#include <iostream>
#include <array>

// using Matrix3x3 = std::array<std::array<int,3>,3>;   - this seems to be better

#define LEN 3

int main(int argc, char* argv[]) {
  std::cout << "enter num into matrix\n";
  std::array<std::array<int, LEN>, LEN> matrix;
  for (int i = 0; i < LEN; i++) {
    for (int j = 0; j < LEN; j++) {
      std::cin >> matrix[i][j];
    }
  }
  for (int i = 0; i < LEN; i++) {
    for (int j = 0; j < LEN; j++) {
      std::cout << matrix[i][j] << "\t";
    }
    std::cout << std::endl;
  }
  return 0;
}
