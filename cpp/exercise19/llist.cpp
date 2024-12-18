#include "llist.hpp"
#include <iostream>

auto llist_create(int new_value) -> llist_t {
  // TODO: Placeholder code.
  llist_t list;
  node_t* new_node = new node_t;
  new_node->next = nullptr;
  new_node->value = new_value;
  list.head = new_node;
  list.size = 1;
  return list;
}

auto llist_insert_value(llist_t& list, int new_value) -> bool {
  bool success = true;
  node_t* new_node = new node_t;
  node->next = nullptr;
  node->value = new_value;
  list.head->next = &node;
  list.size++;
  return success;
}

auto llist_get_count(const llist_t& list) -> int { return list.size; }

auto llist_get_data(const llist_t& list) -> void {
  node_t* current_pos = list.head;
  for (int i = 0; i < llist_get_count(list); i++) {
    std::cout << current_pos->value << std::endl;
    current_pos = current_pos->next;
  }
}

// auto llist_search_value() -> bool {}

// auto llist_remove_value() -> bool {}

// auto llist_change_value() -> bool {}

// auto llist_destroy_list() -> bool {}
