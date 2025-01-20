#include <iostream>
void last() { // called by third()
  std::cout << "Start last" << std::endl;
  std::cout << "last throwing an int exception" << std::endl;
  throw -1;
  std::cout << "End last" << std::endl;
}
void third() { // called by second()
  std::cout << "Start third" << std::endl;
  last();
  std::cout << "End third" << std::endl;
}
void second() { // called by first()
  std::cout << "Start second" << std::endl;
  try {
    third();
  } catch (double) {
    std::cout << "second caught a double exception";
    std::cout << std::endl;
  }
  std::cout << "End second" << std::endl;
}
void first() { // called by main
  std::cout << "Start first" << std::endl;
  try {
    second();
  } catch (int) {
    std::cout << "first caught an int exception" << std::endl;
  } catch (double) {
    std::cout << "first caught a double exception";
    std::cout << std::endl;
  }
  std::cout << "End first" << std::endl;
}
int main(void) {
  std::cout << "Start main" << std::endl;
  try {
    first();
  } catch (int) {
    std::cout << "main caught an int exception";
    std::cout << std::endl;
  }
  std::cout << "End main" << std::endl;
  return 0;
}
