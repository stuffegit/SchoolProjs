#include <iostream>
#include <regex> // cheatcode lib
#include <string>

bool isValidDateTime(const std::string& dateTime) {
  const std::regex pattern(R"(\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2})"); // ok
  return std::regex_match(dateTime, pattern); // returns true if matching
}

int main() {
  std::string dateTime;

  std::cout << "Enter date and time (yyyy-mm-dd hh:mm:ss): ";
  std::getline(std::cin, dateTime); // getline doesnt rq after spaces

  if (isValidDateTime(dateTime)) {
    std::cout << "Valid date and time format.\n";
  } else {
    std::cout << "Invalid date and time format.\n";
  }

  return 0;
}
