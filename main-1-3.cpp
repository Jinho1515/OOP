#include <iostream>

#include "Person.h"

PersonList createPersonList(int n);
PersonList deepCopyPersonList(PersonList pl);

int main() {
  PersonList a = createPersonList(3);

  for (int i = 0; i < a.numPeople; ++i) {
    std::cout << "  " << i << ": " << a.people[i].name << ", age "
              << a.people[i].age << "\n";
  }
  a.people[1].name = "OrigChanged";
  a.people[2].age = 42;

  PersonList b = deepCopyPersonList(a);

  for (int i = 0; i < b.numPeople; ++i) {
    std::cout << "  " << i << ": " << b.people[i].name << ", age "
              << b.people[i].age << "\n";
  }

  return 0;
}
