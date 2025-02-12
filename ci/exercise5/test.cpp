#include "queue.h"
#include <gtest/gtest.h>

TEST(queueTests, TestOutput) {
  std::string testname{"stf"};
  EXPECT_EQ(queue(testname), "Hello, stf") << "queue func failed";
}
