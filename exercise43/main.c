#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  uint8_t* data;
  size_t size;
  size_t top;
} Stack;

Stack* stack_create(size_t size);
void stack_push(Stack* stack, uint8_t data);
void stack_pop(Stack* stack);
size_t stack_count(const Stack* stack);
Stack* stack_clear(Stack* stack);
void stack_print(const Stack* stack);

int main(void) {
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

  stack = stack_clear(stack);
  printf("Stack cleared\n");
  stack_print(stack);

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

Stack* stack_clear(Stack* stack) {
  if (stack) {
    free(stack->data);
    free(stack);
    stack = NULL;
  }
  return stack;
}

void stack_print(const Stack* stack) {
  if (stack != NULL && stack->data != NULL) {

    for (size_t i = 0; i < stack->size; i++) {
      printf("%d ", stack->data[i]);
    }
    printf("\n");
  } else {
    printf("No stack or stack data.\n");
  }
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
