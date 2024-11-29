#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>

typedef struct node_t {
  uint8_t data;
  struct node_t* next;
} node_t;

node_t* node_create(int size);
void node_print(node_t* head);
void node_free(node_t** head);
void node_queue_enqueue(node_t** queue, int value);
void node_queue_dequeue(node_t** queue);
int node_queue_getqueuecount(node_t** queue);
void node_queue_deletedata(node_t** queue);

#endif // !QUEUE_H
