#include <algorithm>
#include <array>
#include <cstdlib>
#include <ctime>
#include <iostream>

#define LEN 10

using compare_t = bool (*)(int, int);

bool compare_asc(int a, int b) { return a > b; }

bool compare_desc(int a, int b) { return a < b; }

void sort(size_t length, int* arr, compare_t compare) {
  for (size_t i = 0; i < length; ++i) {
    for (size_t j = i + 1; j < length; ++j) {
      if (!compare(arr[i], arr[j])) {
        std::swap(arr[i], arr[j]);
      }
    }
  }
}

void fill_arr(std::array<int, LEN>& arr) {
  srand(time(NULL));
  for (int i = 0; i < arr.size(); i++) {
    arr[i] = rand() % 100;
  }
}

void print_arr(const std::array<int, LEN>& arr) {
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr.at(i) << " ";
  }
  std::cout << std::endl;
}

void swap_values_in_arr(std::array<int, LEN>& arr, int value1, int value2) {
  if (value1 < arr.size() && value2 < arr.size()) {
    std::swap(arr[value1], arr[value2]);
  }
}

int main(void) {
  srand(time(NULL));
  std::array<int, LEN> arr;
  std::array<int, LEN>* parr = &arr;
  fill_arr(*parr);
  print_arr(*parr);
  swap_values_in_arr(*parr, 0, 1);
  print_arr(*parr);
  sort(parr->size(), parr->data(), compare_asc);
  print_arr(*parr);
  sort(parr->size(), parr->data(), compare_desc);
  print_arr(*parr);
  return 0;
}
