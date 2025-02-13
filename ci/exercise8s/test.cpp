#include "queue.hpp"
#include <string>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class Memory : public IMemory {};

template <typename T> class QueueFixture : public queue_t<T> {
public:
  virtual ~QueueFixture() = default;
  virtual int testfunc() { return 1; }
};

using Types = ::testing::Types<int, float, std::string>;
TYPED_TEST_SUITE(QueueFixture, Types);

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}