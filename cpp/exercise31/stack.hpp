
#ifndef STACK_HPP
#define STACK_HPP

#include <cstddef>
#include <iostream>
#include <utility>

template <typename T> class stack_t {
  T* arr;
  size_t size;
  size_t top;

public:
  stack_t(size_t _size);
  ~stack_t();

  size_t get_size() const { return size; }
  bool pushelem(const T& element);
  size_t get_elem() const;
  T pop_elem(bool& success);
  void clear();

  // Uncopyable
  stack_t(const stack_t&) = delete;
  stack_t& operator=(const stack_t&) = delete;

  // Movable
  stack_t(stack_t&& src) noexcept;
  stack_t& operator=(stack_t&& src) noexcept;
};

// Con+De-structors
template <typename T> stack_t<T>::stack_t(size_t _size) : size(_size), top(0) {
  arr = new T[_size];
  std::cout << "stack_t constructed." << std::endl;
}

template <typename T> stack_t<T>::~stack_t() {
  delete[] arr;
  std::cout << "stack_t destructed." << std::endl;
}

// Move constructor
template <typename T> stack_t<T>::stack_t(stack_t&& src) noexcept : arr(nullptr), size(0), top(0) {
  *this = std::move(src);
}

template <typename T> stack_t<T>& stack_t<T>::operator=(stack_t&& src) noexcept {
  if (this != &src) {
    delete[] arr;

    arr = src.arr;
    size = src.size;
    top = src.top;

    src.arr = nullptr;
    src.size = 0;
    src.top = 0;
  }
  return *this;
}

// Implement stack functions
template <typename T> bool stack_t<T>::pushelem(const T& element) {
  if (top >= size) {
    return false; // Indicate error
  }
  arr[top++] = element;
  return true;
}

template <typename T> T stack_t<T>::pop_elem(bool& success) {
  if (top == 0) {
    success = false; // Indicate error
    return T();      // Return default value of T
  }
  success = true;
  return arr[--top];
}

template <typename T> size_t stack_t<T>::get_elem() const { return top; }

template <typename T> void stack_t<T>::clear() { top = 0; }

#endif
