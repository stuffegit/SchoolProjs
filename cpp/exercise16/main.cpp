#include <iostream>
#include <array>
#include <algorithm>

#define LEN 10

bool contains(const std::array<int, LEN>& arr, int target);
void fill_arr(std::array<int, LEN>& arr);
void print_arr(const std::array<int, LEN>& arr);

int main(int argc, char* argv[]) {
  std::array<int, LEN> arr{};
  fill_arr(arr);
  print_arr(arr);
  return 0;
}

bool contains(const std::array<int, LEN>& arr, int target) {
  return std::find(arr.begin(), arr.end(), target) != arr.end();
}

void fill_arr(std::array<int, LEN>& arr) {
  for (int i = 0; i < arr.size();) {
    int temp = (rand() % 98) + 1;
    if (!contains(arr, temp)) {
      arr[i] = temp;
      i++;
    }
  }
}

void print_arr(const std::array<int, LEN>& arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
