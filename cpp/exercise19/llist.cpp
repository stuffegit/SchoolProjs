#include "llist.hpp"
#include <iostream>

auto llist_create(int new_value) -> llist_t* {
  llist_t* list = new llist_t;
  list->head = nullptr;
  list->size = 0;
  bool success = true;
  node_t* new_node = new (std::nothrow) node_t;
  if (!new_node) {
    success = false;
  } else {
    new_node->value = new_value;
    new_node->next = nullptr;
    list->head = new_node;
    list->size = 1;
  }
  if (!success) {
    delete list;
    list = nullptr;
  }
  return list;
}

auto llist_insert_value(llist_t& list, int new_value) -> bool {
  bool success = true;
  node_t* new_node = new node_t;
  if (!new_node) {
    success = false;
  } else {
    new_node->value = new_value;
    new_node->next = nullptr;

    if (list.head == nullptr) {
      list.head = new_node;
    } else {
      node_t* current_pos = list.head;
      while (current_pos->next != nullptr) {
        current_pos = current_pos->next;
      }
      current_pos->next = new_node;
    }
    list.size++;
  }
  return success;
}

auto llist_get_count(const llist_t& list) -> int { return list.size; }

auto llist_get_data(const llist_t& list) -> void {
  node_t* current_pos = list.head;
  while (current_pos != nullptr) {
    std::cout << current_pos->value << " -> ";
    current_pos = current_pos->next;
  }
  std::cout << "nullptr" << std::endl;
}

auto llist_search_value(const llist_t& list, int value) -> void {
  size_t position = 0;
  size_t index = 1;
  node_t* current_pos = list.head;

  while (current_pos != nullptr) {
    if (current_pos->value == value) {
      position = index;
      break;
    }
    current_pos = current_pos->next;
    index++;
  }

  if (position == 0) {
    std::cout << "Value " << value << " not found in the list." << std::endl;
  } else {
    std::cout << "Value " << value << " found at position " << position << "."
              << std::endl;
  }
}

auto llist_remove_value(llist_t& list, size_t position) -> bool {
  bool success = false;

  if (list.head == nullptr) {
    std::cout << "There's no list" << std::endl;
  } else if (position == 0 || position > list.size) {
    std::cout << "Invalid position" << std::endl;
  } else {
    node_t* current_pos = list.head;
    node_t* prev_pos = nullptr;

    if (position == 1) {
      list.head = current_pos->next;
      delete current_pos;
      success = true;
    } else {
      for (size_t index = 1; index < position; ++index) {
        prev_pos = current_pos;
        current_pos = current_pos->next;
      }
      if (current_pos == nullptr) {
        std::cout << "Position does not exist in list.\n";
      } else {
        prev_pos->next = current_pos->next;
        delete current_pos;
        success = true;
      }
    }
    if (success) {
      list.size--;
    }
  }
  return success;
}

auto llist_change_value(llist_t& list, size_t position, int new_value) -> bool {
  bool success = false;

  if (list.head == nullptr) {
    std::cout << "There's no list" << std::endl;
  } else if (position == 0 || position > list.size) {
    std::cout << "Invalid position" << std::endl;
  } else {
    node_t* current_pos = list.head;

    if (position == 1) {
      current_pos->value = new_value;
      success = true;
    } else {
      for (size_t index = 1; index < position; ++index) {
        current_pos = current_pos->next;
      }

      if (current_pos == nullptr) {
        std::cout << "Position does not exist in list.\n";
      } else {
        current_pos->value = new_value;
        success = true;
      }
    }
  }
  return success;
}

auto llist_destroy_list(llist_t& list) -> bool {
  bool success = false;
  node_t* current_pos = list.head;
  node_t* next_node = nullptr;

  while (current_pos != nullptr) {
    next_node = current_pos->next;
    delete current_pos;
    current_pos = next_node;
  }

  list.head = nullptr;
  list.size = 0;

  if (list.head == nullptr) {
    success = true;
  }
  return success;
}
