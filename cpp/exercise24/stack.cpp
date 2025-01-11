#include "stack.hpp"
#include <iostream>

// *-structors
stack_t::stack_t(int new_value)
    : stack_size(1), first(new node_t{new_value, nullptr}) {}
stack_t::stack_t(const stack_t& other)
    : stack_size(other.stack_size), first(nullptr) {
  if (other.first) {
    copy_nodes(other.first);
  }
}
stack_t& stack_t::operator=(const stack_t& other) {
  if (this != &other) { // self-assignment check, idk this 100%
    stack_size = other.stack_size;
    delete_nodes();
    if (other.first) {
      copy_nodes(other.first);
    } else {
      first = nullptr;
    }
  }
  return *this;
}
stack_t::~stack_t() { delete_nodes(); }

// Helper function
void stack_t::delete_nodes() {
  while (first) {
    node_t* temp{first};
    first = first->next;
    delete temp;
  }
}
void stack_t::copy_nodes(const node_t* source) {
  first = new node_t{source->value, nullptr};
  node_t* current{first};
  const node_t* source_current = source->next;
  while (source_current) {
    current->next = new node_t{source_current->value, nullptr};
    current = current->next;
    source_current = source_current->next;
  }
}

// Function implementations
auto stack_t::print() -> void {
  node_t* head{this->first};
  for (std::size_t i = 0; i < this->stack_size; i++) {
    std::cout << head->value << " ";
    head = head->next;
  }
  std::cout << std::endl;
}

auto stack_t::push(int new_value) -> bool {
  bool result{false};
  if (!is_full()) {
    node_t* new_node{new node_t{new_value, first}};
    first = new_node;
    stack_size++;
    result = true;
  } else {
    result = false;
  }
  return result;
}

auto stack_t::get(int get_value) -> bool {
  node_t* head{first};
  bool result{false};
  while (head != nullptr) {
    if (head->value == get_value) {
      result = true;
      break;
    }
    head = head->next;
  }
  return result;
}

auto stack_t::pop() -> int {
  int result{0};
  if (!is_empty()) {
    result = first->value;
    node_t* temp{first};
    first = first->next;
    delete temp;
    stack_size--;
  } else {
    std::cerr << "stack_t is empty" << std::endl;
  }
  return result;
}

auto stack_t::is_full() -> const bool { return stack_size >= STACK_SIZE; }

auto stack_t::is_empty() -> const bool { return stack_size == 0; }

auto stack_t::clear() -> void {
  delete_nodes();
  stack_size = 0;
}
