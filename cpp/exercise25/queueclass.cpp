#include "queueclass.hpp"
#include <iostream>

auto queue_t::enqueue(std::size_t new_value) -> std::size_t {
  node_t* new_node{new node_t{new_value, nullptr}};
  if (top == nullptr) {
    top = new_node;
  } else {
    node_t* current{top};
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = new_node;
  }
  queuesize++;
  return new_value;
}

auto queue_t::dequeue() -> std::size_t {
  std::size_t result{1};
  if (top == nullptr) {
    std::cout << "Queue is empty";
  } else {
    result = top->value;
    node_t* tmp = top;
    top = top->next;
    delete tmp;
    queuesize--;
  }
  return result;
}
