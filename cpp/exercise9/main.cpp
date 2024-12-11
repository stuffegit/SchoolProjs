#include <algorithm>
#include <array>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>

int main(void) {
  srand(time(NULL));
  std::array<int, 10> array;
  std::array<int, 10>* parr = &array;
  for (int i = 0; i < parr->size(); i++) {
    (*parr)[i] = (rand() % 99) + 1;
  }
  std::sort(std::begin(*parr), std::end(*parr));
  for (size_t i = 0; i < parr->size(); i++) {
    std::cout << (*parr)[i] << std::endl;
  }
  return 0;
}
