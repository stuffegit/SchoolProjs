#include "llist.hpp"
#include <iostream>

int main(void) {
  llist_t list = llist_create(1);
  llist_t& reflist = list;
  llist_insert_value(reflist, 2);
  llist_insert_value(reflist, 4);
  std::cout << llist_get_count(reflist) << std::endl;
  llist_get_data(reflist);
  return 0;
}
