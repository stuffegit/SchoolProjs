#include "stack.h"
#include <assert.h>
#include <stdio.h>

Stack* stack_create(size_t size) {
  Stack* stack = malloc(sizeof(Stack));
  assert(stack);

  stack->data = calloc(size, sizeof(uint8_t)); // calloc sets all to 0
  assert(stack->data);

  stack->size = size;
  stack->top = 0;

  return stack;
}

void stack_destroy(Stack* stack) {
  if (stack) {
    free(stack->data);
    free(stack);
  }
}

void stack_print(const Stack* stack) {
  assert(stack && stack->data);

  for (size_t i = 0; i < stack->size; i++) {
    if (stack->data[i] != 0) {
      printf("%d ", stack->data[i]);
    }
  }
  printf("\n");
}

void stack_push(Stack* stack, uint8_t value) {
  assert(stack && stack->data);

  if (stack->top < stack->size) {
    stack->data[stack->top++] = value;
  } else {
    printf("Stack overflow\n");
  }
}

void stack_pop(Stack* stack) {
  assert(stack && stack->data);

  if (stack->top > 0) {
    stack->top -= 1;
    stack->data[stack->top] = 0;
  } else {
    printf("Stack underflow\n");
  }
}

size_t stack_count(const Stack* stack) {
  assert(stack);
  return stack->top;
}

size_t stack_getlen(const Stack* stack) {
  assert(stack);
  return stack->size;
}
