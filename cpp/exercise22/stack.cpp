#include "stack.hpp"
#include <algorithm>
#include <iostream>

Stack& Stack::get_instance() {
  static Stack instance;
  return instance;
}

Stack::Stack() : stack_arr{}, stack_size(0) {
  stack_arr.fill(0);
  std::cout << "Stack initialized." << std::endl;
}
Stack::~Stack() { std::cout << "Stack destroyed." << std::endl; }

auto Stack::print() -> void {
  std::cout << "Stack elements: ";
  for (int i = 0; i < stack_size; i++) {
    std::cout << stack_arr[i] << " ";
  }
  std::cout << std::endl;
}

auto Stack::push(int value) -> bool {
  bool result{false};
  if (!is_full()) {
    stack_arr[stack_size] = value;
    stack_size++;
    result = true;
  } else {
    std::cout << "Stack is full" << std::endl;
    result = false;
  }
  return result;
}

auto Stack::get(int value) -> void {
  const int* it =
      std::find(stack_arr.begin(), stack_arr.begin() + stack_size, value);
  if (it == stack_arr.begin() + stack_size) {
    std::cout << "Value: " << value << " not found." << std::endl;
  } else {
    std::cout << "Value: " << *it << " found." << std::endl;
  }
}

auto Stack::pop() -> int {
  int result{-1};
  if (!is_empty()) {
    stack_size--;
    result = stack_arr[stack_size];
    stack_arr[stack_size] = 0;
  } else {
    std::cout << "Stack is empty" << std::endl;
  }
  return result;
}

auto Stack::is_full() -> const bool { return stack_size >= ARR_SIZE; }

auto Stack::is_empty() -> const bool { return stack_size == 0; }

auto Stack::clear() -> void {
  stack_arr.fill(0);
  stack_size = 0;
  std::cout << "Stack cleared" << std::endl;
}
