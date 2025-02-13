#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cstddef>

struct IMemory {
  virtual void* malloc(size_t size) = 0;
  virtual void free(void* ptr) = 0;
  virtual ~IMemory() = default;
};

template <typename T> class queue_t {
  struct node_t {
    T value;
    node_t* next;
  };

  node_t* front = nullptr;
  node_t* rear = nullptr;
  int elements = 0;
  int max_size = 0;

public:
  queue_t(int size) : max_size(size) {}
  virtual ~queue_t() = default;
  queue_t(const queue_t&) = delete;
  queue_t& operator=(const queue_t&) = delete;

  virtual int testfunc() = 0;
  // virtual bool enqueue(T value) = 0;
  // virtual int dequeue() = 0;
  // virtual int get_elements() = 0;
  // virtual int get_size() = 0;
  // virtual void clear() = 0;
};

#endif // QUEUE_HPP
