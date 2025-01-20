#include <iostream>

int main(void) {

  try {
    throw -1;
  } catch (int x) {
    std::cout << "I caught " << x << std::endl;
  }

  try {
    throw "I caught a char pointer";
  } catch (const char* str_err) {
    std::cout << str_err << std::endl;
  }
  return 0;
}
