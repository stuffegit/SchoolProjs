
#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <cassert>

template <typename T> class stack_t {
private:
  struct node_t {
    T data;
    node_t* next;

    node_t(T value) : data(value), next(nullptr) {}
  };

  node_t* front;
  int elements;
  int max_size;

public:
  stack_t(int size);
  ~stack_t();

  stack_t(const stack_t&) = delete;
  stack_t& operator=(const stack_t&) = delete;

  auto print() -> void;
  auto push(T value) -> bool;
  auto pop() -> T;
  auto get_elements() -> int const { return elements; }
  auto clear() -> void;
};

template <typename T> stack_t<T>::stack_t(int size) : front(nullptr), elements(0), max_size(size) {}

template <typename T> stack_t<T>::~stack_t() { clear(); }

template <typename T> auto stack_t<T>::print() -> void {
  node_t* head = front;
  std::cout << "Stack values: ";
  for (int i = 0; i < elements; ++i) {
    std::cout << head->data << " ";
    if (head->next != nullptr) {
      head = head->next;
    }
  }
  std::cout << std::endl;
}

template <typename T> auto stack_t<T>::push(T value) -> bool {
  if (elements == max_size) {
    return false;
  } else {
    node_t* new_node = new node_t(value);
    new_node->next = front;
    front = new_node;
    ++elements;
    std::cout << "pushed: " << value << std::endl;
    return true;
  }
}

template <typename T> auto stack_t<T>::pop() -> T {
  assert(front != nullptr && "Attempting to pop from an empty stack");
  node_t* temp = front;
  T result = front->data;
  front = front->next;
  delete temp;
  --elements;
  return result;
}

template <typename T> auto stack_t<T>::clear() -> void {
  while (front != nullptr) {
    node_t* temp = front;
    front = front->next;
    delete temp;
  }
  elements = 0;
}

#endif // STACK_HPP
