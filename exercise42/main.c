#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main(void) {
  srand(time(NULL));

  Stack* stack = stack_create(10);

  stack_print(stack);
  printf("Items in stack: %zu\n", stack_count(stack));

  stack_push(stack, 3);
  stack_push(stack, 6);
  stack_push(stack, 9);
  stack_print(stack);
  printf("Items in stack: %zu\n", stack_count(stack));

  stack_pop(stack);
  stack_print(stack);
  printf("Items in stack: %zu\n", stack_count(stack));

  printf("Total stack length: %zu\n", stack_getlen(stack));

  stack_destroy(stack);

  return 0;
}

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
    printf("%d ", stack->data[i]);
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
