#include <stdio.h>

typedef struct node_t {
  float data;
  struct node_t* next;
  struct node_t* previous;
} node_t;

int main(void) {
  node_t node1, node1_5, node2, node3;

  node1.data = 1;
  node1.next = &node1_5;
  node1.previous = NULL;

  node1_5.data = 1.5;
  node1_5.next = &node2;
  node1_5.previous = &node1;

  node2.data = 2;
  node2.next = &node3;
  node2.previous = &node1_5;

  node3.data = 3;
  node3.next = NULL;
  node3.previous = &node2;

  node_t* head = &node1;
  node_t* tail = &node3;

  for (node_t* current = head; current != NULL; current = current->next) {
    printf("%.1f\n", current->data);
  }

  printf("---\n");

  for (node_t* current = tail; current != NULL; current = current->previous) {
    printf("%.1f\n", current->data);
  }

  return 0;
}
