#include "greet.h"
#include <gtest/gtest.h>

TEST(GreetTests, TestOutput) {
  std::string testname{"stf"};
  EXPECT_EQ(greet(testname), "Hello, stf") << "greet func failed";
}
