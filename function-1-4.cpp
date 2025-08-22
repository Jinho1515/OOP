#include "Person.h"

PersonList createPersonList(int n) {
  PersonList list{};
  if (n <= 0) {
    list.people = nullptr;
    list.numPeople = 0;
    return list;
  }

  list.numPeople = n;
  list.people = new Person[n];
  for (int i = 0; i < n; ++i) {
    list.people[i].name = "Jane Doe";
    list.people[i].age = 1;
  }
  return list;
}
PersonList shallowCopyPersonList(PersonList pl){
  PersonList copy{};


  copy.numPeople = pl.numPeople;
  copy.people = pl.people;

  return copy;
}