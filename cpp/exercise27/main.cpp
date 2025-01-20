#include "queue.hpp"
#include <cassert>
#include <iostream>

int main() {
  queue_t queue(10);
  std::cout << "Elements after creation: " << queue.get_elements() << std::endl;
  assert(queue.enqueue(1));
  assert(queue.enqueue(2));
  assert(queue.enqueue(3));
  std::cout << "Elements after three enqueues: " << queue.get_elements() << std::endl;
  assert(queue.dequeue());
  std::cout << "Elements after one dequeue: " << queue.get_elements() << std::endl;
  queue.clear();
  std::cout << "Elements after clear(): " << queue.get_elements() << std::endl;
  return 0;
}
