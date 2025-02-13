#include "queue.hpp"
#include <gtest/gtest.h>
queue_t queue;

TEST(queueTests, TestOutput) {
  EXPECT_EQ(queue.dummyfunc(), 1) << "queue func failed";
}
