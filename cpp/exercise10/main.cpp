#include <array>
#include <cstdlib>
#include <ctime>
#include <iostream>

using matrix2x3_t = std::array<std::array<int, 2>, 3>;

int main(void) {
  srand(time(NULL));
  matrix2x3_t matrix;
  matrix2x3_t* pmat = &matrix;
  for (int i = 0; i < pmat->size(); i++) {
    for (int j = 0; j < (*pmat)[i].size(); j++) {
      (*pmat)[i][j] = (rand() % 99) + 1;
    }
  }
  for (int i = 0; i < pmat->size(); i++) {
    for (int j = 0; j < (*pmat)[i].size(); j++) {
      std::cout << (*pmat)[i][j] << "\t";
    }
    std::cout << std::endl;
  }
  return 0;
}
