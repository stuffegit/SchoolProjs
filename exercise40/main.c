#include "llist.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
