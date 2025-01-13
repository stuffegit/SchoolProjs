#pragma once

#include <cstddef>

struct node_t {
  std::size_t value;
  node_t* next;
};

class queue_t {
  node_t* top;
  std::size_t queuesize;

  // helper func for deconstruct+reset_queue()
  auto clear() -> void {
    while (top != nullptr) {
      node_t* tmp = top;
      top = top->next;
      delete tmp;
    }
  }

public:
  explicit queue_t(std::size_t new_value)
      : top(new node_t{new_value, nullptr}), queuesize(1) {}
  queue_t(const queue_t&) = delete;
  queue_t& operator=(const queue_t& other) = delete;
  ~queue_t() { clear(); }

  // simple func
  auto reset_queue() -> void {
    clear();
    queuesize = 0;
    top = nullptr;
  }
  auto get_elems() -> std::size_t { return queuesize; }

  // forward declare
  auto enqueue(std::size_t new_value) -> std::size_t;
  auto dequeue() -> std::size_t;
};
