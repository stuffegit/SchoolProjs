/**
 * @file    cbuffer.hpp
 * @author  Christoffer Sundström
 * @date    23 January 2025
 * @brief   Implements a circular buffer using
 *          a fixed size array.
 *
 * @desc    Implements the following features:
 *          - Writing data to the buffer.
 *          - Reading(dequeing) data.
 *          - Getting the capacity of the buffer.
 *          - Getting the current amount of elements in buffer.
 *          - Clearing the buffer.
 *
 **/
#ifndef CBUFFER_HPP
#define CBUFFER_HPP

#include <iostream>

/**
 *    Template class for a circular buffer
 *    using a fixed size array.
 *
 *    @param T
 *    Type of the elements in the buffer.
 *
 **/
template <typename T, int N> class cbuffer_t {
private:
  int count;
  int head;
  int tail;
  int capacity;
  T cbuffer[N];

public:
  /**
   *    Constructor
   *
   *    @brief
   *    Creates a fixed array for the buffer
   *      with capacity variable as size.
   *    Sets the head, tail and count to 0.
   *    Errors if capacity is less than 4.
   *
   *    @param _capacity
   *    Capacity of the buffer.
   **/
  cbuffer_t();

  /**
   *    Destructor
   *
   *    @brief
   *    Clears the buffer and destroys object.
   **/
  ~cbuffer_t();

  /**
   *    Copy Constructor functionality is removed.
   **/
  cbuffer_t(const cbuffer_t&) = delete;

  /**
   *    The << operator is overloaded to instead print
   *    the contents of the buffer.
   **/
  friend std::ostream& operator<<(std::ostream& os, const cbuffer_t& buffer) {
    std::cout << "[ ";
    for (int i = 0; i < buffer.capacity; i++) {
      os << buffer.cbuffer[i] << " ";
    }
    std::cout << "]";
    return os;
  }

  /**
   *  @brief
   *  Function to write data to the buffer.
   *  If the buffer is full overwrite the oldest data.
   *
   *  @param data
   *  Data to be written to the buffer.
   *
   *  @returnvalue
   *  Return true if data was written to the buffer.
   *  Return false if the buffer is full.
   *
   */
  bool write_data(const T& data);

  /**
   *    @brief
   *    Function to read data from the buffer.
   *
   *    @returnvalue
   *    Return true if data was read from the buffer.
   *    Return false if the buffer is empty.
   *
   **/
  bool read_data();

  /**
   *    @brief
   *    Function that returns amount of data
   *    elements in buffer.
   *
   *    @returnvalue
   *    Returns the value of the count variable.
   **/
  int get_data_count() { return count; }

  /**
   *    @brief
   *    Function that returns capacity value.
   *
   *    @returnvalue
   *    Returns the value of the capacity variable.
   **/
  int get_capacity() { return capacity; }

  /**
   *    @brief
   *    Function to check if the buffer is at
   *    max capacity.
   *
   *    @returnvalue
   *    True if amount of elements are
   *    equal to or exceeds capacity.
   **/
  bool is_full() { return (count >= capacity); }

  /**
   *    @brief
   *    Function to clear the buffer
   *    Set all elements in the buffer to 0.
   *    Set head, tail and count to 0
   *
   *    @returnvalue void
   **/
  void clear();
};

template <typename T, int N>
cbuffer_t<T, N>::cbuffer_t() : capacity(N), count(0), head(0), tail(0) {
  try {
    if (capacity < 4 || N < 4) {
      throw "ERROR: Circular buffer needs to be atleast 4 indicies long.";
    }
  } catch (const char* err) {
    std::cout << err << std::endl;
    std::exit(1); // terminate program
  }
  for (int i = 0; i < capacity; i++) {
    cbuffer[i] = 0;
  }
  std::cout << "cbuffer_t constructed." << std::endl;
}

template <typename T, int N> cbuffer_t<T, N>::~cbuffer_t() {
  clear();
  std::cout << "cbuffer_t destructed." << std::endl;
}

template <typename T, int N> bool cbuffer_t<T, N>::write_data(const T& data) {
  bool result{false};
  cbuffer[tail] = data;
  tail = (tail + 1) % capacity; // Overlaps around the array.

  if (is_full()) { // If the buffer is full move
    head++;        // the head instead.
  } else {
    count++;
  }
  std::cout << "Wrote " << data << " to buffer." << std::endl;
  result = true;
  return result;
}

template <typename T, int N> bool cbuffer_t<T, N>::read_data() {
  bool result{false};
  if (!count) { // if amount of elements is 0
    std::cout << "Circular buffer is empty." << std::endl;
  } else {
    result = true;
    std::cout << "Removed: " << cbuffer[head] << std::endl;
    cbuffer[head] = 0;
    count--;
    head = (head + 1) % capacity; // overlaps around the array
  }
  return result;
}

template <typename T, int N> void cbuffer_t<T, N>::clear() {
  for (int i = 0; i < capacity; i++) {
    cbuffer[i] = 0;
  }
  head = 0;
  tail = 0;
  count = 0;
}
#endif // CBUFFER_HPP
