#ifndef BASIC_NODE_H
#define BASIC_NODE_H

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
void node_free(node_t** head);

#endif // !BASIC_NODE_H
