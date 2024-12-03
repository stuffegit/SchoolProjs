#include "queue.h"
#include <assert.h>
#include <stdio.h>

queue_t persons = {0};

void enqueue(int element) {
  if (isFull()) {
    (void)printf("queue is full\n");
    return;
  }
  int i = 0;
  while (persons[i] != 0) {
    i++;
  }
  assert(persons[i] == 0);
  persons[i] = element;
}

void dequeue() {
  if (isEmpty()) {
    (void)printf("queue is empty\n");
    return;
  }
  persons[0] = 0;
  for (int i = 0; i < QUEUE_SIZE - 1; i++) {
    persons[i] = persons[i + 1];
  }
  persons[QUEUE_SIZE - 1] = 0;
}

void printQueue() {
  for (int i = 0; i < QUEUE_SIZE; i++) {
    if (persons[i] != 0) {
      (void)printf("%d ", persons[i]);
    }
  }
  (void)printf("\n");
}

bool isEmpty() {
  int result = 1;
  for (int i = 0; i < QUEUE_SIZE; i++) {
    if (persons[i] != 0) {
      result = 0;
    }
  }
  return result;
}

bool isFull() {
  int result = 1;
  for (int i = 0; i < QUEUE_SIZE; i++) {
    if (persons[i] == 0) {
      result = 0;
    }
  }
  return result;
}
