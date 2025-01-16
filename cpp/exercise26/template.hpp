#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>

template <typename T> void print_array(T arr, int length) {
  for (size_t i = 0; i < length; i++) {
    std::cout << arr[i] << "\t";
  }
  std::cout << std::endl;
}

#endif // TEMPLATE_HPP
