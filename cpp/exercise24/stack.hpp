#pragma once

#include <cstddef>

struct node_t {
  int value;
  node_t* next;
};

class stack_t {
public:
  explicit stack_t(int new_value);
  stack_t(const stack_t&);
  stack_t& operator=(const stack_t& other);
  ~stack_t();

  auto print() -> void;
  auto push(int new_value) -> bool;
  auto get(int get_value) -> bool;
  auto pop() -> int;
  auto is_full() -> const bool;
  auto is_empty() -> const bool;
  auto clear() -> void;

private:
  static constexpr std::size_t STACK_SIZE{10};
  std::size_t stack_size;
  node_t* first;

  void copy_nodes(const node_t* source);
  void delete_nodes();
};
