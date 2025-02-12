#include "llist.h"
#include <gtest/gtest.h>

llist_t list;

TEST(ll_tests, test_insert) {
  list.insert(1);
  list.insert(2);
  list.insert(3);
  list.print();
  EXPECT_EQ(list.get_size(), 3) << "Insert test failed";
}
TEST(ll_tests, test_remove) {
  list.remove(1);
  list.print();
  EXPECT_EQ(list.get_size(), 2) << "Insert test failed";
}
