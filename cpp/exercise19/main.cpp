#include "llist.hpp"
#include <iostream>

int main(void) {
  llist_t* list = llist_create(1);
  llist_t& reflist = *list;
  llist_insert_value(reflist, 2);
  llist_insert_value(reflist, 4);
  std::cout << llist_get_count(reflist) << std::endl;
  if (llist_remove_value(reflist, 2)) {
    std::cout << "Successful destruction of node\n";
  } else {
    std::cout << "Node not successfully destroyed\n";
  }
  std::cout << llist_get_count(reflist) << std::endl;
  llist_get_data(reflist);
  llist_search_value(reflist, 4);
  llist_change_value(reflist, 2, 7);
  llist_search_value(reflist, 4);
  llist_get_data(reflist);
  if (llist_destroy_list(reflist)) {
    std::cout << "Successful destruction of list\n";
  } else {
    std::cout << "List not successfully destroyed\n";
  }
  return 0;
}
