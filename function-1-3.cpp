#include "Person.h"

PersonList deepCopyPersonList(PersonList pl) {
  PersonList copy{};
  if (pl.numPeople <= 0 || pl.people == nullptr) {
    copy.people = nullptr;
    copy.numPeople = 0;
    return copy;
  }

  copy.numPeople = pl.numPeople;
  copy.people = new Person[copy.numPeople];

  for (int i = 0; i < copy.numPeople; i++) {
    copy.people[i].name = pl.people[i].name;
    copy.people[i].age = pl.people[i].age;
  }
  return copy;
}