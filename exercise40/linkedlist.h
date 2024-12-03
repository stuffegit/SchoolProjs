#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
  uint8_t data;
  struct node *next;
} node_t;

node_t *node_create(int size);
void node_print(node_t *head);
void node_add(node_t **head, uint8_t value, int position);
void node_del(node_t **head, int position);
void node_modify(node_t **head, int position, int new_data);
int node_getdata(node_t **head, int position);
void node_search(node_t **head, int search_data);
int node_count(node_t **head);
void node_free(node_t *head);

#endif // !LINKEDLIST_H
