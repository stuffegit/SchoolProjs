#pragma once
#include <array>

class Stack {
public:
  Stack();
  Stack(const Stack&) = default;
  ~Stack();

  auto print() -> void;
  auto push(int value) -> bool;
  auto get(int value) -> void;
  auto pop() -> int;
  auto is_full() -> const bool;
  auto is_empty() -> const bool;
  auto clear() -> void;

private:
  static constexpr std::size_t ARR_SIZE{10};
  std::array<int, ARR_SIZE> stack_arr;
  std::size_t stack_size;
};
