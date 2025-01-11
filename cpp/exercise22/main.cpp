#include "stack.hpp"
#include <cassert>
#include <iostream>

int main(void) {
  Stack& stack = Stack::get_instance();

  // Test push
  assert(stack.push(5) == true);
  stack.print();
  stack.get(6);
  stack.get(5);

  // Test push
  assert(stack.push(6) == true);
  stack.print();
  stack.get(6);
  stack.print();

  // Test pop
  int poppedValue = stack.pop();
  assert(poppedValue == 6);
  stack.print();

  // Test clear
  stack.clear();
  assert(stack.is_empty() == true);

  // Test is_full
  for (int i = 0; i < 10; ++i) {
    assert(stack.push(i) == true);
  }
  assert(stack.is_full() == true);
  assert(stack.push(11) == false);

  std::cout << "All tests passed!" << std::endl;

  return 0;
}
