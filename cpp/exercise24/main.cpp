#include "stack.hpp"
#include <cassert>
#include <iostream>

bool test_push(stack_t& stack) {
  stack.push(6);
  return stack.get(6);
}

bool test_pop(stack_t& stack) {
  std::cout << "pop value: " << stack.pop() << std ::endl;
  return !stack.get(6);
}

bool test_is_full(stack_t& stack) {
  for (int i = 0; i < 10; ++i) {
    stack.push(i);
  }
  stack.is_full();
  return !stack.push(11);
}

int main(void) {
  stack_t stack(5);

  std::cout << "Testing push." << std::endl;
  assert(test_push(stack));

  std::cout << "Testing pop." << std::endl;
  assert(test_pop(stack));

  std::cout << "Testing is_full." << std::endl;
  assert(test_is_full(stack));

  std::cout << "All tests passed!" << std::endl;

  return 0;
}
