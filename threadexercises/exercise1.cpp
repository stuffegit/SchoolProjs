/*
Using two threads make a program to print “Ping - Pong” every second to the
terminal. A thread shall print Ping and the other thread shall print Pong to the
terminal. Using two mutexes ensure the right order so that the output looks
like: Ping - Pong Ping - Pong Ping - Pong …
*/
#include <mutex>
#include <thread>
#include <iostream>

static std::mutex mtx1;
static std::mutex mtx2;

void ping() {
  mtx1.lock();
  std::cout << "Ping - ";
  mtx2.unlock();
}

void pong() {
  mtx2.lock();
  std::cout << "Pong" << std::endl;
  mtx1.unlock();
}

int main(void) {
  int i{1};
  while (1) {
    std::cout << "Iterations: " << i++ << std::endl;
    std::thread thrd1(ping);
    std::thread thrd2(pong);
    thrd1.join();
    thrd2.join();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
  return 0;
}
