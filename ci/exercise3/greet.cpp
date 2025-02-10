#include "greet.h"
#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

std::string greet(const std::string& name) {
  if (name.empty())
    return "Hello, my friend.";

  std::stringstream ss(name);
  std::string part;
  std::vector<std::string> lower_names, upper_names;

  while (getline(ss, part, ',')) {
    if (std::all_of(part.begin(), part.end(), ::isupper))
      upper_names.push_back(part);
    else
      lower_names.push_back(part);
  }

  auto format_names = [](const std::vector<std::string>& names, const std::string& sep,
                         const std::string& last_sep) -> std::string {
    if (names.empty())
      return "";
    if (names.size() == 1)
      return names[0];
    if (names.size() == 2)
      return names[0] + last_sep + names[1];
    return std::accumulate(names.begin(), names.end() - 1, std::string(),
                           [](const std::string& a, const std::string& b) {
                             return a.empty() ? b : a + ", " + b;
                           }) +
           "," + last_sep + names.back();
  };

  std::string lower_str = format_names(lower_names, ", ", " and ");
  std::string upper_str = format_names(upper_names, ", ", " AND ");

  std::string result;
  if (!lower_str.empty())
    result += "Hello, " + lower_str + ".";
  if (!upper_str.empty()) {
    if (!result.empty())
      result += " AND ";
    result += "HELLO " + upper_str + "!";
  }

  return result;
}
