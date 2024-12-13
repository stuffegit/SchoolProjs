#pragma once
#include <array>

#define LEN 10

void fill_array(const std::array<int, LEN>& array);
void print_array(const std::array<int, LEN>& array);
void swap_values_in_array(const std::array<int, LEN>& array, int value1,
                          int value2);
void sort_arrays(const std::array<int, LEN>& array);
