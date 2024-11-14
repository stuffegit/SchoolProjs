#include <stdio.h>

void add5(int *x);
void say_value(int a);

int main(void) {
  int a = 5;
  int *pa = &a;
  char b = 's';
  char *pb = &b;

  *pa = 7;
  *pb = 'w';

  add5(pa);
  void (*funcptr)(int a) = &say_value;
  funcptr(*pa);
  return 0;
}

void add5(int *x) { *x += 5; }
void say_value(int a) { printf("Value of a is %d\n", a); }
