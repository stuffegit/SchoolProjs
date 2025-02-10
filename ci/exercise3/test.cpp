#include "greet.h"
#include <gtest/gtest.h>

TEST(GreetTests, TestNullOutput) {
  std::string testname{""};
  EXPECT_EQ(greet(testname), "Hello, my friend.") << "Normal output test failed.";
}
TEST(GreetTests, TestNormalOutput) {
  std::string testname{"a"};
  EXPECT_EQ(greet(testname), "Hello, a.") << "Normal output test failed.";
}
TEST(GreetTests, TestCapsOutput) {
  std::string testname{"A"};
  EXPECT_EQ(greet(testname), "HELLO A!") << "Caps output test failed.";
}
TEST(GreetTests, TestTwoNameOutput) {
  std::string testname{"a,b"};
  EXPECT_EQ(greet(testname), "Hello, a and b.") << "Two normal name output test failed.";
}
TEST(GreetTests, TestTwoCapsNameOutput) {
  std::string testname{"A,B"};
  EXPECT_EQ(greet(testname), "HELLO A AND B!") << "Two caps name output test failed.";
}
TEST(GreetTests, TestFiveNameOutput) {
  std::string testname{"a,b,c,d,e"};
  EXPECT_EQ(greet(testname), "Hello, a, b, c, d, and e.") << "Five name output test failed.";
}
TEST(GreetTests, TestFiveCapsNameOutput) {
  std::string testname{"A,B,C,D,E"};
  EXPECT_EQ(greet(testname), "HELLO A, B, C, D, AND E!") << "Five caps name output test failed.";
}
TEST(GreetTests, TestTwoMixedNameOutput) {
  std::string testname{"A,b"};
  EXPECT_EQ(greet(testname), "Hello, b. AND HELLO A!") << "Two Mixed name output test failed.";
}
TEST(GreetTests, TestSixMixedNameOutput) {
  std::string testname{"A,b,C,d,E,f"};
  EXPECT_EQ(greet(testname), "Hello, b, d, and f. AND HELLO A, C, AND E!")
      << "Five Mixed name output test failed.";
}
