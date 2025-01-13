#include "queueclass.hpp"
#include <cassert>
#include <iostream>

int main() {
  // Test creation of queue
  queue_t queue(10);
  assert(queue.get_elems() == 1);
  std::cout << "Queue creation test passed.\n";

  // Test enqueueing elements
  queue.enqueue(20);
  queue.enqueue(30);
  assert(queue.get_elems() == 3);
  std::cout << "Enqueue test passed.\n";

  // Test dequeueing elements
  std::size_t firstDequeue = queue.dequeue();
  assert(firstDequeue == 10);
  assert(queue.get_elems() == 2);
  std::cout << "Dequeue test 1 passed.\n";
  std::size_t secondDequeue = queue.dequeue();
  assert(secondDequeue == 20);
  assert(queue.get_elems() == 1);
  std::cout << "Dequeue test 2 passed.\n";
  std::size_t thirdDequeue = queue.dequeue();
  assert(thirdDequeue == 30);
  assert(queue.get_elems() == 0);
  std::cout << "Dequeue test 3 passed.\n";

  // Test queue reset
  queue.enqueue(40);
  assert(queue.get_elems() == 1);
  queue.reset_queue();
  assert(queue.get_elems() == 0);
  std::cout << "Queue reset test passed.\n";

  // Test memory cleanup
  {
    queue_t temp_queue(50);
    temp_queue.enqueue(60);
    temp_queue.enqueue(70);
    assert(temp_queue.get_elems() == 3);
  }
  std::cout << "Memory cleanup test passed.\n";
  std::cout << "All tests passed successfully!\n";
  return 0;
}
