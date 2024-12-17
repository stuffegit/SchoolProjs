#include <iostream>

int calc_digits(int num);
int sum_digits(int num);

int main(void) {
  int number_to_test{5284};
  std::cout << calc_digits(number_to_test) << std::endl;
  std::cout << sum_digits(number_to_test) << std::endl;
  return 0;
}

int calc_digits(int num) {
  if (num < 10) {
    return 1;
  }
  return 1 + calc_digits(num / 10);
}

int sum_digits(int num) {
  if (num < 10) {
    return num;
  }
  return (num % 10) + sum_digits(num / 10);
}
