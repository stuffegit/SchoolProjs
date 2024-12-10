#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define QUEUE_SIZE 10

typedef int queue_t[QUEUE_SIZE];

void enqueue(int element);
void dequeue();
void printQueue();
bool isEmpty();
bool isFull();

#endif // !QUEUE_H
