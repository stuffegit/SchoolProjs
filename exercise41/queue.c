#include "queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node_t* node_create(int size) {
  if (size <= 0) {
    return NULL;
  }

  node_t* head = NULL;
  node_t* current = NULL;

  for (int i = 0; i < size; i++) {
    node_t* newnode_t = (node_t*)malloc(sizeof(node_t));
    newnode_t->data = rand() % 100;
    newnode_t->next = NULL;

    if (head == NULL) {
      head = newnode_t;
    } else {
      current->next = newnode_t;
    }
    current = newnode_t;
  }
  return head;
}

void node_print(node_t* head) {
  if (head == NULL) {
    printf("The list is empty.\n");
  } else {
    node_t* current = head; // Starting point.
    while (current != NULL) {
      printf("%d -> ", current->data);
      if (current->next != NULL) {
        current = current->next;
      } else {
        break;
      }
    }
    printf("NULL\n");
  }
}

void node_free(node_t** head) {
  node_t* current = *head; // Starting point.
  while (current != NULL) {
    node_t* temp = current;
    current = current->next;
    free(temp); // Keep stepping through but free'ing the one behind
  }
  *head = NULL;
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
    printf("Value: %d was added at position: %d in queue.\n", value,
           node_queue_getqueuecount(queue));
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
