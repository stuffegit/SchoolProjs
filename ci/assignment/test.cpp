#include "queue.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>

using ::testing::_;
using ::testing::Invoke;
using ::testing::NiceMock;
using ::testing::Return;

class Memory : public IMemory {
  size_t pos{0};
  uint8_t array[8192];
  std::vector<void*> vec;

public:
  MOCK_METHOD(void*, malloc, (size_t size), (override));
  MOCK_METHOD(void, free, (void* ptr), (override));

  size_t memory_blocks(void) { return vec.size(); }

  void* allocate(size_t size) {
    void* ptr{nullptr};
    if ((pos + size) < sizeof(array)) {
      ptr = &array[pos];
      vec.push_back(ptr);
      pos += size;
    }
    return ptr;
  }

  void release(void* ptr) { vec.erase(std::remove(vec.begin(), vec.end(), ptr), vec.end()); }

  ~Memory() { EXPECT_EQ(0, vec.size()); }
};

template <typename T> class QueueFixture : public ::testing::Test {
  const std::tuple<std::vector<int>, std::vector<float>, std::vector<std::string>> all_values{
      {1, 2, 3, 4, 5}, {1.5f, 2.5f, 3.5f, 4.5f, 5.5f}, {"aaa", "bbb", "ccc", "ddd", "eee"}};

protected:
  const std::vector<T> values{std::get<std::vector<T>>(all_values)};
  NiceMock<Memory> mock;
  queue_t<T> queue{mock};

  void SetUp(void) override {
    EXPECT_EQ(0, queue.size());
    for (size_t i = 1; i <= values.size(); i++) {
      ;
    }
  }
};

using Types = ::testing::Types<int, float, std::string>;
TYPED_TEST_SUITE(QueueFixture, Types);
TYPED_TEST(QueueFixture, mallocfails) { ; }
