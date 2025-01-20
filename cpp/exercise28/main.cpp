#include <algorithm>
#include <iostream>
#include <vector>

bool is_prime(int elem) {
  bool result = true;
  for (int i = 2; i * i <= elem; ++i) {
    if (elem % i == 0) {
      result = false;
      break;
    }
  }
  return result;
}

int main(void) {
  srand(time(nullptr));
  std::vector<int> vec1(1000);

  for (int& elem : vec1) {
    elem = (rand() % 99900 + 100) + 1;
  }

  for (auto i = vec1.begin(); i != vec1.end();) {
    if (!is_prime(*i)) {
      i = vec1.erase(i); // https://en.cppreference.com/w/cpp/container/vector/erase
    } else {
      i++;
    }
  }

  std::sort(vec1.begin(), vec1.end(), [](int a, int b) { return a < b; });

  for (const int& elem : vec1) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
  return 0;
}
