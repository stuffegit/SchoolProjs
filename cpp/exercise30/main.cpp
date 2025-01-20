
#include "stack.hpp"
#include <iostream>
#include <cassert>

template <typename T> auto test(stack_t<T>& stack) -> bool {
  assert(stack.push(1) && "Failed to push to the stack");
  assert(stack.push(2) && "Failed to push to the stack");
  assert(stack.push(3) && "Failed to push to the stack");

  stack.print();
  std::cout << "Number of elements: " << stack.get_elements() << std::endl;
  std::cout << "popped: " << stack.pop() << std::endl;
  std::cout << "Number of elements: " << stack.get_elements() << std::endl;
  stack.clear();
  std::cout << "Number of elements after clear: " << stack.get_elements() << std::endl;
  return true;
}

int main() {
  stack_t<int> stack_int(10);
  stack_t<float> stack_float(10);

  std::cout << "-------------------Testing stack_t<int>:" << std::endl;
  test(stack_int);
  std::cout << "-------------------Testing stack_t<float>:" << std::endl;
  test(stack_float);

  return 0;
}
