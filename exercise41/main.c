#include "queue.h"

int main(void) {
  node_t* queue = node_create(5);
  node_print(queue);
  node_queue_enqueue(&queue, 5);
  node_print(queue);
  node_queue_dequeue(&queue);
  node_print(queue);
  node_queue_deletedata(&queue);
  node_print(queue);
  return 0;
}
