#include <array>
#include <iostream>
#include <string>

#define LEN 3

struct person_t {
  std::string name;
  int age;
  int id;
};

int main(void) {
  std::array<person_t, LEN> parr;
  std::array<person_t, LEN>* pparr = &parr;
  for (int i = 0; i < LEN; i++) {
    std::cout << "enter name,age,id\n";
    std::cin >> (*pparr)[i].name;
    std::cin >> (*pparr)[i].age;
    std::cin >> (*pparr)[i].id;
  }

  for (int i = 0; i < LEN; i++) {
    for (int j = 0; j < i; j++) {
      if ((*pparr)[i].id < (*pparr)[j].id) {
        person_t temp = (*pparr)[i];
        (*pparr)[i] = (*pparr)[j];
        (*pparr)[j] = temp;
      }
    }
  }

  for (int i = 0; i < LEN; i++) {
    std::cout << "Person: " << (*pparr)[i].id;
    std::cout << " Name: " << (*pparr)[i].name;
    std::cout << " Age: " << (*pparr)[i].age << std::endl;
  }
  return 0;
}
