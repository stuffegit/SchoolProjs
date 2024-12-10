#include "queue.h"

int main(void) {
  printQueue();
  enqueue(1);
  printQueue();
  enqueue(2);
  enqueue(3);
  enqueue(4);
  enqueue(5);
  enqueue(6);
  enqueue(7);
  enqueue(8);
  enqueue(9);
  printQueue();
  dequeue();
  printQueue();
  return 0;
}
