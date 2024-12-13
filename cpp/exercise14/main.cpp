#include "arrmgr.hpp"
#include <array>
#include <cstdlib>
#include <ctime>

int main(void) {
  srand(time(NULL));
  std::array<int, LEN> arr;
  for (int i = 0; i < arr.size(); i++) {
    arr[i] = rand() % 100;
  }
  return 0;
}
