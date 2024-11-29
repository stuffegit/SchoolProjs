#ifndef STACK_H
#define STACK_H

#include <stdint.h>
#include <stdlib.h>

typedef struct {
  uint8_t* data; // pointer to the stack data
  size_t size;
  size_t top; // index of the top element
} Stack;

Stack* stack_create(size_t size);
void stack_destroy(Stack* stack);
void stack_print(const Stack* stack);
void stack_push(Stack* stack, uint8_t value);
void stack_pop(Stack* stack);
size_t stack_count(const Stack* stack);
size_t stack_getlen(const Stack* stack);

#endif // STACK_H
