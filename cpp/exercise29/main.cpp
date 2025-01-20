#include <iostream>
#include <type_traits>

template <typename T> float map(T value, T minvalue, T maxvalue, float minrange, float maxrange) {
  static_assert(std::is_arithmetic<T>::value, "Value must be an arithmetic type.");
  float returnvalue{0};
  if (minvalue < 0) {
    value += (minvalue * -1);
    maxvalue += (minvalue * -1);
    minvalue = 0;
  }
  returnvalue = // surely theres a more sane way to handle this
      (static_cast<float>(value) / static_cast<float>(maxvalue)) * (maxrange - minrange);

  return returnvalue;
}

int main(void) {
  std::cout << map(0.5f, 0.0f, 3.3f, 0, 1023) << std::endl;      // example case
  std::cout << map(-2.5f, -3.0f, 3.3f, -50, 1023) << std::endl;  // neg-floats to mess with code
  std::cout << map(-2, -3, 3, -50, 1023) << std::endl;           // neg-ints to mess with code
  std::cout << map(-2.0, -3.0, 3.0, -50.0, 1023.0) << std::endl; // neg-doubles to mess with code
  return 0;
}
