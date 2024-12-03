#include "stack.h"
#include <assert.h>
#include <stdio.h>

stack_t persons = {0};
int stacksize = 0;

void push(int element) {
  if (isFull()) {
    (void)printf("stack is full\n");
    return;
  }
  assert(persons[stacksize] == 0);
  persons[stacksize] = element;
  stacksize++;
}

void pop() {
  if (isEmpty()) {
    (void)printf("stack is empty\n");
    return;
  }
  assert(persons[stacksize] == 0);
  persons[stacksize - 1] = 0;
  stacksize--;
}

void printStack() {
  for (int i = 0; i < stacksize; i++) {
    (void)printf("%d ", persons[i]);
  }
  (void)printf("\n");
}

bool isEmpty() { return (stacksize <= 0 ? 1 : 0); }

bool isFull() { return (stacksize >= STACK_SIZE ? 1 : 0); }
