#include "greet.h"

std::string greet(const std::string &name) {
  std::string greeting{"Hello, my friend."};
  if (!name.empty()) {
    greeting = "Hello, " + name;
  }
  return greeting;
}
