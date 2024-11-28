#include "basic_node.h"
#include <assert.h>
#include <stdint.h>

void node_queue_enqueue(node_t** queue, int value);
void node_queue_dequeue(node_t** queue);
int node_queue_getqueuecount(node_t** queue);
void node_queue_deletedata(node_t** queue);

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

void node_queue_enqueue(node_t** queue, int value) {
  int size = 1;
  node_t* newnode_t = (node_t*)malloc(sizeof(node_t));
  newnode_t->data = value;
  newnode_t->next = NULL;

  node_t* current = *queue;

  while (current->next != NULL) {
    current = current->next;
    size++;
  }
  if (current != NULL) {
    newnode_t->next = current->next;
    current->next = newnode_t;
    printf("Value: %d was added at position: %d in queue.\n", value, node_queue_getqueuecount(queue));
  }
}

void node_queue_dequeue(node_t** queue) {
  int old_value = 0;
  int size = 0;
  node_t* current = *queue;

  while (current->next != NULL) {
    current = current->next;
    size++;
  }
  current = *queue;
  assert(current->next);
  old_value = current->data;
  *queue = current->next;
  free(current);
  printf("Value: %d was dequeued, new size: %d\n", old_value, node_queue_getqueuecount(queue));
}

int node_queue_getqueuecount(node_t** queue) {
  int size = 0;
  if (*queue != NULL) {
    node_t* current = *queue;
    while (current != NULL) {
      size++;
      current = current->next;
    }
  }
  return size;
}

void node_queue_deletedata(node_t** queue) {
  node_t* current = *queue; // Starting point.
  while (current != NULL) {
    node_t* temp = current;
    current = current->next;
    free(temp); // Keep stepping through but free'ing the one behind
  }
  *queue = NULL;
}
