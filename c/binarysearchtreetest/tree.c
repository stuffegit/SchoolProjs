#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

struct node_t* insert(struct node_t* root, int value) {
  struct node_t* new_node = (struct node_t*)malloc(sizeof(struct node_t));
  new_node->value = value;
  new_node->left = new_node->right = NULL;

  if (root == NULL)
    return new_node;

  struct node_t* parent = NULL;
  struct node_t* current = root;

  while (current) {
    parent = current;
    if (value < current->value)
      current = current->left;
    else
      current = current->right;
  }

  if (value < parent->value)
    parent->left = new_node;
  else
    parent->right = new_node;

  return root;
}

struct node_t* search(struct node_t* root, int value) {
  struct node_t* current = root;

  while (current && current->value != value) {
    if (value < current->value)
      current = current->left;
    else
      current = current->right;
  }
  return current;
}

void inorder(struct node_t* root) {
  struct node_t* stack[100];
  int top = -1;
  struct node_t* current = root;

  while (current || top != -1) {
    while (current) {
      stack[++top] = current;
      current = current->left;
    }

    current = stack[top--];
    printf("%d ", current->value);
    current = current->right;
  }
}

void free_tree(struct node_t* root) {
  if (!root)
    return;

  struct node_t* stack[100];
  int top = -1;
  stack[++top] = root;

  while (top != -1) {
    struct node_t* current = stack[top--];

    if (current->left)
      stack[++top] = current->left;
    if (current->right)
      stack[++top] = current->right;

    free(current);
  }
}
