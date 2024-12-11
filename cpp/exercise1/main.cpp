#ifdef NUMBER
#if NUMBER == 8 || NUMBER == 16
#include <iostream>

int main(void) {
  std::cout << "hw\n";
  return 0;
}

#else
#error NUMBER not defined to 8 or 16
#endif
#else
#error NUMBER not defined at compiletime with -D
#endif
