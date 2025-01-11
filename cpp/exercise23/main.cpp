#include "geometry.hpp"
#include <iostream>

int main(void) {
  Circle circle(Point(0, 0), 5);
  std::cout << "Circle area: " << circle.get_area() << std::endl;
  Square square(4);
  std::cout << "Square area: " << square.get_area() << std::endl;
  return 0;
}
