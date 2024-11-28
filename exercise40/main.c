#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
  uint8_t data;
  struct node* next;
} node_t;

node_t* node_create(int size);
void node_print(node_t* head);
void node_add(node_t** head, uint8_t value, int position);
void node_del(node_t** head, int position);
void node_modify(node_t** head, int position, int new_data);
int node_getdata(node_t** head, int position);
void node_search(node_t** head, int search_data);
int node_count(node_t** head);
void node_free(node_t* head);

int main(void) {
  srand(time(NULL));

  node_t* head = node_create(5);
  printf("Head contents:\n");
  node_print(head);
  node_add(&head, 5, 5);
  node_print(head);
  node_search(&head, 6);
  node_modify(&head, 5, 6);
  node_print(head);
  node_search(&head, 6);
  node_del(&head, 5);
  node_print(head);
  printf("Data in position: 1 is: %d\n", node_getdata(&head, 1));
  printf("Size of list is: %d\n", node_count(&head));
  node_free(head);
  return 0;
}
//-----------------------------------------------------------------------------
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
  node_t* current = head; // Starting point.
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}
//-----------------------------------------------------------------------------
void node_add(node_t** head, uint8_t value, int position) {
  node_t* newnode_t = (node_t*)malloc(sizeof(node_t));
  newnode_t->data = value;
  newnode_t->next = NULL;

  node_t* current = *head;

  if (position == 0) {
    newnode_t->next = *head;
    *head = newnode_t;
  } else {
    int size = 0;
    while (current != NULL && size < position - 1) {
      size++;
      current = current->next;
    }

    if (current == NULL) {
      printf("Position does not exist in list.\n");
    } else {
      newnode_t->next = current->next;
      current->next = newnode_t;
    }
  }
}
//-----------------------------------------------------------------------------
void node_del(node_t** head, int position) {

  if (*head == NULL) {
    printf("List is empty.\n");
  } else {
    int done = 0;
    node_t* current = *head;

    if (position == 0) {
      *head = current->next;
      free(current);
      done = 1;
    } else {
      int index = 0;

      while (current != NULL && index < position - 1) {
        current = current->next;
        index++;
      }

      if (current == NULL || current->next == NULL) {

        printf("Position does not exist in list.\n");
      } else {
        node_t* to_delete = current->next;
        current->next = to_delete->next;
        free(to_delete);
        done = 1;
      }
    }
    if (!done) {
      printf("Deletion was not successful.\n");
    }
  }
}
//-----------------------------------------------------------------------------
void node_modify(node_t** head, int position, int new_data) {
  node_t* current = *head;
  int index = 0;
  int success = 0;

  while (current != NULL && index <= position) {
    if (position == index) {
      current->data = new_data;
      success = 1;
    }
    current = current->next;
    index++;
  }

  if (!success) {
    printf("Position does not exist in list.\n");
  }
} //-----------------------------------------------------------------------------
int node_getdata(node_t** head, int position) {
  node_t* current = *head;
  int index = 0;
  int data = -1;

  while (current != NULL) {
    if (position == index) {
      data = current->data;
      break;
    }
    current = current->next;
    index++;
  }

  if (data == -1) {
    printf("Position does not exist.\n");
  }

  return data;
}
//-----------------------------------------------------------------------------
void node_search(node_t** head, int search_data) {
  node_t* current = *head;
  int position = 0;
  int success = 0;

  while (current != NULL) {
    position++;
    if (current->data == search_data) {
      printf("Data \'%d\' exists on position: %d\n", search_data, position);
      success = 1;
      break;
    }
    current = current->next;
    position++;
  }

  if (!success) {
    printf("Data does not exist in list.\n");
  }
}
//-----------------------------------------------------------------------------
int node_count(node_t** head) {
  int size = 0;
  node_t* current = *head;
  while (current != NULL) {
    size++;
    current = current->next;
  }
  return size;
}
//-----------------------------------------------------------------------------
void node_free(node_t* head) {
  node_t* current = head; // Starting point.
  while (current != NULL) {
    node_t* temp = current;
    current = current->next;
    free(temp); // Keep stepping through but free'ing the one behind
  }
}
