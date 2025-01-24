/**
 * @file    test.cpp
 * @author  Christoffer Sundström
 * @date    23 January 2025
 * @brief   Tests a circular buffer
 *          using a fixed size array.
 *
 * @desc    This test.cpp file holds all tests
 *          cbuffer.hpp will have functions that constructs,
 *          deconstructs, and handles the buffer.
 *
 *          Supports following features:
 *          - Writing data to the buffer.
 *          - Reading(dequeing) data.
 *          - Getting the capacity of the buffer.
 *          - Getting the current amount of elements in buffer.
 *          - Clearing the buffer.
 *
 **/
#include "cbuffer.hpp"
#include <cassert>

template <typename T> bool tests(T& cbuffer) {
  bool result{false};
  std::cout << cbuffer << std::endl;
  for (int i = 0; i < cbuffer.get_capacity() + 3; i++) {
    assert(cbuffer.write_data(i + 1));
    std::cout << cbuffer << std::endl;
  }
  for (int i = 0; i < cbuffer.get_capacity() - 2; i++) {
    assert(cbuffer.read_data());
    std::cout << cbuffer << std::endl;
  }
  std::cout << "Amount of elements: " << cbuffer.get_data_count() << std::endl;
  std::cout << "Clearing buffer" << std::endl;
  cbuffer.clear();
  std::cout << cbuffer << std::endl;
  std::cout << "Amount of elements: " << cbuffer.get_data_count() << std::endl;
  result = true;
  return result;
}

int main(void) {
  cbuffer_t<int, 4> cbuffer_int;
  // cbuffer_t<float, 5> cbuffer_float;
  // cbuffer_t<double, 6> cbuffer_double;
  assert(tests(cbuffer_int));
  // assert(tests(cbuffer_float));
  // assert(tests(cbuffer_double));
  return 0;
}
