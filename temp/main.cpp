#include <iostream>

int main () {
  int total{1200};
  int cost{1078};
  int whiskey{246};
  int gin{299};
  int vodka{131};
  int liqor{339};
  int beer{63};

  std::cout << whiskey*1.12 << "\n";
  std::cout << gin*1.12 << "\n";
  std::cout << vodka*1.12 << "\n";
  std::cout << liqor*1.12 << "\n";
  std::cout << beer*1.12 << "\n";
  return 0;
}
