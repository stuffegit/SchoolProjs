#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define LIST_SIZE 7

typedef struct Node {
  uint8_t data;
  struct Node* next;
} Node;

typedef struct LinkedList {
  Node* head;
  int size;
} LinkedList;

void list_create(LinkedList* list, int num_nodes);
void list_add(LinkedList* list, uint8_t value);
void list_remove(LinkedList* list);
void list_print(const LinkedList* list);
void list_free(LinkedList* list);

int main(void) {
  LinkedList list = {0};
  list_create(&list, LIST_SIZE);
  list_print(&list);

  list_add(&list, 255);
  list_print(&list);

  list_remove(&list);
  list_print(&list);

  list_remove(&list);
  list_print(&list);

  list_free(&list);
  return 0;
}

void list_create(LinkedList* list, int num_nodes) {
  assert(list != NULL);
  list->head = NULL;
  list->size = 0;

  for (int i = 0; i < num_nodes; i++) {
    list_add(list, i + 1);
  }
}

void list_add(LinkedList* list, uint8_t value) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  assert(new_node != NULL);
  new_node->data = value;
  new_node->next = NULL;

  if (list->head == NULL) {
    list->head = new_node;
  } else {
    Node* current = list->head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
  list->size++;
}

void list_remove(LinkedList* list) {
  if (list->head == NULL) {
    printf("List is empty.\n");
    return;
  }

  if (list->head->next == NULL) {
    free(list->head);
    list->head = NULL;
    list->size--;
    return;
  }

  Node* current = list->head;
  while ((current->next)->next != NULL) {
    current = current->next;
  }

  free(current->next);
  current->next = NULL;
  list->size--;
}

void list_print(const LinkedList* list) {
  Node* current = list->head;
  while (current != NULL) {
    printf("%d->", current->data);
    current = current->next;
  }
  printf("NULL\n");
  printf("Size: %d\n", list->size);
}

void list_free(LinkedList* list) {
  Node* current = list->head;
  while (current != NULL) {
    Node* temp = current;
    current = current->next;
    free(temp);
  }
}
