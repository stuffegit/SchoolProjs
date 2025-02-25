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

  node_t* head = nullptr;
  node_t* tail = nullptr;
  int count{0};
  IMemory& memory;

public:
  queue_t(const queue_t&) = delete;
  queue_t& operator=(const queue_t&) = delete;
  queue_t(IMemory& _memory) : memory(_memory) {}
  queue_t(queue_t&& that) noexcept;
  queue_t& operator=(queue_t&& that) noexcept {
    if (this != &that) {
      clear();
      head = that.head;
      tail = that.tail;
      count = that.count;
      that.head = nullptr;
      that.tail = nullptr;
      that.count = 0;
    }
    return *this;
  }

  bool enqueue(const T& item) {
    node_t* newNode = static_cast<node_t*>(memory.malloc(sizeof(node_t)));
    if (!newNode)
      return false;
    new (newNode) node_t{item, nullptr};
    if (tail)
      tail->next = newNode;
    else
      head = newNode;
    tail = newNode;
    ++count;
    return true;
  }
  bool dequeue(T& item) {
    if (!head)
      return false;
    node_t* temp = head;
    item = head->data;
    head = head->next;
    if (!head)
      tail = nullptr;
    memory.free(temp);
    --count;
    return true;
  }
  size_t size(void) const { return count; }
  void clear(void) {
    while (head) {
      node_t* temp = head;
      head = head->next;
      memory.free(temp);
    }
    tail = nullptr;
    count = 0;
  }
  ~queue_t() { clear(); }
};

#endif // QUEUE_H
