#include <iostream>

#include "Person.h"

PersonList createPersonList(int n);
void destroyPersonList(PersonList& list);

int main() {
  int n = 4;
  PersonList list = createPersonList(n);

  for (int i = 0; i < list.numPeople; ++i) {
    std::cout << i << ": " << list.people[i].name << ", age "
              << list.people[i].age << '\n';
  }

  return 0;
}
