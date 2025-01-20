#include "template.hpp"
#include <array>

template <typename T> void (*fprint_array)(T[], int) = print_array;

int main() {
  std::array<int, 5> arr{1, 2, 3, 4, 5};
  fprint_array<int>(arr.data(), arr.size());
  return 0;
}
