#include <algorithm>
#include <cstdlib>
#include <array>
#include <ctime>
#include <iostream>

int main(int argc, char* argv[]) {
  srand(time(NULL));
  std::array<int, 10> arr;
  for (int i = 0; i < arr.size(); i++) {
    arr[i] = (rand() % 99) + 1;
  }
  std::sort(std::begin(arr), std::end(arr));
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << std::endl;
  }
  return 0;
}
