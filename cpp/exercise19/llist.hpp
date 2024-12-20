#pragma once

#include <cstddef>

struct node_t {
  node_t* next;
  int value;
};

struct llist_t {
  node_t* head;
  int size;
};

auto llist_create(int new_value) -> llist_t*;
auto llist_insert_value(llist_t& list, int value) -> bool;
auto llist_get_count(const llist_t& list) -> int;
auto llist_get_data(const llist_t& list) -> void;
auto llist_search_value(const llist_t& list, int value) -> void;
auto llist_remove_value(llist_t& list, size_t position) -> bool;
auto llist_change_value(llist_t& list, size_t position, int new_value) -> bool;
auto llist_destroy_list(llist_t& list) -> bool;
