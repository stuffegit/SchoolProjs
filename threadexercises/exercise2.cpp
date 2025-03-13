/*
Using a mutex, a condition variable and 3 threads every secode print 1 – 2 – 3
to the terminal. The first thread shall print 1 – , the second thread shall
print 2 – and the third thread shall print 3 and newline. The threads shall be
synchronized.
*/

#include <chrono>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

std::mutex mtx;
std::condition_variable cv;

static volatile size_t order{1};

void print1(void) {
  std::unique_lock<std::mutex> lck(mtx);
  cv.wait(lck, [] { return order == 1; });
  std::cout << "1 - ";
  order = 2;
  cv.notify_all();
}

void print2(void) {
  std::unique_lock<std::mutex> lck(mtx);
  cv.wait(lck, [] { return order == 2; });
  std::cout << "2 - ";
  order = 3;
  cv.notify_all();
}

void print3(void) {
  std::unique_lock<std::mutex> lck(mtx);
  cv.wait(lck, [] { return order == 3; });
  std::cout << "3" << std::endl;
  order = 1;
  cv.notify_all();
}

int main(void) {
  while (1) {
    std::thread thrd1{print1};
    std::thread thrd2{print2};
    std::thread thrd3{print3};
    thrd1.join();
    thrd2.join();
    thrd3.join();
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  return 0;
}
