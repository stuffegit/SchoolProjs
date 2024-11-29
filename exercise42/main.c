#include "stack.h"
#include <stdio.h>
#include <time.h>

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
