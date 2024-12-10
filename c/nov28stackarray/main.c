#include "stack.h"

int main(void) {
  printStack();
  push(1);
  printStack();
  push(2);
  push(3);
  push(4);
  push(5);
  push(6);
  push(7);
  push(8);
  push(9);
  printStack();
  pop();
  printStack();
  return 0;
}
