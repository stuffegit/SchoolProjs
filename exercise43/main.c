#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node { // each node
  int value;
  struct Node* next;
} Node;

typedef struct { // entire stack
  Node* top;
  size_t size;
} Stack;

Stack* stack_create(void);
void stack_push(Stack* stack, int value);
void stack_pop(Stack* stack);
int stack_count(const Stack* stack);
void stack_clear(Stack* stack);
void stack_print(const Stack* stack);

int main(void) {
  Stack* stack = stack_create();

  stack_print(stack);
  printf("Items in stack: %d\n", stack_count(stack));

  stack_push(stack, 3);
  stack_push(stack, 6);
  stack_push(stack, 9);
  stack_print(stack);
  printf("Items in stack: %d\n", stack_count(stack));

  stack_pop(stack);
  stack_print(stack);
  printf("Items in stack: %d\n", stack_count(stack));

  stack_clear(stack);
  printf("Stack cleared\n");
  stack_print(stack);

  return 0;
}

Stack* stack_create(void) {
  Stack* stack = malloc(sizeof(Stack));
  assert(stack);
  stack->top = NULL;
  stack->size = 0;
  return stack;
}

void stack_push(Stack* stack, int value) {
  assert(stack);
  Node* new_node = malloc(sizeof(Node));
  assert(new_node);
  new_node->value = value;
  new_node->next = stack->top;
  stack->top = new_node;
  stack->size++;
}

void stack_pop(Stack* stack) {
  assert(stack);
  if (stack->top) {
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
  } else {
    printf("Stack underflow\n");
  }
}

int stack_count(const Stack* stack) {
  assert(stack);
  return stack->size;
}

void stack_clear(Stack* stack) {
  assert(stack);
  while (stack->top) {
    stack_pop(stack);
  }
}

void stack_print(const Stack* stack) {
  assert(stack);
  Node* current = stack->top;
  if (!current) {
    printf("Stack is empty\n");
    return;
  }
  while (current) {
    printf("%d ", current->value);
    current = current->next;
  }
  printf("\n");
}
