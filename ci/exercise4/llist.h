#ifndef LLIST_H
#define LLIST_H

struct node_t {
  int value;
  node_t* next;

  node_t(int value) : value(value), next(nullptr) {}
};

class llist_t {
  node_t* head;
  int size;

public:
  llist_t() : head(nullptr), size(0) {}
  ~llist_t() { clear(); }

  llist_t(const llist_t&) = delete;
  llist_t& operator=(const llist_t&) = delete;

  llist_t(llist_t&& that) noexcept {
    this->head = that.head;
    this->size = that.size;
  }
  llist_t& operator=(llist_t&& that) noexcept {
    if (this != &that) {
      this->head = that.head;
      this->size = that.size;
    }
    return *this;
  }

  int get_size() { return size; }
  bool sort();
  void print();
  bool insert(int value);
  bool search(int value);
  bool remove(int value);
  bool edit(int old_value, int new_value);
  void clear();
};

#endif // LLIST_H
