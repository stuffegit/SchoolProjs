#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

struct node_t {
  int value;
  node_t* next;
  node_t(int new_value) {
    value = new_value;
    next = nullptr;
  }
};

class queue_t {
  node_t* head;
  int size;

public:
  queue_t();
  ~queue_t();
  bool dummyfunc();
};

#endif // QUEUE_HPP
