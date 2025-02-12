#include "llist.h"
#include <iostream>

bool llist_t::sort() {
  bool result = false;

  if (head != nullptr && head->next != nullptr) {
    node_t* sorted = nullptr;
    node_t* current = head;
    while (current != nullptr) {
      node_t* next = current->next;
      if (sorted == nullptr || sorted->value >= current->value) {
        current->next = sorted;
        sorted = current;
      } else {
        node_t* temp = sorted;
        while (temp->next != nullptr && temp->next->value < current->value) {
          temp = temp->next;
        }
        current->next = temp->next;
        temp->next = current;
      }
      current = next;
    }
    head = sorted;
    result = true;
  } else {
    result = true;
  }
  return result;
}

void llist_t::print() {
  node_t* temp = head;
  if (head == nullptr) {
    std::cout << "List empty";
  } else {
    while (temp != nullptr) {
      std::cout << temp->value << " ";
      temp = temp->next;
    }
  }
  std::cout << std::endl;
}

bool llist_t::insert(int value) {
  bool result{false};
  node_t* new_node = new node_t(value);
  if (head == nullptr) {
    head = new_node;
    size = 1;
    result = true;
  } else {
    new_node->next = head;
    head = new_node;
    size++;
    result = sort();
  }
  return result;
}

bool llist_t::search(int value) {
  bool result{false};
  node_t* temp = head;
  while (temp != nullptr) {
    if (temp->value == value) {
      result = true;
      break;
    }
    temp = temp->next;
  }
  return result;
}

bool llist_t::remove(int value) {
  bool result = false;
  node_t* current = head;
  node_t* prev = nullptr;

  while (current != nullptr) {
    if (current->value == value) {
      if (prev == nullptr) {
        head = current->next;
      } else {
        prev->next = current->next;
      }
      delete current;
      size--;
      result = true;
      break;
    }
    prev = current;
    current = current->next;
  }
  return result;
}

bool llist_t::edit(int old_value, int new_value) {
  bool result = false;
  if (remove(old_value)) {
    result = insert(new_value);
  }
  return result;
}

void llist_t::clear() {
  node_t* current = head;

  while (current != nullptr) {
    node_t* temp = current;
    current = current->next;
    delete temp;
  }

  head = nullptr;
  size = 0;
}
