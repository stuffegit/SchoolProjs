#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

struct node_t {
  int value;
  node_t* next;
}

class queue_t {
  node_t* head;
  int size;

public:
  queue_t() : size(1) {
    head = new node_t(sizeof(node_t));
    std::cout << "Queue constructed" << std::endl;
  }
  ~queue_t() { clear(); }
}

#endif // QUEUE_H
