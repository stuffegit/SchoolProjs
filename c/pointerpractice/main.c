#include <stdio.h>

int main() {
  int x = 10;
  int y = 20;
  int *p = NULL;   // Pointer to int
  int **pp = NULL; // Pointer to a pointer to int

  // Example 1: Assign the address of x to p
  p = &x;
  printf("Example 1: *p = %d, p = %p, &x = %p\n", *p, p, &x);

  // Example 2: Modify x through p
  *p = 15;
  printf("Example 2: x = %d, *p = %d\n", x, *p);

  // Example 3: Assign p's address to pp
  pp = &p;
  printf("Example 3: *pp = %p, pp = %p, &p = %p\n", *pp, pp, &p);

  // Example 4: Modify p through pp (point to y)
  *pp = &y;
  printf("Example 4: *p = %d, p = %p, y = %d\n", *p, p, y);

  // Example 5: Modify y through pp (double dereferencing)
  **pp = 25;
  printf("Example 5: y = %d, **pp = %d\n", y, **pp);

  // Example 6: Reset pp to point to p again
  *pp = &x;
  printf("Example 6: x = %d, *p = %d, **pp = %d\n", x, *p, **pp);

  return 0;
}
