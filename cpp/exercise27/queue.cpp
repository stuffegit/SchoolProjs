#include "queue.hpp"
#include <iostream>

queue_t::queue_t(int size) : front(nullptr), rear(nullptr), elements(0), max_size(size) {
  std::cout << "queue_t constructed." << std::endl;
}
queue_t::~queue_t() {
  clear();
  std::cout << "queue_t destructed." << std::endl;
}

bool queue_t::enqueue(int value) {
  bool result{true};
  if (elements == max_size) {
    result = false;
  } else {
    node_t* new_node = new node_t(value);
    if (rear == nullptr) {
      front = rear = new_node;
    } else {
      rear->next = new_node;
      rear = new_node;
    }
    elements++;
  }
  return result;
}

int queue_t::dequeue() {
  int result{0};
  if (front != nullptr) {
    node_t* temp = front;
    result = front->data;
    front = front->next;
    delete temp;
    elements--;
    if (front == nullptr) {
      rear = nullptr;
    }
  }
  return result;
}

void queue_t::clear() {
  while (front != nullptr) {
    node_t* temp = front;
    front = front->next;
    delete temp;
  }
  rear = nullptr;
  elements = 0;
}
