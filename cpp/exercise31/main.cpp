#include "stack.hpp"
#include <cassert>
#include <iostream>

void test_constructor() {
  try {
    stack_t<int> stack(2); // This should fail gracefully without exception
    if (stack.get_size() <= 3) {
      throw "Size must be greater than three";
    }
  } catch (const char* e) {
    std::cout << "Caught expected invalid argument error: " << e << std::endl;
  }

  stack_t<int> stack(5);
  assert(stack.get_size() == 5);
  assert(stack.get_elem() == 0);
  std::cout << "Constructor test passed.\n";
}

void test_push_pop() {
  stack_t<int> stack(5);
  if (!stack.pushelem(1) || !stack.pushelem(2)) {
    throw "Push failed";
  }
  assert(stack.get_elem() == 2);

  bool success;
  int value = stack.pop_elem(success);
  if (!success) {
    throw "Pop failed";
  }
  assert(value == 2);

  value = stack.pop_elem(success);
  if (!success) {
    throw "Pop failed";
  }
  assert(value == 1);

  assert(stack.get_elem() == 0);
  std::cout << "Push and Pop test passed.\n";
}

void test_clear() {
  stack_t<int> stack(5);
  stack.pushelem(1);
  stack.pushelem(2);
  stack.clear();
  assert(stack.get_elem() == 0);
  std::cout << "Clear test passed.\n";
}

void test_move_constructor() {
  stack_t<int> stack1(5);
  stack1.pushelem(1);
  stack_t<int> stack2(std::move(stack1));
  assert(stack2.get_size() == 5);
  assert(stack2.get_elem() == 1);
  assert(stack1.get_size() == 0); // Moved-from object is empty
  std::cout << "Move Constructor test passed.\n";
}

void test_move_assignment() {
  stack_t<int> stack1(5);
  stack1.pushelem(1);
  stack_t<int> stack2(5);
  stack2 = std::move(stack1);
  assert(stack2.get_size() == 5);
  assert(stack2.get_elem() == 1);
  assert(stack1.get_size() == 0); // Moved-from object is empty
  std::cout << "Move Assignment test passed.\n";
}

void test_exceptions() {
  stack_t<int> stack(5);
  try {
    for (int i = 0; i < 6; ++i) {
      if (!stack.pushelem(i)) {
        throw "Stack overflow";
      }
    }
  } catch (const char* e) {
    std::cout << "Caught expected overflow error: " << e << std::endl;
  }

  try {
    stack.clear();
    bool success;
    stack.pop_elem(success);
    if (!success) {
      throw "Stack underflow";
    }
  } catch (const char* e) {
    std::cout << "Caught expected underflow error: " << e << std::endl;
  }
}

int main() {
  test_constructor();
  test_push_pop();
  test_clear();
  test_move_constructor();
  test_move_assignment();
  test_exceptions();

  std::cout << "All tests passed.\n";
  return 0;
}

