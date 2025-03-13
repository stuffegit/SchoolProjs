/*
Implement a thread-safe uncopyable template stack class using an array.
When a stack is empty, if a thread tries to pop it shall be suspended.
When a stack is full, if a thread tries to push it shall be suspended.

A piece of code is thread-safe if it functions correctly during simultaneous
execution by multiple threads. In particular, it must satisfy the need for
multiple threads to access the same shared data and the shared data shall be
accessed by only one thread at any given time.
*/
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <array>
#include <mutex>
#include <thread>
#include <atomic>
#include <time.h>

std::mutex mtx;

template <typename T, size_t U> class stack_t {
  std::array<T, U> arr;
  std::atomic<size_t> count{0};

public:
  stack_t() {
    arr.fill(0);
  }

  size_t get_size() {
    return arr.max_size();
  }

  size_t get_count() {
    return count;
  }

  bool push(T new_value) {
    bool result{false};
    if (get_count() == get_size()) {
      std::this_thread::yield();
    } else {
      arr[count++] = new_value;
      result = true;
    }
    return result;
  }

  T pop() {
    T result{T()};
    if (count == 0) {
      std::this_thread::yield();
    } else {
      result = arr[--count];
    }
    return result;
  }
};

int main(void) {
  srand(time(nullptr));
  int i{1};
  static stack_t<int, 5> stack;
  for (size_t i = 0; i < 10; i++) {
    std::thread push1{[&] {
      if (stack.push(i++)) {
        std::cout << "Count: " << stack.get_count() << " Push:" << i;
      } else {
        std::cout << "Count: " << stack.get_count() << " Failed push! ";
        std::cout << std::this_thread::get_id() << std::endl;
      }
    }};
    std::thread push2{[&] {
      std::cout << std::this_thread::get_id();
      if (stack.push(i++)) {
        std::cout << " Count: " << stack.get_count() << " Push:" << i;
      } else {
        std::cout << " Count: " << stack.get_count() << " Failed push! ";
      }
      std::cout << std::this_thread::get_id() << std::endl;
    }};
    push1.join();
    push2.join();
  }
  for (size_t i = 0; i < 10; i++) {
    std::thread pop{[&] {
      std::cout << std::this_thread::get_id();
      std::cout << " Count: " << stack.get_count() << " Pop:" << stack.pop()
                << std::endl;
    }};
    pop.join();
  }
  std::cout << std::this_thread::get_id() << " id of main" << std::endl;
  return 0;
}
