
#ifndef QUEUE_HPP
#define QUEUE_HPP

class queue_t {
private:
  struct node_t {
    int data;
    node_t* next;

    node_t(int value) : data(value), next(nullptr) {}
  };

  node_t* front;
  node_t* rear;
  int elements;
  int max_size;

public:
  queue_t(int size);
  ~queue_t();

  queue_t(const queue_t&) = delete;
  queue_t& operator=(const queue_t&) = delete;

  bool enqueue(int value);
  int dequeue();
  int get_elements() { return elements; }
  void clear();
};

#endif // QUEUE_HPP
