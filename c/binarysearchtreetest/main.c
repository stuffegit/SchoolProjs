#include "tree.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
  struct node_t* root = NULL;
  srand(time(NULL));

  printf("Inserting random values:\n");
  for (int i = 0; i < 10; i++) {
    int value = rand() % 100;
    printf("%d ", value);
    root = insert(root, value);
  }
  printf("\n");

  printf("In-order traversal: \n");
  inorder(root);
  printf("\n");

  free_tree(root);

  return 0;
}
