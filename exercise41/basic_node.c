#include "basic_node.h"

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
//-----------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------
void node_free(node_t** head) {
  node_t* current = *head; // Starting point.
  while (current != NULL) {
    node_t* temp = current;
    current = current->next;
    free(temp); // Keep stepping through but free'ing the one behind
  }
  *head = NULL;
}
