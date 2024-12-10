#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define STACK_SIZE 10

typedef int stack_t[STACK_SIZE];

void push(int element);
void pop();
void printStack();
bool isEmpty();
bool isFull();

#endif // !STACK_H
