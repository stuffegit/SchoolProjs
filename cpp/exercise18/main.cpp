#include <iostream>
#include <string>

struct node_t {
  int value;
  node_t* next;
};

struct stack_t {
  node_t* top;
  int size;
};

stack_t create_stack();
void push_stack(stack_t& stack, int i);
void getelems_stack(const stack_t& stack);
void pop_stack(stack_t& stack);
void clear_stack(stack_t& stack);
void destroy_stack(stack_t& stack);

int main(int argc, char* argv[]) {
  stack_t stack = create_stack();
  push_stack(stack, 42);
  push_stack(stack, 4);
  push_stack(stack, 2);
  push_stack(stack, 500);
  getelems_stack(stack);
  pop_stack(stack);
  getelems_stack(stack);
  clear_stack(stack);
  getelems_stack(stack);
  destroy_stack(stack);
  return 0;
}

stack_t create_stack() {
  stack_t new_stack = {nullptr, 0};
  std::cout << "stack created" << std::endl;
  return new_stack;
}

void push_stack(stack_t& stack, int i) {
  node_t* new_node = new node_t();
  new_node->value = i;
  new_node->next = stack.top;
  stack.top = new_node;
  stack.size++;
  std::cout << "pushed " << i << " to stack" << std::endl;
}

void getelems_stack(const stack_t& stack) {
  node_t* current = stack.top;
  std::cout << "elements: ";
  while (current != nullptr) {
    std::cout << current->value << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

void pop_stack(stack_t& stack) {
  if (stack.top != nullptr) {
    node_t* temp = stack.top;
    stack.top = stack.top->next;
    delete temp;
    stack.size--;
    std::cout << "pop" << std::endl;
  } else {
    std::cout << "stack is empty!" << std::endl;
  }
}

void clear_stack(stack_t& stack) {
  while (stack.top != nullptr) {
    pop_stack(stack);
  }
  std::cout << "cleared stack" << std::endl;
}

void destroy_stack(stack_t& stack) {
  clear_stack(stack);
  std::cout << "destroyed stack" << std::endl;
}
